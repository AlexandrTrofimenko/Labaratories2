/*
Вариант 6.
Создайте односвязный список из N = 10000 целых чисел и реализуйте операцию поиска в нем элемента k. 
Выполните M = 1000 поисковых запросов.
Реализуйте такую же операцию для массива. Сравните производительность
*/
#include <iostream>
struct T_List
{
	T_List* next;
	int elements;
};

void ADD(T_List* head, int elements)
{
	T_List* p = new T_List;
	p->elements = elements;

	p->next = head->next;
	head->next = p;
}
void PRINT(T_List* head)
{
	T_List* p = head->next;
	while (p != nullptr)
	{
		std::cout << p->elements << std::endl;
		p = p->next;
	}
}
void CLEAR(T_List* head)
{
	T_List* tmp;
	T_List* p = head->next;
	while (p != nullptr)
	{
		tmp = p;
		p = p->next;
		delete tmp;
	}
}

bool FIND(T_List* head,int x)
{
	T_List* p = head->next;
	while (p->next->next != nullptr)
	{
		if (p->elements == x)
		{
			return true;
		}
		else
		{
			p = p->next;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	T_List* head = new T_List;
	head->next = nullptr;
	int N = 10000;
	int M = 1000;
//	int k = rand();
	int x = 0;
	for (int i = 0; i < N; i++)
	{
		ADD(head, rand() %10);
	}
//	PRINT(head);
	std::cin >> x;
	if (FIND(head,x) == true)
	{
		std::cout << x << "-найден" << std::endl;
	}
	else
	{
		std::cout << x << "-не найден" << std::endl;
	}
	CLEAR(head);
	delete head;
	return 0;
}