#if false

#include <iostream>
using namespace std;

class CUser
{
public:
    // 묵시적 변환 생성 막기.
    explicit CUser(int param)
        :id(param)
    {
        cout << "constructor" << endl;
    }

    operator int(void)
    {
        return id;
    }

    CUser(const CUser& rhs)
    {
        cout << "copy constructor" << endl;
    }

    int GetID() const
    {
        return id;
    }

    void SetID(int nParam)
    {
        id = nParam;
    }

private:
    int id = 0;
};

void TestFunc(CUser user)
{
    cout << "TestFunc : " << user.GetID() << endl;
}

int main()
{
    CUser user(10);

    cout << user << endl;
    cout << (int)user << endl;
    cout << static_cast<int>(user) << endl;

    return 0;
}

#endif