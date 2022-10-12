#if false

// �𸣰ڵ�

#pragma once
#include <iostream>
using namespace std;

#pragma region CUserInfo Class Definition
class CUserInfo {
public:
    int id = 0;
    string name = "";
    CUserInfo(int inputId, string inputName);
    CUserInfo(const CUserInfo& Sp);
};
CUserInfo::CUserInfo(int inputId, string inputName) {
    id = inputId;
    name = inputName;
}
CUserInfo::CUserInfo(const CUserInfo& Sp) {
    id = Sp.id;
    name = Sp.name;
}
#pragma endregion


#pragma region CDepositInfo Class Definition
class CDepositInfo
{
public:
    int pay;
    int period;
    const float interestrate = 0.03f;
    const float tax = 0.154f;
    float DepositNormalResult;
    float DepositTaxResult;
};

class CDepositCalculator {
public:
    void DepositNormalCalc(CDepositInfo info);
    void DepositTaxCalc(CDepositInfo info);
    void DepositPrintResult(CDepositInfo info);
};

void CDepositCalculator::DepositNormalCalc(CDepositInfo info)
{
    info.DepositNormalResult = info.pay * info.interestrate;
    info.DepositNormalResult += info.pay * info.period;
}

void CDepositCalculator::DepositTaxCalc(CDepositInfo info)
{
    info.DepositTaxResult = info.DepositNormalResult - (info.DepositNormalResult * info.tax);
    info.DepositTaxResult += info.pay * info.period;
}
void CDepositCalculator::DepositPrintResult(CDepositInfo info) {
    cout << fixed << "���� : �ſ� " << info.pay << "�� " << info.period << "���� ��ġ�ϸ� " << info.DepositTaxResult << "��" << endl;
}
#pragma endregion

class CSavingsInfo
{
public:
    float monthlypay;
    float period;
    const float interestrate = 0.04f;
    const float tax = 0.154f;
    int SavingsNormalResult;
    int SavingsTaxResult;
};

class CSavingsCalculator {
public:
    void SavingsNormalCalc(CSavingsInfo info);
    void SavingsTaxCalc(CSavingsInfo info);
    void SavingsPrintResult(CSavingsInfo info);
};

void CSavingsCalculator::SavingsNormalCalc(CSavingsInfo info)
{
    info.SavingsNormalResult = (info.monthlypay * info.interestrate * (info.period + 1) * info.period / 2) / 12;
    info.SavingsNormalResult += info.monthlypay * info.period;
}

void CSavingsCalculator::SavingsTaxCalc(CSavingsInfo info)
{
    info.SavingsTaxResult = info.SavingsNormalResult - (info.SavingsNormalResult * info.tax);
    info.SavingsTaxResult += info.monthlypay * info.period;
}
void CSavingsCalculator::SavingsPrintResult(CSavingsInfo info) {
    cout << fixed << "�ſ� " << info.monthlypay << "���� " << info.period << "���� �Ա��ϸ� " << info.SavingsTaxResult << "��";
}

void main()
{

    //����� ���� �Է�
    string TempName;
    int Tempid;
    cout << "���̵� �Է��ϼ��� : ";
    cin >> Tempid;
    cout << "�̸��� �Է��ϼ��� : ";
    cin >> TempName;
    CUserInfo user(Tempid, TempName);

    // ���� ����
    CDepositInfo DepositInfo;
    CDepositCalculator DepositCalc;
    cout << "[���� �Է¶��Դϴ�.]" << endl;
    cout << "��ġ�� �ݾ��� �Է����ּ��� : ";
    cin >> DepositInfo.pay;
    cout << "��ġ�� �Ⱓ�� �Է����ּ��� : ";
    cin >> DepositInfo.period;
    DepositCalc.DepositNormalCalc(DepositInfo);
    DepositCalc.DepositTaxCalc(DepositInfo);

    // ���� ����
    CSavingsInfo SavingsInfo;
    CSavingsCalculator SavingsCalc;
    cout << "[���� �Է¶��Դϴ�.]" << endl;
    cout << "�ſ� �Ա��� �ݾ��� �Է����ּ��� : ";
    cin >> DepositInfo.pay;
    cout << "���� �Ⱓ�� �Է����ּ��� : ";
    cin >> DepositInfo.period;
    SavingsCalc.SavingsNormalCalc(SavingsInfo);
    SavingsCalc.SavingsTaxCalc(SavingsInfo);

    //���
    CUserInfo user1(user);
    cout << user1.id << "/" << user1.name << endl;
    DepositCalc.DepositPrintResult(DepositInfo);
    SavingsCalc.SavingsPrintResult(SavingsInfo);
}

#endif