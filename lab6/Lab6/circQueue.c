#include <stdio.h>
#include <stdlib.h>
#include "lab6.h"

void initQueue(struct Queue ** qPtr)
{

	struct Queue *q = (struct Queue *)calloc(1, sizeof(struct Queue));
	q->currSize = 0;
	q->front = 0;
	q->rear = 0;
	qPtr = &q;

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
	if(Q->currSize == 0){
	
	

	}


}

void dequeue(struct Queue * Q, struct Data *d)
{
}

void freeQueue(struct Queue * q){
}
