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
#include <sstream>
#include <iostream>
#include <vector>

//#include "stdio.h"    to convert string to char

using namespace std;

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



	// >> There is no need for all these paramters , already found in the class of Truck and Cargo

	int no_Normal, no_Special, no_VIP,												// Number of trucks of each type 
		Normal_speed, Special_speed, VIP_speed,										// Speed of all trucks of each type 
		Normal_capacity, Special_capacity, VIP_capacity,							// no. of cargos that truck can carry (Truck capacity)
		Normal_CheckUp_duration, Special_CheckUp_duration, VIP_CheckUp_duration,	// duration of the CheckUp of each truck after completing no. of journeys
		CheckUp_Journeys,															// no. of journeys the truck completes before performing checkUp  
		AutoPromotion,																// no. of hours after which a normal cargo is automatically prompoted to a VIP cargo 
		MaxW,																		// Maximum waiting hours for a cagro
		no_events;																	// no. of comming events (no. of comming lines)
		
	string EventType, CargoType, TruckType;			//TODO: covert string into char
	
	int EventTime[2] = { 0,0 },
		CargoID,
		TruckID,
		CargoLoadTime;
	
	float CargoDistance,
		  CargoCost,
		  CargoExtraMoney;

	int EventLineNum = 1;

		string* inputFileLines;
		string** events;
		int LineNum = 0;


public:
	// constructor and destructor

	MarsStation(string name);	// Takes name of the input file

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
	//int getCargo_ID();
	//int getTruck_ID();
	//int getCargo_Load_Time();
	
	//int* getEvent_Time();
	
	/*float getCargo_Distance();
	float getCargo_Cost();
	float getCargo_Extra_Money();
	string getCargo_Type();
	string getTruck_Type();
	string getEvent_Type();*/

	// input file handler	---------------------------
	bool openFileIn(ifstream& file, string name);	// Open input file and return True if succeeded
	bool check_file_is_empty(ifstream& file);

	// events handler	---------------------------
	//Select Event to be excuted
	void ExecuteEvent(char Event, Cargo* pCargo=nullptr);
	
	//Add Cargo
	void AddCargo(Cargo* pCargo, TYP type) ;
		
	void Start_Next_Event(string** DataFile,int EventLineNum);	// set event variables with the new data of the next line || NOTE: you have to call it after finishing each task
};
#endif
