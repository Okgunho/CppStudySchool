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
	int salary = 0;				// ����
	int national = 0;			// ���ο���
	int health = 0;				// �ǰ�����
	int longTermCare = 0;		// ����纸��
	int employment = 0;			// ��뺸��
	int income = 0;				// �ҵ漼
	int localIncome = 0;		// ����ҵ漼
	const int taxFree = 200000; // �����
};

class Person {
public:
	int inputSalary() {
		cout << "���� �Է� (�� ����) : ";
		cin >> this->salary;
		return salary;
	}

	int inputIncomeTax() {
		cout << "�ҵ漼 �Է� (�� ����) : ";
		cin >> incomeTax;
		return incomeTax;
	}
private:
	int salary = 0;		// ����
	int incomeTax = 0;	// �ҵ漼
};

int main() {
	fourMajorInsurance insurance;
	Person person;
	
	insurance.setMonthlyPay(person.inputSalary());
	insurance.setIncomeTax(person.inputIncomeTax());
	insurance.includeTaxFree();

	cout << "���� ���� : " << insurance.nationalPension() << endl;
	cout << "�ǰ����� : " << insurance.healthInsurance() << endl; 
	cout << "����纸�� : " << insurance.longTermCareInsurance(insurance.healthInsurance()) << endl;
	cout << "��뺸�� : " << insurance.employmentInsurance() << endl;
	cout << "�ҵ漼 : " << fixed << insurance.getIncomeTax() << endl;
	cout << "����ҵ漼 : " << insurance.localIncomeTax() << endl;
	

	cout << "�Ǽ��ɾ� : " << fixed << insurance.finalSalary() << "��";

	return 0;
}

// 4�뺸��
// ���� ���� : �� �ҵ���� 4.5%
// �ǰ����� : ���������� 3.495%
// ����纸�� : �ǰ�������� 12.27%
// ��뺸�� : �� �ҵ���� 0.9%