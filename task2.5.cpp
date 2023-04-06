/*Створити абстрактний базовий клас прогресія із віртуальною функцією 
сума прогресії. Створити похідні класи: арифметична прогресія й геометрична 
прогресія. Кожний клас має два поля типу double. Перше - перший член прогресії, 
друге (double) - постійна прогресії. (Арифметична прогресія aj=a0+jd, j=0,1,2,… сума 
арифметичної прогресії: sn=(n+1)(a0+an)/2, геометрична прогресія: aj=a0r
j
, j=0,1,2,… 
сума геометричної прогресії: sn=(a0-anr)/(1-r) ).*/

#include <iostream>
#include <math.h>

using namespace std;

class Progression
{
public:
	Progression() : a0(0) {}
	Progression(double a0) : a0(a0) {}

	virtual double sum(int n) = 0;

protected:
	double a0;
};

class ArithmeticProgression : protected Progression
{
public:
	ArithmeticProgression() : d(0) {}
	ArithmeticProgression(double a0, double d) : Progression(a0), d(d) {}

	double sum(int n)
	{
		double an = a0 + (n - 1) * d;
		return n * (a0 + an) / 2.0;
	}

protected:
	double d;
};

class GeometricProgression : protected Progression
{
public:
	GeometricProgression() : r(0) {}
	GeometricProgression(double a0, double r) : Progression(a0), r(r) {}

	double sum(int n)
	{
		double an = a0 * pow(r, n - 1);
		return (an * r - a0) / (r - 1);
	}

protected:
	double r;
};

int main()
{
	ArithmeticProgression ap(1, 1);
	cout << "ArithmeticProgression(1, 1), sum 1..6: " << ap.sum(6) << endl;
	GeometricProgression gp(1, 2);
	cout << "GeometricProgression(1, 2), sum 1..6: " << gp.sum(6) << endl;
}