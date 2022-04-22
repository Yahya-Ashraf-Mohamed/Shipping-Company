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
		/*string getEvent_Type();*/

		//virtual int getEvent_Time() = 0 ;
		//virtual void setEvent_Time(string EventTime) = 0 ;

		//string getEvent_Type();

		//Execute Event (code depends on Event )
		virtual void Execute() = 0;

	};

#endif

