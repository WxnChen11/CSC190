#include "lab3.h"

int testBits(int * a, int n, unsigned int regVar)
{

int x;
unsigned int g=0;

for(x=0; x<n; x++){

g = g | (1 << a[x]);
printf("%d\n",g);

}

if ((regVar & g) == g){
	return 1;
}

printf("%d\n",regVar);

return 0;


}

void setBits(int * a, int n, unsigned int * regVar)
{

unsigned int g = 0;

int x;

for(x=0; x<n; x++){

g = g | (1 << a[x]);

}

*regVar = (*regVar | g);

}

void clearBits(int * a, int n, unsigned int * regVar)
{

unsigned int g = 0, p = 0;

int x;

for(x=0; x<n; x++){

g = g | (1 << a[x]);

}

*regVar = ~(~(*regVar) | g); 
}
