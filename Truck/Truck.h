#pragma once
#include"../DataStructures/Queue.h"
#include"../Defs.H"

class Truck
{
private:
	TYP Type;   // Decides the type of the truck used in making list
	Status Truck_Status= WAITING;
	double Speed;       // will be read form the input file
	double DelivaryInterval;        // will be calculated depending on cargos input
	double MaintenanceCheckupTime;   // will be read form the input file after maxNumber of Journeys
	int maxJourneys;              // will be read form the input file
	int TruckCapacity;            // will be read form the input file
public:
	Truck(TYP Type ,double Speed, int maxJourneys , int TruckCapacity );
	void setDelivaryInterval(double DistanceFurthest, double sumUnloadTimes, double timeBack);
	double getDelivaryInterval();
	int getmaxJourneys();
	int getTruckCapacity();
	TYP getType();
	~Truck();
};
