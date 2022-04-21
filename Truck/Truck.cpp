#include"Truck.h"

Truck::Truck(TYP TypeTruck, int TruckID, double Speed, int maxJourneys, int TruckCapacity)
{
	switch (TypeTruck)
	{
	case(VIP):
		this->TypeTruck = TypeTruck;
		break;
	case(NORMAL):
		this->TypeTruck = TypeTruck;
		break;
	case(SPECIAL):
		this->TypeTruck = TypeTruck;
		break;
	}
	this->TruckID = TruckID;
	this->Speed = Speed;
	this->maxJourneys = maxJourneys;
	this->TruckCapacity = TruckCapacity;
	this->Priority = Speed + TruckCapacity + (Speed / TruckCapacity) + Order;
}

void Truck::setDelivaryInterval(double DistanceFurthest, double sumUnloadTimes, double timeBack)
{
	DelivaryInterval = (DistanceFurthest / this->Speed) + sumUnloadTimes + timeBack;
}

double Truck::getDelivaryInterval()
{
	return this->DelivaryInterval;
}

TYP Truck::getTruckType()
{
	return this->TypeTruck;
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

double Truck::getPriority()
{
	return Priority;
}

int Truck::getOrderNum()
{
	return Order;
}

int Truck::Order = 0;

// >> How to pass a Priority Queue to the function

//Cargo* Truck::LoadCargo( PriorityQueue<Cargo*> PriorityQueueCargos , TYP TypeCargo)
//{
//
//	if (TypeCargo == TypeTruck)
//	{
//		for (int i = 0 ; i < PriorityQueueCargos.getSize(); i++)
//		{
//			CargoStack.push(PriorityQueueCargos.dequeue());
//		}
//	}
//	else if (TypeCargo == VIP)
//	{
//		for (int i = 0; i < PriorityQueueCargos.getSize(); i++)
//		{
//			CargoStack.push(PriorityQueueCargos.dequeue());
//			TotalCargosDelivered++;
//		}
//	}
//	else if (TypeCargo == NORMAL)
//	{
//		for (int i = 0; i < PriorityQueueCargos.getSize(); i++)
//		{
//			CargoStack.push(PriorityQueueCargos.dequeue());
//			TotalCargosDelivered++;
//		}
//	}
//}

int Truck::getCountTotalCargosDelivered()
{
	return TotalCargosDelivered;
}

void Truck::setTruckActiveTime(int time[2])
{
	TotalTruckActiveTime[0] = time[0];
	TotalTruckActiveTime[1] = time[1];
}

int* Truck::getTruckActiveTime()
{
	return TotalTruckActiveTime;
}

void Truck::setMaintananceTime(int time[2])
{
	StartMaintananceTime[0] = time[0];
	StartMaintananceTime[1] = time[1];
}

int* Truck::getMaintananceTime()
{
	return StartMaintananceTime;
}

void Truck::setTruckUtilization(int TotalSimulationTime[2])  // Time in min will be converted to hours to be able to do the operation
{
	TruckUtilization = TotalCargosDelivered / (TruckCapacity * TotalDeliveryJourneys) * (TotalTruckActiveTime[0] + TotalTruckActiveTime[1] * (1 / 60)) / (TotalSimulationTime[0] + TotalSimulationTime[1] * (1 / 60));
}

double Truck::getTruckUtilization()
{
	return TruckUtilization;
}

void Truck::setMovingTime(int time[2])
{
	TruckMovingTime[0] = time[0];
	TruckMovingTime[1] = time[1];
}
int* Truck::getMovingTime()
{
	return TruckMovingTime;
}

Truck :: ~Truck()
{}