#include <iostream>
using namespace std;

class fourMajorInsurance{
public:
	int includeTaxFree() {
		salary -= taxFree;
		return salary;
	}

	int localIncomeTax() {
		localIncome = income / 10;
		return localIncome;
	}

	int nationalPension() {
		national = salary * 0.045;
 		return national;
	}

	int healthInsurance() {
		health = salary * 0.03495;
		return health;
	}

	int longTermCareInsurance(int param) {
		longTermCare = param * 0.1227;

		return longTermCare;
	}

	int employmentInsurance() {
		employment = salary * 0.009;
		return employment;
	}

	int finalSalary() {
		salary += taxFree;
		salary -= (national + health + longTermCare + employment + income + localIncome);
		return salary;
	}

	void setMonthlyPay(float salary) {
		this->salary = salary;
	}

	int getMonthlyPay() {
		return this->salary;
	}

	void setIncomeTax(float incomeTax) {
		this->income = incomeTax;
	}

	int getIncomeTax() {
		return this->income;
	}

private:
	int salary = 0;				// 월급
	int national = 0;			// 국민연금
	int health = 0;				// 건강보험
	int longTermCare = 0;		// 장기요양보험
	int employment = 0;			// 고용보험
	int income = 0;				// 소득세
	int localIncome = 0;		// 지방소득세
	const int taxFree = 200000; // 비과세
};

class Person {
public:
	int inputSalary() {
		cout << "월급 입력 (원 단위) : ";
		cin >> this->salary;
		return salary;
	}

	int inputIncomeTax() {
		cout << "소득세 입력 (원 단위) : ";
		cin >> incomeTax;
		return incomeTax;
	}
private:
	int salary = 0;		// 월급
	int incomeTax = 0;	// 소득세
};

int main() {
	fourMajorInsurance insurance;
	Person person;
	
	insurance.setMonthlyPay(person.inputSalary());
	insurance.setIncomeTax(person.inputIncomeTax());
	insurance.includeTaxFree();

	cout << "국민 연금 : " << insurance.nationalPension() << endl;
	cout << "건강보험 : " << insurance.healthInsurance() << endl; 
	cout << "장기요양보험 : " << insurance.longTermCareInsurance(insurance.healthInsurance()) << endl;
	cout << "고용보험 : " << insurance.employmentInsurance() << endl;
	cout << "소득세 : " << fixed << insurance.getIncomeTax() << endl;
	cout << "지방소득세 : " << insurance.localIncomeTax() << endl;
	

	cout << "실수령액 : " << fixed << insurance.finalSalary() << "원";

	return 0;
}

// 4대보험
// 국민 연금 : 월 소득액의 4.5%
// 건강보험 : 보수월액의 3.495%
// 장기요양보험 : 건강보험료의 12.27%
// 고용보험 : 월 소득액의 0.9%