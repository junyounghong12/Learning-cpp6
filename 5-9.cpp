#include <iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value) { this->value = value; } // �Ű� ���� value�� ��� value�� �ʱ�ȭ�Ѵ�.
	Accumulator& add(int n); // value�� n�� ���� ���� �����Ѵ�.
	int get() { return value; } // ������ �� value�� �����Ѵ�.
};

Accumulator& Accumulator::add(int n) {
	value += n;
	return *this; // ���� ����
}

int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc�� value ����� 280| �ȴ�.
	cout << acc.get(); // 28 ���
}