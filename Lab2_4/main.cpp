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
	//std::string surname;
	int age;
};

void ADD(T_List* head, int age)
{
	T_List* p = new T_List;
	p->age = age;

	p->next = head->next;
	head->next = p;
}

void PRINT(T_List* head)
{
	T_List* p = head->next;
	while (p != nullptr)
	{
		std::cout << p->age << std::endl;
		p = p->next;
	}
}

void DELETE(T_List* head)
{
	T_List* tmp;
	T_List* p = head;
	while (p->next != nullptr)
	{
		if (p->next->age % 2 == 0)
		{
			tmp = p->next;
			p->next = p->next->next;
			delete tmp;
		}
		else
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

void DUPLICATE(T_List* head)
{
	T_List* p = head->next;
	while (p != nullptr)
	{
		if (p->age % 2 == 1)
		{
			T_List* q = new T_List;
			q->next = p->next;
			p->next = q;
			q->age = p->age;
			p = p->next;
		}
		p = p->next;
	}
}

void SWAPSORT(T_List* head)
{
	//for(int i=0;i<n-1;i++)
	//	for(int j=i+1;j<n;j++)
	T_List* p = head->next;
	while (p->next->next != nullptr)
	{
		T_List* q = p->next;
		while (q->next != nullptr)
		{
			if (p->age > q->age)
				std::swap(p->age, q->age);
			q = q->next;
		}
		p = p->next;
	}
}

int main()
{
	srand(time(NULL));
	T_List* head = new T_List;
	head->next = nullptr;
	int N = 10000;
	int M = 1000;
	int k = rand();
	for (int i = 0; i < N; i++)
	{
		ADD(head, rand() % 10);
	}
//	PRINT(head);
	CLEAR(head);
	delete head;	

	return 0;
}