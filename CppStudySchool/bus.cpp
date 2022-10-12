#if false

#include<iostream>
#include<time.h>

using namespace std;

class Bus {
public:
	int a(int a, int b) {
		int aaa = interval - a % interval - b;
		if (aaa < 0) {
			aaa += interval;
		}
		return aaa;
	}

private:
	int interval = 20;
};

class Human {
public:
	void setHour(int hour) {
		this->cureentHour = hour;
	}

	void setMin(int min) {
		this->currentMin = min;
	}

	int getHour() {
		return this->cureentHour;
	}

	int getMin() {
		return this->currentMin;
	}

	float humanSpeed() {
		return distance / speed * 60;
	}

private:
	int cureentHour = 0;
	int currentMin = 0;
	float distance= 470;
	float speed = 4000;
};

class InputTime {
public:
	int inputHour() {
		cout << "현재 시간 (24시간제) : ";
		cin >> this->hour;
		return hour;
	}

	int inputMin() {
		cout << "현재 분 : ";
		cin >> this->min;
		return min;
	}

	int changeTimeToMin() {
		return hour * 60 + min;
	}
private:
	int hour;
	int min;
};

int main()
{
	Bus bus;
	Human human;
	InputTime time;

	human.setHour(time.inputHour());
	human.setMin(time.inputMin());

	cout << bus.a(time.changeTimeToMin(), human.humanSpeed()) << "분 뒤에 출발하시오.";
}

#endif
