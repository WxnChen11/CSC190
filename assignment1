#include "assignment1.h"

double ** choleskyDecomp(double ** A, int n, int i)
{

//printf("%d\n",i);

if
(i==1){

//return A;

}

if(identity(A,n) == 1){

//printf("holy");
return A;

}

if(i==n-1){

//return A;

}


int x, y;
double a;

a = A[i][i];

double **V;

initMatrix(&V, n);

double **L;

initMatrix(&L,n);

for(x=0; x<i; x++){

L[x][x] = 1;

}

L[i][i] = sqrt(a);
//printf("%d %lf\n",i,a);

for(x=i+1;x<n; x++){

L[x][i] = (A[x][i]/sqrt(a));

}

for(x=i+1; x<n; x++){

L[x][x] = 1; 

}

//printMatrix(A,n);
//printMatrix(L,n);

for(x=i+1; x<n; x++){

for(y=i+1; y<n; y++){

V[x][y] = A[x][i] * A[i][y];

}



}


//printMatrix(V,n);


for(x=i+1; x<n; x++){

	A[x][i] = 0;
	A[i][x] = 0;
	for(y=i+1; y<n; y++){

	A[x][y] = A[x][y] - (V[x][y])/a;
	

	}

}

A[i][i] = 1;

if(i==1){

//return L;

}

//return A;
return mult(L, choleskyDecomp(A,n,i+1), n);
//return L;

}
double ** mult(double ** L1,double ** L2, int n)
{



int x, y, z;
double sum = 0;
double **A;


initMatrix(&A,n);


for(x=0; x<n; x++){


	for(z=0; z<n; z++){


		for(y=0; y<n; y++){

		sum += L1[x][y] * L2 [y][z];

		}

	A[x][z] = sum;
	sum = 0;

	}
}

freeMatrix(L1,n); //same matrix?????
//freeMatrix(L2,n);

return A;


}

int identity(double ** A, int n)
{

int x;

for(x=0; x<n; x++){

if(A[x][x] != 1){

return 0;

}



}



return 1;


}


void initMatrix(double ***mat,int n)
{

double **matrix = (double **)calloc(n,sizeof(double*));

int x;

double **count = matrix;

for(x=0; x<n; x++){

	*count = (double *)calloc(n,sizeof(double));
	//**count = 3;
	//(*count)[2] = 5;
	count++;

}

*mat = matrix;
//printf("%p\n",*matrix);

}

double **readMatrix(char * filename)
{

    FILE *fp=fopen(filename, "r");
    double **mat = (double **)calloc(MATSIZE, sizeof(double *));
    double **res = mat;
    double *count;
    int x,y;
    for(x=0; x<MATSIZE; x++){
	
    *res = (double *)calloc(MATSIZE, sizeof(double));
	count = *res;
	for(y=0; y<MATSIZE; y++){
		
		fscanf(fp, "%lf", count);
		//printf("%lf\n",*count);
		count++;
		//printf("%p\n",count);
	
	}

	//printf("%d\n",x);
	//printf("%lf\n", *(count-1));
    res++;
    //printf("%p\n",mat);
    }    
	
	
    fclose(fp);
	//printf("%p\n",res);
	//printf("%p\n",*res);
    return mat;
	
}

void freeMatrix(double ** matrix, int n)
{

double **count = matrix;
int x;

for(x=0; x<n; x++){

//free(*count);
free((matrix)[x]);
//count++;

}

free(matrix);

}

void printMatrix(double ** A, int n)
{

int x,y;

//printf("arg %p\n",A);

double **count = A;
double *elem = *count;

//printf("arg %p\n",*A);

for(x=0; x<n; x++){

elem = *count;

for(y=0; y<n; y++){

printf("%lf ",*elem);
elem++;

}

printf("\n");

count++;

}
}

