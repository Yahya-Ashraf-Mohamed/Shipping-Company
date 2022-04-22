#pragma once
#include <iostream>
#include <string>
using namespace std;

#include"MarsStation/MarsStation.h"
#include"Event/test.h"


//main
int main()
{
	cout << "Hello World"<<endl;

	test* Test = new test();
	Test->excute();

	return 0;
}
