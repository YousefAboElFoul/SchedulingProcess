#include "process.h"
#include <iostream>

using namespace std;

class Scheduler
{
public:
	Scheduler();
	Scheduler(bool, bool);
	//------setters and getters-------------//

	process * getQueue1();
	//--------------------------------------//
	
	process * getQueue2();

	//--------------------------------------//
	void setFlag1(bool);
	bool getFlag1();
	//--------------------------------------//
	void setFlag2(bool);
	bool getFlag2();
	//--------------------------------------//

	bool insertProcess(process * );
	bool removeProcess();

	void schedulerRun();

private:
	process * Queue1[140];
	process * Queue2[140];
	bool Flag1, Flag2;
};

