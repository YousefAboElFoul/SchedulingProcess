#include "Scheduler.h"
#include <iostream>

using namespace std;

Scheduler::Scheduler()
{
	// initializing both Queues
	for (int i = 0; i < 3; i++)
	{
		Queue1[i] = nullptr;
		Queue2[i] = nullptr;
	}

}
Scheduler::Scheduler(bool f)
{
	// initializing flag
	setFlag(f);

}

//getter function for queue1
process * Scheduler::getQueue1()
{
	return *Queue1;
}

//getter function for queue2
process * Scheduler::getQueue2()
{
	return *Queue2;
}

//setter function for flag
void Scheduler::setFlag(bool f)
{
	Flag = f;
}

//getter function for flag
bool Scheduler::getFlag()
{
	return Flag;
}


bool Scheduler::insertProcess(process * Queue[], process * p) // check if this is possible
{
	for (int i = 0; i < size; i++) // going through array
	{
		if (Queue[i] == nullptr) // if not equal to null
		{
			Queue[i] = p; // insert in array

			sortingAlgorithm(Queue);

			return true;
		}
	}
	return false;
}

bool Scheduler::removeProcess(process * Queue[])
{
	for (int i = 0; i < size; i++) // going through array
	{
		if (Queue[i] != nullptr) // if not equal to pointer
		{

				Queue[i] = NULL; // set equal to null

				sortingAlgorithm(Queue); // its empty for now

				return true;
		}
		else
		{
			Flag = false; // switch flags because active Queue is empty

		}
	}
	return false;

}

void Scheduler::sortingAlgorithm(process * Queue[], int size) // i will be implementing a simple bubble sort algorithm
{
	int i;
	bool swap_occured = true;

	while (swap_occured)
	{
			swap_occured = false;
			
			for (i = 0; i < size - 1; i++)
			{
				if ((Queue[i+1]->get_priority) > (Queue[i]->get_priority)) // add null case
				{
					
					process * temp = Queue[i];
					Queue[i] = Queue[i+1];
					Queue[i+1] = temp;

					swap_occured = true;

				}
			}
	}
}

void Scheduler::updatePriority()
{
	
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




