#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define ARRAYSIZE 100

float f(float x);
void simpsonsAdaptiveIntegration(float aOrig, float bOrig, float eps, float minIntSize);
float S(float a, float b);
int belowErrorBound(float a, float m, float b, float e);
int allIntervalsOkay(float arr[], float pHolder, float eps, float minIntSize);
int firstAvailable(float arr[], float pHolder);
