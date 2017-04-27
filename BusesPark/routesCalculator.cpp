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
	list<times> departTimes;        // расписание отправлений
	list<times> busesOnLineTimes;   // массив с данными о временах отправления и прибытия в парк автобусов,
								    // находящихся в данный момент на линии
	int busesInPark = 0;            // число автобусов, находящихся в данный момент в парке
	int busesOnLine = 0;            // число автобусов, находящихся в данный момент на линии
	int busesNeed = 0;              // минимальное число автобусов для обеспечения
					                // работы по заданному расписанию отправлений


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

// пробегаем по массиву с отправлениями	
	for(list<times>::iterator it = departTimes.begin(); it != departTimes.end(); it++) 
	{
// пробегаем по массиву с автобусами, которые в данный момент на линии
		for(list<times>::iterator jt = busesOnLineTimes.begin(); jt != busesOnLineTimes.end(); jt++) 
		{																							 
			if (busesOnLine > 0 && ((*jt).endTime < (*it).departTime))
			{
// если автобус к моменту очередного отправления завершил свой маршрут, удаляем данные о нём
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

// отправление очередного автобуса
			busesOnLineTimes.push_back( *it);
			busesOnLine++;
	}
	
	printf("Need buses: %d", busesNeed);
}