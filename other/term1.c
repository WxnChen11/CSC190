#include <stdio.h>
#include <stdlib.h>

int main (void){

int i = 1;
int *p;
int **q;



*p = 1;

printf("%d\n",p);
printf("%d\n",*p);
printf("%d\n",&*p);
printf("%d\n", &i);
}
