#include "Ocean.h"
#include<iostream>
#include <Windows.h>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	std::setlocale(LC_ALL, "rus");
	Ocean* myOcean = new Ocean;
	myOcean->initialize();
	myOcean->run();
}
