#if false

#include <iostream>
using namespace std;

class CUser
{
public:
    CUser()
    {
        id = new int();
        cout << "constructor" << endl;
    }

    CUser(int nParam)
    {
        // 중복 참조를 방지하기 위해 깊은 복사
        id = new int();
        *id = nParam;
    }

    CUser(const CUser& rhs)
    {
        // 중복 참조를 방지하기 위해 깊은 복사
        id = new int();
        *id = *rhs.id;
    }

    // 대입 연산자 오버로딩
    CUser& operator=(const CUser& rhs)
    {
        *id = *rhs.id;
        return *this;
    }

    int GetID() const
    {
        return *id;
    }

    void SetID(int nParam)
    {
        *id = nParam;
    }

    ~CUser()
    {
        delete id;
    }

private:
    int* id;
};

CUser TestFunc(CUser param)
{
    return param;
}

int main()
{
    CUser user(10);
    CUser user1(user); // 얕은 복사

    // 아래는 user.operator=(user1); 과 같음
    user = user1; // 얕은 복사

    return 0;
}
#endif