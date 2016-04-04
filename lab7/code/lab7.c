#include "lab7.h"

struct Node * insertBST(struct Node * r, struct Data d){

	if(r == NULL){
		struct Node *n = (struct Node *)calloc(1, sizeof(struct Node));
		n->lChild = NULL;
		n->rChild = NULL;
		n->d = d;

		return n;
	}

	else if(r->d.data < d.data){

		r-> rChild = insertBST( r-> rChild, d);

	}

	else if(r->d.data > d.data){
		r-> lChild = insertBST( r-> lChild, d);
	}

	return r;
}

void printInOrder(struct Node * r){


	if(r != NULL){

		printInOrder(r-> lChild);
		printf("%d ", r->d.data);
		printInOrder(r-> rChild);

	}

}

void printInReverseOrder(struct Node * r){


	if(r != NULL){

		printInReverseOrder(r-> rChild);
		printf("%d ", r->d.data);
		printInReverseOrder(r-> lChild);

	}

}
void deleteTree(struct Node * r){


	if(r != NULL){

		deleteTree(r-> lChild);
		deleteTree(r-> rChild);
		free(r);
	}



}

void printBSTs(struct Node * r1, struct Node * r2){

    struct Stack *s1 = initializeStack();
    struct Stack *s2 = initializeStack();
    struct Node * d;

    push(s1, r1);

    while(isEmpty(s1) == 0){

        d = pop(s1);
        if(d != NULL){

            push(s2, d);
            push(s1, d->lChild);
            push(s1, d->rChild);
        }
    }

    push(s1, r2);
    while(isEmpty(s1) == 0){

        d = pop(s1);
        if(d != NULL){

            push(s2, d);
            push(s1, d->lChild);
            push(s1, d->rChild);

        }
    }

    struct Node *root;
    root = NULL;

    while(isEmpty(s2) == 0){

        d = pop(s2);
        root = insertBST(root, d->d);
    }

    printInReverseOrder(root);

    deleteTree(root);

    freeStack(s1);
    freeStack(s2);
}
