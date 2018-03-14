#pragma once
class Scheduler
{
public:
	Scheduler();
	Scheduler(int,int,bool,bool);
	//------setters and getters-------------//
	void setQueue1();
	int getQueue1();
	//--------------------------------------//
	void setQueue2();
	int getQueue2();
	//--------------------------------------//
	void setFlag1();
	bool getFlag1();
	//--------------------------------------//
	void setFlag2();
	bool getFlag2();
	//--------------------------------------//

private:
	int Queue1[10];
	int Queue2[10];
	bool Flag1,FLag2;
};

