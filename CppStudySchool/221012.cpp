#if false

#include<iostream>
using namespace std;

class CPerson
{
public:
	CPerson() : age(0)
	{
		cout << "CPerson()" << endl;
	}

	int GetAge()
	{
		return age;
	}

	void SetAge(int param)
	{
		age = param;
	}

protected:
	void Print()
	{
		cout << "CPerson::Print()" << endl;
	}

private:
	int age;
};

class CStudent : public CPerson
{
public:
	CStudent()
	{
		cout << "CStudent()" << endl;
	}

	void SetAge(int param) {
		if (param < 0)
		{
			CPerson::SetAge(0);
		}
	}

	void TestFunc()
	{
		Print();
		SetAge(45);
		cout << CPerson::GetAge() << endl; // GetAge()로 작성해도 무방
	}
};

void main() {
	CStudent student;

	CStudent& person = student;
	person.SetAge(10);
	cout << person.GetAge() << endl;
}

#endif