#pragma once
#include "event.h"

class TakeTableSit : public Event
{
public:
	TakeTableSit(int,bool);
	~TakeTableSit() = default;
	void execute(std::list<Event*>* agenda, Restaurant* restaurant) override;
	void CancelEvent(std::list<Event*>* agenda, Restaurant* restaurant) override;
	bool GetFlag() override;
	int GetEventTime() override;
private:
	int event_time_;
	bool flag_;
};

