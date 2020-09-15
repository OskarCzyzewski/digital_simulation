#pragma once
#include <list>
#include "event.h"
	
//Class to define conditional events and start function

class Events
{
public:
	Events() = default;
	~Events() = default;
	static void ManagerWork(std::list<Event *> *agenda, Restaurant *restaurant);
	static bool ManagerChoice(std::list<Event *> *agenda, Restaurant *restaurant); // This function I'll use to choose client from queue ( S2 )
	static void BuffetMembers(std::list<Event *> *agenda, Restaurant *restaurant);
	static void WaiterFood(std::list<Event *> *agenda, Restaurant *restaurant);
	static void WaiterDrink(std::list<Event *> *agenda, Restaurant *restaurant);
	static void CashierWork(std::list<Event *> *agenda, Restaurant *restaurant);
	static void SortAgenda(std::list<Event *> *agenda);
	static void SortMembers(std::list<Client *> *members);
	static void Start(std::list<Event *> *agenda, Restaurant *restaurant);
};