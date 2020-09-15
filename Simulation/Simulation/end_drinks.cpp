#include "stdafx.h"
#include "end_drinks.h"
#include "events.h"
#include <iostream>


EndDrinks::EndDrinks(const int event_time, const bool flag)
{
	this->event_time_ = event_time;
	this->flag_ = flag;
}

void EndDrinks::execute(std::list<Event*>* agenda, Restaurant * restaurant)
{
	Events::SortMembers(restaurant->clients_group_drinks_);  // Sort members by consumption time
	Client *client = restaurant->clients_group_drinks_->front();
	std::cout << "Kelner podal napoje Klientowi o ID: "<< client->GetId()<< std::endl;


	restaurant->queue_for_meal_->push_back(client);
	restaurant->clients_group_drinks_->pop_front();
	Restaurant::SetWaiters();  //to increment number of waiters

}

void EndDrinks::CancelEvent(std::list<Event*>* agenda, Restaurant * restaurant)
{
	std::cout << "Klienci, ktortch obslugiwal kelner opuscili restauracje podczas alarmu " << std::endl;
	
	Restaurant::SetWaiters();  //to increment number of waiters
}

bool EndDrinks::GetFlag()
{
	return this->flag_;
}

int EndDrinks::GetEventTime()
{
	return this->event_time_;
}

