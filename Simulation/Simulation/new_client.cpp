#include "stdafx.h"
#include "new_client.h"
#include <iostream>
#include <ctime>
#include "generators.h"
#include "statistics.h"


NewClient::NewClient(const int event_time, const bool flag)
{
	this->event_time_ = event_time;
	this->flag_ = flag;
	this->id_ = 0;
}

void NewClient::execute(std::list<Event*> *agenda, Restaurant * restaurant )
{
	auto k = Generators::GetSeed();
	const auto time = static_cast<int>(Generators::Norm(Generators::NewClientAvg(),Generators::NewClientSigma(),k));
	Generators::SetSeed(k);

	std::cout << "Przybycie nowego klienta do restauracji " <<std::endl;
	Event::SetClientId();
	id_ = Event::GetClientId();

	if(Event::GetClientId() == 5000)
	{
		Statistics::SetPhase();
		Statistics::ResetStatistics();
	}
	
	k = Generators::GetSeed();
	const auto x = Generators::Uniform(k);
	Generators::SetSeed(k);

	if(x < 0.5)  
	{
		const auto client = new Client(id_,Event::GetSystemTime());
		restaurant->queue_for_table_->push_back(client);
		std::cout << "Klienci o ID: "<< client->GetId() <<" zostali przydzieleni do kolejki do stolikow" << std::endl;
	}
	else
	{
		const auto client = new Client(id_);
		restaurant->queue_for_buffet_->push_back(client);
		std::cout << "Klienci o ID: " << client->GetId() << " zostali przydzieleni do kolejki do bufetu" << std::endl;
	}
	
	agenda->push_back(new NewClient(Event::GetSystemTime() + time , false));
}

void NewClient::CancelEvent(std::list<Event*>* agenda, Restaurant * restaurant)
{

}

bool NewClient::GetFlag()
{
	return this->flag_;
}

int NewClient::GetEventTime()
{
	return this->event_time_;
}





