#pragma once
#include <iostream>
namespace math
{
	class kramer
	{
	public:
		kramer(int n,int m)
		{
			m_n = n;
			m_m = m;
			m_matrix = new double* [m_n];
			for (int i = 0; i < m_n; i++)
			{
				m_matrix[i] = new double[m_m];
			}
			m_freeVar = new double [m_n];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
				{
					std::cout << "A[" << i << "][" << j << "]=";
					std::cin >> m_matrix[i][j];
				}

			std::cout << std::endl << "Please enter free variables" << std::endl;
			for (int i = 0; i < n; i++)
			{
				std::cout << "b[" << i << "]=";
				std::cin >> m_freeVar[i];
			}
			m_answer = new double[m_n];
		}
		double DET(int n,double** mat)
		{
			mat = m_matrix;
			double d = 0;
			int c, subi, i, j, subj;
			double** submat;
			submat = new double* [n];
			for (int i = 0; i < n; i++)
				submat[i] = new double[n];

			if (n == 2)
			{
				return((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
			}
			else
			{
				for (c = 0; c < n; c++)
				{
					subi = 0;
					for (i = 1; i < n; i++)
					{
						subj = 0;
						for (j = 0; j < n; j++)
						{
							if (j == c)
							{
								continue;
							}
							submat[subi][subj] = m_matrix[i][j];
							subj++;
						}
						subi++;
					}
					d = d + (pow(-1, c) * m_matrix[0][c] * DET(n - 1, submat));
				}
			}
			delete[] submat;
			return d;

		}
		void Kramer(int n)
		{
			double* detArray = new double[n];
			double deterMain;
			double* temp = new double[n];
			std::cout << "Finding determinant of main matrix" << std::endl;
			std::cout << "deterMain = ";
			deterMain = DET(n, m_matrix);
			std::cout << deterMain << std::endl;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					temp[j] = m_matrix[i][j];
					m_matrix[i][j] = m_freeVar[j];
				}
				detArray[i] = DET(n, m_matrix);
				for (int k = 0; k < n; k++)
				{
					m_matrix[i][k] = temp[k];
				}
			}

			for (int i = 0; i < n; i++)
			{
				m_answer[i] = detArray[i] / deterMain;
				std::cout << m_answer[i] << std::endl;
			}
			delete[] detArray;
			delete[] temp;
		}
		~kramer()
		{
			for (int i = 0; i < m_n; i++)
			{
				delete[] m_matrix[i];
			}
			delete m_matrix;
			delete m_freeVar;
			delete m_answer;
		}
	private:
		int m_n, m_m;
		double** m_matrix;
		double* m_freeVar;
		double* m_answer;
	};
}