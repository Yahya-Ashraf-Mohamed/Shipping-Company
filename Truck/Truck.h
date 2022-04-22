#pragma once
#include"../DataStructures/Stack.h"
#include"../Defs.H"
#include"../Cargo/Cargo.h"
#include"../DataStructures/PriorityQueue.h"

class Truck
{
private:
	TYP TypeTruck;   // Decides the type of the truck used in making list
	Status Truck_Status = WAITING;
	double Speed;				    // will be read form the input file
	double DelivaryInterval;        // will be calculated depending on cargos input
	double MaintenanceCheckupTime;   // will be read form the input file after maxNumber of Journeys
	int maxJourneys;              // will be read form the input file
	int TruckCapacity;            // will be read form the input file
	int TruckID;                   // will be read form the input file
	int* StartMaintananceTime = new int[2];
	static int Order;
	double Priority;
	//Stack <Cargo*> *CargoStack ();   // Name of the stack that include the cargos
	int* TotalTruckActiveTime = new int[2];
	int TotalCargosDelivered = 0;
	int TotalDeliveryJourneys;
	double TruckUtilization;
	int* TruckMovingTime = new int[2];

public:
	Truck(TYP TypeTruck, int TruckID, double Speed, int maxJourneys, int TruckCapacity);
	void setDelivaryInterval(double DistanceFurthest, double sumUnloadTimes, double timeBack);
	double getDelivaryInterval();
	int getmaxJourneys();
	int getTruckCapacity();
	int getTruckID();
	TYP getTruckType();
	double getTruckSpeed();
	double getPriority();
	static int getOrderNum();
	void setMaintananceTime(int time[2]);
	int* getMaintananceTime();
	void setTruckActiveTime(int time[2]);
	int* getTruckActiveTime();
	int getCountTotalCargosDelivered();
	double getTruckUtilization();
	void setTruckUtilization(int TotalSimulationTime[2]);

	void setMovingTime(int time[2]);
	int* getMovingTime();

	//Cargo* LoadCargo (PriorityQueue<Cargo*> PriorityQueueCargos , TYP TypeCargo);

	~Truck();
};