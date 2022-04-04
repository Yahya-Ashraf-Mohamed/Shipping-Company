#pragma once

#include "..//Def.h"
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
};

