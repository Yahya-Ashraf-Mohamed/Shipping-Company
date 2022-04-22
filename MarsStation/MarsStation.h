#pragma once
#ifndef MARS_STATION_H
#define MARS_STATION_H

//#include"..\Defs.H"
#include "..\UI\UI.h"
#include "..\Cargo\Cargo.h"
#include "..\DataStructures\Queue.h"
#include "..\DataStructures\LinkedList.h"
#include "..\Event\Event.h"

#include "..\Truck\Truck.h"
#include  <fstream>
//#include  <string>  in UI
#include <sstream>
//#include <iostream>  in UI
#include <vector>

//#include "stdio.h"    to convert string to char

using namespace std;

//ApplicationManagar
class MarsStation
{
	UI* pUI; //pointer to the UI
	//ReadyEvent* pReadyEvent;
	//PromotionEvent* pPromotionEvent;
	//CancellationEvent* pCancellationEvent;
	


	//event queue need to be implemented
	//loaded cargo list need to be implemented (add member variable truck pointer in cargo)
	//delivered cargo list need to be implemented
	
	//Cargo listes
	Queue<Cargo*> VIP_Cargo;      //need to be a priority queue
	Queue<Cargo*> Special_Cargo;
	LinkedList Normal_Cargo;
	PriorityQueue<Cargo*> Delivered_Cargo;

	//Event Queue;
	Queue<Event*> EVENT;
	
	//Counts
	int VIP_Cargo_count=0;
	int Special_Cargo_count=0;
	int Normal_Cargo_count=0;

	int promoted_Cargo_count = 0;


	//Truck Queue
	Queue<Truck*> Waiting_VIP_Truck;
	Queue<Truck*> Waiting_SPECIAL_Truck;
	Queue<Truck*> Waiting_NORMAL_Truck;
	Queue<Truck*> MAINTANANCE_VIP_Truck;
	Queue<Truck*> MAINTANANCE_Normal_Truck;
	Queue<Truck*> MAINTANANCE_Special_Truck;
	Queue<Truck*> MOVING_Truck;


	int Clock[2] = { 1,5 };



	// >> There is no need for all these paramters , already found in the class of Truck and Cargo

	int no_Normal, no_Special, no_VIP,												// Number of trucks of each type 
		Normal_speed, Special_speed, VIP_speed,										// Speed of all trucks of each type 
		Normal_capacity, Special_capacity, VIP_capacity,							// no. of cargos that truck can carry (Truck capacity)
		Normal_CheckUp_duration, Special_CheckUp_duration, VIP_CheckUp_duration,	// duration of the CheckUp of each truck after completing no. of journeys
		CheckUp_Journeys,															// no. of journeys the truck completes before performing checkUp  
		AutoPromotion,																// no. of hours after which a normal cargo is automatically prompoted to a VIP cargo 
		MaxW,																		// Maximum waiting hours for a cagro
		no_events;																	// no. of comming events (no. of comming lines)
		
	char EventType, CargoType, TruckType;			//TODO: covert string into char
	
	int EventTime[2] = { 1,5 },
		CargoID,
		TruckID,
		CargoLoadTime;
	
	float CargoDistance,
		  CargoCost,
		  CargoExtraMoney;

	ifstream dataFile;	// File stream object
	ofstream OutPutFile;

public:

//================================= CONSTRUCTOR / DESTRUCTOR / UI POINTER =================================
	
	// constructor and destructor

	MarsStation();	// Takes name of the input file

	~MarsStation();

	//Gets a pointer to UI Object
	UI* GetUI();


	// setters Functions		---------------------------
	void setClock_Hours(int Hours);				//set the clock hours
	void setClock_Days(int Days);			//set the clock minutes
	void setClock(int Hours, int Days);		//set the clock hours and minutes
	void setInt_Variables(ifstream& DataFile);	//set the values of the integar variables
	void setEvent_Time(string EventTime);

	// getters Functions		---------------------------
	int getClock_Hours();						//get clock hour
	int getClock_Days();						//get clock days
	int getCargo_ID();
	int getTruck_ID();
	int getCargo_Load_Time();
	
	int* getEvent_Time();
	
	float getCargo_Distance();
	float getCargo_Cost();
	float getCargo_Extra_Money();

	/*string getCargo_Type();
	string getTruck_Type();
	string getEvent_Type();*/

	char getCargo_Type();
	char getTruck_Type();
	char getEvent_Type();

	// input file handler	---------------------------
	bool openFileIn(ifstream& file, string name);	// Open input file and return True if succeeded
	bool check_file_is_empty(ifstream& file);
	void ReadFile(string Filename);
	bool Create_Output_File();
	void Excute_Output_File(Cargo*);
	//void Enqueue_Events(char EventType, int EventDay, int EventHour);		deleted struct

	// events handler	---------------------------
	//Select Event to be excuted
	//void ExecuteEvent(char Event, Cargo* pCargo=nullptr);  deleted
	
	//=================================================== EVENTS =================================================//

	//Add Cargo to Cargo Queue depending on it's type
	void AddCargo(Cargo* pCargo, TYP type) ;
	
	//Promote normal cargo to VIP cargoes 
	Cargo* PromoteCargo(int cargo_id);

	//Cancel Cargo
	void CancelCargo(int cargo_id);

	void addReadyEvent(int Eventtime_day, int Eventtime_hour, TYP type, double distance, int LoadTime, int id, float Cost);

	void addPromotionEvent(int Eventtime_day, int Eventtime_hour, int id, float Extra_Money);

	void addCancellationEvent(int Eventtime_day, int Eventtime_hour, int id);

//=============================================================================================================
	
	// Input Functions		--------------------------- (uncomment later)
	//void setClock_Hours(int Hours);				//set the clock hours
	//void setClock_Days(int Days);			//set the clock minutes
	//void setClock(int Hours, int Days);		//set the clock hours and minutes
	//void setInt_Variables(fstream DataFile);	//set the values of the integar variables

	// Output Functions		---------------------------(uncomment later)
	//int getClock_Hours();						//get clock hour
	//int getClock_Days();						//get clock days

	// file handler	--------------------------- (uncomment later)
	//bool openFileIn(fstream& file, string name);	//
	//-----------------------------------------------------------

	// Run the program
	void Run();
	
	Queue<Cargo*> getVIP_Cargo();
	Queue<Cargo*> getSpecial_Cargo();
	LinkedList getNormal_Cargo();
	PriorityQueue<Cargo*> getDelivered_Cargo();

};
#endif
