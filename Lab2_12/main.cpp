// map::begin/end
#include <iostream>
#include <map>

int main()
{
	std::map<char, int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " " << it->second << '\n';

	return 0;
}

/*#include <iostream>
#include <memory> // для std::shared_ptr
#include <string>

#include <iostream>
#include <memory> // для std::shared_ptr и std::weak_ptr
#include <string>

class Person
{
	std::string m_name;
	std::weak_ptr<Person> m_partner; // обратите внимание: теперь это std::weak_ptr

public:

	Person(const std::string& name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is now partnered with " << p2->m_name << "\n";

		return true;
	}
};

int main()
{
	auto lucy{ std::make_shared<Person>("Lucy") };
	auto ricky{ std::make_shared<Person>("Ricky") };

	std::cout << lucy.use_count() << std::endl;
	std::cout << ricky.use_count() << std::endl;

	partnerUp(lucy, ricky);

	std::cout << lucy.use_count() << std::endl;
	std::cout << ricky.use_count() << std::endl;

	return 0;
}*/

/*// 1. std::unique_ptr

class Person
{
public:
	Person(const std::string& name)
	{
		m_name = name;
	}

	std::string Name() { return m_name; }

private:
	std::string m_name;
};

void func(std::unique_ptr<Person> p, std::unique_ptr<Person> q)
{

}

std::unique_ptr<Person> PersonFactory(const std::string& name)
{
	return std::make_unique<Person>(name);
}

int main()
{
	//func(std::unique_ptr<Person>(new Person("Alex")), std::unique_ptr<Person>(new Person("Petr")));

	auto person = std::make_unique<Person>("Misha");
	person->Name();

	Person* raw = person.get();
	raw->Name();

	auto person_3 = PersonFactory("Ivan");

	auto person_2 = person;		// Копировать unique_ptr нельзя!!!



	return 0;
}*/


/*template <typename T>
class SmartPointer
{
public:
	SmartPointer(int n)
	{
		m_ptr = new T[n];
	}

	~SmartPointer()
	{
		delete[] m_ptr;
	}

	T* get() { return m_ptr; }

private:
	T* m_ptr;
};

int main()
{
	while (1)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		SmartPointer<double> mas(1000000);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	return 0;
}*/