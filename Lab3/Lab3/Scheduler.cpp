#include "Scheduler.h"
#include <iostream>

using namespace std;
//adding  a comment so that it can update in my branch


Scheduler::Scheduler()
{
	for (int i = 0; i < 3; i++)
	{
		Queue1[i] = nullptr;
		Queue2[i] = nullptr;
	}

}
Scheduler::Scheduler(bool f)
{
	setFlag(f);

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
void Scheduler::setFlag(bool f)
{
	Flag = f;
}
bool Scheduler::getFlag()
{
	return Flag;
}
//--------------------------------------//

bool Scheduler::insertProcess(process * Queue[], process * p) // check if this is possible
{
	for (int i = 0; i < 140; i++) // going through array
	{
		if (Queue[i] == nullptr) // if not equal to null
		{
			Queue[i] = p; // insert in array

		    // *need to add sorting algorithm here*
			// sort by highest number priority , first in queue[0]
			return true;
		}
	}
	return false;
}

bool Scheduler::removeProcess(process * Queue[])
{
	for (int i = 0; i < 140; i++) // going through array
	{
		if (Queue[i] != nullptr) // if not equal to pointer
		{

				Queue[i] = NULL; // set equal to null

				// *need to add sorting algorithm here*
				// sort by highest number priority , first in queue[0]

				return true;
		}
		else
		{
			Flag = false; // switch flags because active Queue is empty

		}
	}
	return false;

}

void Scheduler::updatePriority()
{
	//figure out equation in pdf document
}

void Scheduler::schedulerRun()
{
	process * process_running;
	int Tq;

	if (Flag == true)
	{
		process_running = Queue1[0];
		removeProcess(Queue1); // make sure you can pass array of pointers

	}
	else
	{
		process_running = Queue2[0];
		removeProcess(Queue2); // make sure you can pass array of pointers

	}

	if ((process_running->get_priority()) < 100)
	{
		Tq = (140 - (process_running->get_priority())) * 20;
	}
	else
	{
		Tq = (140 - (process_running->get_priority())) * 5;
	}

	if ((process_running->get_burst_time()) > Tq)
	{
		int time_left;

		time_left = (process_running->get_burst_time()) - Tq;

		process_running->set_burst_time(time_left); // set new burst time left after Tq

		if (Flag == true)
		{
			insertProcess(Queue2, process_running); // we are moving the processes back into expired queue

		}
		else
		{
			insertProcess(Queue1, process_running); // we are moving the processes back into expired queue

		}
	}
	else
	{
		process_running->set_burst_time(0); // set new burst time = 0, process has terminated (we do not put it back into queue)
	}
}




