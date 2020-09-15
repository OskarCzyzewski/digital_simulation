#include "stdafx.h"
#include "end_meal.h"
#include "end_consumption.h"
#include "events.h"
#include <iostream>
#include "generators.h"


EndMeal::EndMeal(const int event_time, const bool flag)
{
	this->event_time_ = event_time;
	this->flag_ = flag;
}



void EndMeal::execute(std::list<Event*>* agenda, Restaurant* restaurant)
{
	auto k = Generators::GetSeed();
	const auto time = static_cast<int>(Generators::Exp(Generators::EndConsumptionLambda(), k));
	Generators::SetSeed(k);

	Events::SortMembers(restaurant->clients_group_meals_); //Sort consumption members by consumption time
	auto client = restaurant->clients_group_meals_->front();
	std::cout << "Kelner podal jedzenie Klientowi o ID:" << client->GetId() << std::endl;
	const auto flag = client->GetAware();
	restaurant->members_consumption_->push_back(client);
	restaurant->clients_group_meals_->pop_front();
	Restaurant::SetWaiters();	//   waiters_++

	client->SetConsumption(Event::GetSystemTime() + time);

	agenda->push_back(new EndConsumption(Event::GetSystemTime() + time, flag));

}

void EndMeal::CancelEvent(std::list<Event*>* agenda, Restaurant * restaurant)
{
	std::cout << "Klienci, ktortch obslugiwal kelner opuscili restauracje podczas alarmu " << std::endl;

	Restaurant::SetWaiters();	//   waiters_++
}

bool EndMeal::GetFlag()
{
	return this->flag_;
}

int EndMeal::GetEventTime()
{
	return this->event_time_;
}
