/*
������� 6
2.������� ������ ��������� ln x � 1 = 0 � ��������� �� 10^-4 � ������� ��������.
*/
#include <iostream>
double f(double a)
{
	return a - 10;
}
double bisection(double a,double b,double j)
{
	double fa = f(a);
	while (true)
	{
		double x = (a + b) / 2;
		if ((abs(x - a) < j) || (abs(x - b) < j))
		{
			return x;
		}
		else if (f(x) * fa > 0)
		{
			a = x;
		}
		else
		{
			b = x;
		}
	}
}