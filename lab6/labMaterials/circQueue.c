#include <stdio.h>
#include <stdlib.h>
#include "lab6.h"

void initQueue(struct Queue ** qPtr)
{

	struct Queue *q = (struct Queue *)calloc(1, sizeof(struct Queue));
	q->currSize = 0;
	q->front = 0;
	q->rear = 0;
	*qPtr = q;

}

int isEmpty(struct Queue * Q)
{

	if(Q->currSize == 0){
		return 1;
	}

	return 0;
}

void enqueue(struct Queue * Q, struct Data d)
{
	struct Node n;
	n.data = d;
	if(Q->currSize < MaxQueueSize){
	Q->queueArray[Q->rear] = n;
	Q->rear = ((Q->rear)+1)%MaxQueueSize;
	Q->currSize++;
	}
}

void dequeue(struct Queue * Q, struct Data *d)
{

	struct Node n;
	
	if(isEmpty(Q) != 1){

	n = Q->queueArray[Q->front];
	*d = n.data;
	Q->front = ((Q->front)+1)%MaxQueueSize;
	Q->currSize--;

	}
}	

void freeQueue(struct Queue * q){

	free(q);


}
