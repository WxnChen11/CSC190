#include "lab4.h"

struct vInterface initVInterface(int (*sS)(int), int (*sG)(int), int (*sP)(int))
{

struct vInterface interface;
interface.setSpeed = sS;
interface.setGear = sG;
interface.setPassengers = sP;

return interface;


}
