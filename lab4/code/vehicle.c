#include "lab4.h"

struct Vehicle * initVehicle(int wheels, char * model, struct vInterface vInt)
{

Vehicle *vehic = (Vehicle *)malloc(sizeof(Vehicle));

vehic->numwheels = wheels;
strcpy(vehic->model, model);
vehic->vehInt = vInt;
vehic->numPassengers=0;
vehic->currSpeed=0;
vehic->gear=0;

return vehic;

}

void cleanUpVehicle(struct Vehicle * v)
{
	free(v);
}
