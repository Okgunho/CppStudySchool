#if false

#include<iostream>
using namespace std;

class Calculate {
public :
	int periodOfMonth;	// ���� �Ⱓ 
	int monthMoney;	// �Ŵ� �Ա��� �ݾ�
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
		cout << "���� �Ⱓ(�� ����, �ִ� 36����) : ";
		cin >> periodOfMonth;
		cout << "�޸��� �Ա��� �ݾ�(�� ����) : ";
		cin >> monthMoney;
	}
};

int main()
{
	Calculate cal;

	int savingKind;

	cout << "========���� ����========" << endl;
	cout << "���� ���� ����. (���ڷ� ����)" << endl;
	cout << "1.Ư�� ����" << endl;
	cout << "2.�Ϲ� ����" << endl;
	cout << "���� : ";
	cin >> savingKind;
	cal.interestKind(savingKind);
	cal.input();
	cout << "���� : " << cal.beforeTaxCalc() << endl;
	cout << "���� : " << cal.afterTaxCalc() << endl;
}

#endif