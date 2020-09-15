#include "stdafx.h"
#include "cashier_event.h"
#include <iostream>


CashierEvent::CashierEvent(const int event_time, const bool flag)
{
	this->event_time_ = event_time;
	this->flag_ = flag;
}



void CashierEvent::execute(std::list<Event*>* agenda, Restaurant* restaurant)
{
	std::cout << "Kasjer zakonczyl obsluge klienta" << std::endl;
	Restaurant::SetCashiers();	//to increment number of cashiers

}

void CashierEvent::CancelEvent(std::list<Event*>* agenda, Restaurant * restaurant)
{
	std::cout << "Klienci, ktorych obslugiwal kasjer opuscili restauracje podczas alarmu " << std::endl;
	Restaurant::SetCashiers();	//to increment number of cashiers

}

bool CashierEvent::GetFlag()
{
	return this->flag_;
}

int CashierEvent::GetEventTime()
{
	return this->event_time_;
}
