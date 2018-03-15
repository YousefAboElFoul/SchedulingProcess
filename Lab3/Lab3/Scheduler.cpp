#include "Scheduler.h"
#include <iostream>

using namespace std;

Scheduler::Scheduler()
{
	for (int i = 0; i < 3; i++)
	{
		Queue1[i] = nullptr;
		Queue2[i] = nullptr;
	}

}
Scheduler::Scheduler(bool f1,bool f2)
{
	setFlag1(f1);
	setFlag2(f2);

}

process * Scheduler::getQueue1()
{
	return *Queue1;
}
//--------------------------------------//

process * Scheduler::getQueue2()
{
	return *Queue2;
}
//--------------------------------------//
void Scheduler::setFlag1(bool f1)
{
	Flag1 = f1;
}
bool Scheduler::getFlag1()
{
	return Flag1;
}
//--------------------------------------//
void Scheduler::setFlag2(bool f2)
{
	Flag2 = f2;
}
bool Scheduler::getFlag2()
{
	return Flag2;
}

bool Scheduler::insertProcess(process * p)
{
	for (int i = 0; i < 140; i++) // going through array
	{
		if (Queue1[i] == nullptr) // if not equal to null
		{
			Queue1[i] = p; // insert in array

		    // *need to add sorting algorithm here*
			// sort by lowest priority "1" , first in queue[0]
			return true;
		}
	}
	return false;
}

bool Scheduler::removeProcess()
{
	for (int i = 0; i < 140; i++) // going through array
	{
		if (Queue1[i] != nullptr) // if not equal to pointer
		{

				Queue1[i] = NULL; // set equal to null

				// *need to add sorting algorithm here*
				// sort by lowest priority "1" , first in queue[0]

				return true;
		}
	}
	return false;

}

void Scheduler::schedulerRun()
{
	process * process_running;

	if (Flag1 == true)
	{
		process_running = Queue1[0];
		removeProcess();

	}
	else
	{
		process_running = Queue2[0];
		removeProcess();

	}

	if ((process_running->get_priority()) < 100)
	{
		int Tq = (140 - (process_running->get_priority())) * 20;
	}
	else
	{
		int Tq = (140 - (process_running->get_priority())) * 5;
	}

}




