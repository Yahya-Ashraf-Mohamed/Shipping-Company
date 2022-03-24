#pragma once
#ifndef _EVENT_H
#define _EVENT_H

	class MarsStation; //forward class declaration

	//Base class for all possible Events (abstract class)
	class Event
	{
	protected:
		MarsStation* pStation;	//Events needs station pointer to do their job
		int event_time[2];      // [day,hour] "user input"
		int cargo_id;           
	public:
		Event(MarsStation* pApp) { pStation = pApp; }	//constructor


		//Execute Event (code depends on Event )
		virtual void Execute() = 0;

	};

#endif

