#pragma once
#include"ReadyEvent.h"
#include "PromotionEvent.h"
#include"..\MarsStation\MarsStation.h"

//initializing static Variable
int ReadyEvent::AutoP = 0;

ReadyEvent::ReadyEvent(MarsStation* pApp, int Eventtime_day, int Eventtime_hour, char type, double distance, int LoadTime, int id, float Cost) :Event(pApp)
{
	event_time[0] = Eventtime_day;
	event_time[1] = Eventtime_hour;
	cargo_type = get_cargo_type(type);
	cargo_distance = distance;
	load_time = LoadTime;
	cargo_id = id;
	cost = Cost;
}

ReadyEvent::~ReadyEvent(void)
{
}

void ReadyEvent::setAutoP(int x)
{
	AutoP = x;
}

int  ReadyEvent::getAutoP()
{
	return AutoP;
}


TYP ReadyEvent::get_cargo_type(char CargoType)
{
	TYP type;
	switch (CargoType)  //Cargo class excepects cargo_type enumerated type "TYP"
	{
	case 'V':
		type = VIP;
		break;
	case 'S':
		type = SPECIAL;
		break;
	case 'N':
		type = NORMAL;
		break;
	}
	return type;
}

void ReadyEvent::Execute()
{
	//Create Cargo and add it to List
	pCargo = new Cargo(cargo_type, cargo_distance, load_time, cargo_id, cost);
	pStation->AddCargo(pCargo, cargo_type);

	// Stores ReadyEvent_time in the created Cargo 
	pCargo->Set_ReadyEvent_time(event_time);

	//creates Autop Event and adds it to the event queue
	if (cargo_type == NORMAL)
	{
		////Event time [day,hour]
		//int AutoP_day= event_time[0] + AutoP;
		//int AutoP_hour= event_time[0];

		//PromotionEvent* p= pStation->addPromotionEvent(AutoP_day, AutoP_hour, cargo_id);
		//p->setAutoP(true);
		
	}

}

int ReadyEvent::getEvent_Time()
{
	return event_time[0] * 24 + event_time[1];
}
