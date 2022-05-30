#include <iostream>
#include <memory> 
#include <string>
class Teacher;
class Student
{
public:
	Student(const std::string& name)
	{
		m_name = name;

		std::cout << "Student +" << std::endl;

	}
	~Student()
	{
		std::cout << "Student -" << std::endl;
	}

	std::string NameS() 
	{ 
		return m_name; 
	}
	std::shared_ptr<Student> GetT()
	{ 
		m_teacher; 
	}

	friend void teach(std::shared_ptr<Teacher>& T, std::shared_ptr<Student>& S);
private:
	std::string m_name;
	std::shared_ptr<Teacher> m_teacher;
};
class Teacher
{
public:
	Teacher(const std::string& name)
	{
		m_name = name;
		m_i = -1;

		std::cout << "Teacher +" << std::endl;

	}
	~Teacher()
	{

		std::cout << "Teacher -" << std::endl;
	}
	std::shared_ptr<Student> GetS()
	{
		return m_student[m_i];
	}
	void addstudent()
	{
		m_i = m_i + 1;
		std::cout << "Student create" << std::endl;
	}
	friend void teach(std::shared_ptr<Teacher>& T, std::shared_ptr<Student>& S);


private:
	std::string m_name;
	int m_i;
	std::shared_ptr<Student> m_student[10];

};

void teach(std::shared_ptr<Teacher>& T, std::shared_ptr<Student>& S)
{
	T->addstudent();
	S->m_teacher = T;
	T->GetS() = S;
	std::cout << T->m_name << " teach " << S->m_name << std::endl;
}

int main()
{
	std::shared_ptr<Student> student1 = std::make_shared<Student>("Misha");
	std::shared_ptr<Student> student2 = std::make_shared<Student>("Sanencka");
	std::shared_ptr<Student> student2 = std::make_shared<Student>("PavlyshaSmirn");
	std::shared_ptr<Teacher> teacher = std::make_shared<Teacher>("Maksim Vladimirovich");
	teach(teacher, student1);
	teach(teacher, student2);
}