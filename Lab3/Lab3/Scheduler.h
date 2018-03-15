#include "process.h"
#include <iostream>

using namespace std;

class Scheduler
{
public:
	Scheduler();
	Scheduler(process, process, bool, bool);
	//------setters and getters-------------//
	void setQueue1();
	process *getQueue1();
	//--------------------------------------//
	void setQueue2();
	process*getQueue2();
	//--------------------------------------//
	void setFlag1();
	bool getFlag1();
	//--------------------------------------//
	void setFlag2();
	bool getFlag2();
	//--------------------------------------//

private:
	process Queue1[10], Queue2[10];
	bool Flag1,FLag2;
};

