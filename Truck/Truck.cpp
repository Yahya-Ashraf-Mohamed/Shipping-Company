#include"Truck.h"

Truck::Truck(TYP TypeTruck, int TruckID, double Speed, int maxJourneys, int TruckCapacity, int MaintenanceCheckupDuration)
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

int Truck::getTruckSpeed()
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

//Stack<Cargo*>* Truck::LoadCargo(PriorityQueue<Cargo*> PriorityQueueCargos)
//{
//	while (!PriorityQueueCargos.isEmpty())
//	{
//		Cargo* pCargo = nullptr;
//		PriorityQueueCargos.peek(pCargo);
//		TYP CargoType = pCargo->getCargo_Type();
//		if (CargoType == TypeTruck)
//		{
//
//			PriorityQueueCargos.dequeue(pCargo);
//			CargoStack->push(pCargo);
//		}
//		else if (CargoType == TypeTruck)
//		{
//			PriorityQueueCargos.dequeue(pCargo);
//			CargoStack->push(pCargo);
//			TotalCargosDelivered++;
//		}
//		else if (CargoType == TypeTruck)
//		{
//			PriorityQueueCargos.dequeue(pCargo);
//			CargoStack->push(pCargo);
//			TotalCargosDelivered++;
//		}
//	}
//	return CargoStack;
//}

int Truck::getCountTotalCargosDelivered()
{
	return TotalCargosDelivered;
}

void Truck::set_Truck_Total_Active_Time(int* currentTime)
{
	TotalTruckActiveTime[0] = TotalTruckActiveTime[0] + currentTime[0];
	TotalTruckActiveTime[1] = TotalTruckActiveTime[1] + currentTime[1];

	if (TotalTruckActiveTime[1] > 24)
	{
		TotalTruckActiveTime[0] = TotalTruckActiveTime[0] + 1;
		TotalTruckActiveTime[1] = TotalTruckActiveTime[1] - 24;
	}
}

int* Truck::get_Truck_Total_Active_Time()
{
	return TotalTruckActiveTime;
}


void Truck::set_End_Maintanance_Time(int* currentTime)
{
	End_Maintanance_Time[0] = currentTime[0];
	End_Maintanance_Time[1] = currentTime[1] + MaintenanceCheckupDuration;
}

int* Truck::get_End_Maintanance_Time()
{
	return End_Maintanance_Time;
}

void Truck::set_Truck_Utilization(int* TotalSimulationTime)  // Time in days will be converted to hours to be able to do the operation
{
	if (Total_Delivery_Journeys == 0)
		TruckUtilization = 0;
	else
		TruckUtilization = TotalCargosDelivered / (TruckCapacity * Total_Delivery_Journeys) * (TotalTruckActiveTime[0] * 24 + TotalTruckActiveTime[1]) / (TotalSimulationTime[0] * 24 + TotalSimulationTime[1]);
}

int Truck::get_Truck_Utilization()
{
	return TruckUtilization;
}

void Truck::setMovingTime(int* Curranttime)
{
	TruckMovingTime[0] = Curranttime[0];
	TruckMovingTime[1] = Curranttime[1];
}
int* Truck::getMovingTime()
{
	return TruckMovingTime;
}

Truck :: ~Truck()
{}



//Added by Yahya new
//========================================================
int Truck::get_Num_Of_Journeys()
{
	return NumberOFJourneys;
}

void Truck::set_Num_Of_Journeys(int NJ)
{
	NumberOFJourneys = NumberOFJourneys + NJ;
}

void Truck::set_Truck_ActiveTime(int* currentTime)
{
	Truck_ActiveTime[0] = currentTime[0];
	Truck_ActiveTime[1] = currentTime[1];
}

int* Truck::get_Truck_ActiveTime()
{
	return Truck_ActiveTime;
}

void Truck::set_Waiting_Time_For_Cargoes(int* currentTime)
{
	Cargo* pCargo = nullptr;

	Stack <Cargo*> Temp; /////////////////////(TruckCapacity)

	while (Carried_Cargoes.isEmpty() == false)
	{
		Carried_Cargoes.pop(pCargo);
		Temp.push(pCargo);
	}

	while (Temp.isEmpty() == false)
	{
		Temp.pop(pCargo);

		pCargo->set_Waiting_Time(currentTime);

		Carried_Cargoes.push(pCargo);
	}
}



void Truck::LoadCargo(PriorityQueue<Cargo*> PriorityQueueCargos, int* currantTime)
{
	Cargo* pCargo = nullptr;

	while (PriorityQueueCargos.isEmpty() == false)
	{
		PriorityQueueCargos.dequeue(pCargo);

		pCargo->set_Delivery_time(currantTime, Speed);
		pCargo->set_Delivary_Truck_ID(TruckID);

		Carried_Cargoes.push(pCargo);
	}
		
}


int Truck::get_Total_Num_Of_Journeys()
{
	return Total_Delivery_Journeys;
}

void Truck::Add_Total_Num_Of_Journeys()
{
	Total_Delivery_Journeys = Total_Delivery_Journeys + 1;
}

int* Truck::get_Return_back_time()
{
	return Return_back_time;
}

void Truck::set_Return_back_time(int* curant_time)
{
	Cargo* Farthest_Cargo;
	Carried_Cargoes.pop(Farthest_Cargo);
	int CargoDistance = Farthest_Cargo->getCargoDistance();
	int CargoUnloadTime = Farthest_Cargo->getCargo_Load_Time();

	Return_back_time[1] = curant_time[1] + (CargoDistance / Speed)*2 + CargoUnloadTime;

	while (Return_back_time[1] > 24)
	{
		Return_back_time[0] = Return_back_time[0] + 1;
		Return_back_time[1] = Return_back_time[1] - 24;
	}

	Carried_Cargoes.push(Farthest_Cargo);

}


Queue <Cargo*> Truck::Deliver_Cargo(int* currantTime)
{
	Queue <Cargo*> Truck_Delivered_Cargo;
	Cargo* cargo;
	Stack <Cargo*> Temp;

	while (Carried_Cargoes.isEmpty() == false)
	{
		Carried_Cargoes.pop(cargo);

		if (cargo->get_Delivery_time() < currantTime)
		{
			Temp.push(cargo);
		}
		else
		{
			Truck_Delivered_Cargo.enqueue(cargo);
		}
	}

	while (Temp.isEmpty() == false)
	{
		Temp.pop(cargo);
		Carried_Cargoes.push(cargo);
	}

	return Truck_Delivered_Cargo;
}

Stack <Cargo*> Truck::get_Carried_Cargoes()
{
	return Carried_Cargoes;
}

void Truck::Add_To_total_Cargos_Delivered(int size)
{
	TotalCargosDelivered = TotalCargosDelivered + size;
}
//========================================================
