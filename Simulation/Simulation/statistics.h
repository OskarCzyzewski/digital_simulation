#pragma once
#include "restaurant.h"

class Statistics
{

public:
	Statistics() = default;
	~Statistics() = default;
	
	static double GetAvgWait();
	static void SetAvgWait(int);

	static double  GetAvgQueue();
	static void SetAvgQueue(int);

	static double GetAvgWaiter();
	static void SetAvgWaiter(int);

	static double GetAvgCashier();
	static void SetAvgCashier(int);

	static void ResetStatistics();

	static int GetPeople(Restaurant *);

	static bool GetPhase();
	static void SetPhase();
private:
	static double avg_wait_for_table_;
	static int count_wait_for_table_;
	static int n_wait_for_table_;

	static double avg_queue_table_length_;
	static int count_queue_table_length_;
	static int n_queue_table_length_;

	static double avg_waiter_;
	static int count_waiter_;
	static int n_waiter_;

	static double avg_queue_cashier_length_;
	static int count_queue_cashier_length_;
	static int n_queue_cashier_length_;

	static bool phase_;		
};

