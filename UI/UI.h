#pragma once
#include <iostream>
#include "..//Defs.H"
#include <string>
#include "..//MarsStation/MarsStation.h"
using namespace std;

class UI
{
private:

	MarsStation* pStation;
	MODE AppMode;	// Application Mode interactive or step_by_step or silent
	string inputFileName;

public:

	// Constructors
	UI();			// No Argument constructor

	// Getters Functions  ---------------------------
	MODE GetAppMode()const;     //returns App Mode state
	string getInput_File_Name();

	// Run UI Functions	--------------------------------------
	void Start_silent_Mode();
	
	void Start_interactive_Mode(int day, int hour);//to be continued
	
	void Start_step_by_step_Mode(int day, int hour);//to be continued

	void Show_State();
	void Show_Waiting_Cargos();
	void Show_Loading_Trucks();
	void Show_Empty_Trucks();
	void Show_Moving_Cargos();
	void Show_In_CheckUp_Trucks();
	void Show_Delivered_Cargos();

	void End_Simulation();

	void startAPP();

	void Show_Error(Error errorType);
	~UI();		//Destructor

};


