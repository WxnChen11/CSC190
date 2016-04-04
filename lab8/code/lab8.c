#include "lab8.h"

struct flowNetwork * initFlowNetwork(){

    struct flowNetwork *fn = (struct flowNetwork *)calloc(1, sizeof(struct flowNetwork));

    fn->adjMatrix = initAdjMatrix();

    int i;

    for(i = 0; i < NODES; i++){

        fn->visitedNodes[i] = 0;
        fn->parent[i] = -1;
    }

    return fn;
}

void deleteFlowNetwork(struct flowNetwork * fN){

    deleteAdjMatrix(fN->adjMatrix);
    free(fN);
}

int breadthFirstPathSearch(struct flowNetwork * fN, int s, int t){

    struct Queue *q;
    initQueue(&q);

    struct Data d;
    d.vertex = s;

    struct Edge **adjm = fN->adjMatrix;

    enqueue(q, d);

    while(isQueueEmpty(q) == 0){

        struct Data dqdata;
        dequeue(q, &dqdata);

        int v = dqdata.vertex;

        int i;



        for(i = 0; i < NODES; i++){

            if(fN->visitedNodes[i] == 0 && adjm[v][i].flowCap != 0 && adjm[v][i].flowCap > adjm[v][i].flow){

                fN->visitedNodes[i] = 1;
                fN->parent[i] = v;
                struct Data eqdata;
                eqdata.vertex = i;
                enqueue(q, eqdata);
            }
        }


    }

    free(q);

    if(fN->visitedNodes[t] == 1){

        return 1;
    }

    return 0;


}
