#pragma once
#include"Event.h"

//Class responsible for adding  new Cargo 
class ReadyEvent : public Event
{
private:
	TYP cargo_type;           //TYP is enum that contains ( NORMAL , SPECIAL , VIP )
	double cargo_distance;    //The distance that the cargo will travel in kilometeres
	int load_time;            //Time (in hours) to load or unload cargo
	int cargo_id;             // unique sequence number that identifies each cargo
	float cost;                 //cost of delievering the cargo
	static int AutoP;        //represents number of days after which a normal cargo is Auto promoted to VIP cargo

public:
	ReadyEvent( MarsStation* pApp, int Eventtime_day , int Eventtime_hour , char type , double distance , int LoadTime , int id  , float Cost );
	virtual ~ReadyEvent(void);

	//TYP	get_cargo_type(char CargoType);
	void setAutoP(int x);
	int  getAutoP();


	//gets cargo type from UI and returns it with as enum value "TYP"
	TYP get_cargo_type(char CargoType);

	//Execute Event 
	virtual void Execute();

	virtual int getEvent_Time();


};