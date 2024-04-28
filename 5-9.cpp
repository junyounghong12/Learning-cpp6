#include <iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value) { this->value = value; } // 매개 변수 value로 멤버 value를 초기화한다.
	Accumulator& add(int n); // value에 n을 더해 값을 누적한다.
	int get() { return value; } // 누적된 값 value를 리턴한다.
};

Accumulator& Accumulator::add(int n) {
	value += n;
	return *this; // 참조 리턴
}

int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc의 value 멤버가 280| 된다.
	cout << acc.get(); // 28 출력
}