#include "process.h"
#include <iostream>

using namespace std;

process::process()
{
	time_left = 0;
}

process::process(int pid, int at, int bt, int p)
{
	set_PID(pid);
	set_arrival_time(at);
	set_burst_time(bt);
	set_priority(p);
}

process::~process()
{
}

void process::set_PID(int pid)
{
	PID = pid;
}

int process::get_PID()
{
	return PID;
}

void process::set_arrival_time(int at)
{
	arrival_time = at;
}

int process::get_arrival_time()
{
	return arrival_time;
}

void process::set_burst_time(int bt)
{
	burst_time = bt;
}

int process::get_burst_time()
{
	return burst_time;
}

void process::set_priority(int p)
{
	priority = p;
}

int process::get_priority()
{
	return priority;
}
