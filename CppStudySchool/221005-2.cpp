#if false

#include <iostream>
using namespace std;

class CUser {
public:
	CUser()
	{
		cout << "CUser() " << endl;
	}

	~CUser()
	{
		cout << "~CUser() " << endl;
	}

	CUser(const CUser& rhs) : id(rhs.id)
	{
		cout << "CUser(const CUser& rhs)" << endl;
	}

	CUser(const CUser&& rhs) : id(rhs.id)
	{
		cout << "CUser(const CUser&& rhs)" << endl;
	}

	CUser& operator=(const CUser&) = default;

	int GetData() const 
	{
		return id;
	}

	void SetData(int nParam)
	{
		id = nParam;
	}
private:
	int id = 0;
};

CUser Func(int nParam)
{
	CUser a;

	return a;
}

int main() 
{
	CUser user;
	CUser user2 = Func(10);
}


#endif