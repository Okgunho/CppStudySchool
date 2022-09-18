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
// 예금
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
		cout << "예금 기간 (월 단위) : ";
		cin >> month;
		cout << "예금 금액 (원 단위) : ";
		cin >> depositAmount;
	}

	float Calculator() {
		float year = month / 12;
		moneyWithInterest = depositAmount * (percentage + (interest * year) *tax);
		return moneyWithInterest;
	}
	// 예금금액 * 예금이자  * 84.6 
};
// 적금
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
		cout << "적금 기간 (월 단위) : ";
		cin >> month;
		cout << "매달 입금 금액 (원 단위) : ";
		cin >> monthly_payment;
	}

	float Calculator(){
		principal = monthly_payment * month;
		moneyWithInterest = principal * (percentage + (interest * (month  + 1) / 24 ) * tax );
		return moneyWithInterest;
	}
	//세후 적금 실제 이자율 = { 적금 연 이자율×(만기 개월 수 + 1)÷24 }×(1 - 이자소득세율)
};

int main() {
	int savingKind;

	UserInfo userInfo;
	//아이디 비번
	cout << "아이디 입력 (숫자로만) : ";
	cin >> userInfo.id;
	cout << "이름 입력 : ";
	cin >> *userInfo.name;

	cout << "1.예금 2.적금" << endl;
	cout << "선택하시오. (번호로)" << endl;
	cin >> savingKind;

	if (savingKind == 1) {
		Deposit deposit(userInfo);
		deposit.Input();
		cout << "id :" << deposit.id << endl << "name : " << *deposit.name << endl;
		cout << fixed << "최종금액 : " << deposit.Calculator();
	}
	else if (savingKind == 2) {
		InstallmentSavings savings(userInfo);
		savings.Input();
		cout << "id :" << savings.id << endl << "name : " << *savings.name << endl;
		cout << fixed << "최종금액 : " << savings.Calculator();
	}
	return 0;
}

// test