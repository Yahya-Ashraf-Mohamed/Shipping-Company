#include "MarsStation.h"

//#include "..\Event\Event.h"
#include "..\Event\ReadyEvent.h"
#include "..\Event\CancellationEvent.h"
//#include "..\Event\PromotionEvent.h"

#include  <fstream>

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
	
	//Add Cargo to Cargo Queue depending on it's type
	void MarsStation::AddCargo(Cargo* pCargo, TYP CargoType)
	{
		switch (CargoType)
		{
		case VIP:
			VIP_Cargo.enqueue(pCargo);
			VIP_Cargo_count++;
			break;
		case SPECIAL:
			Special_Cargo.enqueue(pCargo);
			Special_Cargo_count++;
			break;
		case NORMAL:
			Normal_Cargo.enqueue(pCargo);
			Normal_Cargo_count++;
			break;
		}
	}

	//Promote normal cargo to VIP cargoes and returns pointer to the promoted Cargo
	//Auto promote still not Handelled
	Cargo* MarsStation::PromoteCargo(int cargo_id)
	{
		Cargo* pCargo = Normal_Cargo.RemoveNode(cargo_id);
		if (pCargo)
		{
			Normal_Cargo_count--;
			VIP_Cargo.enqueue(pCargo);
			VIP_Cargo_count++;
		}
		return pCargo;
	}

	//Cancel Cargo
	void MarsStation::CancelCargo(int cargo_id)
	{
		Cargo* pCargo = Normal_Cargo.RemoveNode(cargo_id);
		if (pCargo)
		{
			Normal_Cargo_count--;
			delete pCargo;
		}
	}

	void MarsStation::addReadyEvent(int Eventtime_day, int Eventtime_hour, char type, double distance, int LoadTime, int id, int Cost)
	{
		ReadyEvent* p = new ReadyEvent(this, Eventtime_day, Eventtime_hour, type, distance, LoadTime, id, Cost);
		EVENT.enqueue(p);
	}

	PromotionEvent* MarsStation::addPromotionEvent(int Eventtime_day, int Eventtime_hour, int id, int Extra_Money)
	{
		PromotionEvent* p = new PromotionEvent(this , Eventtime_day, Eventtime_hour, id, Extra_Money);
		EVENT.enqueue(p);
		return p;
	}

	void MarsStation::Autop_Count_increment()
	{
		AutoP_Count ++;
	}

	void MarsStation::addCancellationEvent( int Eventtime_day, int Eventtime_hour, int id)
	{
		CancellationEvent* p = new CancellationEvent(this, Eventtime_day, Eventtime_hour, id);
		EVENT.enqueue(p);
	}

//=================================================== Input Functions =================================================

//void MarsStation::setClock_Hours(int Hours)
//{
//	Clock[0] = Hours;
//}
//
//void MarsStation::setClock_Days(int Days)
//{
//	Clock[1] = Days;
//}
//
//void MarsStation::setClock(int Hours, int Days)
//{
//	Clock[0] = Hours;
//	Clock[1] = Days;
//}
//
//void MarsStation::setInt_Variables(fstream DataFile)
//{
//	DataFile >> no_Normal >> no_Special >> no_VIP
//		>> Normal_speed >> Special_speed >> VIP_speed
//		>> Normal_capacity >> Special_capacity >> VIP_capacity
//		>> Normal_CheckUp_duration >> Special_CheckUp_duration >> VIP_CheckUp_duration
//		>> CheckUp_Journeys
//		>> AutoPromotion
//		>> MaxW
//		>> no_events;
//}
//
//



//=================================================== Output Functions =================================================

//int MarsStation::getClock_Days()
//{
//	return Clock[1];
//}
//
//int MarsStation::getClock_Hours()
//{
//	return Clock[0];
//}


//=================================================== File handler =================================================

//bool MarsStation::openFileIn(fstream& file, string name)
//{
//	file.open(name, ios::in);
//	if (file.fail())
//		return false;
//	else
//		return true;
//
//}

