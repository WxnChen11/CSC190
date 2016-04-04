#include "lab8.h"

struct Edge ** initAdjMatrix(){

    struct Edge **m = (struct Edge **)calloc(NODES, sizeof(struct Edge *));

    int i,j;

    for(i = 0; i < NODES; i++){

        m[i] = (struct Edge *)calloc(NODES, sizeof(struct Edge));

    }

    for(i = 0; i < NODES; i++){
        for(j = 0; j < NODES; j++){

            struct Edge e;
            e.flow = 0;
            e.flowCap = 0;
            m[i][j] = e;
        }

    }

    return m;
}

void insertAdjMatrix(struct Edge ** aM, int vi, int vj, int flow, int flowCap){

    struct Edge e = aM[vi][vj];
    e.flow = flow;
    e.flowCap = flowCap;

    aM[vi][vj] = e;

}

void deleteAdjMatrix(struct Edge ** aM){

    int i;

    for(i = 0; i < NODES; i++){

        free(aM[i]);

    }

    free(aM);
}

void printAdjMat(struct Edge ** aM){

    int i,j;

    for(i = 0 ; i < NODES; i++){
        for(j = 0; j < NODES; j++){

            struct Edge e = aM[i][j];

            if(e.flowCap > 0){

                printf("Edge: (%d, %d) Flow: %d Max Cap: %d\n", i, j, e.flow, e.flowCap);
            }

        }

    }

}
