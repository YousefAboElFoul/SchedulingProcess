#include "Scheduler.h"
#include <string>
#include <iostream>

using namespace std;

Scheduler::Scheduler()
{
}

Scheduler::Scheduler(bool f,int c)
{
	// initializing flag
	setFlag(f);

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

void Scheduler::setClock(int c)
{
	clock = c;
}

bool Scheduler::getClock()
{
	return clock;
}

void Scheduler::insertProcess(process * Queue[], process * p) // check if this is possible
{
	for (int i = 0; i < 3; i++) // going through array
	{
		if (Queue[i] == nullptr) // if not equal to null
		{
			Queue[i] = p; // insert in array
			break;

		}
	}
}

void Scheduler::removeProcess(process * Queue[], int x)
{

		Queue[x] = nullptr;

		//check if queue is empty after
}

void Scheduler::isQueue1Empty(process * Queue[])
{
	Flag = false;

	for (int i = 0; i < 3; i++) // going through array
	{
		if (Queue[i] != nullptr) // if not equal to pointer
		{
			Flag = true;

		}
	}
}

void Scheduler::isQueue2Empty(process * Queue[])
{
	Flag = true;

	for (int i = 0; i < 3; i++) // going through array
	{
		if (Queue[i] != nullptr) // if not equal to pointer
		{
			Flag = false;

		}
	}
}
int Scheduler::getHighestPriority(process * Queue[], int size)
{
	int max = 500;
	int temp;

	for (int i = 0; i < size; i++)
	{
		if (Queue[i] != nullptr)
		{
			temp = (Queue[i]->get_priority());

			if (temp < max)
			{
				max = temp;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (Queue[i] != nullptr)
		{
			if (max == (Queue[i])->get_priority())
			{
				return i;
			}

		}
	}
}

void Scheduler::updatePriority()
{
	
}

void Scheduler::schedulerRun(process * Queue1[], process * Queue2[])
{
	process * process_running;
	int Tq;

	if (Flag == true)
	{
		int index = getHighestPriority(Queue1, 3);
		process_running = Queue1[index];
		removeProcess(Queue1,index); //remove the right process
	}
	else
	{
		int index = getHighestPriority(Queue2, 3);
		process_running = Queue2[index];
		removeProcess(Queue2,index); // make sure you can pass array of pointers
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

		if (Flag)
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

	if (Flag)
	{
		isQueue1Empty(Queue1);
	}
	else
	{
		isQueue2Empty(Queue2);
	}
}




