#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

// Search TODO to find the locations where code needs to be completed

#define     NUM_THREADS     2

typedef struct {
    unsigned int id;
    TMatrix *m, *n, *t;
} thread_arg_t;

static void *thread_main(void *p_arg) {
    // TODO
    thread_arg_t *v = (thread_arg_t *) p_arg;
    int prev;

    if (v->id == 0) {
        prev = 0;
    } else {
        prev = v->m->nrows / 2;
    }

    int next;

    if (v->id == 0) {
        next = v->m->nrows / 2;
    } else {
        next = v->m->nrows;
    }

    for (unsigned int i = prev; i < next; i++) {
        for (unsigned int j = 0; j < v->n->ncols; j++) {
            TElement sum = (TElement) 0;
            for (unsigned int k = 0; k < v->m->ncols; k++)
                sum += v->m->data[i][k] * v->n->data[k][j];
            v->t->data[i][j] = sum;
        }
    }
    return NULL;
}

/* Return the sum of two matrices.
 *
 * If any pthread function fails, report error and exit.
 * Return NULL if anything else is wrong.
 *
 * Similar to mulMatrix, but with multi-threading.
 */
TMatrix *mulMatrix_thread(TMatrix *m, TMatrix *n) {
    if (m == NULL || n == NULL
        || m->ncols != n->nrows)
        return NULL;

    TMatrix *t = newMatrix(m->nrows, n->ncols);
    if (t == NULL)
        return t;

    // TODO
    pthread_t pthread1, pthread2;
    thread_arg_t thr0, thr1;

    thr0.id = 0;
    thr1.id = 1;
    thr0.m = m;
    thr0.n = n;
    thr0.t = t;
    thr1.m = m;
    thr1.n = n;
    thr1.t = t;
    void *v1, *v2;

    pthread_create(&pthread1, NULL, thread_main, (void *) &thr0);
    pthread_create(&pthread2, NULL, thread_main, (void *) &thr1);
    // TODO
    pthread_join(pthread1, &v1);
    pthread_join(pthread2, &v2);
    return t;
}