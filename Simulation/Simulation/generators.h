#pragma once
class Generators
{
public:
	double static  Uniform(int &x);   //Uniform generator
	double static Exp(double,int &x); //Exponential generator
	double static Norm(int ,double,int &x );  //Gauss generator
	
	int static NewClientAvg();		//to new client
	int static NewClientSigma();		//to new client

	int static EndBuffetAvg();		//to end buffet
	int static EndBufferSigma();		//to end buffet

	int static EndDrinkLambda();	//to end drink

	int static EndMealLambda();	//to end food

	int static EndConsumptionLambda();	//to end consumption

	int static CashierEventLambda();	//to cashier event

	int static AlarmAvg();		//to alarm
	int static AlarmSigma();		//to alarm

	static int GetSeed();
	static void SetSeed(int);
private:
	static int avg_a_;		//to new client
	static int sigma_a_;	//to new client
	
	static int avg_b_;		//to end buffet			!!Not to change!!
	static int sigma_b_;	//to end buffet
	
	static int lambda_n_;	//to end drink
	
	static int lambda_j_;	//to end food
	
	static int lambda_f_;	//to end consumption	!! Not to change !!

	static int lambda_p_;	//to cashier event

	static int avg_e_;		//to alarm
	static int sigma_e_;	//to alarm

	static int x_;
	 
	Generators() = default;
	~Generators() = default;
};

