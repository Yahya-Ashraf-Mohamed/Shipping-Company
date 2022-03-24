#pragma once
#include"Event.h"
//include cargo

//Class responsible for adding  new Cargo 
class ReadyEvent : public Event
{
private:
	TYP cargo_type;      //TYP is enum that contains ( NORMAL , SPECIAL , VIP )
	double cargo_distance;    //The distance that the cargo will travel in kilometeres
	int load_time;            //Time (in hours) to load or unload cargo
	int cost;                 //cost of delievering the cargo
public:
	ReadyEvent(MarsStation* pApp);
	virtual ~ReadyEvent(void);

	//Execute Event 
	virtual void Execute();



};