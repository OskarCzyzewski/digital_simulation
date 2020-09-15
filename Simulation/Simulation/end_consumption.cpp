#include "stdafx.h"
#include "end_consumption.h"
#include "events.h"
#include <iostream>


EndConsumption::EndConsumption(const int event_time, const bool flag)
{
	this->event_time_ = event_time;
	this->flag_ = flag;
}



void EndConsumption::execute(std::list<Event*>* agenda, Restaurant * restaurant)
{
	Events::SortMembers(restaurant->members_consumption_);		//Sort consumption members by consumption time
	Client *client = restaurant->members_consumption_->front();
	std::cout << " Klient o ID:" << client->GetId() <<" zakonczyl jedzenie"<< std::endl;

	switch (client->GetTable())
	{
	case 2:
		restaurant->SetTableTwo(0);
		break;
	case 3:
		restaurant->SetTableThree(0);
		break;
	case 4:
		restaurant->SetTableFour(0);
		break;
	default:
		break;
	}

	restaurant->queue_for_cashiers_->push_back(client);
	restaurant->members_consumption_->pop_front();

}

void EndConsumption::CancelEvent(std::list<Event*>* agenda, Restaurant * restaurant)
{
	std::cout << "Klienci opuscili restauracje podczas alarmu " << std::endl;
	
}

bool EndConsumption::GetFlag()
{
	return this->flag_;
}

int EndConsumption::GetEventTime()
{
	return this->event_time_;
}
