#pragma once
#ifndef MARS_STATION_H
#define MARS_STATION_H

#include"..\Defs.H"
#include "..\UI\UI.h"
#include "..\Cargo\Cargo.h"
#include "..\DataStructures\Queue.h"
#include "..\Event\Event.h"
#include "..\Event\ReadyEvent.h"
#include "..\Event\PromotionEvent.h"
#include "..\Event\CancellationEvent.h"


//ApplicationManegar
class MarsStation
{
	UI* pUI; //pointer to the UI
	Queue<Cargo*> VIP_Cargo;
	Queue<Cargo*> Special_Cargo;
	Queue<Cargo*> Normal_Cargo;
public:
	// constructor and destructor
	MarsStation();
	~MarsStation();

	//Gets a pointer to UI Object
	UI* GetUI();

	//Select Event to be excuted
	void ExecuteEvent(char Event, Cargo* pCargo=nullptr);
	//Add Cargo
	void AddCargo(Cargo* pCargo, TYP type);
};
#endif