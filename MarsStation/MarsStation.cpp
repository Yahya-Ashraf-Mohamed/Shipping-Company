#include "MarsStation.h"

//#include "..\Event\Event.h"
#include "..\Event\ReadyEvent.h"
#include "..\Event\CancellationEvent.h"
//#include "..\Event\PromotionEvent.h"

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
		delete pUI;
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
	initiate_Autop(AutoPromotion);
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
	/*ReadyEvent Revent(this);
	Revent.setAutoP(AutoPromotion);*/

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
			//TYP CargoT = NORMAL;
			if (EventType == 'R')
			{
				dataFile >> CargoType >> ETime >> CargoID >> CargoDistance >> CargoLoadTime >> CargoCost;
				setEvent_Time(ETime);

				addReadyEvent(EventTime[0], EventTime[1], CargoType, CargoDistance, CargoLoadTime, CargoID, CargoCost);
		
			}
			else if (EventType == 'P')
			{
				dataFile >> ETime >> CargoID >> CargoExtraMoney;
				setEvent_Time(ETime);
				addPromotionEvent(EventTime[0], EventTime[1], CargoID, CargoExtraMoney);
			}
			else if (EventType == 'X')
			{
				dataFile >> ETime >> CargoID;
				setEvent_Time(ETime);
				addCancellationEvent(EventTime[0], EventTime[1], CargoID);
			}
		}

	}

	Create_Normal_Truck();
	Create_VIP_Truck();
	Create_Special_Truck();

	dataFile.close();		//close input file
}

void MarsStation::Create_Normal_Truck()
{
	for (int i = 1; i < no_Normal + 1; i++)
	{
		Truck* t = new Truck(NORMAL, i, Normal_speed, CheckUp_Journeys, Normal_capacity, Normal_CheckUp_duration);
		Waiting_NORMAL_Truck.enqueue(t);
	}
}

void MarsStation::Create_Special_Truck()
{
	for (int i = 1; i < no_Special + 1; i++)
	{
		Truck* t = new Truck(SPECIAL, i, Normal_speed, CheckUp_Journeys, Normal_capacity, Normal_CheckUp_duration);
		Waiting_SPECIAL_Truck.enqueue(t);
	}
}

void MarsStation::Create_VIP_Truck()
{
	for (int i = 1; i < no_VIP + 1; i++)
	{
		Truck* t = new Truck(VIP, i, Normal_speed, CheckUp_Journeys, Normal_capacity, Normal_CheckUp_duration);
		Waiting_VIP_Truck.enqueue(t);
	}
}

bool MarsStation::Create_Output_File(string outputFileName)		//to be completed after events
{

	OutPutFile.open(outputFileName);	// Create and Open output file

	OutPutFile << "CDT\t ID\t PT\t WT\t TID\t" << endl;
	//for loop on cargoDlivered list
	//OutPutFile << "Day:Time" << "\t " << "ID" << "\t " << "Prepartiontime" << "\t " << "WaitTime" << "\t " << "TruckID"<< endl;

	//OutPutFile << "..........................................................................." << endl;
	//OutPutFile << "..........................................................................." << endl;
	//OutPutFile << "Cargos: " << /*<<total cargo count <<*/ "[N: " << /*get delevered normal count<<*/ ", S: " << /*get delevered Special count<<*/ ", V: "/*get delevered Vip count<< endl*/;
	//OutPutFile << "Cargo Avg Wait = " << /*get Averg wait time<<*/  endl;
	//OutPutFile << "Auto-promoted Cargos: " << /*get % promoted cargo<<*/ "%" << endl;
	//OutPutFile << "Trucks: " << /*get munber of trucks<<*/"[N: " << /*get delevered normal count<<*/ ", S: " << /*get delevered Special count<<*/ ", V: "/*get delevered Vip count<<*/ << endl;
	//OutPutFile << "Avg Active time = 91%" << endl;
	//OutPutFile << "Avg utilization = 87%" << endl;

//	OutPutFile.close();

	return true;
}

