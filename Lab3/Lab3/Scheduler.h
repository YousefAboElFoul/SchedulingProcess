#include "process.h"
#include <iostream>

using namespace std;

class Scheduler
{
public:
	Scheduler();
	Scheduler(bool);
	//------setters and getters-------------//

	process * getQueue1();
	//--------------------------------------//
	
	process * getQueue2();

	//--------------------------------------//
	void setFlag(bool);
	bool getFlag();
	//--------------------------------------//

	//--------------------------------------//

	bool insertProcess(process * [], process * );
	bool removeProcess(process * []);

	void schedulerRun();

	void updatePriority();

private:
	process * Queue1[140];
	process * Queue2[140];
	bool Flag;
};

