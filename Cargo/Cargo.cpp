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

void Cargo::Set_ReadyEvent_time(int* Eventtime)
{
	ReadyEvent_time[0] = Eventtime[0];
	ReadyEvent_time[1] = Eventtime[1];
};
int* Cargo::get_ReadyEvent_time()
{
	return ReadyEvent_time;
};