//need implementation
void MarsStation::Excute_Output_File(string outputFileName)
{
	//OutPutFile.open(outputFileName);	// Create and Open output file

	Cargo* nextCargo;
	while (Delivered_Cargo.peek(nextCargo))
	{
		Delivered_Cargo.dequeue(nextCargo);
		OutPutFile << nextCargo->get_Delivery_time()[0] << ":" << nextCargo->get_Delivery_time()[1] << "\t"
				   << nextCargo->getCargoID() << "\t"
				   << nextCargo->get_ReadyEvent_time()[0] << ":" << nextCargo->get_ReadyEvent_time()[1]
				   << /*to be edited in phase 2*/ nextCargo->get_Delivery_time()[0] - nextCargo->get_ReadyEvent_time()[0] << ":" << nextCargo->get_Delivery_time()[1] - nextCargo->get_ReadyEvent_time()[1]
				   << endl;		
	}

//	OutPutFile.close();
	
}

void MarsStation::Analysis_Output_File(string outputFileName)
{
//	OutPutFile.open(outputFileName);	// Create and Open output file

	OutPutFile << "..........................................................................." << endl;
	OutPutFile << "..........................................................................." << endl;
	OutPutFile << "Cargos: " << (VIP_Cargo_count + Special_Cargo_count + Normal_Cargo_count)
		       << "[N: " << Normal_Cargo_count
			   << ", S: " << Special_Cargo_count
			   << ", V: " << VIP_Cargo_count << "]" << endl;
	//OutPutFile << "Cargo Avg Wait = " << /*get Averg wait time<<*/  endl;
	OutPutFile << "Auto-promoted Cargos: " << (AutoP_Count / (VIP_Cargo_count + Special_Cargo_count + Normal_Cargo_count)) * 100 << "%" << endl;
	//OutPutFile << "Trucks: " << /*get munber of trucks<<*/"[N: " << /*get delevered normal count<<*/ ", S: " << /*get delevered Special count<<*/ ", V: "/*get delevered Vip count<<*/ << endl;
	//OutPutFile << "Avg Active time = 91%" << endl;
	//OutPutFile << "Avg utilization = 87%" << endl;

	OutPutFile.close();

}

//void MarsStation::Enqueue_Events(char EventType, int EventDay, int EventHour) deleted struct
//{
//	Events newEvent; //create event with the input values
//	newEvent.EventType = EventType;
//	newEvent.EventDay = EventDay;
//	newEvent.EventHour = EventHour;
//	EVENTS_List.enqueue(newEvent);	// then enque this event	
//}


//=================================================== LOAD ==================================================

bool MarsStation::LoadingRule(Truck* ptruck, TYP CargoType)
{
	int TruckCapacity = ptruck->getTruckCapacity();

	switch (CargoType)
	{
	case VIP:
		if (VIP_Cargo.getSize() >= TruckCapacity)
			return true;
		break;
	case SPECIAL:
		if (Special_Cargo.getSize() >= TruckCapacity)
			return true;
		break;
	case NORMAL:
		if (Normal_Cargo.getSize() >= TruckCapacity)
			return true;
		break;
	}
	return false;
}

