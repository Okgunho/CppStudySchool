#if false

#include<iostream>
using namespace std;

class Calculate {
public :
	int periodOfMonth;	// 적금 기간 
	int monthMoney;	// 매달 입금할 금액
	float beforeTax = 0;
	float afterTax = 0;
	float interest = 0;
	float tax = 0.846;

	int interestKind(int kind) {
		if (kind == 1) { interest = 0.04; }
		else if (kind == 2) { interest = 0.03; }
		return interest;
	}

	int beforeTaxCalc() {
		for (int i = 0; i < periodOfMonth; i++)
		{
			beforeTax += monthMoney;
			beforeTax += ((float)monthMoney * interest * ((float)periodOfMonth - i) / periodOfMonth);
		}
		return beforeTax;
	}

	int afterTaxCalc() {
		for (int i = 0; i < periodOfMonth; i++)
		{
			afterTax += monthMoney;
			afterTax += ((float)monthMoney * interest * ((float)periodOfMonth - i) / periodOfMonth) * tax;
		}
		return afterTax;
	}

	void input() {
		cout << "적금 기간(월 단위, 최대 36개월) : ";
		cin >> periodOfMonth;
		cout << "달마다 입금할 금액(원 단위) : ";
		cin >> monthMoney;
	}
};

int main()
{
	Calculate cal;

	int savingKind;

	cout << "========적금 계산기========" << endl;
	cout << "적금 종류 선택. (숫자로 선택)" << endl;
	cout << "1.특판 적금" << endl;
	cout << "2.일반 적금" << endl;
	cout << "선택 : ";
	cin >> savingKind;
	cal.interestKind(savingKind);
	cal.input();
	cout << "세전 : " << cal.beforeTaxCalc() << endl;
	cout << "세후 : " << cal.afterTaxCalc() << endl;
}

#endif