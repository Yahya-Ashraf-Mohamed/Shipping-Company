#pragma once
#ifndef MARS_STATION_H
#define MARS_STATION_H

#include"..\Defs.H"
#include "..\UI\UI.h"
#include "..\Cargo\Cargo.h"
#include "..\DataStructures\Queue.h"

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
	
	//Cargo Queue
	Queue<Cargo*> VIP_Cargo;      //need to be a priority queue
	Queue<Cargo*> Special_Cargo;
	Queue<Cargo*> Normal_Cargo;  //loop deque and enque
	
	//Truck Queue
	//Queue<Truck*> VIP_Truck;
	Queue<Truck*> SPECIAL_Truck;
	Queue<Truck*> NORMAL_Truck;
	Queue<Truck*> MAINTANANCE_Truck;
	Queue<Truck*> NONAVAILABLE_Truck;


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
	// constructor and destructor
	MarsStation();
	~MarsStation();

	//Gets a pointer to UI Object
	UI* GetUI();

	//Select Event to be excuted
	void ExecuteEvent(char Event, Cargo* pCargo=nullptr);
	
	//Add Cargo
	void AddCargo(Cargo* pCargo, TYP type) ;
	
	
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
