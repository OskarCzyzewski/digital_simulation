// Simulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "restaurant.h"
#include <iostream>
#include "event.h"
#include "events.h"
#include "statistics.h"


int main()
{
	auto restaurant = new Restaurant();
	auto agenda = new std::list<Event*>();
	bool event_trig;
	int choice;
	std::cout << "Wybierz tryb:" << std::endl << "1: tryb krokowy " << std::endl << "2 : tryb ciagly " << std::endl;
	std::cin >> choice;
	Events::Start(agenda, restaurant);
	while(Event::GetClientId() < 15000)
	{
	if(choice == 1)
	{
		Event::SetSystemTime(agenda->front()->GetEventTime());
		std::cout << "Aktualny czas 1 zdarzenia: " << Event::GetSystemTime() << std::endl<<std::endl;
		agenda->front()->execute(agenda,restaurant);
		agenda->pop_front();
		std::cout << std::endl <<std::endl;
		getchar();
		do
		{
			event_trig = false;
			if(restaurant->queue_for_table_->size() > 0  && Restaurant::GetManager() && Events::ManagerChoice(agenda,restaurant))
			{
				event_trig = true;
				Events::ManagerWork(agenda, restaurant);
				getchar();
			}
			if(restaurant->queue_for_buffet_->size() > 0 && restaurant->GetBuffetSeats() >= restaurant->queue_for_buffet_->front()->GetNumberOfPeople() )
			{
				event_trig = true;
				Events::BuffetMembers(agenda, restaurant);
				getchar();
			}
			if(restaurant->queue_for_drink_->size() > 0 && Restaurant::GetWaiters() > 0 )
			{
				event_trig = true;
				Events::WaiterDrink(agenda, restaurant);
				getchar();
			}
			if(restaurant->queue_for_meal_->size() > 0 && Restaurant::GetWaiters() > 0)
			{
				event_trig = true;
				Events::WaiterFood(agenda, restaurant);
				getchar();
			}
			if(restaurant->queue_for_cashiers_->size() > 0 && Restaurant::GetCashiers() > 0)
			{
				event_trig = true;
				Events::CashierWork(agenda, restaurant);
				getchar();
			}

		} while (event_trig);
		Events::SortAgenda(agenda);
		std::cout << std::endl << std::endl;
	}
					
	if(choice ==2)
	{
		Event::SetSystemTime(agenda->front()->GetEventTime());

		std::cout << "Aktualny czas 1 zdarzenia: " << Event::GetSystemTime() << std::endl;
		agenda->front()->execute(agenda, restaurant);
		agenda->pop_front();

		std::cout << std::endl << std::endl;
		do
		{
			event_trig = false;
			if (restaurant->queue_for_table_->size() > 0 && Restaurant::GetManager() && Events::ManagerChoice(agenda, restaurant))
			{
				event_trig = true;
				Events::ManagerWork(agenda, restaurant);
				
			}
			if (restaurant->queue_for_buffet_->size() > 0 && restaurant->GetBuffetSeats() >= restaurant->queue_for_buffet_->front()->GetNumberOfPeople())
			{
				event_trig = true;
				Events::BuffetMembers(agenda, restaurant);
			}
			if (restaurant->queue_for_drink_->size() > 0 && Restaurant::GetWaiters() > 0)
			{
				event_trig = true;
				Events::WaiterDrink(agenda, restaurant);
				
			}
			if (restaurant->queue_for_meal_->size() > 0 && Restaurant::GetWaiters() > 0)
			{
				event_trig = true;
				Events::WaiterFood(agenda, restaurant);

			}
			if (restaurant->queue_for_cashiers_->size() > 0 && Restaurant::GetCashiers() > 0)
			{
				event_trig = true;
				Events::CashierWork(agenda, restaurant);
			}

		} while (event_trig);
		Events::SortAgenda(agenda);
		std::cout << std::endl;		
	}
	

	Statistics::SetAvgQueue(restaurant->queue_for_table_->size());
	
	Statistics::SetAvgCashier(restaurant->queue_for_cashiers_->size());
	
	
	std::cout << "Statystyki: " << std::endl;
	std::cout << "sredni czas oczekiwania na stolik: " << Statistics::GetAvgWait() << std::endl;
	std::cout << "srednia dlugosc kolejki do stolik: " << Statistics::GetAvgQueue() << std::endl;
	std::cout << "sredni czas oczekiwania na obsluge przez kelnera od momentu zajecia miejsca przy stoliku: " << Statistics::GetAvgWaiter() << std::endl;
	std::cout << "srednia dlugosc kolejki przy kasach " << Statistics::GetAvgCashier() << std::endl;
	

	std::cout << "Ilosc stolikow 4 osobowych " << Restaurant::GetTableFour() << std::endl;
	std::cout << "Ilosc stolikow 3 osobowych " << Restaurant::GetTableThree() << std::endl;
	std::cout << "Ilosc stolikow 2 osobowych " << Restaurant::GetTableTwo() << std::endl;
	std::cout << std::endl;
	}
	
	getchar();
    return 0;
}

