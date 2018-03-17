#include "process.h"
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
	int size;
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

			/*Process_size[counter-1].set_PID(PID);
			Process_size[counter-1].set_arrival_time(arrival_time);
			Process_size[counter - 1].set_burst_time(burst_time);
			Process_size[counter - 1].set_priority(priorty);
			counter++;
			*/}
		}
		myfile.close();
	}

	else cout << "Unable to open file";


	return 0;
}