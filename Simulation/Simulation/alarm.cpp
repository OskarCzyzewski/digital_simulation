#include "stdafx.h"
#include "alarm.h"
#include <iostream>
#include "generators.h"


Alarm::Alarm(const int event_time, const bool flag	)
{
	this->event_time_ = event_time;
	this->flag_ = flag;
}


void Alarm::execute(std::list<Event*>* agenda, Restaurant* restaurant)
{
	auto k = Generators::GetSeed();
	const auto time = static_cast<int>(Generators::Norm(Generators::AlarmAvg(), Generators::AlarmSigma(), k));
	Generators::SetSeed(k);

	std::cout << "Alarm: nieswiadomi klienci opuszczaja restauracje " << std::endl;
	
	Event *event = nullptr;
	int y = agenda->size();
	while (y-- > 0)
	{
		event = agenda->front();
		if(event->GetFlag())
		{
			event->CancelEvent(agenda,restaurant);
			agenda->pop_front();
		}
		else
		{
			agenda->push_back(event);
			agenda->pop_front();
		}

	}



	Client *client = nullptr;
	int x = restaurant->queue_for_buffet_->size();

	while (x-- > 0)
	{
		client = restaurant->queue_for_buffet_->front();
		if (client->GetAware())
		{
			restaurant->queue_for_buffet_->pop_front();
		}
		else
		{
			restaurant->queue_for_buffet_->push_back(client);
			restaurant->queue_for_buffet_->pop_front();
		}
	}


	client = nullptr;
	x = restaurant->queue_for_cashiers_->size();

	while (x-- > 0)
	{
		client = restaurant->queue_for_cashiers_->front();
		if (client->GetAware())
		{
			restaurant->queue_for_cashiers_->pop_front();
		}
		else
		{
			restaurant->queue_for_cashiers_->push_back(client);
			restaurant->queue_for_cashiers_->pop_front();
		}
	}
	
	
	
	client =nullptr;
	x = restaurant->queue_for_table_->size();	

	while (x-- > 0)
	{
		client = restaurant->queue_for_table_->front();
		if (client->GetAware())
		{
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
			restaurant->queue_for_table_->pop_front();
		}
		else
		{
			restaurant->queue_for_table_->push_back(client);
			restaurant->queue_for_table_->pop_front();
		}
	}

	client = nullptr;
	x = restaurant->queue_for_drink_->size();	

	while (x-- > 0)
	{
		client = restaurant->queue_for_drink_->front();
		if (client->GetAware())
		{
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
			restaurant->queue_for_drink_->pop_front();
			
		}
		else
		{
			restaurant->queue_for_drink_->push_back(client);
			restaurant->queue_for_drink_->pop_front();
		}
	}

	client = nullptr;
	x = restaurant->queue_for_meal_->size();	 

	while (x-- > 0)
	{
		client = restaurant->queue_for_meal_->front();
		if (client->GetAware())
		{
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
			restaurant->queue_for_meal_->pop_front();
		}
		else
		{
			restaurant->queue_for_meal_->push_back(client);
			restaurant->queue_for_meal_->pop_front();
		}
	}


	client = nullptr;
	x = restaurant->buffet_members_->size();	

	while (x-- > 0)
	{
		client = restaurant->buffet_members_->front();
		if (client->GetAware())
		{
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
		else
		{
			restaurant->buffet_members_->push_back(client);
			restaurant->buffet_members_->pop_front();
		}
	}

	client = nullptr;
	x = restaurant->clients_group_drinks_->size();	

	while (x-- > 0)
	{
		client = restaurant->clients_group_drinks_->front();
		if (client->GetAware())
		{
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
			restaurant->clients_group_drinks_->pop_front();
		}
		else
		{
			restaurant->clients_group_drinks_->push_back(client);
			restaurant->clients_group_drinks_->pop_front();
		}
	}

	client = nullptr;
	x = restaurant->clients_group_meals_->size();	

	while (x-- > 0)
	{
		client = restaurant->clients_group_meals_->front();
		if (client->GetAware())
		{
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
			restaurant->clients_group_meals_->pop_front();
		}
		else
		{
			restaurant->clients_group_meals_->push_back(client);
			restaurant->clients_group_meals_->pop_front();
		}
	}

	client = nullptr;
	x = restaurant->members_consumption_->size();	

	while (x-- > 0)
	{
		client = restaurant->members_consumption_->front();
		if (client->GetAware())
		{
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
			restaurant->members_consumption_->pop_front();
		}
		else
		{
			restaurant->members_consumption_->push_back(client);
			restaurant->members_consumption_->pop_front();
		}
	}

	
	agenda->push_back(new Alarm(Event::GetSystemTime() + time, false));
}

void Alarm::CancelEvent(std::list<Event*>* agenda, Restaurant * restaurant)
{
}

bool Alarm::GetFlag()
{
	return this->flag_;
}

int Alarm::GetEventTime()
{
	return this->event_time_;
}
