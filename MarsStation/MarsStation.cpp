#include "MarsStation.h"

#include "..\Event\Event.h"
#include "..\Event\ReadyEvent.h"
#include "..\Event\CancellationEvent.h"
#include "..\Event\PromotionEvent.h"

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

////Add Cargo to Cargo Queue depending on it's type
//void MarsStation::AddCargo( Cargo newCargo , TYP CargoType)
////void MarsStation::AddCargo (Cargo* pCargo, TYP CargoType)
//{
//	switch (CargoType)
//	{
//	case VIP:
//		VIP_Cargo.enqueue(newCargo);
//		break;
//	case SPECIAL:
//		VIP_Cargo.enqueue(newCargo);
//		break;
//	case NORMAL:
//		VIP_Cargo.enqueue(newCargo);
//		break;
//	}
//}


//=================================================== Input Functions =================================================

void MarsStation::setClock_Hours(int Hours)
{
	Clock[0] = Hours;
}

void MarsStation::setClock_Days(int Days)
{
	Clock[1] = Days;
}

void MarsStation::setClock(int Hours, int Days)
{
	Clock[0] = Hours;
	Clock[1] = Days;
}

void MarsStation::setInt_Variables(fstream DataFile)
{
	DataFile >> no_Normal >> no_Special >> no_VIP
		>> Normal_speed >> Special_speed >> VIP_speed
		>> Normal_capacity >> Special_capacity >> VIP_capacity
		>> Normal_CheckUp_duration >> Special_CheckUp_duration >> VIP_CheckUp_duration
		>> CheckUp_Journeys
		>> AutoPromotion
		>> MaxW
		>> no_events;
}





//=================================================== Output Functions =================================================

int MarsStation::getClock_Days()
{
	return Clock[1];
}

int MarsStation::getClock_Hours()
{
	return Clock[0];
}


//=================================================== File handler =================================================

bool MarsStation::openFileIn(fstream& file, string name)
{
	file.open(name, ios::in);
	if (file.fail())
		return false;
	else
		return true;

}

