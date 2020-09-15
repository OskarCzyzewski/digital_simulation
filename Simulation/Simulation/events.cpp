#include "stdafx.h"
#include "events.h"
#include "new_client.h"
#include "take_table_sit.h"
#include <iostream>
#include "end_consumpiton_buffet.h"
#include "end_drinks.h"
#include "end_meal.h"
#include "cashier_event.h"
#include "alarm.h"
#include "generators.h"
#include "statistics.h"


void Events::ManagerWork(std::list<Event*>* agenda, Restaurant * restaurant) // when manager take clients form queue
{
	Restaurant::ManagerFalse();
	auto client = restaurant->queue_for_table_->front();
	const auto flag = client->GetAware();
	client ->SetWait(Event::GetSystemTime());	//function to set waiting time for table

	std::cout << "Klient czekal na stolik: " << client->GetWait() << " czasu " << std::endl;
	Statistics::SetAvgWait(client->GetWait());
	if (client->GetNumberOfPeople() <= 2 && Restaurant::GetTableTwo() > 0)
            {
                
			std::cout << "Manager prowadzi grupe klientow o ID: " << client->GetId() << " skladajacej sie z " <<client->GetNumberOfPeople() <<" osob do 2 osobowego stolika. Manager bedzie wolny o czasie: " <<Event::GetSystemTime() + Event::ManagerTime() <<std::endl;
			
	  		Restaurant::SetTableTwo(1); // table_two_ --;
			client->SetTable(2);  // client->Table = 2;
            }
      else if (client->GetNumberOfPeople() <= 3 && Restaurant::GetTableThree() > 0)
            {
		  std::cout << "Manager prowadzi grupe klientow o ID: " << client->GetId() << " skladajacej sie z " << client->GetNumberOfPeople() << " osob do 3 osobowego stolika. Manager bedzie wolny o czasie: " << Event::GetSystemTime() + Event::ManagerTime() << std::endl;
				
      			Restaurant::SetTableThree(1);	//table_three --;
				client->SetTable(3);
            }
            else if (client->GetNumberOfPeople() <= 4 && Restaurant::GetTableFour() > 0)
            {
				std::cout << "Manager prowadzi grupe klientow o ID: " << client->GetId() << " skladajacej sie z " << client->GetNumberOfPeople() << " osob do 4 osobowego stolika. Manager bedzie wolny o czasie: " << Event::GetSystemTime() + Event::ManagerTime() << std::endl;
            	Restaurant::SetTableFour(1);  //table_four -- ;
				client->SetTable(4);
            }


	agenda->push_back(new TakeTableSit(Event::GetSystemTime() + Event::ManagerTime(), flag));
}

bool Events::ManagerChoice(std::list<Event*>* agenda, Restaurant* restaurant)	
{
	bool flag;
	Client * client2 = nullptr;
	int x = restaurant->queue_for_table_->size();
	while(x > 0)
	{
		flag = false;
		auto client1 = restaurant->queue_for_table_->front();
		switch (client1->GetNumberOfPeople())
		{
		case 1: case 2:
			if (Restaurant::GetTableFour() > 0 || Restaurant::GetTableThree() > 0 || Restaurant::GetTableTwo() > 0)
			{
				flag = true;
			}
			break;
		
		case 3:
			if (Restaurant::GetTableThree() > 0 || Restaurant::GetTableFour() > 0)
				{
					flag = true;
				}
			break;

		case 4:
			if (Restaurant::GetTableFour() > 0)
				{
					flag = true;
				}

			break;

		default:
			break;
		}

		if ((client2 == nullptr) && flag )    //Sprawdzanie czy client 2 pokazuje na NULL
		{
			client2 = client1; 
			restaurant->queue_for_table_->pop_front(); // usuwanie z 1 miejca klienta
		}
		else
		{
			restaurant->queue_for_table_->push_back(client1); // przydzielanie klienta na koniec kolejki	
			restaurant->queue_for_table_->pop_front(); // usuwanie z 1 miejca klienta	
		}
		x--;
	}
	if (client2 != nullptr)
	{
		restaurant->queue_for_table_->push_front(client2);
		flag = true;
	}
	else
	{
		flag = false;
	}
	return flag;
}

void Events::BuffetMembers(std::list<Event*>* agenda, Restaurant * restaurant)
{
	auto k = Generators::GetSeed();
	const auto time = static_cast<int>(Generators::Norm(Generators::EndBuffetAvg(), Generators::EndBufferSigma(), k));
	Generators::SetSeed(k);

	Client *client = restaurant->queue_for_buffet_->front();
	std::cout << "Klienci o ID: "<< client->GetId() <<" o liczebnosci: " << client->GetNumberOfPeople() <<" wchodza do bufetu " << std::endl;
	const auto flag = client->GetAware();
	switch(client->GetNumberOfPeople())
	{
	case 1:
		Restaurant::SetBuffetSeats(1);
		break;
	case 2:
		Restaurant::SetBuffetSeats(2);
		break;
	case 3:
		Restaurant::SetBuffetSeats(3);
		break;
	case 4:
		Restaurant::SetBuffetSeats(4);
		break;
	default:
		break;
	}

	client->SetConsumption(Event::GetSystemTime() + time);
	restaurant->buffet_members_->push_back(client);
	restaurant->queue_for_buffet_->pop_front();

	agenda->push_back(new EndBuffet(Event::GetSystemTime() + time, flag));
	
}

