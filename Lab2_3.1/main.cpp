/*
������� 6
2.������� ������ ��������� ln x � 1 = 0 � ��������� �� 10^-4 � ������� ��������.
*/
#include <iostream>
<<<<<<< HEAD
#include <cmath>
double f(double a)
{
	return log(a)-1;
=======
double f(double a)
{
	return a - 10;
>>>>>>> main
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
<<<<<<< HEAD
}
int main()
{
	std::cout << "ln (x)-1 = 0" << std::endl;
	double eps = 1e-4;
	double result = bisection(0, 10, eps);
	std::cout << "x = " << result;
	return 0;
=======
>>>>>>> main
}