#pragma once
enum TYP
{
	NORMAL,
	SPECIAL,
	VIP
};

enum Status
{
	MOVING,
	WAITING,
	LOADED,
	MAINTANANCE
};

enum  MODE	//Modes of operation
{
	interactive,
	step_by_step,
	silent
};

enum Error
{
	error_Open_inputFile,
	error_Print_OutputFile
};

//enum OutputType
//{
//	Waiting_Cargos,
//	Loading_Trucks,
//	Empty_Trucks,
//	Moving_Cargos,
//	In_CheckUp_Trucks,
//	Delivered_Cargos
//};