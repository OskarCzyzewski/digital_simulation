#include "stdafx.h"
#include "end_consumpiton_buffet.h"
#include "events.h"
#include <iostream>


EndBuffet::EndBuffet(const int event_time, const bool flag)
{
	this->event_time_ = event_time;
	this->flag_ = flag;
}

void EndBuffet::execute(std::list<Event*>* agenda, Restaurant* restaurant)
{

	Events::SortMembers(restaurant->buffet_members_);

	Client *client = restaurant->buffet_members_->front();
	restaurant->queue_for_cashiers_->push_back(client);
	std::cout << "Klienci o Id: " << client->GetId() << " zakonczyli konsumpcje w bufecie i udaja sie do kolejki do kasy" <<  std::endl;
	switch (client->GetNumberOfPeople())
	{
	case 1:
		restaurant->SetBuffetSeats2(1);
		break;
	case 2:
		restaurant->SetBuffetSeats2(2);
		break;
	case 3:
		restaurant->SetBuffetSeats2(3);
		break;
	case 4:
		restaurant->SetBuffetSeats2(4);
		break;
	default:
		break;
	}
	restaurant->buffet_members_->pop_front();


}

void EndBuffet::CancelEvent(std::list<Event*>* agenda, Restaurant * restaurant)
{
	std::cout << "Klienci obecni w bufecie opuscili restauracje podczas alarmu" << std::endl;
	
}

bool EndBuffet::GetFlag()
{
	return this->flag_;
}

int EndBuffet::GetEventTime()
{
	return this->event_time_;
}


