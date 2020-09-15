#include "stdafx.h"
#include "restaurant.h"
#include <iostream>

int Restaurant::waiters_;
int Restaurant::table_two_;
int Restaurant::table_three_;
int Restaurant::table_four_;
int Restaurant::buffet_seats_;
bool Restaurant::manager_;
int Restaurant::cashiers_;


void Restaurant::SetCashiers()
{
	Restaurant::cashiers_++;
}

void Restaurant::SetWaiters()
{
	Restaurant::waiters_++;
}

int Restaurant::GetCashiers()
{
	return Restaurant::cashiers_;
}

void Restaurant::ManagerTrue()
{
	Restaurant::manager_ = true;
}

void Restaurant::ManagerFalse()
{
	Restaurant::manager_ = false;
}

bool Restaurant::GetManager()
{
	return Restaurant::manager_;
}

int Restaurant::GetTableTwo()
{
	return Restaurant::table_two_;
}

int Restaurant::GetTableThree()
{
	return Restaurant::table_three_;
}

int Restaurant::GetTableFour()
{
	return Restaurant::table_four_;
}

void Restaurant::SetTableTwo(const int x)
{
	if (x == 1)
		Restaurant::table_two_--;
	if (x == 0)
		Restaurant::table_two_++;
}

void Restaurant::SetTableThree(const int x)
{
	if (x == 1)
		Restaurant::table_three_--;
	if (x == 0)
		Restaurant::table_three_++;
}

void Restaurant::SetTableFour(const int x)
{
	if (x == 1)
		Restaurant::table_four_--;
	if (x == 0)
		Restaurant::table_four_++;
}

void Restaurant::SetBuffetSeats(const int x)
{
	Restaurant::buffet_seats_ -= x;
}

void Restaurant::SetBuffetSeats2(const int x)
{
	Restaurant::buffet_seats_ += x;
}

int Restaurant::GetBuffetSeats()
{
	return Restaurant::buffet_seats_;
}

void Restaurant::SetWaiters2()
{
	Restaurant::waiters_--;
}

void Restaurant::SetCashiers2()
{
	Restaurant::cashiers_--;
}

int Restaurant::GetWaiters()
{
	return Restaurant::waiters_;
}

Restaurant::Restaurant()
{
	waiters_ = 5;  //13
	table_two_ = 8;		//Not to change !!
	table_three_ = 14;	//Not to change !!
	table_four_ = 4;	//Not to change !!
	buffet_seats_ = 20; //Not to change !!
	manager_ = true;
	cashiers_ = 6;		// Not to change
	queue_for_table_ = new std::list<Client*>();
	queue_for_buffet_ = new std::list<Client *>();
	queue_for_cashiers_ = new std::list<Client *>();
	queue_for_drink_ = new std::list<Client*>();
	queue_for_meal_ = new std::list<Client*>();
	buffet_members_ = new std::list<Client*>();
	clients_group_drinks_ = new std::list<Client*>();
	clients_group_meals_ = new std::list<Client*>();
	members_consumption_ = new std::list<Client*>();
}



