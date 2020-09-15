#pragma once
#include "event.h"

class NewClient : public Event
{

public:
	NewClient(int, bool);
	~NewClient() = default;
	void execute(std::list<Event*> *agenda, Restaurant *restaurant ) override;
	void  CancelEvent(std::list<Event*>* agenda, Restaurant* restaurant) override;
	bool GetFlag() override;
	int GetEventTime() override;
	
private:
	int event_time_;
	int id_;
	bool flag_;
};

