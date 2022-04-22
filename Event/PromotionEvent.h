#pragma once
#include"Event.h"


//Class responsible for moving normal cargo to vip if not loaded yet
class PromotionEvent : public Event
{
private:
	int cargo_id;				 // unique sequence number that identifies each cargo
	int extra_money;			// extra cost for moving normal cargo to vip
	bool AutoP = false;		//is it auto promotion event
public:
	PromotionEvent( MarsStation* pApp , int Eventtime_day , int Eventtime_hour , int id , int Extra_Money=0);
	virtual ~PromotionEvent(void);

	void setAutoP(bool x);
	bool isAutoP();

	//Execute Event 
	virtual void Execute();


};