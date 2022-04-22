#include "UI.h"


UI::UI()
{
	startAPP();
}


void UI::startAPP()
{
	cout << "\t\t\t\t===================================================" << endl;
	cout << "\t\t\t\t||	  WELCOME TO SHIPPING COMPANY APP	  ||" << endl;
	cout << "\t\t\t\t===================================================" << endl;

	cout << endl << endl;
	while (true)
	{
		cout << "Enter Input file name: ";
		cin >> this->inputFileName;
	
		cout << "Enter Output file name: ";
		cin >> this->outputFileName;

		if (this->inputFileName != " ")
			break;
		else
			cout << "Error! Please enter a valid name ex: Name.txt" << endl;
	}
	cout << "Choose Mood:-   1)Interactive moode" << endl;
	cout << "		2)Step by step mood" << endl;
	cout << "		3)Silent mood" << endl;
	
	int mood;
	while (true)
	{
		cout << "Mood: ";
		cin >> mood;

		if (mood == 1)
		{
			this->AppMode = interactive;
			cout << endl << "Starting Interactive mood..." << endl;
			break;
		}
		else if (mood == 2)
		{
			this->AppMode = step_by_step;
			cout << endl << "Starting Step by step mood..." << endl;
			break;
		}
		else if (mood == 3)
		{
			this->AppMode = silent;
			cout << endl << "Starting silent mood..." << endl;
			break;
		}
		else
			cout << "Error! Please enter a valid number from 1 -> 3" << endl;
	}

}


// Function get App mode interactive or step_by_step or silent
MODE UI::GetAppMode()const
{
	return AppMode;
}

string UI::getInput_File_Name()
{
	return inputFileName;
}

string UI::getOutput_File_Name()
{
	return outputFileName;
}

void UI::Start_silent_Mode()
{
	cout << "Simulation Starts...";
}

void UI::End_Simulation(string outputFileName)
{
	cout << "Simulation ends, Output file created with name \""<< outputFileName<< "\". ";
}

void UI::Start_step_by_step_Mode(int Days, int Hours)//to be continued ) //input: time h, time day
{
	cout << "Simulation Starts..." << endl;
	cout << "Current Time (Day:Hour):- " << Days << ":" << Hours << endl;
}

void UI::Start_interactive_Mode(int Days, int Hours)//to be continued ) //input: time h, time day
{
	cout << "Simulation Starts..." << endl;
	cout << "Current Time (Day:Hour):- " << Days << ":" << Hours << endl;
}
//
//void UI::Show_State()
//{
//	Show_Waiting_Cargos();
//	Show_Loading_Trucks();
//	Show_Empty_Trucks();
//	Show_Moving_Cargos();
//	Show_In_CheckUp_Trucks();
//	Show_Delivered_Cargos();
//}
//
//void UI::Show_Waiting_Cargos()
//{	
//	//cout << /*pStation->getVIP_Cargo().getCount() << */" Waiting Cargos: [" << /*pStation->getNormal_Cargo().PrintInfo() << */"] ("
//	//	<< /*pStation->getSpecial_Cargo().PrintInfo() << */ ") {" << /*pStation->getVIP_Cargo().PrintInfo() << */ "}";
//}
//
//void UI::Show_Loading_Trucks()
//{
//}
//
//void UI::Show_Empty_Trucks()
//{
//}
//
//void UI::Show_Moving_Cargos()
//{
//}
//
//void UI::Show_In_CheckUp_Trucks()
//{
//}
//
//void UI::Show_Delivered_Cargos()
//{
//
//	//cout << /*pStation->getVIP_Cargo().getCount() << */" Waiting Cargos: [" << /*pStation->getNormal_Cargo().PrintInfo() << */"] ("
//	//	<< /*pStation->getSpecial_Cargo().PrintInfo() << */ ") {" << /*pStation->getVIP_Cargo().PrintInfo() << */ "}";
//
//}


void UI::Show_Error(Error ErrorType)
{
	switch (ErrorType)
	{
	case(error_Open_inputFile):
		cout << "Error in openning input file!" << endl;
		break;
	case(error_Print_OutputFile):
		cout << "Error in executing output file!" << endl;
		break;
		//to be completed
	}
}

UI::~UI(){}
