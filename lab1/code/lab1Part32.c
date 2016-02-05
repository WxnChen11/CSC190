#include "lab1.h"

void simpsonsAdaptiveIntegration(float aOrig, float bOrig, float eps, float minIntSize)
{	
	float anew = aOrig;
	float ans = 0;
	float bnew = bOrig;
	while((anew < bOrig) && (bnew - anew > minIntSize))
	{
		float mid = (anew + bnew)/2;
		float error = (S(anew, mid)+ S(mid, bnew) - S(anew,bnew))/15;
		while((error > eps) && (bOrig - anew > minIntSize))
		{
			bnew = mid;
			mid = (anew+bnew)/2;
			error = (S(anew,mid)+S(mid,bnew)-S(anew,bnew))/15;
		}
		ans += S(anew,bnew);
		anew = bnew;
		bnew = bOrig;
	}
	printf("%f \n",ans);
}

