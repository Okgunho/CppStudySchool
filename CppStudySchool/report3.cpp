#include <iostream>

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
class Deposit : public UserInfo{
private:
	const float interest = 0.03;
	const float tax = 0.846;
	const float percentage = 1;
	float month;
	float depositAmount;
	float moneyWithInterest;
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

	float Calculator() {
		float year = month / 12;
		moneyWithInterest = depositAmount * (percentage + (interest * year) *tax);
		return moneyWithInterest;
	}
	// ���ݱݾ� * ��������  * 84.6 
};

// ����
class InstallmentSavings : public UserInfo {
private :
	const float interest = 0.04;
	const float percentage = 1;
	const float tax = 0.846;
	float month;
	float monthly_payment;
	float principal;
	float moneyWithInterest;
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

	float Calculator(){
		principal = monthly_payment * month;
		moneyWithInterest = principal * (percentage + (interest * (month  + 1) / 24 ) * tax );
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
		cout << "id :" << deposit.id << endl << "name : " << *deposit.name << endl;
		cout << fixed << "�����ݾ� : " << deposit.Calculator();
	}
	else if (savingKind == 2) {
		InstallmentSavings savings(userInfo);
		savings.Input();
		cout << "id :" << savings.id << endl << "name : " << *savings.name << endl;
		cout << fixed << "�����ݾ� : " << savings.Calculator();
	}
	
	return 0;
}