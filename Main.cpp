#pragma once
#include <iostream>
#include <string>
using namespace std;

#include"MarsStation/MarsStation.h"
#include"Event/test.h"

#include  <fstream>
#include  <string>
//main
int main()
{
    MarsStation Station;
	Station.Run();
	std::cout << "Bye World!\n";

}
