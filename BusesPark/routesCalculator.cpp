#include "routesCalculator.h"
#include "stdafx.h"
#include <list>

using namespace std;

times::times(int depTime, int enTime)
{
	departTime = depTime;
	endTime = enTime;
}

void calculate()
{
	printf("Calculator");
	list<times> departTimes;
	list<times> busesOnLineTimes;
	int busesInPark = 0;
	int busesOnLine = 0;

	departTimes.push_back(times(1, 3));
	departTimes.push_back(times(5, 10));
	departTimes.push_back(times(7, 9));
	
	for(list<times>::iterator it = departTimes.begin(); it != departTimes.end(); it++)
	{
		for(list<times>::iterator jt = busesOnLineTimes.begin(); jt != busesOnLineTimes.end(); jt++)
		{
			if (busesOnLine > 0 && ((*jt).endTime < (*it).departTime))
			{
				busesOnLineTimes.remove(*jt);
				busesOnLine--;
				busesInPark++;
			}
		}

		if (busesInPark <= 0)
			busesInPark++;
		busesInPark--;
			busesOnLineTimes.push_back( *it);
			busesOnLine++;
	}

	printf("Need buses: %d", busesInPark);
}