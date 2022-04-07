#pragma once
#include "..//Defs.H"
#include <string>
using namespace std;

class UI
{
private:

	MODE AppMode;	// Application Mode interactive or step_by_step or silent


public:

	// Constructors
	UI();			// No Argument constructor



	// Input Functions  ---------------------------
	void SetAppMode(MODE);		//set App Mode state


	// Output Functions  ---------------------------
	MODE GetAppMode()const;     //returns App Mode state
	ostream Start_silent_Mode();

	~UI();		//Destructor


///////////////////////////////////////////////////////////////////// To be handeled //////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////
	//NOTE:these functions doesn't have implementation please add them
	//these info is found in the input file
	char get_Event();
	char get_cargo_type();
	double get_cargo_distance();

	//Event time [day,hour]
	//let Event time be ET
	int get_ET_day();
	int get_ET_hour();

	int get_load_time();
	int get_cargo_id ();
	int get_cargo_cost();
	///////////////////////////////////////////////////////////////////////
};

