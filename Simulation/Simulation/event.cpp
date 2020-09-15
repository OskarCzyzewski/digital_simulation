#include "stdafx.h"
#include "event.h"

int Event::system_time_ = 0;
int Event::id_ = 0;
int Event::manager_time_ = 240;	//40
Event::Event(const int time, const bool flag)
{
	this->event_time_ = time;
	this->flag_ = flag;
}
int Event::GetSystemTime()
{
	return Event::system_time_;
}

void Event::SetSystemTime(const int val)
{
	Event::system_time_ = val;

}

int Event::GetClientId()
{
	return Event::id_;
}

void Event::SetClientId()
{
	Event::id_++;
}

int Event::ManagerTime()
{
	return manager_time_;
}



