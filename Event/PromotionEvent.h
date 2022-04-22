#pragma once
#include"Event.h"


//Class responsible for moving normal cargo to vip if not loaded yet
class PromotionEvent : public Event
{
private:
	int cargo_id;				 // unique sequence number that identifies each cargo
	float extra_money;			// extra cost for moving normal cargo to vip
	bool AutoP = false;		//is it auto promotion event
public:
	PromotionEvent( MarsStation* pApp , int Eventtime_day , int Eventtime_hour , int id , float Extra_Money=0);
	virtual ~PromotionEvent(void);

	virtual int getEvent_Time();

	void setAutoP(bool x);
	bool isAutoP();

	//Execute Event 
	virtual void Execute();


};