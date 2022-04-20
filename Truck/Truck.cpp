#include"Truck.h"

Truck ::Truck (TYP Type , int TruckID ,double Speed, int maxJourneys , int TruckCapacity)
{
	switch (Type)
	{
		case(VIP):
			this->Type = Type;
			break;
		case(NORMAL):
			this->Type = Type;
			break;
		case(SPECIAL):
			this->Type = Type;
			break;
	}
	this->TruckID = TruckID ;
	this->Speed = Speed;
	this->maxJourneys = maxJourneys;
	this->TruckCapacity = TruckCapacity;
}

void Truck :: setDelivaryInterval(double DistanceFurthest, double sumUnloadTimes, double timeBack)
{
	DelivaryInterval = (DistanceFurthest / this->Speed ) + sumUnloadTimes + timeBack;
}

double Truck :: getDelivaryInterval()
{
	return this->DelivaryInterval;
}

TYP Truck::getTruckType()
{
	return this->Type;
}

int Truck::getTruckID()
{
	return TruckID;
}
int Truck::getmaxJourneys()
{
	return this->maxJourneys;
}
int Truck::getTruckCapacity()
{
	return this->TruckCapacity;
}

double Truck::getTruckSpeed()
{
	return this->Speed;
}

double Truck::getTruckPriority()
{
	double Priority = Speed+TruckCapacity+(Speed/TruckCapacity)+Order;
	return Priority;
}

int Truck :: getOrderNum()
{
	return Order;
}

int Truck::Order = 0;

Truck :: ~Truck()
{}