void Events::WaiterFood(std::list<Event*>* agenda, Restaurant * restaurant)
{
	auto k = Generators::GetSeed();
	const auto time = static_cast<int>(Generators::Exp(Generators::EndMealLambda(), k));
	Generators::SetSeed(k);
	
	std::cout << "Klienci obslugiwani sa przez kelnera ( jedzenie )" << std::endl;


	auto client = restaurant->queue_for_meal_->front();
	const auto flag = client->GetAware();
	Restaurant::SetWaiters2(); //to decrement


	client->SetConsumption(Event::GetSystemTime() + time);
	restaurant->clients_group_meals_->push_back(client);
	restaurant->queue_for_meal_->pop_front();
	agenda->push_back(new EndMeal(Event::GetSystemTime() + time, flag));
}

void Events::WaiterDrink(std::list<Event*>* agenda, Restaurant * restaurant)
{
	std::cout << "Klienci obslugiwani sa przez kelnera ( napoje )" << std::endl;

	auto k = Generators::GetSeed();
	const auto time = static_cast<int>(Generators::Exp(Generators::EndDrinkLambda(), k));
	Generators::SetSeed(k);
	

	Client *client = restaurant->queue_for_drink_->front();
	const auto flag = client->GetAware();
	Restaurant::SetWaiters2(); // to decrement 
	client->SetTimeWaiter(Event::GetSystemTime());

	Statistics::SetAvgWaiter(client->GetTimeWaiter());  //to show statistics
	
	client->SetConsumption(Event::GetSystemTime() + time);
	restaurant->clients_group_drinks_->push_back(client);
	restaurant->queue_for_drink_->pop_front();

	agenda->push_back(new EndDrinks(Event::GetSystemTime() + time, flag));

}

void Events::CashierWork(std::list<Event*>* agenda, Restaurant * restaurant)
{
	std::cout << "Klienci obslugiwani sa przez kasjera " << std::endl;

	auto k = Generators::GetSeed();
	const auto time = static_cast<int>(Generators::Exp(Generators::CashierEventLambda(), k));
	Generators::SetSeed(k);

	const auto client = restaurant->queue_for_cashiers_->front();
	const auto flag = client->GetAware();
	restaurant->SetCashiers2();
	agenda->push_back(new CashierEvent(Event::GetSystemTime() + time, flag));
	restaurant->queue_for_cashiers_->pop_front();
}

void Events::SortAgenda(std::list<Event*>* agenda)
{
	std::cout << "Sortowanie tablicy zdarzen" << std::endl;
	const int x = agenda->size();

	const auto event = new Event*[x];	

	Event *event2;
	auto j = x;
	auto i = 0;
	while(j--)	 
	{
		event2 = agenda->front();
		event[i] = event2;
		i++;
		agenda->pop_front();
	}

	event2 = nullptr;
	//Tu sortowanie tablicy
		
	 	for ( i=1 ; i< x ; i++ )
		{
			j=i;
			event2 = event[i];
			while ((j>0) && ( event[j-1]->GetEventTime() > event2->GetEventTime() ))
		{
			event[j]=event[j-1];
			j--;
		}
			event[j]=event2;
		}

		//uzupe³enienie agendy posortowanymi zdarzeniami
		for (i = 0; i < x; i++)
		{
			agenda->push_back(event[i]);
		}
		delete event;
}

void Events::SortMembers(std::list<Client*>* members)
{
	const int x = members->size();  // do utworzenia wielkoœci tablicy wskaŸników

	const auto client = new Client*[x];	// dynamiczna tablica wskaŸników

	Client *client2;
	auto j = x;
	auto i = 0;
	while (j--)	//przypisanie listy zdarzeñ na tablicê 
	{
		client2 = members->front();
		client[i] = client2;
		i++;
		members->pop_front();
	}

	client2 = nullptr;
	//Tu sortowanie tablicê

	for (i = 1; i< x; i++)
	{
		j = i;
		client2 = client[i];
		while ((j>0) && (client[j - 1]->GetConsumption() > client2->GetConsumption()))
		{
			client[j] = client[j - 1];
			j--;
		}
		client[j] = client2;
	}

	//uzupe³enienie agendy posortowanymi zdarzeniami
	for (i = 0; i < x; i++)
	{
		members->push_back(client[i]);
	}
	delete client;
}

void Events::Start(std::list<Event*>* agenda, Restaurant *restaurant)
{
	std::cout << "Start symulacji  " << std::endl;
	agenda->push_back(new NewClient(0, false));

	auto k = Generators::GetSeed();
	const auto time = static_cast<int>(Generators::Norm(Generators::AlarmAvg(), Generators::AlarmSigma(), k));
	Generators::SetSeed(k);

	agenda->push_back(new Alarm(time, false));
}





