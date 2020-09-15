#pragma once
#include "event.h"
class CashierEvent :
	public Event
{
public:
	CashierEvent(int,bool);
	~CashierEvent() = default;
	void execute(std::list<Event*>* agenda, Restaurant* restaurant) override;
	void CancelEvent(std::list<Event*>* agenda, Restaurant* restaurant) override;
	bool GetFlag() override;
	int GetEventTime() override;
private:
	int event_time_;
	bool flag_;
};

