#include "lab4.h"

int setSpeed(int speed)
{

if(speed<=260){

	return speed;

}

return -1;

}

int setGear(int gear)
{

if(gear<=5){

	return gear;

}

return -1;

}

int setPassengers(int passengers)
{

if(passengers<=5){

	return passengers;

}

return -1;

}

void setCarState(struct Car * c, int speed, int gear, int passengers, int nav){

c->veh->currSpeed = (c->veh->vehInt.setSpeed)(speed);
c->veh->gear = (c->veh->vehInt.setGear)(gear);
c->veh->numPassengers = (c->veh->vehInt.setPassengers)(passengers);
c->hasNav = nav;

}

void printCarState(struct Car * c){

printf("Speed of the Car is: %d",c->veh->currSpeed);
printf("Gear of the Car is set at: %d",c->veh->gear);
printf("Passengers in the Car are: %d",c->veh->numPassengers);
printf("Navigator in the Car: %d",c->hasNav);

}

struct Car * initCar(int nav, char * model)
{

Car *car1 = (Car *)malloc(sizeof(Car));
vInterface vInt = initVInterface(setSpeed, setGear, setPassengers); 
car1->veh = initVehicle(4, model, vInt);
car1->hasNav = nav;
car1->setCarState = setCarState;


}
                       
void cleanUpCar(struct Car * c)
{
	free(c);
}
                       



