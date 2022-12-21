#include "Random.h"
//#include<ctime>
unsigned Random::RanMax( int maxV)
{
	//srand(time(NULL));  
	//Работает, но с огормной задержкой, bruh
	int rv;
	if (maxV==0) return 0;
	else
	{
		rv = rand() % maxV;
		return rv;
	}
}