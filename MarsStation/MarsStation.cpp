#include "MarsStation.h"


//================================= CONSTRUCTOR / DESTRUCTOR / UI POINTER =================================
MarsStation::MarsStation()
{
	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
MarsStation::~MarsStation()
{
	delete pUI;
}
UI* MarsStation::GetUI()
{
	return pUI;
}

//=================================================== EVENTS =================================================
	
//selecting the Event to be excecuted

void MarsStation::ExecuteEvent(char eventt, Cargo* pCargo)
{
	int Eventtime_day = pUI->get_ET_day();
	int Eventtime_hour = pUI->get_ET_hour();

	Event* pEvent = nullptr;
	switch (eventt)
	{
	case 'R':
		pEvent = new ReadyEvent(this, Eventtime_day, Eventtime_hour);
		break;
	}
	if (pEvent)
	{
		pEvent->Execute();
		delete pEvent;
		pEvent = nullptr;
	}
}

//Add Cargo to Cargo Queue depending on it's type

void MarsStation::AddCargo (Cargo* pCargo, TYP CargoType)
{
	switch (CargoType)
	{
	case VIP:
		VIP_Cargo.enqueue(pCargo);
		break;
	case SPECIAL:
		VIP_Cargo.enqueue(pCargo);
		break;
	case NORMAL:
		VIP_Cargo.enqueue(pCargo);
		break;
	}
}

//=============================================================================================================
