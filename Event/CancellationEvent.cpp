#include "CancellationEvent.h"
#include "..\MarsStation\MarsStation.h"


CancellationEvent::CancellationEvent(MarsStation* pApp, int Eventtime_day, int Eventtime_hour, int id) :Event(pApp)
{
	event_time[0] = Eventtime_day;
	event_time[1] = Eventtime_hour;
	cargo_id = id;
}

CancellationEvent:: ~CancellationEvent()
{}

//int CancellationEvent::getEvent_Time()
//{
//
//}
//void CancellationEvent::setEvent_Time(string EventTime)
//{
//
//}

void CancellationEvent::Execute()
{
	pStation->CancelCargo(cargo_id);
}