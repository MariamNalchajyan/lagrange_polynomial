#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
#define n 10
using namespace std;


double SIN(double x)
{
	return sin(x * x * x);
}

double Lag(double x, vector<double> vect_x, vector<double> vect_y)
{
	double mult = 1;
	double sum = 0;
	for (int i = 0; i < vect_x.size(); i++)
	{
		for (int j = 0; j < vect_x.size(); j++)
		{
			if (i != j)
			{
				mult *= (x - vect_x[j]) / (vect_x[i] - vect_x[j]);
			}
		}
		sum += vect_y[i] * mult;
	}
	return sum;
}
vector<double> Lagrange(vector<double>vext_xj, vector<double> vect_x, vector<double> vect_y)
{
	vector<double> result;
	for (int i = 0; i < vext_xj.size(); i++)
	{
		result.push_back(Lag(vext_xj[i], vect_x, vect_y));
	}
	return result;
}


int main()
{
	vector<double> vect_x;
	vector<double> vect_y;
	vector<double> vect_xj;
	double a = 0;
	double b = 2;
	double h = (b - a) / n;
	cout << left << setw(5) << "x(i)" << " | " << left << setw(5) << "f(i)" << endl;
	for (int i = 0; i <= n ; i++)
	{
		double x = a + i * h;
		vect_x.push_back(x);
		vect_y.push_back(SIN(x));
		cout << left << setw(5) << vect_x.back() << " | " << left << setw(5) << vect_y.back() << endl;
	}
	cout << endl << endl;
	cout << left << setw(5) << "x(j)" << " | " << left << setw(5) << "F(j)" << endl;
	double x = 0;
	while (x < 2.00001)
	{
		vect_xj.push_back(x);
		x += 0.08;
	}
	vector<double> Fj = Lagrange(vect_xj, vect_x, vect_y);
	for (int i = 0; i < Fj.size(); i++)
	{
		cout << left << setw(5) << vect_xj[i] << " | " << left << setw(5) << Fj[i] << endl;
	}
	return 0;
}

