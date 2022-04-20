#include "MarsStation.h"

#include "..\Event\Event.h"
#include "..\Event\ReadyEvent.h"
#include "..\Event\CancellationEvent.h"
#include "..\Event\PromotionEvent.h"
//#include "..\Cargo\Cargo.h"
#include  <fstream>

//================================= CONSTRUCTOR / DESTRUCTOR / UI POINTER =================================

MarsStation::MarsStation()
{
	//Creates the UI Object & Initialize the UI
	pUI = new UI;
	ReadFile(pUI->getInput_File_Name());
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

	while (splitString.good()) 
	{
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
char MarsStation::getCargo_Type()
{
	return CargoType;
}
char MarsStation::getTruck_Type()
{
	return TruckType;
}
char MarsStation::getEvent_Type()
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


void MarsStation::ReadFile(string FileName)
{
	ifstream dataFile;	// File stream object


	if (openFileIn(dataFile, FileName) == false)
	{

	}
	else
	{
		setInt_Variables(dataFile);

		char EventType;
		string EventTime;

		while (!check_file_is_empty(dataFile))
		{
			dataFile >> EventType;
			if (EventType == 'R')
			{
				dataFile >> CargoType >> EventTime >> CargoID >> CargoDistance >> CargoLoadTime >> CargoCost;
				setEvent_Time(EventTime);
				//call function creat ready event that returns a pointer to this event to put it in the queue
				//enque this event in ready event
				//READY_Events.enqueue(Readyevent);
				//this function must be in run function when its time comes			//pReadyEvent->ReadyEvent(CargoType, EventTime[0], EventTime[1], CargoID, CargoDistance, CargoLoadTime, CargoCost);
		
			}
			else if (EventType == 'P')
			{
				dataFile >> EventTime >> CargoID >> CargoExtraMoney;
				setEvent_Time(EventTime);
				//pPromotionEvent->ReadyEvent(EventTime[0], EventTime[1], CargoID, CargoExtraMoney);
			}
			else if (EventType == 'X')
			{
				dataFile >> EventTime >> CargoID;
				setEvent_Time(EventTime);
				//pCancellationEvent->ReadyEvent(EventTime[0], EventTime[1], CargoID );
			}
			//save event in queue||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
		}

	}
}

void MarsStation::Enqueue_Events(char EventType, int EventDay, int EventHour)
{
	Events newEvent; //create event with the input values
	newEvent.EventType = EventType;
	newEvent.EventDay = EventDay;
	newEvent.EventHour = EventHour;
	EVENTS_List.enqueue(newEvent);	// then enque this event	
}

//=================================================== EVENTS =================================================
//selecting the Event to be excecuted

void MarsStation::ExecuteEvent(char eventt, Cargo* pCargo)
{
	int Eventtime_day = EventTime[1];
	int Eventtime_hour = EventTime[0];

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

void MarsStation::Run()
{
	bool state = true;
	while (state == true)
	{
		if (Clock[1] == 24)
		{
			Clock[0] = Clock[0] + 1;
			Clock[1] = 1;
		}

		///////run application

		Clock[1] = Clock[1] + 1;
	}
	if (pUI->GetAppMode() == 2)
		pUI->Start_silent_Mode();
}