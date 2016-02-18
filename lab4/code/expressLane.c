#include "lab4.h"

struct ExpressLaneRec * initExpressLane(float enterTime, float exitTime)
{

struct ExpressLaneRec *lane = (struct ExpressLaneRec *)malloc(sizeof(struct ExpressLaneRec));

lane->enterTime = enterTime;
lane->exitTime = exitTime;
lane->car=NULL;
lane->nextRec=NULL;

return lane;

}

struct ExpressLaneRec * addCarRec(struct Car * c, float enterTime, float exitTime, struct ExpressLaneRec * eL)
{

struct ExpressLaneRec *lane = initExpressLane(enterTime, exitTime);

lane->car = c;

if(eL!=NULL){
eL->nextRec = lane;
}

return lane;


}

void printRecords(struct ExpressLaneRec * eLCurr)
{

while(eLCurr != NULL){

printf("Car enter time is %f\n",eLCurr->enterTime);
printf("Car exit time is %f\n",eLCurr->exitTime);

printCarState(eLCurr->car);

printf("\n");

eLCurr = eLCurr->nextRec;

}


}

void cleanUpRec(struct ExpressLaneRec * eL)
{

while(eL != NULL){

cleanUpCar(eL->car);

struct ExpressLaneRec *temp = eL->nextRec;

free(eL);

eL = temp;

};

}

