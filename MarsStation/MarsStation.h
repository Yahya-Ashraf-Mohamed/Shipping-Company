#pragma once
#ifndef MARS_STATION_H
#define MARS_STATION_H

#include"..\Defs.H"
#include "..\UI\UI.h"
#include "..\Cargo\Cargo.h"
#include "..\DataStructures\Queue.h"
#include "..\DataStructures\LinkedList.h"
#include "..\Event\Event.h"
#include "..\Event\PromotionEvent.h"

#include "..\Truck\Truck.h"
#include  <fstream>
#include  <string>


//ApplicationManagar
class MarsStation
{
	UI* pUI; //pointer to the UI
	
	//event queue need to be implemented
	//loaded cargo list need to be implemented (add member variable truck pointer in cargo)
	//delivered cargo list need to be implemented
	
	//Cargo listes
	Queue<Cargo*> VIP_Cargo;      //need to be a priority queue
	Queue<Cargo*> Special_Cargo;
	LinkedList Normal_Cargo;
	
	//Event Queue;
	Queue<Event*> EVENT;
	
	//Counts
	int VIP_Cargo_count=0;
	int Special_Cargo_count=0;
	int Normal_Cargo_count=0;

	int AutoP_Count = 0;


	//Truck Queue
	Queue<Truck*> VIP_Truck;
	Queue<Truck*> SPECIAL_Truck;
	Queue<Truck*> NORMAL_Truck;
	Queue<Truck*> MAINTANANCE_Truck;
	Queue<Truck*> MOVING_Truck;


	int Clock[2] = { 0,0 };
//----------------------------- file uncomment later
	//string input;// To hold file input
	//fstream dataFile;// File stream object

	//int no_Normal, no_Special, no_VIP,												// Number of trucks of each type 
	//	Normal_speed, Special_speed, VIP_speed,										// Speed of all trucks of each type 
	//	Normal_capacity, Special_capacity, VIP_capacity,							// no. of cargos that truck can carry (Truck capacity)
	//	Normal_CheckUp_duration, Special_CheckUp_duration, VIP_CheckUp_duration,	// duration of the CheckUp of each truck after completing no. of journeys
	//	CheckUp_Journeys,															// no. of journeys the truck completes before performing checkUp  
	//	AutoPromotion,																// no. of hours after which a normal cargo is automatically prompoted to a VIP cargo 
	//	MaxW,																		// Maximum waiting hours for a cagro
	//	no_events;																	// no. of comming events (no. of comming lines)
//--------------------------------------------------------------------------

public:


//================================= CONSTRUCTOR / DESTRUCTOR / UI POINTER =================================
	
	// constructor and destructor
	MarsStation();
	~MarsStation();

	//Gets a pointer to UI Object
	UI* GetUI();

//=================================================== EVENTS =================================================
	
	//Add Cargo to Cargo Queue depending on it's type
	void AddCargo(Cargo* pCargo, TYP type) ;
	
	//Promote normal cargo to VIP cargoes 
	Cargo* PromoteCargo(int cargo_id);

	//Cancel Cargo
	void CancelCargo(int cargo_id);

	void addReadyEvent(int Eventtime_day, int Eventtime_hour, char type, double distance, int LoadTime, int id, int Cost);

	PromotionEvent* addPromotionEvent(int Eventtime_day, int Eventtime_hour, int id, int Extra_Money = 0);

	void Autop_Count_increment();

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
};
#endif
