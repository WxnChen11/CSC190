#include "lab1.h"

void simpsonsAdaptiveIntegration(float aOrig, float bOrig, float eps, float minIntSize)
{	
	
	float a = aOrig;
	float b = bOrig;
	float placeHolder;
	if (a < b)
	{
		 placeHolder = a - 1;
	}	
	else
	{	
		 placeHolder = b - 1;
	}

	float intPairs[ARRAYSIZE];
	int z;
	for(z = 0; z<ARRAYSIZE; z++)
	{
		intPairs[z] = placeHolder;
	}

	intPairs[0] = a;
	intPairs[1] = b;
	
	int cont = 1;

	while (cont == 1)
	{
		int x;
		for(x = 0; x<ARRAYSIZE; x+=2)
		{
			if(allIntervalsOkay(intPairs, placeHolder, eps, minIntSize) == 1)
			{
				float res;
				int i;
				for(i = 0; i<ARRAYSIZE; i+=2)
				{
					if(intPairs[i] == placeHolder)
					{
						continue;
					}	

					res += S(intPairs[i], intPairs[i+1]);
				}

				printf("Result is: %9.6f\n", res);
				//printf("%9.6f",intPairs[20]);
				cont = 0;
				break;
				
			}

			if (belowErrorBound(intPairs[x], (intPairs[x] + intPairs[x+1])/2, intPairs[x+1], eps)== 0)

			{
				float first, mid, last;
				first = intPairs[x];
				mid = (intPairs[x] + intPairs[x+1])/2;
				last = intPairs[x+1];

				int i = firstAvailable(intPairs, placeHolder);
				
				intPairs[i] = mid;
				intPairs[i+1] = last;
				
				intPairs[x+1] = mid;
			}
			 	
		}  				
	}
		
	}

int belowErrorBound(float a, float m, float b, float e)
{
	if ((float)fabs((S(a,m) + S(m,b) - S(a,b)))/15 < e)
	{	
		return 1;
	}

	else
	{
		return 0;
	}
}

int allIntervalsOkay(float arr[], float pHolder, float eps, float minIntSize)
{

	int full = 1;
	
	int i;
	for (i = 0; i < ARRAYSIZE; i+=2)
	{
		if (arr[i] == pHolder)
		{
			full = 0;
		}
	}

	if(full == 1)
	{
		return 1;
	}

	int a;
	for (a = 0; a < ARRAYSIZE; a += 2)
	{
		if (arr[a] == pHolder)
		{
			continue;
		}

		if(( belowErrorBound(arr[a], (arr[a] + arr[a+1])/2, arr[a+1], eps) == 0) && (arr[a+1] - arr[a]) > minIntSize)
		{
			return 0;	
		} 
		
	
	}

	return 1;
}

int firstAvailable(float arr[], float pHolder){

	int a;	

	for (a = 0; a < ARRAYSIZE; a+=2)
	{
		if(arr[a] == pHolder)
		{
			return a;
		}
	}

	return -1;
	
}
