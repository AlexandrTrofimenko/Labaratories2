/*
¬ариант 6
1.	–еализуйте алгоритм бинарного поиска, о котором шла речь на лекции.
–ешите задачу выполнени€ M (0<M<10000) поисковых запросов над массивом из N (0<N<100000) элементов,
использу€ проход по массиву циклом и бинарный поиск. 
—равните врем€ работы этих двух подходов.
*/
#include <iostream>
#include <chrono>
class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};
int BinarySearch(int* mass, int l, int n, int k)
{
	if (k < mass[l])
	{
		return -1;
	}
		
	if (k == mass[l])
	{
		return 0;
	}
	if (k > mass[n])
	{
		return -1;
	}

	int a = l;
	int b = n;

	while (a + 1 < b)
	{
		int c = (a + b) / 2;
		if (k > mass[c])
		{
			a = c;
		}
		else
		{
			b = c;
		}
	}
	if (mass[b] == k)
	{
		return b;
	}
	else
	{
		return -1;
	}
}
int main()
{
	srand(time(NULL));
	int M = 10000;
	int N = 100000;
	int* mass = new int [N];
	int k = rand() % +1;
	for (int i = 0; i < N; i++)
	{
		mass[i] = rand();
	}
	Timer A;
	for (int i = 0; i < M; i++)
	{
		BinarySearch(mass, 0, N - 1, k);
	}
	std::cout << "BinarySearch = " << A.elapsed() << std::endl;
	Timer B;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (mass[j] == k)
			{
				break;
			}
	std::cout << "Search= " << B.elapsed() << std::endl;
	return 0;
}