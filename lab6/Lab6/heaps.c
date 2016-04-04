#include <stdio.h>
#include <stdlib.h>
#include "lab6.h"

struct Heap * initMinHeap()
{
	struct Heap *h = (struct Heap *)calloc(1, sizeof(struct Heap));
	h->count = 0;
	return h;

}

void insertMinHeap(struct Heap * h, struct Data d)
{
	struct Node n;
	n.data = d;
	
	h->count = h->count + 1;

	int cInd = (h->count);
	int pInd = cInd/2;
	
	if(h->count == 1){
	
	h->heapArray[1] = n;
	return;	

	}

	
	while(pInd > 0){
	
		if((h->heapArray)[pInd].data.data > d.data){
			(h->heapArray)[cInd] = (h->heapArray)[pInd];
			cInd = pInd;
			pInd = cInd/2;

		}
		else{
			(h->heapArray)[cInd] = n;
			return;
		}
		

	}
		
	(h->heapArray)[cInd] = n;
}

struct Data removeMinHeap(struct Heap * h)
{

	struct Data res = h->heapArray[1].data; 
	h->heapArray[1] = h->heapArray[h->count];
	h->count = h->count - 1;
	
	int pInd = 1;
	int cInd = pInd * 2;
	
	struct Data holder;

	while(cInd < h->count){


		if(h->heapArray[cInd].data.data > h->heapArray[cInd+1].data.data){
			cInd = cInd + 1;
		}
		
		if(h->heapArray[pInd].data.data > h->heapArray[cInd].data.data){
			
			holder = h->heapArray[pInd].data;

			h->heapArray[pInd].data = h->heapArray[cInd].data;
			h->heapArray[cInd].data = holder;
						
		}

		pInd = cInd;
		cInd = pInd*2;

	}
	
	if(cInd == h->count){
		if(h->heapArray[cInd].data.data < h->heapArray[pInd].data.data){

			holder = h->heapArray[pInd].data;
			h->heapArray[pInd].data = h->heapArray[cInd].data;
			h->heapArray[cInd].data = holder;
		}
	}

	return res;
}

void freeMinHeap(struct Heap * h)
{

free(h);

}
