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
        // �ߺ� ������ �����ϱ� ���� ���� ����
        id = new int();
        *id = nParam;
    }

    CUser(const CUser& rhs)
    {
        // �ߺ� ������ �����ϱ� ���� ���� ����
        id = new int();
        *id = *rhs.id;
    }

    // ���� ������ �����ε�
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
    CUser user1(user); // ���� ����

    // �Ʒ��� user.operator=(user1); �� ����
    user = user1; // ���� ����

    return 0;
}
#endif