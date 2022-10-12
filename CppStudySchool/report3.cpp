#if false

#include <iostream>

#define percentage 1
#define tax 0.846
#define depositInterest 0.03
#define savingsInterest 0.04

using namespace std;

class UserInfo
{
public:
	UserInfo() = default;

	UserInfo(const UserInfo& userinfo)
	{
		name = new string();
		*name = *userinfo.name;
	}

	int id;
	string* name = new string();
};


// ����
class Deposit : public UserInfo {
private:
	double month;
	double depositAmount;
	double moneyWithInterest;
public:
	Deposit(const UserInfo& userinfo)
	{
		name = new string();
		*name = *userinfo.name;
	}

	void Input() {
		cout << "���� �Ⱓ (�� ����) : ";
		cin >> month;
		cout << "���� �ݾ� (�� ����) : ";
		cin >> depositAmount;
	}

	int Calculator() {
		double year = month / 12;
		moneyWithInterest = depositAmount * (percentage + (depositInterest * year) * tax);
		return moneyWithInterest;
	}
	// ���ݱݾ� * ��������  * ����
};

// ����
class InstallmentSavings : public UserInfo {
private:
	double month;
	double monthly_payment;
	double moneyWithInterest;
public:
	InstallmentSavings(const UserInfo& userinfo)
	{
		name = new string();
		*name = *userinfo.name;
	}

	void Input() {
		cout << "���� �Ⱓ (�� ����) : ";
		cin >> month;
		cout << "�Ŵ� �Ա� �ݾ� (�� ����) : ";
		cin >> monthly_payment;
	}

	int Calculator() {
		int principal = monthly_payment * month;
		moneyWithInterest = principal * (percentage + (savingsInterest * (month + 1) / 24) * tax);
		return moneyWithInterest;
	}
	//���� ���� ���� ������ = { ���� �� ��������(���� ���� �� + 1)��24 }��(1 - ���ڼҵ漼��)
};

int main() {
	int savingKind;

	UserInfo userInfo;
	//���̵� ���
	cout << "���̵� �Է� (���ڷθ�) : ";
	cin >> userInfo.id;
	cout << "�̸� �Է� : ";
	cin >> *userInfo.name;

	cout << "1.���� 2.����" << endl;
	cout << "�����Ͻÿ�. (��ȣ��)" << endl;
	cin >> savingKind;

	if (savingKind == 1) {
		Deposit deposit(userInfo);
		deposit.Input();
		cout << "id :" << userInfo.id << endl << "name : " << *deposit.name << endl;
		cout << fixed << "�����ݾ� : " << deposit.Calculator();
	}
	else if (savingKind == 2) {
		InstallmentSavings savings(userInfo);
		savings.Input();
		cout << "id :" << userInfo.id << endl << "name : " << *savings.name << endl;
		cout << fixed << "�����ݾ� : " << savings.Calculator();
	}
	return 0;
}

#endif