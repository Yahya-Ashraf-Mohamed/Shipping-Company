#pragma once
#ifndef _EVENT_H
#define _EVENT_H

#include "..\MarsStation\MarsStation.h"

	//Base class for all possible Events (abstract class)
	class Event
	{
	protected:
		MarsStation* pStation;	//Events needs station pointer to do their job
		int event_time[2];      // [day,hour] "user input"
		Cargo* pCargo;           // cargo pointer carring cargo info
		UI* pUI;               //Get a Pointer to the user Interfaces
	public:
		//constructor
		Event(MarsStation* pApp)
		{
			pStation = pApp;
			pUI = pApp->GetUI();
		}	


		//Execute Event (code depends on Event )
		virtual void Execute() = 0;

	};

#endif

