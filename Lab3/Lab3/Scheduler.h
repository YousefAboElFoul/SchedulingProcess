#include "process.h"
#include <iostream>

using namespace std;

class Scheduler
{
public:
	Scheduler();
	Scheduler(bool,int);
	//------setters and getters-------------//

	void setFlag(bool);
	bool getFlag();

	void setClock(int);
	bool getClock();

	//--------------------------------------//

	void insertProcess(process * [], process * );
	void removeProcess(process * [], int );

	void isQueue1Empty(process * []);

	void isQueue2Empty(process *[]);

	int getHighestPriority(process *[], int);

	void schedulerRun(process * [], process * []);

	void updatePriority();

private:

	bool Flag;
	int clock;
};

