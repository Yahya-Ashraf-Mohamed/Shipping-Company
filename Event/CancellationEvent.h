#pragma once
#include"Event.h"

//Class responsible for cancelling normal cargo if not loaded yet
class CancellationEvent : public Event
{
private:
	int cargo_id;             // unique sequence number that identifies each cargo
public:
	CancellationEvent( MarsStation* pApp, int Eventtime_day, int Eventtime_hour, int id );
	virtual ~CancellationEvent(void);

	//Execute Event 
	virtual void Execute();
};