#include "stdafx.h"
#include <cmath>
#include "generators.h"

int Generators::avg_a_ = 420;		//to new client	//1500 
int Generators::sigma_a_ = 50;		//to new client //100

int Generators::avg_b_ = 2900;		//to end buffet			!!Not to change!!
int Generators::sigma_b_ = 80;		//to end buffet

int Generators::lambda_n_ = 830;	//to end drink	//370

int Generators::lambda_j_ = 2000;	//to end food

int Generators::lambda_f_ = 2020;	//to end consumption	!! Not to change !!

int Generators::lambda_p_ = 2500;	//to cashier event		//220

int Generators::avg_e_ = 4200;		//to alarm
int Generators::sigma_e_ = 50;		//to alarm

int Generators::x_ = 423669749;		//seed

double Generators::Uniform(int & x)
{
	const auto a = 16807;
	const auto q = 127773;
	const auto r = 2836;
	double const range = 2147483647;   //2^31 -1


	const auto h = x / q;
	x = a * (x - q * h) - r * h;
	if (x < 0) x += range;
	const auto val = static_cast<double>(x) / range;
	return val;
}

double Generators::Exp(const double avg, int & x)
{
	const auto k = log(Generators::Uniform((x)));
	auto const val = ((-1)*(k))*avg;
	return val;
}

double Generators::Norm(const int average, const double variance, int & x)
{
	double y = 0;
	const auto n = 12;
	for (auto i = 0; i < n; i++)
	{
		y += Uniform(x);
	}
	return int(((y - (double(n) / 2))*(variance * 12 / n)) + average);
}

int Generators::NewClientAvg()
{
	return Generators::avg_a_;
}

int Generators::NewClientSigma()
{
	return Generators::sigma_a_;
}

int Generators::EndBuffetAvg()
{
	return Generators::avg_b_;
}

int Generators::EndBufferSigma()
{
	return Generators::sigma_b_;
}

int Generators::EndDrinkLambda()
{
	return Generators::lambda_n_;
}

int Generators::EndMealLambda()
{
	return Generators::lambda_j_;
}

int Generators::EndConsumptionLambda()
{
	return Generators::lambda_f_;
}

int Generators::CashierEventLambda()
{
	return Generators::lambda_p_;
}

int Generators::AlarmAvg()
{
	return Generators::avg_e_;
}

int Generators::AlarmSigma()
{
	return Generators::sigma_e_;
}

int Generators::GetSeed()
{
	return Generators::x_;
}

void Generators::SetSeed(const int x)
{
	Generators::x_ = x;
}
