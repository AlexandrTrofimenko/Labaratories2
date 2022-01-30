// Ввод и вывод данных в расчете не учитывать. Считать, что 0 < N <= 10000.
// Вариант 6.
// Дана строка длины N.Если в ней есть хотя бы одна гласная, отсортируйте буквы по алфавиту.
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
void Sort(char mas[10000])
{
	for (int i = 0; i < strlen(mas)-1; i++)
	{
		for (int j = i + 1; j < strlen(mas) - 1; j++)
		{
			if (mas[i] > mas[j])
			{
				std::swap(mas[i], mas[j]);
			}
		}			
	}	
}
bool isVowels(char mas[10000],char n[7])
{
	for (int i = 0; i < strlen(mas) - 1; i++)
	{
		for (int j = i + 1; j < strlen(n); j++)
		{
			if (mas[i] == mas[j])
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
	unsigned short int N = 10000;
	char vowels[7] = "eyuioa";
	char* stroka = new char[N];
	std::cin.getline(stroka, N);
	Timer t;
	if (isVowels(stroka, vowels))
	{
		Sort(stroka);
		std::cout << "Время : " << t.elapsed() << std::endl;
		for (int i = 0; i < strlen(stroka)-1; i++)
		{
			std::cout << stroka[i];
		}
	}
	else
	{
		std::cout << "Гласных нет" << std::endl;
	}
	delete[] stroka;
	return 0;
}