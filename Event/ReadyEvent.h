#pragma once
#include"Event.h"

//Class responsible for adding  new Cargo 
class ReadyEvent : public Event
{
private:
	TYP cargo_type;      //TYP is enum that contains ( NORMAL , SPECIAL , VIP )
	double cargo_distance;    //The distance that the cargo will travel in kilometeres
	int load_time;            //Time (in hours) to load or unload cargo
	int cargo_id;             // unique sequence number that identifies each cargo
	int cost;                 //cost of delievering the cargo
public:
	ReadyEvent(MarsStation* pApp, int Eventtime_day,int Eventtime_hour);
	virtual ~ReadyEvent(void);

	//gets cargo type from UI and returns it with as enum value "TYP"
	TYP get_cargo_type();

	//Execute Event 
	virtual void Execute();



};