#include "UI.h"
#include <string>
using namespace std;


UI::UI()
{
	AppMode = silent;	//Design Mode is the startup mode

}

// Function set App mode interactive or step_by_step or silent
void UI::SetAppMode(MODE mode)
{
	AppMode = mode;
}


// Function get App mode interactive or step_by_step or silent
MODE UI::GetAppMode()const
{
	return AppMode;
}

//ostream UI::Start_silent_Mode()
//{
////	cout << "Silent Mode\n" << "Si";
//}