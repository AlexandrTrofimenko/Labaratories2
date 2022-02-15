// Ввод и вывод данных в расчете не учитывать. Считать, что 0 < N <= 10000.
// Вариант 6.
// Дана строка длины N.Если в ней есть хотя бы одна гласная, отсортируйте буквы по алфавиту.
#include <iostream>
#include <chrono>
#include <string>
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
void SWAPSORT(std::string& m) 
{
	for (int i = 0; i < m.length(); i++)
	{
		for (int j = i + 1; j < m.length(); j++)
		{
			if (m[i] > m[j])
			{
				std::swap(m[i], m[j]);
				
			}
		}			
	}	
}
bool isVowels(std::string& m, std::string& n)
{
	for (int i = 0; i < m.length(); i++)
	{
		for (int j = 0; j < n.length(); j++)
		{
			if (m[i] == n[j])
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	setlocale(LC_ALL,"RUS");
	std::cout << "Введите строчку:";
	int N = 0;
	std::string vowels = "eyuioa";
	std::string stroka;
	std::cin >> stroka;
	N = stroka.length();
	Timer t;
	if (isVowels(stroka, vowels))
	{
		std::cout << "Время : " << t.elapsed() << std::endl;
		SWAPSORT(stroka);
		std::cout << stroka <<std::endl;
	}
	else
	{
		std::cout << "Гласных нет" << std::endl;
	}
	return 0;
}