//=================================================== EVENTS =================================================

	//Add Cargo to Cargo Queue depending on it's type
	void MarsStation::AddCargo(Cargo* pCargo, TYP CargoType)
{
	switch (CargoType)
	{
	case VIP:
		VIP_Cargo.enqueue(pCargo); 
		VIP_Cargo_count++;
		VIP_Cargo_Size++;
		break;
	case SPECIAL:
		Special_Cargo.enqueue(pCargo);
		Special_Cargo_count++;
		Special_Cargo_Size++;
		break;
	case NORMAL:
		Normal_Cargo.enqueue(pCargo);
		Normal_Cargo_count++;
		Normal_Cargo_Size++;
		break;
	}
}

	//Promote normal cargo to VIP cargoes and returns pointer to the promoted Cargo
	Cargo* MarsStation::PromoteCargo(int cargo_id)
	{
		Cargo* pCargo = Normal_Cargo.RemoveNode(cargo_id);
		if (pCargo)
		{
			Normal_Cargo_count--;
			Normal_Cargo_Size--;
			VIP_Cargo.enqueue(pCargo);
			VIP_Cargo_count++;
			VIP_Cargo_Size++;
		}
		return pCargo;
	}

	//Cancel Cargo
	void MarsStation::CancelCargo(int cargo_id)
	{
		Cargo* pCargo = Normal_Cargo.RemoveNode(cargo_id);
		if (pCargo)
		{
			Normal_Cargo_count--;
			Normal_Cargo_Size--;
			delete pCargo;
		}
	}

	//create Ready event then adds it to the Event queue 
	void MarsStation::addReadyEvent(int Eventtime_day, int Eventtime_hour, char type, double distance, int LoadTime, int id, float Cost)
	{
		ReadyEvent* p = new ReadyEvent(this, Eventtime_day, Eventtime_hour, type, distance, LoadTime, id, Cost);
		EVENT.enqueue(p);
	}

	//create Promotion event then adds it to the Event queue and returns the pointer 
	PromotionEvent* MarsStation::addPromotionEvent(int Eventtime_day, int Eventtime_hour, int id, int Extra_Money)
	{
		PromotionEvent* p = new PromotionEvent(this , Eventtime_day, Eventtime_hour, id, Extra_Money);
		EVENT.enqueue(p);
		return p;
	}

	//set Autop to its value in ready event
	void MarsStation::initiate_Autop(int value)
	{
		ReadyEvent::setAutoP(value);
	}

	//increments autop count
	void MarsStation::Autop_Count_increment()
	{
		AutoP_Count ++;
	}

	//create Cancellation event then adds it to the Event queue 
	void MarsStation::addCancellationEvent( int Eventtime_day, int Eventtime_hour, int id)
	{
		CancellationEvent* p = new CancellationEvent(this, Eventtime_day, Eventtime_hour, id);
		EVENT.enqueue(p);
	}

//======================================================== UI Function ============================================//
	void MarsStation::Show_State(int Days, int Hours)
	{
		pUI->Show_State(Days, Hours);
		Show_Waiting_Cargos();
		Show_Loading_Trucks();
		Show_Empty_Trucks();
		Show_Moving_Cargos();
		Show_In_CheckUp_Trucks();
		Show_Delivered_Cargos();
		cout << endl;
	}

	void MarsStation::Show_Waiting_Cargos()
	{
		cout << (VIP_Cargo_Size + Special_Cargo_Size + Normal_Cargo_Size) << " Waiting Cargos: [";
		//VIP_Cargo.getSize() + Special_Cargo.getSize() + Normal_Cargo.getSize()
		Normal_Cargo.PrintList();
			 
		cout << "] (";
		
		Special_Cargo.Display();

		cout << ") {";

		VIP_Cargo.Display();
		
		cout << "}" << endl;
	}

	void MarsStation::Show_Loading_Trucks()
	{
	}

	void MarsStation::Show_Empty_Trucks()
	{
	}

	void MarsStation::Show_Moving_Cargos()
	{
	}

	void MarsStation::Show_In_CheckUp_Trucks()
	{
	}

	void MarsStation::Show_Delivered_Cargos()
	{	
		cout << Delivered_Cargo_Count << " Delivered Cargos: ";
		
		Delivered_Cargo.Display();

	}


