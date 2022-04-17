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


void UI::Start_silent_Mode()
{
	cout << "Simulation Starts...";
}

void UI::End_silent_Mode()
{
	cout << "Simulation ends, Output file created with name \"Output.txt\". ";
}

void UI::Start_step_by_step_Mode(int Days, int Hours)//to be continued ) //input: time h, time day
{
	cout << "Current Time (Day:Hour):- " << Days << ":" << Hours << endl;

	//enum OutputType  I was thinking about it
	//{
	//	Waiting_Cargos,
	//	Loading_Trucks,
	//	Empty_Trucks,
	//	Moving_Cargos,
	//	In_CheckUp_Trucks,
	//	Delivered_Cargos
	//};

}

void UI::Start_interactive_Mode(int Days, int Hours)//to be continued ) //input: time h, time day
{
	cout << "Current Time (Day:Hour):- " << Days << ":" << Hours << endl;
}

UI::~UI(){}
