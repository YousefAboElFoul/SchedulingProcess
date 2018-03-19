#include "Scheduler.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <vector>

//#include <pthread.h/LINUX>
int size;
using namespace std;

int main() {
//	clock_t start;
//	start=clock();//setting 
/*	int size;
	int my_num;
	string line;
	ifstream myfile;
	int counter = 0;
	vector<process> Process_size;
	string PID="";
	char space = ' ';
	int arrival_time=0,burst_time=0,priorty=0;


	
	
	 myfile.open ("pbsinput.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (counter == 0)
			{
				istringstream buffer(line);				//swtiches string into an intger
				buffer >> size;
				cout << "size is:" << size << endl;
				Process_size.resize(size);
				counter=counter+1;
				
			}
			if (myfile >>PID>>arrival_time>>burst_time>>priorty);
				
			{	cout << line<<"am a bug<<"<<endl;
				cout << PID << "," << arrival_time << "," << burst_time << "," << priorty << endl;

			Process_size[counter-1].set_PID(PID);
			Process_size[counter-1].set_arrival_time(arrival_time);
			Process_size[counter - 1].set_burst_time(burst_time);
			Process_size[counter - 1].set_priority(priorty);

			counter++;
			*}
		}
		myfile.close();
	}

	//else cout << "Unable to open file";
*/

	process obj1,obj2,obj3;

	obj1.set_PID("P1");
	obj1.set_arrival_time(1000);
	obj1.set_burst_time(2500);
	obj1.set_priority(90);

	obj2.set_PID("P2");
	obj2.set_arrival_time(2000);
	obj2.set_burst_time(100);
	obj2.set_priority(120);

	obj3.set_PID("P3");
	obj3.set_arrival_time(3200);
	obj3.set_burst_time(100);
	obj3.set_priority(120);

//------------------------- after things are set

	Scheduler scheduler;

	process * ptr1, * ptr2, *ptr3;
	process * Queue1[3];
	process * Queue2[3];

	for (int i = 0; i < 3; i++)
	{
		Queue1[i] = nullptr;
		Queue2[i] = nullptr;
	}


	ptr1 = &obj1;
	ptr2 = &obj2;
	ptr3 = &obj3;

	scheduler.setFlag(true);

	scheduler.insertProcess(Queue1, ptr1);

	cout << "Queue1" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << Queue1[i]->get_priority() << endl;
		cout << Queue1[i]->get_burst_time() << endl;
	}

	scheduler.schedulerRun(Queue1, Queue2);

	cout << "Queue1" << endl;

	for (int i = 0; i < 3; i++)
	{
		if (Queue1[i] != nullptr)
		{
			cout << Queue1[i]->get_priority() << endl;
			cout << Queue1[i]->get_burst_time() << endl;

		}
	}

	cout << "Queue2" << endl;
	for (int i = 0; i < 3; i++)
	{
		if (Queue2[i] != nullptr)
		{
			cout << Queue2[i]->get_priority() << endl;
			cout << Queue2[i]->get_burst_time() << endl;

		}
	}

	scheduler.insertProcess(Queue1, ptr2);

	scheduler.schedulerRun(Queue1, Queue2);

	cout << "Queue1" << endl;

	for (int i = 0; i < 3; i++)
	{
		if (Queue1[i] != nullptr)
		{
			cout << Queue1[i]->get_priority() << endl;
			cout << Queue1[i]->get_burst_time() << endl;

		}
	}

	cout << "Queue2" << endl;
	for (int i = 0; i < 3; i++)
	{
		if (Queue2[i] != nullptr)
		{
			cout << Queue2[i]->get_priority() << endl;
			cout << Queue2[i]->get_burst_time() << endl;

		}
	}

	scheduler.schedulerRun(Queue1, Queue2);

	cout << "Queue1" << endl;

	for (int i = 0; i < 3; i++)
	{
		if (Queue1[i] != nullptr)
		{
			cout << Queue1[i]->get_priority() << endl;
			cout << Queue1[i]->get_burst_time() << endl;

		}
	}

	cout << "Queue2" << endl;
	for (int i = 0; i < 3; i++)
	{
		if (Queue2[i] != nullptr)
		{
			cout << Queue2[i]->get_priority() << endl;
			cout << Queue2[i]->get_burst_time() << endl;

		}
	}

	scheduler.schedulerRun(Queue1, Queue2);

	cout << "Queue2" << endl;
	for (int i = 0; i < 3; i++)
	{
		if (Queue2[i] != nullptr)
		{
			cout << Queue2[i]->get_priority() << endl;
			cout << Queue2[i]->get_burst_time() << endl;

		}
	}

	system("pause");

	return 0;
}