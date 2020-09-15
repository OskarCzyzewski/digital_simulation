#pragma once
#include <list>
#include "restaurant.h"

class Event
{
public:
	void virtual execute(std::list<Event *> *agenda, Restaurant *restaurant ) = 0;		
	void virtual CancelEvent(std::list<Event*>* agenda, Restaurant* restaurant) = 0;    
	bool virtual GetFlag() = 0;
	int virtual GetEventTime() = 0;
	Event() = default;
	Event(int, bool);
	virtual ~Event()= default;
	static int GetSystemTime();
	static void SetSystemTime(int);
	static int GetClientId();
	static void SetClientId();
	static int ManagerTime();

	
private:
	int event_time_;
	bool flag_;
	static int system_time_;
	static int id_ ;
	static int manager_time_;
};

