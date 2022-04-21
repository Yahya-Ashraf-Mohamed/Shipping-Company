#pragma once
#include <iostream>
#include "..//Defs.H"
#include <string>
using namespace std;

class UI
{
private:

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
	void End_silent_Mode();

	void Start_interactive_Mode(int day, int hour);//to be continued
	
	void Start_step_by_step_Mode(int day, int hour);//to be continued

	void startAPP();

	void Show_Error(Error errorType);
	~UI();		//Destructor

};


