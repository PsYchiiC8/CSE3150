#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int userThreadCounter = 1;
int userThreadsServed = 0;

pthread_mutex_t userMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t kernelMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dummyMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t userCond = PTHREAD_COND_INITIALIZER;
pthread_cond_t kernelCond = PTHREAD_COND_INITIALIZER;

typedef struct {
    int filled;
    int servedId;
    pthread_mutex_t mutex;
} packet_obj;

typedef struct {
    packet_obj** packet_array;
    int id;
    int N;
    int X;
} thread_arg_t;

packet_obj* packet_init() {
    packet_obj* p = (packet_obj*)malloc(sizeof(packet_obj));
    p->filled = 0;
    p->servedId = -1;
    pthread_mutex_init(&p->mutex, NULL);
    return p;
}

void thread_arg_init(thread_arg_t* t, packet_obj** givenPacketArray, int givenId, int givenN, int givenX) {
    t->packet_array = givenPacketArray;
    t->id = givenId;
    t->N = givenN;
    t->X = givenX;
}

void* userThread(void* arg_in) {
    thread_arg_t* arg = (thread_arg_t*)arg_in;
    int my_id = arg->id;
    int N = arg->N;
    int X = arg->X;
    packet_obj** pArray = arg->packet_array;

    usleep(10000 + 10000 * (my_id * 1000 % 5));

    while (userThreadCounter != my_id) {
        pthread_mutex_lock(&userMutex);
        pthread_cond_wait(&userCond, &userMutex);
        pthread_mutex_unlock(&userMutex);
    }

    int i = 0;
    int packetsChecked = 0;
    while (1) {
        packet_obj* p = pArray[i];
        pthread_mutex_lock(&p->mutex);
        if (!p->filled) {
            p->filled = 1;
            p->servedId = my_id;
            printf("User level thread %d is going to put data in a packet\n", my_id);

            userThreadCounter++;
            userThreadsServed++;
            pthread_cond_broadcast(&kernelCond);
            pthread_mutex_unlock(&p->mutex);
            break;
        }
        pthread_mutex_unlock(&p->mutex);
        i = (i + 1) % X;
    }

    pthread_mutex_lock(&dummyMutex);
    pthread_cond_broadcast(&kernelCond);
    pthread_mutex_unlock(&dummyMutex);

    if (userThreadsServed < N) {
        pthread_mutex_lock(&userMutex);
        pthread_cond_signal(&userCond);
        pthread_mutex_unlock(&userMutex);
    }

    pthread_exit(NULL);
}

void* kernelThread(void* arg_in) {
    thread_arg_t* arg = (thread_arg_t*)arg_in;
    int my_id = arg->id;
    int N = arg->N;
    int X = arg->X;
    packet_obj** pArray = arg->packet_array;

    usleep(10000 + 10000 * (my_id * 1000 % 5));

    int i = 0;
    int packetsChecked = 0;
    while (userThreadsServed < N) {
        packet_obj* p = pArray[i];
        pthread_mutex_lock(&p->mutex);
        if (p->filled) {
            p->filled = 0;
            int servedId = p->servedId;
            userThreadsServed++;
            printf("user thread %d getting served\n", servedId);
            pthread_cond_signal(&userCond);
        }
        pthread_mutex_unlock(&p->mutex);
        i = (i + 1) % X;

        if (packetsChecked == X) {
            pthread_mutex_lock(&dummyMutex);
            printf("No data available, Going to sleep kernel thread %d\n", my_id);
            pthread_cond_broadcast(&userCond);
            pthread_cond_wait(&kernelCond, &dummyMutex);
            pthread_mutex_unlock(&dummyMutex);
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s X N M\n", argv[0]);
        return 1;
    }

    int X = atoi(argv[1]);
    int N = atoi(argv[2]);
    int M = atoi(argv[3]);

    pthread_mutex_init(&userMutex, NULL);
    pthread_mutex_init(&kernelMutex, NULL);
    pthread_mutex_init(&dummyMutex, NULL);
    pthread_cond_init(&userCond, NULL);
    pthread_cond_init(&kernelCond, NULL);

    packet_obj** packetArray = (packet_obj**)malloc(X * sizeof(packet_obj*));

    for (int i = 0; i < X; i++) {
        packetArray[i] = packet_init();
    }

    pthread_t userThreads[N];
    thread_arg_t userThreadArgs[N];
    pthread_t kernelThreads[M];
    thread_arg_t kernelThreadArgs[M];

    for (int i = 0; i < N; i++) {
        thread_arg_t t;
        thread_arg_init(&t, packetArray, i + 1, N, X);
        userThreadArgs[i] = t;
    }

    for (int i = 0; i < M; i++) {
        thread_arg_t t;
        thread_arg_init(&t, packetArray, i + 1, N, X);
        kernelThreadArgs[i] = t;
    }

    for (int i = 0; i < N; i++) {
        pthread_create(&userThreads[i], NULL, userThread, &userThreadArgs[i]);
    }

    for (int i = 0; i < M; i++) {
        pthread_create(&kernelThreads[i], NULL, kernelThread, &kernelThreadArgs[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(userThreads[i], NULL);
    }

    for (int i = 0; i < M; i++) {
        pthread_join(kernelThreads[i], NULL);
    }

    pthread_mutex_destroy(&userMutex);
    pthread_mutex_destroy(&kernelMutex);

    for (int i = 0; i < X; i++) {
        pthread_mutex_destroy(&packetArray[i]->mutex);
        free(packetArray[i]);
    }

    free(packetArray);
    pthread_cond_destroy(&userCond);

    pthread_cond_destroy(&kernelCond);

    return 0;
}