#include"Truck.h"

Truck ::Truck (TYP Type , double Speed, int maxJourneys , int TruckCapacity)
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
		case(NONAVAILABLE):
			this->Type = Type;
			break;
		case(MAINTANANCE):
			this->Type = Type;
			break;
	}
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

TYP Truck::getType()
{
	return this->Type;
}

int Truck::getmaxJourneys()
{
	return this->maxJourneys;
}
int Truck::getTruckCapacity()
{
	return this->TruckCapacity;
}


Truck :: ~Truck()
{}