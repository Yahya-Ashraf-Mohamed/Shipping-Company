#include "Cargo.h"

Cargo::Cargo(TYP type, double dist, int LT, int ID, int COST) 
{
	cargo_type = type;
	cargo_distance = dist;
	load_time = LT;
	cargo_id = ID;
	cost = COST;
}
Cargo::~Cargo() {}


void Cargo::Set_cargo_type(TYP type)
{
	cargo_type = type;
}
TYP  Cargo::get_cargo_type()
{
	return cargo_type;
}


void Cargo::Set_cargo_id(int x)
{
	cargo_id = x;
}
int Cargo::get_cargo_id()
{
	return cargo_id;
}


void Cargo::Set_cost(int x)
{
	cost = x;
}
int Cargo::get_cost()
{
	return cost;
}


void Cargo::Set_ReadyEvent_time(int* Eventtime)
{
	ReadyEvent_time[0] = Eventtime[0];
	ReadyEvent_time[1] = Eventtime[1];
}
int* Cargo::get_ReadyEvent_time()
{
	return ReadyEvent_time;
}

//void Cargo::Set_PromotionEvent_time(int* Eventtime)
//{
//	PromotionEvent_time[0] = Eventtime[0];
//	PromotionEvent_time[1] = Eventtime[1];
//}
//int* Cargo::get_PromotionEvent_time()
//{
//	return PromotionEvent_time;
//}