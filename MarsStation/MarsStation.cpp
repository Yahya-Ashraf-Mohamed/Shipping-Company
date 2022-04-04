#include "MarsStation.h"

// Constructors
MarsStation::MarsStation() {}

// Input Functions		---------------------------
void MarsStation::setClock_Hours(int Hours)
{
	Clock[0] = Hours;
}

void MarsStation::setClock_Minutes(int Minutes)
{
	Clock[1] = Minutes;
}

void MarsStation::setClock(int Hours, int Minutes)
{
	Clock[0] = Hours;
	Clock[1] = Minutes;
}

void MarsStation::setInt_Variables(fstream DataFile)
{
	DataFile >> no_Normal >> no_Special >> no_VIP
		>> Normal_speed >> Special_speed >> VIP_speed
		>> Normal_capacity >> Special_capacity >> VIP_capacity
		>> Normal_CheckUp_duration >> Special_CheckUp_duration >> VIP_CheckUp_duration
		>> CheckUp_Journeys
		>> AutoPromotion
		>> MaxW
		>> no_events;
}

// Output Functions		---------------------------
int MarsStation::getClock_Minutes()
{
	return Clock[1];
}

int MarsStation::getClock_Hours()
{
	return Clock[0];
}

// Variable Functions	---------------------------
bool MarsStation::openFileIn(fstream& file, string name)
{
	file.open(name, ios::in);
	if (file.fail())
		return false;
	else
		return true;

}