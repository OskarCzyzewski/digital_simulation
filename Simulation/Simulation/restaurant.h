#pragma once
#include "client.h"
#include <list>
class Event;

class Restaurant
{
public:
	std::list<Client *> *queue_for_table_;
	std::list<Client *> *queue_for_buffet_;
	std::list<Client *> *queue_for_cashiers_;
	std::list<Client *> *queue_for_drink_;
	std::list<Client *> *queue_for_meal_;
	
	std::list<Client *> *buffet_members_;
	std::list<Client *> *clients_group_drinks_;
	std::list<Client *> *clients_group_meals_;
	std::list<Client *> *members_consumption_;
	
	static void SetCashiers();
	static void SetWaiters();
	static int GetCashiers();
	static void ManagerTrue();
	static void ManagerFalse();
	static bool GetManager();
	static int GetTableTwo();
	static int GetTableThree();
	static int GetTableFour();
	static void SetTableTwo(int );
	static void SetTableThree(int);
	static void SetTableFour(int );
	static void SetBuffetSeats(int);
	static void SetBuffetSeats2(int );
	static int GetBuffetSeats();
	static void SetWaiters2();
	static void SetCashiers2();
	static int GetWaiters();
	Restaurant();
	~Restaurant() = default;
	
private:
	static int waiters_; //number of waiters
	static int table_two_; //number of table for two
	static int table_three_; //number of table for three
	static int table_four_;	//number of table for four
	static int buffet_seats_; // number of seats in buffet place
	static bool manager_;	// variable to check if manager is available
	static int cashiers_;	//number of cashiers in restaurant


};

