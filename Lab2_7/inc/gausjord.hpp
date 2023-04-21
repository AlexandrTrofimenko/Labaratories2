#pragma once
#include <iostream>
namespace math
{
	class gausjord
	{
	public:
		gausjord(int n, int m, int order)
		{
			m_n = n;
			m_m = m;
			m_order = order;
			m_mat = new double*[m_n];
			for (int i = 0; i < m_n; i++)
			{
				m_mat[i] = new double[2*m_m];
			}
			for (int i = 0; i < m_order; i++)
			{
				for (int j = 0; j < 2 * m_order; j++)
				{
					if (j == (i + m_order))
						m_mat[i][j] = 1;
				}
			}
		}
		void gausjord::OutMatrix(int n, int m)

		{
			m_n = n;
			m_m = m;
			for (int i = 0; i < m_n; i++)
			{

				for (int j = 0; j < m_m; j++)
				{
					std::cout << m_mat[i][j] << "  ";
				}
				std::cout << "\n";
			}
		}
		void gausjord::OutInverse(int n,int m)

		{
			m_n = n;
			m_m = m;
			for (int i = 0; i < m_n; i++)
			{

				for (int j = m_n; j < m_m; j++)
				{
					std::cout << m_mat[i][j] << " ";
				}
				std::cout << "\n";
			}
			return;

		}
		void gausjord::InverseOfMatrix(int order)
		{
			double temp;
			m_order = order;
			std::cout << "=== Matrix ===\n";
			OutMatrix(m_order, m_order);
			for (int i = 0; i < m_order; i++)
			{
				for (int j = 0; j < 2 * m_order; j++)
				{
					if (j == (i + m_order))
						m_mat[i][j] = 1;
				}
			}
			for (int i = m_order - 1; i > 0; i--)
			{
				if (m_mat[i-1][0] < m_mat[i][0])
					for (int j = 0; j < 2 * m_order; j++)
					{

						temp = m_mat[i][j];
						m_mat[i][j] = m_mat[i - 1][j];
						m_mat[i - 1][j] = temp;
					}
			}
			std::cout << "\n=== Augmented Matrix ===\n";
			OutMatrix(m_order, m_order * 2);

			for (int i = 0; i < m_order; i++)
			{
				for (int j = 0; j < m_order; j++)
				{
					if (j != i)
					{
						temp = m_mat[j][i] / m_mat[i][i];
						for (int k = 0; k < 2 * m_order; k++)
						{
							m_mat[j][k] -= m_mat[i][k] * temp;
						}
					}
				}
			}
			for (int i = 0; i < m_order; i++)
			{
				temp = m_mat[i][i];
				for (int j = 0; j < 2 * m_order; j++)
				{
					m_mat[i][j] = m_mat[i][j] / temp;
				}
			}
			std::cout << "\n=== Inverse Matrix ===\n";
			OutInverse(m_order, 2 * m_order);
		}
		~gausjord()
		{
			std::cout << "Destructor" << std::endl;
			for (int i = 0; i < m_n; i++)
			{
				delete[] m_mat[i];
			}
			delete m_mat;
		}
		friend std::ostream& operator>>(std::ostream& in, gausjord& mat);

	public:
		int m_n, m_m;
		int m_order;
		double** m_mat;
	};
	std::istream& operator>>(std::istream& in, gausjord& mat)
	{
		for (int i = 0; i < mat.m_n; i++)
		{
			for (int j = 0; j < mat.m_m; j++)
			{
				in >> mat.m_mat[i][j];
			}
		}
		return in;
	}
}