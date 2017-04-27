#include "routesCalculator.h"
#include "stdafx.h"
#include <list>

using namespace std;

void calculate()
{
	printf("Calculator");
		list<times> departTimes;
	list<times> busesOnLineTimes;
	int buses_in_park = 0;
	int busesOnLine = 0;
	
	for(list<times>::iterator it = departTimes.begin(); it != departTimes.end(); it++)
	{
		for(list<times>::iterator jt = busesOnLineTimes.begin(); jt != busesOnLineTimes.end(); jt++)
		{
			if ((*jt).endTime < (*it).departTime)
			{
				busesOnLineTimes.remove(*jt);
				busesOnLine--;
				buses_in_park++;
			}
		}

		if (buses_in_park <= 0)
			buses_in_park++;
		buses_in_park--;
			busesOnLineTimes.push_back( *it);
			busesOnLine++;
	}

	printf("Need buses: %d", buses_in_park);
}