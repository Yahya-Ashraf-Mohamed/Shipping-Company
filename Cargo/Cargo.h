#pragma once
#ifndef _CARGO_H
#define _CARGO_H
#include "..\Defs.H"

class Cargo
{
private:
	TYP cargo_type;      //TYP is enum that contains ( NORMAL , SPECIAL , VIP )
	double cargo_distance;    //The distance that the cargo will travel in kilometeres
	int load_time;            //Time (in hours) to load or unload cargo
	int cargo_id;             // unique sequence number that identifies each cargo
	int cost;                 //cost of delievering the cargo

	//Event time [day,hour]
	int ReadyEvent_time[2];

public:
	Cargo(TYP type,double dist,int LT,int ID,int COST);
	~Cargo();

	//int getCargo_ID();
	//float getCargo_Distance();
	//float getCargo_Cost();
	//float getCargo_Extra_Money();
	//string getCargo_Type();
	//int getCargo_Load_Time();
	void Set_ReadyEvent_time(int* Eventtime );
	int* get_ReadyEvent_time();
};

#endif