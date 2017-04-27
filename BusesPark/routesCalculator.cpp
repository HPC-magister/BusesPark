#include "routesCalculator.h"
#include "stdafx.h"
#include <list>

using namespace std;


typedef struct times
{
public:
	times(int depTime, int enTime);
	~times();
	int departTime;
	int endTime;
};

times::times(int depTime, int enTime)
{
	departTime = depTime;
	endTime = enTime;
}

times::~times()
{	
}

void calculate()
{
	printf("Calculator\n");
	list<times> departTimes;
	list<times> busesOnLineTimes;
	int busesInPark = 0;
	int busesOnLine = 0;
	int busesNeed = 0;


// 1st variant
	departTimes.push_back(times(1, 3));
	departTimes.push_back(times(5, 10));
	departTimes.push_back(times(7, 9));
/*
// 2nd variant
	departTimes.push_back(times(1, 3));
	departTimes.push_back(times(1, 8));
	departTimes.push_back(times(5, 10));
	departTimes.push_back(times(7, 9));
/*
// 3d variant
	departTimes.push_back(times(1, 8));
	departTimes.push_back(times(5, 10));
	departTimes.push_back(times(7, 9));*/
	
	for(list<times>::iterator it = departTimes.begin(); it != departTimes.end(); it++)
	{
		
		for(list<times>::iterator jt = busesOnLineTimes.begin(); jt != busesOnLineTimes.end(); jt++)
		{
			if (busesOnLine > 0 && ((*jt).endTime < (*it).departTime))
			{
				busesOnLineTimes.erase(jt);
				printf("Depart time: %d\n", (*it).departTime);
				busesOnLine--;
				busesInPark++;

				if (busesOnLineTimes.size() == 0)
					break;
				jt = busesOnLineTimes.begin();
			}
		}
		printf("Online buses: %d\n", busesOnLine);
	
		if (busesInPark <= 0)
		{
			busesInPark++;
			busesNeed++;
		}
		busesInPark--;
			busesOnLineTimes.push_back( *it);
			busesOnLine++;
	}
	
	printf("Need buses: %d", busesNeed);
}