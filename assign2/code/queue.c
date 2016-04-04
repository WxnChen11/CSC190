#include "queue.h"

struct Queue initQueue()
{

	struct Queue queue;

	queue.currSize = 0;
	queue.front = NULL;
	queue.rear = NULL;

	return queue;

}

void enqueue(struct Queue *qPtr, struct Data d)
{

	struct Node *nd = (struct Node *)calloc(1, sizeof(struct Node));
	nd->next = NULL;
	nd->data = d;

	if ((qPtr->rear) != NULL){
		qPtr->rear->next = nd;
		qPtr->rear = nd;
	}
	else{
		qPtr->rear = nd;
		qPtr->front = nd;	
	
	}

	qPtr->currSize = (qPtr->currSize) + 1;

}

struct Data dequeue(struct Queue *qPtr)
{

	struct Data dt;
	struct Node *temp;

	if((qPtr->front) != NULL){
	//printf("removing\n");
	dt = qPtr->front->data;
	temp = qPtr->front->next;
	free(qPtr->front);
	qPtr->front = temp;
	

	if(qPtr->currSize == 1){
		qPtr->rear = NULL;

	}

	qPtr->currSize = (qPtr->currSize) - 1;
	//printf("%lf", dt.arrivalTime);
	return dt;

	}

}
void freeQueue(struct Queue *qPtr)
{

	struct Node *temp;
	struct Node *node;

	node = qPtr->front;

	int size = qPtr->currSize;
	
	int x;
	for(x = 0; x < size; x++){
	
	//printf("free");

	temp = node->next;
	free(node);
	node = temp;

	}

}




