#pragma once
#ifndef _CARGO_H
#define _CARGO_H
#include "..\Defs.H"

class Cargo
{
private:
	TYP cargo_type;			  //TYP is enum that contains ( NORMAL , SPECIAL , VIP )
	double cargo_distance;    //The distance that the cargo will travel in kilometeres
	int load_time;            //Time (in hours) to load or unload cargo
	int cargo_id;             // unique sequence number that identifies each cargo
	int cost;                 //cost of delievering the cargo

	//Event time [day,hour]
	int ReadyEvent_time[2];
	/*int PromotionEvent_time[2];*/
public:
	Cargo(TYP type,double dist,int LT,int ID,int COST);
	~Cargo();

	void Set_cargo_type(TYP type);
	TYP  get_cargo_type();


	void Set_cargo_id(int x);
	int  get_cargo_id();

	void Set_cost(int x);
	int  get_cost();

	void Set_ReadyEvent_time(int* Eventtime);
	int* get_ReadyEvent_time();

	//void Set_PromotionEvent_time(int* Eventtime);
	//int* get_PromotionEvent_time();
};

#endif