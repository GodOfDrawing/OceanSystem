#include "Random.h"
//#include<ctime>
unsigned Random::RanMax( int maxV)
{
	//srand(time(NULL));  
	//��������, �� � �������� ���������, bruh
	int rv;
	if (maxV==0) return 0;
	else
	{
		rv = rand() % maxV;
		return rv;
	}
}