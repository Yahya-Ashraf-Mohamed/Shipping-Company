//#pragma once
//#include "..\DataStructures\Queue.h"
//#include "..\MarsStation\MarsStation.h"
//
//#include "Event.h"
//#include "CancellationEvent.h"
//#include "PromotionEvent.h"
//#include "ReadyEvent.h"
//
//class test
//{
//	MarsStation* M = new MarsStation();
//	Queue<Event*> EVENT;
//	Event* E;
//public:
//	test() {};
//
//
//	void addReadyEvent(int Eventtime_day, int Eventtime_hour, TYP type, double distance, int LoadTime, int id, int Cost)
//	{
//		ReadyEvent* p1 = new ReadyEvent(M, Eventtime_day, Eventtime_hour, type, distance, LoadTime, id, Cost);
//		EVENT.enqueue(p1);
//	}
//
//
//	void excute()
//	{
//
//		ReadyEvent* p1 = new ReadyEvent(M, 1, 5, VIP, 10, 6, 300, 1000);
//		PromotionEvent* p2 = new PromotionEvent(M, 2, 2, 300, 5);
//		CancellationEvent* p3 = new CancellationEvent(M, 3, 3, 300);
//		bool x=EVENT.enqueue(p1);
//		cout << "enque p1:" << x << endl;
//		bool y=EVENT.enqueue(p2);
//		cout << "enque p2:" << y << endl;
//		bool z= EVENT.enqueue(p3);
//		cout << "enque p3:" << z << endl;
//		bool H = EVENT.isEmpty();
//		cout << "is empty:" << H << endl;
//		bool l = EVENT.dequeue(E);
//		cout << "dequeue p1:" << l << endl;
//		bool ll= EVENT.dequeue(E);
//		cout << "dequeue p2:" << ll << endl;
//		bool lll= EVENT.dequeue(E);
//		cout << "dequeue p3:" << lll << endl;
//		bool HH = EVENT.isEmpty();
//		cout << "is empty:" << HH << endl;
//
//	}
//
//};
//
