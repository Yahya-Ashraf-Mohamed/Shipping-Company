#include "Cargo.h"

Cargo::Cargo(TYP type, double dist, int LT, int ID, float COST)
{
	cargo_type = type;
	cargo_distance = dist;
	load_time = LT;
	cargo_id = ID;
	cost = COST;
}
Cargo::~Cargo() {}

void Cargo::setCargoID(int ID)
{
	this->cargo_id = ID;
}
void Cargo::setCargoDistance(int distance)
{
	this->cargo_distance = distance;
}
void Cargo::setCargoCost(float cost)
{
	this->cost = cost;
}
void Cargo::setCargoExtraMoney(float cargoExtraMoney)
{
	this->cargo_extra_money = cargoExtraMoney;
}
void Cargo::promoteCargo(Cargo* cargo)
{
	cargo->cargo_type = VIP;
}
void Cargo::setCargoLoadTime(int loadTime)
{
	load_time = loadTime;
}


int Cargo::getCargoID()
{
	return cargo_id;
}
double Cargo::getCargoDistance()
{
	return cargo_distance;
}

float Cargo::getCargoCost()
{
	return cost;
}
float Cargo::getCargo_Extra_Money()
{
	if (this->cargo_type == NORMAL)
		return cargo_extra_money;
	else
		return 0;
}
TYP Cargo::getCargo_Type()
{
	return cargo_type;
}
void Cargo::Set_cargo_type(TYP type)
{
	cargo_type = type;
}

int Cargo::getCargo_Load_Time()
{
	return load_time;
}



bool Cargo::Set_ReadyEvent_time(int* Eventtime)
{
	if (Eventtime == nullptr)
		return false;
	else
	{
		ReadyEvent_time[0] = Eventtime[0];
		ReadyEvent_time[1] = Eventtime[1];
		return true;
	}
}
int* Cargo::get_ReadyEvent_time()
{
	return ReadyEvent_time;
}

bool Cargo::set_Delivery_time(int* Eventtime)
{
	if (Eventtime == nullptr)
		return false;
	else
	{
		Delivery_time[0] = Eventtime[0];
		Delivery_time[1] = Eventtime[1];
		return true;
	}
}
int* Cargo::get_Delivery_time()
{
	return Delivery_time;
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



//Added by Yahya new
//========================================================

void Cargo::set_Waiting_Time(int* currentTime)
{
	Waiting_Time[0] = currentTime[0] - ReadyEvent_time[0];
	Waiting_Time[1] = currentTime[1] - ReadyEvent_time[1];
}

int* Cargo::get_Waiting_Time()
{
	return Waiting_Time;
}