//=================================================== Input Functions =================================================



	void MarsStation::Run()
	{

		Create_Output_File(pUI->getOutput_File_Name());

		pUI->Start_Simulation();

		while (EVENT.isEmpty() == false || (VIP_Cargo.isEmpty() == false || Normal_Cargo.isEmpty() == false || Special_Cargo.isEmpty() == false))
		{

			//Added by Yahya new
			//=====================================================================================================================================================

		//================================================================= ALL DAY ===========================================================================


			if (Waiting_VIP_Truck.isEmpty() == false)			// Check If VIP truck want to go to MAINTANANCE
			{
				Truck* VIP_Truck;

				while (Waiting_VIP_Truck.peek(VIP_Truck))
				{
					if (VIP_Truck->get_Num_Of_Journeys() < this->CheckUp_Journeys)
						break;
					else
					{
						VIP_Truck->set_Num_Of_Journeys(this->CheckUp_Journeys);		//reset the number of journeys done

						// for bonus if we load cargo imediatly so we have to check if it was empty
						// else deload first and save deload time then move it to MAINTANANCE

						Waiting_VIP_Truck.dequeue(VIP_Truck);
						MAINTANANCE_VIP_Truck.enqueue(VIP_Truck);

						this->Calculate_Truck_Time_Wait_to_Maintanance(VIP_Truck);
					}
				}
			}

			if (Waiting_NORMAL_Truck.isEmpty() == false)			// Check If Normal truck want to go to MAINTANANCE
			{
				Truck* Normal_Truck;

				while (Waiting_NORMAL_Truck.peek(Normal_Truck))
				{
					if (Normal_Truck->get_Num_Of_Journeys() < this->CheckUp_Journeys)
						break;
					else
					{
						Normal_Truck->set_Num_Of_Journeys(this->CheckUp_Journeys);

						// for bonus if we load cargo imediatly so we have to check if it was empty
						// else deload first and save deload time then move it to MAINTANANCE

						Waiting_NORMAL_Truck.dequeue(Normal_Truck);
						MAINTANANCE_Normal_Truck.enqueue(Normal_Truck);

						this->Calculate_Truck_Time_Wait_to_Maintanance(Normal_Truck);

					}
				}
			}

			if (Waiting_SPECIAL_Truck.isEmpty() == false)			// Check If Special truck want to go to MAINTANANCE
			{
				Truck* Special_Truck;

				while (Waiting_SPECIAL_Truck.peek(Special_Truck))
				{
					if (Special_Truck->get_Num_Of_Journeys() < this->CheckUp_Journeys)
						break;
					else
					{
						Special_Truck->set_Num_Of_Journeys(this->CheckUp_Journeys);

						// for bonus if we load cargo imediatly so we have to check if it was empty
						// else deload first and save deload time then move it to MAINTANANCE

						Waiting_SPECIAL_Truck.dequeue(Special_Truck);
						MAINTANANCE_Special_Truck.enqueue(Special_Truck);

						this->Calculate_Truck_Time_Wait_to_Maintanance(Special_Truck);

					}
				}
			}


			if (MAINTANANCE_VIP_Truck.isEmpty() == false)		// Check If VIP truck Finished MAINTANANCE
			{
				Truck* VIP_Truck;
				while (MAINTANANCE_VIP_Truck.peek(VIP_Truck))
				{
					if (VIP_Truck->get_End_Maintanance_Time()[0] != Clock[0] || VIP_Truck->get_End_Maintanance_Time()[1] != Clock[1])
						break;
					else
					{
						MAINTANANCE_VIP_Truck.dequeue(VIP_Truck);
						Waiting_VIP_Truck.enqueue(VIP_Truck);
						VIP_Truck->set_Truck_ActiveTime(Clock);
					}
				}
			}


			if (MAINTANANCE_Special_Truck.isEmpty() == false)		// Check If Special truck Finished MAINTANANCE
			{
				Truck* Special_Truck;
				while (MAINTANANCE_Special_Truck.peek(Special_Truck))
				{
					if (Special_Truck->get_End_Maintanance_Time()[0] != Clock[0] || Special_Truck->get_End_Maintanance_Time()[1] != Clock[1])
						break;
					else
					{
						MAINTANANCE_Special_Truck.dequeue(Special_Truck);
						Waiting_SPECIAL_Truck.enqueue(Special_Truck);
						Special_Truck->set_Truck_ActiveTime(Clock);
					}
				}
			}



			if (MAINTANANCE_Normal_Truck.isEmpty() == false)		// Check If Normal truck Finished MAINTANANCE
			{
				Truck* Normal_Truck;
				while (MAINTANANCE_Normal_Truck.peek(Normal_Truck))
				{
					if (Normal_Truck->get_End_Maintanance_Time()[0] != Clock[0] || Normal_Truck->get_End_Maintanance_Time()[1] != Clock[1])
						break;
					else
					{
						MAINTANANCE_Normal_Truck.dequeue(Normal_Truck);
						Waiting_NORMAL_Truck.enqueue(Normal_Truck);
						Normal_Truck->set_Truck_ActiveTime(Clock);
					}
				}
			}



			//================================================================= DURING WORKING HOURS =============================================================		



			if (Clock[1] > 4 && Clock[1] < 24)
			{
				if (EVENT.isEmpty() == false)		// Excute the next event when its time comes 
				{
					Event* nextEvent;

					while (EVENT.peek(nextEvent))
					{
						if (nextEvent->get_Event_time()[0] == Clock[0] && nextEvent->get_Event_time()[1] == Clock[1])
						{
							EVENT.dequeue(nextEvent);
							nextEvent->Execute();
						}
						else
							break;
					}
				}

				//@yasmeen now we have cargos created and stored in waiting list 
				// you have to   
				//Load VIP Cargos @Yasmeen  by moving cargo from waiting to loading when its time comes so you load one by one

				//Load normal Cargos @Yasmeen  by moving cargo from waiting to loading when its time comes

				//Load special Cargos @Yasmeen  by moving cargo from waiting to loading when its time comes



				// for bonus we have to load instantinously after creating the cargo so the header of the following if condition will be removed
				// --> if (Loading_VIP_Cargo.getSize() > this->VIP_capacity - 1)

				if (Loading_VIP_Cargo.getSize() > 0)		// After loading complete the cargos moves into the truck (stack) to be delivered
				{
					Cargo* Cargo;
					Truck* Truck;

					if (Waiting_VIP_Truck.isEmpty() == false)
					{
						Waiting_VIP_Truck.dequeue(Truck);
						Truck->LoadCargo(Loading_VIP_Cargo);
						Loading_trucks[0] = Truck;							//@yahya not the best idea but it is good for now.
					}

					// @Mariam Check for max waiting rule to make the following code
					else if (Waiting_NORMAL_Truck.isEmpty() == false)
					{
						Waiting_NORMAL_Truck.dequeue(Truck);
						Truck->LoadCargo(Loading_VIP_Cargo);		//@yasmeen please make sure that normal truck carry VIP cargo 
						Loading_trucks[1] = Truck;
					}

					// @Mariam Check for max waiting rule to make the following code
					else if (Waiting_SPECIAL_Truck.isEmpty() == false)
					{
						Waiting_SPECIAL_Truck.dequeue(Truck);
						Truck->LoadCargo(Loading_VIP_Cargo);		//@yasmeen please make sure that Special truck carry VIP cargo
						Loading_trucks[2] = Truck;
					}
				}


				if (Loading_Special_Cargo.getSize() > 0)		// After loading complete the cargos moves into the truck (stack) to be delivered
				{
					Cargo* Cargo;
					Truck* Truck;

					if (Waiting_SPECIAL_Truck.isEmpty() == false)
					{
						Waiting_SPECIAL_Truck.dequeue(Truck);
						Truck->LoadCargo(Loading_Special_Cargo);
						Loading_trucks[2] = Truck;
					}
				}

				if (Loading_Normal_Cargo.getSize() > 0)		// After loading complete the cargos moves into the truck (stack) to be delivered
				{
					Cargo* Cargo;
					Truck* Truck;

					if (Waiting_NORMAL_Truck.isEmpty() == false)
					{
						Waiting_NORMAL_Truck.dequeue(Truck);
						Truck->LoadCargo(Loading_Normal_Cargo);
						Loading_trucks[1] = Truck;
					}

					// @Mariam Check for max waiting rule to make the following code

					else if (Waiting_VIP_Truck.isEmpty() == false)
					{
						Waiting_VIP_Truck.dequeue(Truck);
						Truck->LoadCargo(Loading_Normal_Cargo);
						Loading_trucks[0] = Truck;
					}
				}

				for (int i = 0; i > 3; i++)
				{
					if (Loading_trucks[i] != nullptr)
					{
						MOVING_Truck.enqueue(Loading_trucks[i]);

					}
				}





			}
			//================================================================= DURING OFF HOURS =============================================================		













			//================================================================== RESULTS ================================================================


					//add colock +1 , check if off hours 


			switch (pUI->GetAppMode())
			{
			case interactive:
				Show_State(Clock[0], Clock[1]);
				system("pause");		// press any key to continue
				//pUI->Start_interactive_Mode(Clock[0], Clock[1]);
				break;
			case step_by_step:
				Show_State(Clock[0], Clock[1]);
				Sleep(1000);
				//pUI->Start_step_by_step_Mode(Clock[0], Clock[1]);
				break;
				//case silent:
				//	pUI->Start_silent_Mode();
				//	break;
			}




			Excute_Output_File(pUI->getOutput_File_Name());
			Analysis_Output_File(pUI->getOutput_File_Name());
			pUI->End_Simulation(pUI->getOutput_File_Name());







			//===========================================================================DELETED=============================================
			

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



			if (Clock[1] % 5 == 0 && (Clock[1] > 6 || Clock[0] > 0)) // && Clock[0] != 0
			{

				Cargo* deliveredCargo;

				if (VIP_Cargo.dequeue(deliveredCargo) != false)
				{
					deliveredCargo->set_Delivery_time(Clock);
					Delivered_Cargo.enqueue(deliveredCargo);
					VIP_Cargo_Size = VIP_Cargo_Size - 1;
					Delivered_Cargo_Count = Delivered_Cargo_Count + 1;
				}

				if (Special_Cargo.dequeue(deliveredCargo) != false)
				{
					deliveredCargo->set_Delivery_time(Clock);
					Delivered_Cargo.enqueue(deliveredCargo);
					Special_Cargo_Size = Special_Cargo_Size - 1;
					Delivered_Cargo_Count = Delivered_Cargo_Count + 1;
				}

				if (Normal_Cargo.dequeue(deliveredCargo) != false)
				{
					deliveredCargo->set_Delivery_time(Clock);
					Delivered_Cargo.enqueue(deliveredCargo);
					Normal_Cargo_Size = Normal_Cargo_Size - 1;
					Delivered_Cargo_Count = Delivered_Cargo_Count + 1;
				}
			}

		}

		switch (pUI->GetAppMode())
		{
		case interactive:
			Show_State(Clock[0], Clock[1]);
			system("pause");		// press any key to continue
			//pUI->Start_interactive_Mode(Clock[0], Clock[1]);
			break;
		case step_by_step:
			Show_State(Clock[0], Clock[1]);
			Sleep(1000);
			//pUI->Start_step_by_step_Mode(Clock[0], Clock[1]);
			break;
			//case silent:
			//	pUI->Start_silent_Mode();
			//	break;
		}


		Clock[1] = Clock[1] + 1;


		///////run application



		/*if (EVENTS_List.getCount() == 0)
		{
			if (Excute_Output_File() == false)
				pUI->Show_Error(error_Print_OutputFile);
			state = false;
		}*/



		/*if (EVENTS_List.isEmpty())
			break;*/

			//Clock[1] = Clock[1] + 1;

		if (Clock[1] == 25)
		{
			Clock[0] = Clock[0] + 1;
			Clock[1] = 1;
		}

		Excute_Output_File(pUI->getOutput_File_Name());


		// check that all queues are empty except delivered cargoes and waiting trucks
		//Cargo* nextCargo;
		//while (Delivered_Cargo.peek(nextCargo))
		//{
		//	Delivered_Cargo.dequeue(nextCargo);
		//	Excute_Output_File();
		//}
		Analysis_Output_File(pUI->getOutput_File_Name());
		pUI->End_Simulation(pUI->getOutput_File_Name());
	}

	//Queue<Cargo*> MarsStation::getVIP_Cargo() { return VIP_Cargo; }
	//Queue<Cargo*> MarsStation::getSpecial_Cargo() { return Special_Cargo; }
	//LinkedList MarsStation::getNormal_Cargo() { return Normal_Cargo; }
	//PriorityQueue<Cargo*> MarsStation::getDelivered_Cargo() { return Delivered_Cargo; }
	//=======================================================================================================================================================================




	//===================================== Functions of Run Function ===============================================
	void MarsStation::Calculate_Truck_Time_Wait_to_Maintanance(Truck* truck)
	{
		truck->set_End_Maintanance_Time(Clock);


		int* Stop_Active_Time = new int[2];
		Stop_Active_Time = truck->get_Truck_ActiveTime();

		int* diffActiveTime = new int[2];

		if (Stop_Active_Time[1] > Clock[1])
		{
			diffActiveTime[1] = 24 - Stop_Active_Time[1] + Clock[1];
			if (diffActiveTime[1] > 24)
			{
				diffActiveTime[1] = diffActiveTime[1] - 24;
				diffActiveTime[0] = Clock[0] - (Stop_Active_Time[0] + 1);
				diffActiveTime[0] = diffActiveTime[0] + 1;
			}
			else
				diffActiveTime[0] = Clock[0] - (Stop_Active_Time[0] + 1);
		}
		else
		{
			diffActiveTime[0] = Clock[0] - Stop_Active_Time[0];
			diffActiveTime[1] = Clock[1] - Stop_Active_Time[1];
		}


		truck->set_Truck_Total_Active_Time(diffActiveTime);

	}