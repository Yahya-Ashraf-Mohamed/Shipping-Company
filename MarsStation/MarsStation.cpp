#include "MarsStation.h"

#include "..\Event\Event.h"
#include "..\Event\ReadyEvent.h"
#include "..\Event\CancellationEvent.h"
#include "..\Event\PromotionEvent.h"

#include  <fstream>

//================================= CONSTRUCTOR / DESTRUCTOR / UI POINTER =================================
//MarsStation::MarsStation()
//{
//	//Creates the UI Object & Initialize the UI
//	pUI = new UI;
//
//	events = new string * [no_events];
//
//	for (int i = 0; i < no_events; i++)
//	{
//		events[i] = new string[7];		// hint: you have to change 7 as their is 3 and 4
//	}
//}

MarsStation::MarsStation(string name)
{
	ifstream dataFile/*(name)*/;// File stream object
	

	if (openFileIn(dataFile, name) == false)
	{
		//pop an error message        //TO DO
	}
	else
	{
		setInt_Variables(dataFile);
		string LineTemp;

		while (!check_file_is_empty(dataFile))
		{
			getline(dataFile, LineTemp);
			inputFileLines[LineNum] = LineTemp;
			LineNum++;
		}

		events = new string * [no_events];

		for (int i = 0; i < no_events; i++)
		{
			events[i] = new string[7];		// hint: you have to change 7 as their is 3 and 4
		}

		int j = 0, k = 0;

		for (int i = 0; i < no_events; i++) {

			stringstream ssin(inputFileLines[k]);
			while (ssin.good() && j < 7) {
				ssin >> events[i][j];
				++j;
			}
			j = 0;
			++k;
		}

		Start_Next_Event(events, EventLineNum);

		//Creates the UI Object & Initialize the UI
		pUI = new UI;

	}

}

MarsStation::~MarsStation()
{
	//delete pUI;
}
UI* MarsStation::GetUI()
{
	return pUI;
}

//=================================================== Input Functions =================================================

void MarsStation::setClock_Hours(int Hours)
{
	Clock[0] = Hours;
}

void MarsStation::setClock_Days(int Days)
{
	Clock[1] = Days;
}

void MarsStation::setClock(int Hours, int Days)
{
	Clock[0] = Hours;
	Clock[1] = Days;
}

void MarsStation::setInt_Variables(ifstream& DataFile)
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

void MarsStation::setEvent_Time(string Time)
{
	vector<string> v;
	string EventTime_S[2] = { "","" };
	stringstream splitString(Time);

	while (splitString.good()) {
		string substr;
		getline(splitString, substr, ':');
		v.push_back(substr);
	}
	for (int j = 0; j < v.size(); j++)
		EventTime_S[j] = v[j];

	stringstream StringToIntConverter_EventTime_day(EventTime_S[0]);
	StringToIntConverter_EventTime_day >> EventTime[0];
	stringstream StringToIntConverter_EventTime_Hour(EventTime_S[1]);
	StringToIntConverter_EventTime_Hour >> EventTime[1];

}

//=================================================== Output Functions =================================================

int MarsStation::getClock_Days()
{
	return Clock[1];
}

int MarsStation::getClock_Hours()
{
	return Clock[0];
}

int MarsStation::getCargo_ID()
{
	return CargoID;
}
int MarsStation::getTruck_ID()
{
	return TruckID;
}
int MarsStation::getCargo_Load_Time()
{
	return CargoLoadTime;
}
int* MarsStation::getEvent_Time()
{
	return EventTime;
}
float MarsStation::getCargo_Distance()
{
	return CargoDistance;
}
float MarsStation::getCargo_Cost()
{
	return CargoCost;
}
float MarsStation::getCargo_Extra_Money()
{
	return CargoExtraMoney;
}
string MarsStation::getCargo_Type()
{
	return CargoType;
}
string MarsStation::getTruck_Type()
{
	return TruckType;
}
string MarsStation::getEvent_Type()
{
	return EventType;
}

//=================================================== File handler =================================================

bool MarsStation::openFileIn(ifstream& file, string name)
{
	file.open(name/*, ios::in*/);
	if (file.fail())
		return false;
	else
		return true;

}

bool MarsStation::check_file_is_empty(ifstream& file) {
	return file.peek() == EOF;
}


//=================================================== EVENTS =================================================
	
//selecting the Event to be excecuted

void MarsStation::ExecuteEvent(char eventt, Cargo* pCargo)
{
	int Eventtime_day = pUI->get_ET_day();
	int Eventtime_hour = pUI->get_ET_hour();

	Event* pEvent = nullptr;
	switch (eventt)
	{
	case 'R':
		pEvent = new ReadyEvent(this, Eventtime_day, Eventtime_hour);
		break;
	}
	if (pEvent)
	{
		pEvent->Execute();
		delete pEvent;
		pEvent = nullptr;
	}
}

//Add Cargo to Cargo Queue depending on it's type
void MarsStation::AddCargo( Cargo* pCargo , TYP CargoType)
{
	switch (CargoType)
	{
	case VIP:
		VIP_Cargo.enqueue(pCargo);
		break;
	case SPECIAL:
		VIP_Cargo.enqueue(pCargo);
		break;
	case NORMAL:
		VIP_Cargo.enqueue(pCargo);
		break;
	}
}

void MarsStation::Start_Next_Event(string** events, int EventLineNum)
{
	EventType = events[EventLineNum][0];

	if(EventType == "R")
	{
		CargoType = events[EventLineNum][1];
		setEvent_Time(events[EventLineNum][2]);

		stringstream StringToIntConverter_CargoID(events[EventLineNum][3]);		// object from the class stringstream
		StringToIntConverter_CargoID >> CargoID;		// The object has the string numbers and stream it to the integer CargoID
		stringstream StringToIntConverter_CargoDistance(events[EventLineNum][4]);
		StringToIntConverter_CargoDistance >> CargoDistance;
		stringstream StringToIntConverter_CargoLoadTime(events[EventLineNum][5]);
		StringToIntConverter_CargoLoadTime >> CargoLoadTime;
		stringstream StringToIntConverter_CargoCost(events[EventLineNum][6]);
		StringToIntConverter_CargoCost >> CargoCost;
		
	}
	else if (EventType == "P")
	{
		setEvent_Time(events[EventLineNum][1]);
		stringstream StringToIntConverter_CargoID(events[EventLineNum][2]);
		StringToIntConverter_CargoID >> CargoID;
		stringstream StringToIntConverter_CargoExtraMoney(events[EventLineNum][3]);
		StringToIntConverter_CargoExtraMoney >> CargoExtraMoney;
	}
	else
	{
		setEvent_Time(events[EventLineNum][1]);
		stringstream StringToIntConverter_CargoID(events[EventLineNum][2]);
		StringToIntConverter_CargoID >> CargoID;
	}
}
