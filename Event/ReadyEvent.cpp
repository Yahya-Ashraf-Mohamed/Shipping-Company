#pragma once
#include"ReadyEvent.h"
#include"..\MarsStation\MarsStation.h"

//initializing static Variable
int ReadyEvent::AutoP = 0;

ReadyEvent::ReadyEvent(MarsStation* pApp, int Eventtime_day, int Eventtime_hour, TYP type, double distance, int LoadTime, int id, int Cost) :Event(pApp)
{
	event_time[0] = Eventtime_day;
	event_time[1] = Eventtime_hour;
	cargo_type = type;
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
		//Event time [day,hour]
		int AutoP_day= event_time[0] + AutoP;
		int AutoP_hour= event_time[0];

		//pStation->addPromotionEvent(AutoP_day, AutoP_hour, cargo_id);     //error remain extr money
	}

}

//================================= ignore =========================
//gets cargo type from UI and returns it with as enum value "TYP"
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

//===============================================================


//int ReadyEvent::getEvent_Time()
//{
//	return event_time[0]*24 + event_time[1];
//}
//void ReadyEvent::setEvent_Time(string EventTime)
//{
//
//}