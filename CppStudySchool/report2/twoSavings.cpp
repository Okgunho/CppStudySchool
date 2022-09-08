#if true

#include<iostream>
using namespace std;

class Calculate {
public :
	int periodOfYear;	// ���� �Ⱓ
	int mMoney;	// �Ŵ� �Ա��� �ݾ�
	float beforeTax = 0;
	float afterTax = 0;
	float interest = 0;

	int interestKind(int kind) {
		if (kind == 1) { interest = 0.04; }
		else if (kind == 2) { interest = 0.03; }
		return interest;
	}
	

	int beforeTaxCalc() {
		for (int i = 0; i < periodOfYear * 12; i++)
		{
			beforeTax += mMoney;
			beforeTax += ((float)mMoney * interest * ((float)periodOfYear * 12 - i) / 12);
			
		}
		return beforeTax;
	}

	int afterTaxCalc() {
		for (int i = 0; i < periodOfYear * 12; i++)
		{
			afterTax += mMoney;
			afterTax += ((float)mMoney * interest * ((float)periodOfYear * 12 - i) / 12) * (84.6 / 100);
		}
		return afterTax;
	}
 

	void input() {
		cout << "���� �Ⱓ(�� ����, �ִ� 3��) : ";
		cin >> periodOfYear;

		cout << "�޸��� �Ա��� �ݾ�(�� ����) : ";
		cin >> mMoney;
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