#pragma once
#include"ReadyEvent.h"
#include"..\MarsStation\MarsStation.h"

ReadyEvent::ReadyEvent(MarsStation* pApp, int Eventtime_day, int Eventtime_hour) : Event(pApp)
{
	event_time[0] = Eventtime_day;
	event_time[1] = Eventtime_hour;
}

ReadyEvent::~ReadyEvent(void)
{
}


//gets cargo type from UI and returns it with as enum value "TYP"

TYP ReadyEvent::get_cargo_type()
{
	char CargoType = pUI->get_cargo_type();
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


//Excecute Event

void ReadyEvent::Execute()
{
	//get user input from UI
	cargo_type = get_cargo_type();
	cargo_distance = pUI->get_cargo_distance();
	load_time = pUI->get_load_time();
	cargo_id = pUI->get_cargo_id();
	cost = pUI->get_cargo_cost();

	//Create Cargo and add it to Queue
	pCargo = new Cargo(cargo_type, cargo_distance, load_time, cargo_id, cost);
	pStation->AddCargo(pCargo, cargo_type);

	// Stores ReadyEvent_time in the created Cargo 
	pCargo->Set_ReadyEvent_time(event_time);
}

