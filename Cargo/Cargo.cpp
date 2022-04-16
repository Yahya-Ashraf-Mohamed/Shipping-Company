#include "Cargo.h"

Cargo::Cargo(TYP type, double dist, int LT, int ID, int COST) 
{
	cargo_type = type;
	cargo_distance = dist;
	load_time = LT;
	cargo_id = ID;
	cost = COST;
};
Cargo::~Cargo() {};

//int Cargo :: getCargo_ID()
//{
//}
//
//float  Cargo :: getCargo_Distance()
//{
//}
//float Cargo::getCargo_Cost()
//{
//}
//float Cargo::getCargo_Extra_Money()
//{
//}
//TYP Cargo::getCargo_Type()
//{
//}
//int Cargo::getCargo_Load_Time()
//{
//}


void Cargo::Set_ReadyEvent_time(int* Eventtime)
{
	ReadyEvent_time[0] = Eventtime[0];
	ReadyEvent_time[1] = Eventtime[1];
};
int* Cargo::get_ReadyEvent_time()
{
	return ReadyEvent_time;
};