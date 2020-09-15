#include "stdafx.h"
#include "statistics.h"

double Statistics::avg_wait_for_table_ = 0;
int Statistics::count_wait_for_table_= 0;
int Statistics::n_wait_for_table_= 1;

double Statistics::avg_queue_table_length_ = 0;
int Statistics::count_queue_table_length_ = 0;
int Statistics::n_queue_table_length_= 1;

double Statistics::avg_waiter_ = 0;
int Statistics::count_waiter_ = 0;
int Statistics::n_waiter_ = 1;

double Statistics::avg_queue_cashier_length_ = 0;
int Statistics::count_queue_cashier_length_ = 0;
int Statistics::n_queue_cashier_length_ = 1;

bool Statistics::phase_ = false;

double Statistics::GetAvgWait()
{
	return Statistics::avg_wait_for_table_;
}

void Statistics::SetAvgWait(const int val)
{
	Statistics::count_wait_for_table_ += val;
	Statistics::avg_wait_for_table_ = static_cast<double>(Statistics::count_wait_for_table_) / Statistics::n_wait_for_table_;
	Statistics::n_wait_for_table_++;
}

double Statistics::GetAvgQueue()
{
	return Statistics::avg_queue_table_length_;
}


void Statistics::SetAvgQueue(const int val)
{
	Statistics::count_queue_table_length_ += val;
	Statistics::avg_queue_table_length_ = static_cast<double>(Statistics::count_queue_table_length_) / Statistics::n_queue_table_length_;
	Statistics::n_queue_table_length_++;

}

double Statistics::GetAvgWaiter()
{
	return Statistics::avg_waiter_;
}

void Statistics::SetAvgWaiter(const int val)
{
	Statistics::count_waiter_ += val;
	Statistics::avg_waiter_ = static_cast<double>(Statistics::count_waiter_) / Statistics::n_waiter_;
	Statistics::n_waiter_++;
}

double Statistics::GetAvgCashier()
{
	return Statistics::avg_queue_cashier_length_;
}

void Statistics::SetAvgCashier(const int val)
{
	Statistics::count_queue_cashier_length_ += val;
	Statistics::avg_queue_cashier_length_ = static_cast<double>(Statistics::count_queue_cashier_length_) / Statistics::n_queue_cashier_length_;
	Statistics::n_queue_cashier_length_++;
}

void Statistics::ResetStatistics()
{
	avg_wait_for_table_ = 0;
	count_wait_for_table_ = 0;
	n_wait_for_table_ = 1;

	avg_queue_table_length_ = 0;
	count_queue_table_length_ = 0;
	n_queue_table_length_ = 1;

	avg_waiter_ = 0;
	count_waiter_ = 0;
	n_waiter_ = 1;

	avg_queue_cashier_length_ = 0;
	count_queue_cashier_length_ = 0;
	n_queue_cashier_length_ = 1;
}

int Statistics::GetPeople(Restaurant *restaurant)
{
	
	int const x =restaurant->queue_for_table_->size() + restaurant->queue_for_buffet_->size() + restaurant->queue_for_cashiers_->size() + restaurant->queue_for_drink_->size() + restaurant->queue_for_meal_->size() + restaurant->members_consumption_->size() + restaurant->clients_group_meals_->size() + restaurant->clients_group_drinks_->size() + restaurant->buffet_members_->size();
	return x;
}

bool Statistics::GetPhase()
{
	return Statistics::phase_;
}

void Statistics::SetPhase()
{
	Statistics::phase_ = true;
}
