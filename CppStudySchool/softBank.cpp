#if false

#include <iostream>
using namespace std;

class Calculate {
public:
	int periodOfYear;	// 적금 기간
	int mMoney;	// 매달 입금할 금액
	float beforeTax = 0;
	float afterTax = 0;
	float interest = 3.55 / 100;
	
	int bfcalc() {
		for (int i = 0; i < periodOfYear * 12; i++)
		{
			beforeTax += mMoney;
			beforeTax += (float)mMoney * interest * ((float)periodOfYear*12 - i) / 12 ;
		}
		return beforeTax;
	}

	int afcalc() {
		for (int i = 0; i < periodOfYear * 12; i++)
		{
			afterTax += mMoney;
			afterTax += ((float)mMoney * interest * ((float)periodOfYear * 12 - i) / 12) * (84.6 / 100);
		}
		return afterTax;
	}
};

int main()
{
	Calculate cal;

	cout << "========적금 계산기========" << endl;
	
	cout << "적금 기간(년 단위, 최대 3년) : ";
	cin >> cal.periodOfYear;

	cout << "달마다 입금할 금액(원 단위) : ";
	cin >> cal.mMoney;

	cout << "세전 : " <<  cal.bfcalc() << endl;
	cout << "세후 : " << cal.afcalc() << endl;
}

#endif
