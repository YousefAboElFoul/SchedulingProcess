#include <iostream>

using namespace std;

class process
{
public:

	process();
	~process();

	void set_PID(int);
	int get_PID();

	void set_arrival_time(int);
	int get_arrival_time();

	void set_burst_time(int);
	int get_burst_time();

	void set_priority(int);
	int get_priority();



private:
	int PID, arrival_time, burst_time, priority;

};

