#pragma once
#include "..\Defs.H"
class Cargo
{
private:
	TYP cargo_type;			  //TYP is enum that contains ( NORMAL , SPECIAL , VIP )
	int cargo_distance;    //The distance that the cargo will travel in kilometeres
	int load_time;            //Time (in hours) to load or unload cargo
	int cargo_id;             // unique sequence number that identifies each cargo
	float cost;                 //cost of delievering the cargo
	float cargo_extra_money;    //extra money of promotion from normal to vip cargo
	//Event time [day,hour]
	int ReadyEvent_time[2];
	int Delivery_time[2];
	/*int PromotionEvent_time[2];*/

	//========================================================
	//Added by Yahya new

	int* Waiting_Time = new int[2];

	//========================================================


public:
	Cargo(TYP type, double dist, int LT, int ID, float COST);
	~Cargo();


	void setCargoID(int);
	void setCargoDistance(int);
	void setCargoCost(float);
	void setCargoExtraMoney(float);
	void promoteCargo(Cargo*);
	void setCargoLoadTime(int);


	int getCargoID();
	int getCargoDistance();
	float getCargoCost();
	float getCargo_Extra_Money();

	TYP getCargo_Type();
	void Set_cargo_type(TYP type);

	//string getCargo_Type();

	int getCargo_Load_Time();
	bool Set_ReadyEvent_time(int* Eventtime);
	int* get_ReadyEvent_time();


	//void Set_PromotionEvent_time(int* Eventtime);
	//int* get_PromotionEvent_time();


	//Added by Yahya new
	//========================================================

	void set_Waiting_Time(int* currentTime);
	int* get_Waiting_Time();

	void set_Delivery_time(int* Eventtime);
	int* get_Delivery_time();

	//========================================================

};
