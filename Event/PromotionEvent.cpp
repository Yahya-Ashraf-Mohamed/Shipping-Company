#pragma once
#include"PromotionEvent.h"
#include"..\MarsStation\MarsStation.h"

PromotionEvent::PromotionEvent(MarsStation* pApp, int Eventtime_day, int Eventtime_hour, int id, float Extra_Money) :Event(pApp)
{
	event_time[0] = Eventtime_day;
	event_time[1] = Eventtime_hour;
	cargo_id = id;
	extra_money = Extra_Money;
}

PromotionEvent::~PromotionEvent(void)
{}


void PromotionEvent::setAutoP(bool x)
{
	AutoP = x;
}

bool PromotionEvent::isAutoP()
{
	return AutoP;
}

void PromotionEvent::Execute()
{
	pCargo=pStation->PromoteCargo(cargo_id);
	if (pCargo)
	{
		pCargo->Set_cargo_type(VIP);
		float newCost = pCargo->getCargoCost() + extra_money;
		pCargo->setCargoCost(newCost);
		if (AutoP && pCargo)
			pStation->Autop_Count_increment();
		/*pCargo->Set_PromotionEvent_time(event_time);*/
	}

}