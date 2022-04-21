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
	//Run();
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
		pUI->Show_Error(error_Open_inputFile);
	}
	else
	{
		setInt_Variables(dataFile);

		char EventType;
		string ETime;

		while (!check_file_is_empty(dataFile))
		{
			dataFile >> EventType;
			if (EventType == 'R')
			{
				dataFile >> CargoType >> ETime >> CargoID >> CargoDistance >> CargoLoadTime >> CargoCost;
				setEvent_Time(ETime);

				//addReadyEvent(EventTime[0], EventTime[1], CargoType, CargoDistance, CargoLoadTime, CargoID, CargoCost);
		
			}
			else if (EventType == 'P')
			{
				dataFile >> ETime >> CargoID >> CargoExtraMoney;
				setEvent_Time(ETime);
				// PromotionEvent* pPromotionEvent (EventTime[0], EventTime[1]);
				// pPromotionEvent->Promote(CargoID, CargoExtraMoney);
				// PROMOTED_Events.enqueue(pPromotionEvent);
				

				//pPromotionEvent->ReadyEvent(EventTime[0], EventTime[1], CargoID, CargoExtraMoney);  XXXXX wrong!
			}
			else if (EventType == 'X')
			{
				dataFile >> ETime >> CargoID;
				setEvent_Time(ETime);
				// CancellationEvent* pCancellationEvent (EventTime[0], EventTime[1]);
				// pCancellationEvent->Cancel(CargoID);
				// CANCELLED_Events.enqueue(pCancellationEvent);
				

				//pCancellationEvent->ReadyEvent(EventTime[0], EventTime[1], CargoID );
			}

			//Enqueue_Events(EventType, EventTime[0], EventTime[1]);		//save event in EventList queue		
		}

	}
	dataFile.close();		//close input file
}

bool MarsStation::Excute_Output_File()		//to be completed after events
{
	ofstream OutPutFile;
	OutPutFile.open("Report.txt");	// Create and Open output file

	OutPutFile << "CDT\t ID\t PT\t WT\t TID\t" << endl;
	//for loop on cargoDlivered list
	//OutPutFile << "Day:Time" << "\t " << "ID" << "\t " << "Prepartiontime" << "\t " << "WaitTime" << "\t " << "TruckID"<< endl;

	OutPutFile << "..........................................................................." << endl;
	OutPutFile << "..........................................................................." << endl;
	OutPutFile << "Cargos: " << /*<<total cargo count <<*/ "[N: " << /*get delevered normal count<<*/ ", S: " << /*get delevered Special count<<*/ ", V: "/*get delevered Vip count<< endl*/;
	OutPutFile << "Cargo Avg Wait = " << /*get Averg wait time<<*/  endl;
	OutPutFile << "Auto-promoted Cargos: " << /*get % promoted cargo<<*/ "%" << endl;
	OutPutFile << "Trucks: " << /*get munber of trucks<<*/"[N: " << /*get delevered normal count<<*/ ", S: " << /*get delevered Special count<<*/ ", V: "/*get delevered Vip count<<*/ << endl;
	OutPutFile << "Avg Active time = 91%" << endl;
	OutPutFile << "Avg utilization = 87%" << endl;

	OutPutFile.close();

	return true;
}

//void MarsStation::Enqueue_Events(char EventType, int EventDay, int EventHour)
//{
//	Events newEvent; //create event with the input values
//	newEvent.EventType = EventType;
//	newEvent.EventDay = EventDay;
//	newEvent.EventHour = EventHour;
//	EVENTS_List.enqueue(newEvent);	// then enque this event	
//}

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
		Special_Cargo.enqueue(pCargo);
		break;
	case NORMAL:
		Normal_Cargo.enqueue(pCargo);
		break;
	}
}

