#include "stdafx.h"
#include "take_table_sit.h"
#include <iostream>


TakeTableSit::TakeTableSit(int event_time,bool flag)
{
	this->event_time_ = event_time;
	this->flag_ = flag;
}



void TakeTableSit::execute(std::list<Event*>* agenda, Restaurant * restaurant)
{
	auto client = restaurant->queue_for_table_->front();
	std::cout << "Klient o id= " << client->GetId() << " usiadl przy stoliku " << std::endl;
	std::cout << "Manager jest wolny" << std::endl;
	Restaurant::ManagerTrue();
	client->SetTimeWaiter(Event::GetSystemTime());
	restaurant->queue_for_drink_->push_back(client);
	restaurant->queue_for_table_->pop_front();

}

void TakeTableSit::CancelEvent(std::list<Event*>* agenda, Restaurant * restaurant)
{
	std::cout << "Klienci, ktorych prowadzil manager opuscili restauracje podczas alarmu. Manager od tego momentu jest wolny" << std::endl;
	Restaurant::ManagerTrue();
	
}

bool TakeTableSit::GetFlag()
{
	return this->flag_;
}

int TakeTableSit::GetEventTime()
{
	return this->event_time_;
}
