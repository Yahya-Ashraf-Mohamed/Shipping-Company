#pragma once
#include"ReadyEvent.h"
#include"..\MarsStation\MarsStation.h"

ReadyEvent::ReadyEvent(MarsStation* pApp, int Eventtime_day, int Eventtime_hour) :Event(pApp)
{
	event_time[0] = Eventtime_day;
	event_time[1] = Eventtime_hour;
}

ReadyEvent::~ReadyEvent(void)
{
}

void ReadyEvent::Execute()
{
	char CargoType = pUI->get_cargo_type();
	switch (CargoType)  //Cargo class excepects cargo_type enumerated type "TYP"
	{
	case 'V':
		cargo_type=VIP;
		break;
	case 'S':
		cargo_type = SPECIAL;
		break;
	case 'N':
		cargo_type = NORMAL;
		break;
	}

	cargo_distance = pUI->get_cargo_distance();
	load_time = pUI->get_load_time();
	cargo_id = pUI->get_cargo_id();
	cost = pUI->get_cargo_cost();

	pCargo = new Cargo(cargo_type, cargo_distance, load_time, cargo_id, cost);
	pStation->AddCargo(pCargo, cargo_type);

	pCargo->Set_ReadyEvent_time(event_time);
}

