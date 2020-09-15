#pragma once
class Client
{
public:
	Client(int,int);
	Client(int);
	~Client() = default;
	int GetId() const;
	
	bool GetAware() const;
	
	void SetWait(int);
	int GetWait() const;
	
	int GetNumberOfPeople() const;
	
	void SetTable(int );
	int GetTable() const;
	
	void SetConsumption(int);
	int GetConsumption() const;
	
	int GetTimeWaiter() const;
	void SetTimeWaiter(int);

private:
	int client_id_;			//ID number
	int number_people_;		//number of people in group
	int time_to_table_;		//this variable shows how much time this group spend in queue to table
	int time_to_waiter_;	//this variable shows how much time this group waited for waiter
	bool aware_;			//this variable shows if this person is aware of the malfunction of the alarm
	int table_;				//this variable shows what size of table client
	int consumption_;       //I'll use this variable to sort clients in groups 
};

