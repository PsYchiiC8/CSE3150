#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

#define     NUM_THREADS     2

typedef struct {
    unsigned int id;
    TMatrix *m, *n, *t;
} thread_arg_t;

/* the main function of threads */
static void *thread_main(void *p_arg) {
    // TODO
    thread_arg_t *myMatrix = (thread_arg_t*) p_arg;

    TMatrix *m = myMatrix->m;
    TMatrix *n = myMatrix->n;
    TMatrix *t = myMatrix->t;

    for(unsigned int i = myMatrix->id; i < m->nrows; i += NUM_THREADS){
        for(unsigned int j = 0; j < n->ncols; j++){
            t->data[i][j] = m->data[i][j] + n->data[i][j];
        }
    }

    pthread_exit(NULL);
    return NULL;
}

/* Return the sum of two matrices. The result is in a newly created matrix.
 *
 * If a pthread function fails, report error and exit. 
 * Return NULL if something else is wrong.
 *
 * Similar to addMatrix, but this function uses 2 threads.
 */
TMatrix *addMatrix_thread(TMatrix *m, TMatrix *n) {
    if (m == NULL || n == NULL
        || m->nrows != n->nrows || m->ncols != n->ncols)
        return NULL;

    TMatrix *t = newMatrix(m->nrows, m->ncols);
    if (t == NULL)
        return t;

    // TODO
    pthread_t threads[NUM_THREADS];
    thread_arg_t args[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++){
        args[i].id = i;
        args[i].m = m;
        args[i].n = n;
        args[i].t = t;
        if(pthread_create(&threads[i], NULL, thread_main, &args[i]) != 0){
            fprintf(stderr, "Thread creation failed");
            exit(-1);
        }
    }

    for(int i = 0; i < NUM_THREADS; i++){
        if(pthread_join(threads[i], NULL) != 0){
            fprintf(stderr, "Thread joining failed");
            exit(-1);
        }
    }

    return t;
}
