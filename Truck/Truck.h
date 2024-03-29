#pragma once
#include"../DataStructures/Stack.h"
#include"../Defs.H"
#include"../Cargo/Cargo.h"
#include"../DataStructures/PriorityQueue.h"
#include "..//DataStructures/Queue.h"

class Truck
{
private:
	TYP TypeTruck;   // Decides the type of the truck used in making list
	Status Truck_Status = WAITING;
	int Speed;				    // will be read form the input file
	double DelivaryInterval;        // will be calculated depending on cargos input
	int MaintenanceCheckupDuration;   // will be read form the input file after maxNumber of Journeys
	int maxJourneys;              // will be read form the input file
	int TruckCapacity = 1;            // will be read form the input file
	int TruckID;                   // will be read form the input file
	static int Order;
	double Priority;
	//Stack <Cargo*>* CargoStack = new Stack <Cargo*>;   // Name of the stack that include the cargos
	int* TotalTruckActiveTime = new int[2];
	int TotalCargosDelivered = 0;
	double TruckUtilization;
	int* TruckMovingTime = new int[2];


	//========================================================
	//Added by Yahya new
	int NumberOFJourneys = 0;
	int* Truck_ActiveTime = new int[2] { 0, 0 };

	int* End_Maintanance_Time = new int[2];

	Stack <Cargo*> Carried_Cargoes;   // stack to carry the cargos carried on the truck

	int Total_Delivery_Journeys = 0;

	int* Return_back_time = new int[2];
	//========================================================

public:
	Truck(TYP TypeTruck, int TruckID, double Speed, int maxJourneys, int TruckCapacity, int MaintenanceCheckupDuration);
	void setDelivaryInterval(double DistanceFurthest, double sumUnloadTimes, double timeBack);
	double getDelivaryInterval();
	int getmaxJourneys();
	int getTruckCapacity();
	int getTruckID();
	TYP getTruckType();
	int getTruckSpeed();
	double getPriority();
	static int getOrderNum();

	int getCountTotalCargosDelivered();
	int get_Truck_Utilization();
	void set_Truck_Utilization(int* TotalSimulationTime);

	void setMovingTime(int* Curranttime);
	int* getMovingTime();


	//Added by Yahya new
	//========================================================
	int get_Num_Of_Journeys();
	void set_Num_Of_Journeys(int NJ);

	void set_Truck_Total_Active_Time(int* currentTime);
	int* get_Truck_Total_Active_Time();

	void set_Truck_ActiveTime(int* currentTime);
	int* get_Truck_ActiveTime();


	void set_End_Maintanance_Time(int* currentTime);
	int* get_End_Maintanance_Time();

	void set_Waiting_Time_For_Cargoes(int* currentTime);

	int get_Total_Num_Of_Journeys();
	void Add_Total_Num_Of_Journeys();

	void set_Return_back_time(int* curant_time);
	int* get_Return_back_time();

	void LoadCargo(PriorityQueue<Cargo*> PriorityQueueCargos, int* currantTime);
	
	Queue<Cargo*> Deliver_Cargo(int* currantTime);
	
	Stack <Cargo*> get_Carried_Cargoes();

	void Add_To_total_Cargos_Delivered(int size);
	//========================================================

	~Truck();
};