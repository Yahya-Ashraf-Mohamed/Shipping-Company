#pragma once
#ifndef _EVENT_H
#define _EVENT_H
#include"..\Cargo\Cargo.h"
//#include"..\MarsStation\MarsStation.h"
	class MarsStation;  //forward declaration
	

	//Base class for all possible Events (abstract class)
	class Event
	{
	protected:
		MarsStation* pStation;	//Events needs station pointer to do their job
		int event_time[2];      // [day,hour] "user input"
		Cargo* pCargo;           // cargo pointer carring cargo info
	public:
		//constructor
		Event(MarsStation* pApp)
		{
			pStation = pApp;
		}	

		/*string getEvent_Type();
		int* getEvent_Time();
		void setEvent_Time(string EventTime);*/

		//Execute Event (code depends on Event )
		virtual void Execute() = 0;

	};

#endif

