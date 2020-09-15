#include "stdafx.h"
#include "client.h"
#include "generators.h"


Client::Client(const int id, const int time_to)
{
	this->client_id_ = id;

	auto k = Generators::GetSeed();
	auto choice = Generators::Uniform(k);
	Generators::SetSeed(k);

	
	if (choice < 0.19) {
		this->number_people_ = 1;
	}
	else if (choice < 0.54) {
		this->number_people_ = 2;
	}
	else if (choice < 0.84) {
		this->number_people_ = 3;
	}
	else {
		this->number_people_ = 4;
	}
	
	this->time_to_table_ = time_to;
	this->time_to_waiter_ = 0;
	this->consumption_ = 0;
	this->table_ = 0;
	 k = Generators::GetSeed();
	 choice = Generators::Uniform(k);
	 Generators::SetSeed(k);
	
	 if (choice < 0.7)
	 {
		 aware_ = false;
	 }
	 else
	 {
		 aware_ = true;
	 }
	
}

Client::Client(const int id )
{
	this->client_id_ = id;
	auto k = Generators::GetSeed();
	auto choice = Generators::Uniform(k);
	Generators::SetSeed(k);


	if (choice < 0.19) {
		this->number_people_ = 1;
	}
	else if (choice < 0.54) {
		this->number_people_ = 2;
	}
	else if (choice < 0.89) {
		this->number_people_ = 3;
	}
	else {
		this->number_people_ = 4;
	}
	this->time_to_table_ = 0;
	this->time_to_waiter_ = 0;
	this->consumption_ = 0;
	this->table_ = 0;
	k = Generators::GetSeed();
	choice = Generators::Uniform(k);
	Generators::SetSeed(k);

	if (choice <= 0.7)
	{
		aware_ = false;
	}
	else
	{
		aware_ = true;
	}
}

int Client::GetId() const
{
	return this->client_id_;
}

bool Client::GetAware() const
{
	return this->aware_;
}

void Client::SetWait(int time)
{
	this->time_to_table_ = time - time_to_table_;
}

int Client::GetWait() const
{
	return this-> time_to_table_;
}

int Client::GetNumberOfPeople() const
{
	return this->number_people_;
}

void Client::SetTable(int x)
{
	this->table_ = x;
}

int Client::GetTable() const
{
	return this->table_;
}

void Client::SetConsumption(int x)
{
	this->consumption_ = x;
}

int Client::GetConsumption() const
{
	return this->consumption_;
}

int Client::GetTimeWaiter() const
{
	return this->time_to_waiter_;
}

void Client::SetTimeWaiter(int x)
{
	this->time_to_waiter_ = x - time_to_waiter_;
}
