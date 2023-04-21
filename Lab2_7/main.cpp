#include <iostream>
#include <stdlib.h>
#include <matrix.hpp>
#include <gaus.hpp>
#include <kramer.hpp>
#include <gausjord.hpp>	
using namespace math;
void OutMatrix(double mat[][20],int n, int m)

{
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < m; j++)
		{
			std::cout << mat[i][j] << "  ";
		}
		std::cout << "\n";
	}
}
void OutInverse(int n, int m,double mat[][20])

{

	for (int i = 0; i < n; i++)
	{

		for (int j = n; j < m; j++)
		{
			std::cout << mat[i][j] << " ";
		}
		std::cout << "\n";
	}
	return;
}
void InverseOfMatrix(double mat[][20],int order)
{
	double temp;
	std::cout << "=== Matrix ===\n";
	OutMatrix(mat,order,order);
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < 2 * order; j++)
		{
			if (j == (i + order))
				mat[i][j] = 1;
		}
	}
	for (int i = order - 1; i > 0; i--)
	{
		if (mat[i-1][0] < mat[i][0])
			for (int j = 0; j < 2 * order; j++)
			{

				temp = mat[i][j];
				mat[i][j] = mat[i - 1][j];
				mat[i - 1][j] = temp;
			}
	}
	std::cout << "\n=== Augmented Matrix ===\n";
	OutMatrix(mat,order, order * 2);

	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			if (j != i)
			{
				temp = mat[j][i] / mat[i][i];
				for (int k = 0; k < 2 * order; k++)
				{
					mat[j][k] -= mat[i][k] * temp;
				}
			}
		}
	}
	for (int i = 0; i < order; i++)
	{
		temp = mat[i][i];
		for (int j = 0; j < 2 * order; j++)
		{
			mat[i][j] = mat[i][j] / temp;
		}
	}
	std::cout << "\n=== Inverse Matrix ===\n";
	OutInverse(order, 2 * order,mat);
}
int main()
{
	//Гаусс-Джордано
	int order;
	order = 3;
	double A[20][20] = {	{ 5, 1, 9 },
							 { 4, 2, 8 },
							 { 7, 0, 6 },
							 { 0 } };
	InverseOfMatrix(A, order);
	gausjord a(3, 3, 3);
	std::cin >> a;
	a.InverseOfMatrix(3);
	return 0;
}
/*int main()
{
	
	setlocale(LC_ALL, "Rus");
// Операции с матрицей 
	int i = 0;
	int j = 0;
	std::cout<< "Введите кол-во строк матрицы " << std::endl;
	std::cin >> i;
	std::cout<< "Введите кол-во столбцов матрицы " << std::endl;
	std::cin >> j;
	Matrix A(i, j);
	std::cout<< "Введите элементы матрицы A" << std::endl;
	std::cin >> A;
	std::cout << A;
	A.transposition();
	std::cout << A;
	A.transposition();
	std::cout << A;*/
// Метод решения СЛАУ методом Гаусса 
/*int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m;
	std::cout << "Введите кол-во ур-ний: ";
	std::cin >> n;
	std::cout << "Введите кол-во неизвестных: ";
	std::cin >> m;
	Gaus a(n, m);
	a.GausIn();
	a.GausOut();
	return 0;
}*/
/*	// Метод Крамера
int main()
{
	int n;
	std::cout << "Enter a number of variables "; 
	std::cin >> n;
	kramer A(n, n);
	A.Kramer(n);
	return 0;
}
*/