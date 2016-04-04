#include "assignment2.h"

double calcAverageWaitingTime(struct Simulation * S)
{

	double total = (S->eventQueue).currSize;

	double sum = 0;

	struct Data D; 

	while((S->eventQueue).currSize != 0){
	
	D = dequeue(&(S->eventQueue));
	
	sum += (D.departureTime - D.arrivalTime);
	//printf("%lf,%lf\n",D.departureTime, D.arrivalTime);

	}

	freeQueue(&(S->buffer));
	freeQueue(&(S->eventQueue));
	return sum / total;	

}

struct Simulation initSimulation(double arrivalRate, double serviceTime, double simTime)
{

	struct Simulation sim;
	sim.currTime = 0;
	sim.arrivalRate = arrivalRate;
	sim.serviceTime = serviceTime;
	sim.timeForNextArrival = getRandTime(arrivalRate);
	sim.timeForNextDeparture = sim.timeForNextArrival + serviceTime;
	sim.totalSimTime = simTime;
	sim.buffer = initQueue();
	sim.eventQueue = initQueue();

	return sim;
}

double runSimulation(double arrivalRate, double serviceTime, double simTime)
{


	struct Simulation sim = initSimulation(arrivalRate, serviceTime, simTime);


	while(sim.currTime < sim.totalSimTime){

	if((sim.timeForNextArrival < sim.timeForNextDeparture) || (sim.buffer.currSize == 0)){
	sim.e = ARRIVAL;
	}
	else{
	sim.e = DEPARTURE;
	}

	//printf("Curr: %lf\n",sim.currTime);
	
	if(sim.e == ARRIVAL){


		sim.currTime = sim.timeForNextArrival;
		
		struct Data d;
		d.arrivalTime = sim.currTime;

		enqueue(&(sim.buffer), d); 

		sim.timeForNextArrival = sim.currTime + getRandTime(sim.arrivalRate);

		if(sim.buffer.currSize == 1){

		sim.timeForNextDeparture = sim.currTime + serviceTime;
		//printf("ok");
		}

	}

	else if(sim.e == DEPARTURE){

		sim.currTime = sim.timeForNextDeparture;
		
		struct Data packet = dequeue(&(sim.buffer));

		//printf("Depart: %lf\n", packet.arrivalTime);
		
		packet.departureTime = sim.currTime;
		//printf("Arrival: %lf\n", packet.arrivalTime);
		//printf("Depart: %lf\n", packet.departureTime);

		sim.timeForNextDeparture = sim.currTime + serviceTime;

		enqueue(&(sim.eventQueue), packet);
	}


	}
	
	return calcAverageWaitingTime(&sim);


}