void MarsStation::Run()
{	
	switch (pUI->GetAppMode())
	{
	//case interactive:
	//	pUI->Start_interactive_Mode();
	//	break;
	//case step_by_step:
	//	pUI->Start_step_by_step_Mode();
	//	break;
	case silent:
		pUI->Start_silent_Mode();
		break;
	}

	while (/*EVENT.isEmpty()==false*/true)
	{
		// Off Hours
		while (MAINTANANCE_VIP_Truck.isEmpty() == false)		//check on manintenance of VIP truck list
		{
			Truck* VIP_Truck;
			while (MAINTANANCE_VIP_Truck.peek(VIP_Truck))
			{

				//if(VIP_Truck->getMAINTANANCE_Start_Time_Hour + VIP_CheckUp_duration >= Clock[1] && VIP_Truck->getMAINTANANCE_Start_Time_day + VIP_CheckUp_duration >= Clock[0])
				//{
					//MAINTANANCE_VIP_Truck.dequeue(VIP_Truck);
					//Waiting_VIP_Truck.enqueue(VIP_Truck);
				//}
				//else
					//break;
			}
		}
		while (MAINTANANCE_Normal_Truck.isEmpty() == false)		//check on manintenance of Normal truck list
		{
			Truck* Normal_Truck;
			while (MAINTANANCE_Normal_Truck.peek(Normal_Truck))
			{

				//if(Normal_Truck->getMAINTANANCE_Start_Time_Hour + VIP_CheckUp_duration >= Clock[1] && Normal_Truck->getMAINTANANCE_Start_Time_day + VIP_CheckUp_duration >= Clock[0])
				//{
					//MAINTANANCE_VIP_Truck.dequeue(Normal_Truck);
					//Waiting_VIP_Truck.enqueue(Normal_Truck);
				//}
				//else
					//break;
			}
		}
		while (MAINTANANCE_Special_Truck.isEmpty() == false)		//check on manintenance of Special truck list
		{
			Truck* Special_Truck;
			while (MAINTANANCE_Special_Truck.peek(Special_Truck))
			{

				//if(Special_Truck->getMAINTANANCE_Start_Time_Hour + VIP_CheckUp_duration >= Clock[1] && Special_Truck->getMAINTANANCE_Start_Time_day + VIP_CheckUp_duration >= Clock[0])
				//{
					//MAINTANANCE_VIP_Truck.dequeue(Special_Truck);
					//Waiting_VIP_Truck.enqueue(Special_Truck);
				//}
				//else
					//break;
			}
		}

		//calculations like distance, time, truck utilization,.........
		
		//while (MOVING_Truck.isEmpty() == false)
		//{
		// Truck* MovingTruck;
			//while (MOVING_Truck.peek(MovingTruck))  //priority queue moving truck dequeue if (the time for deliviring last cargo comes)
			// {
				// for (int i = 0; i < truck capacity, i++)
				//	{
				//		pop cargo from stack
				//		enque the cargo into the delivered cargo queue
				//		truck order = order +1;
				//	}
				// dequeue this truck
				// if (truck->no.jurney exeeded )
				//		enqueue in maintenance truck list
				// else
				//		enque in waiting truck
			// }
		//}



		if (Clock[1] < 5 && Clock[1] > 23)		//working hours
		{
			//if (dequeue event from EventList is == R)
			//{
			//	
			//}
			//else if (dequeue event from EventList is == P)
			//{
			// 
			//}
			//else	if (dequeue event from EventList is == X)
			//{
			// 
			//}
		}

		///////run application



		Clock[1] = Clock[1] + 1;
		/*if (EVENTS_List.getCount() == 0)
		{
			if (Excute_Output_File() == false)
				pUI->Show_Error(error_Print_OutputFile);
			state = false;
		}*/


		switch (pUI->GetAppMode())
		{
			//case interactive:
			//	pUI->Start_interactive_Mode();
			//	break;
			//case step_by_step:
			//	pUI->Start_step_by_step_Mode();
			//	break;
		case silent:
			pUI->End_silent_Mode();
			break;
		}


		/*if (EVENTS_List.isEmpty())
			break;*/
	}

	// check that all queues are empty except delivered cargoes and waiting trucks
}