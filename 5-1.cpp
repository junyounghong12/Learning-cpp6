#include <iostream>
using namespace std;

class Circle {
	int r; // private ��� ����
public:
	Circle(int r) { this->r = r; } // ������
	int getn() { return r; } // r ��ȯ
	void setn(int r) { this->r = r; } // r ����
};

// �� Circle ��ü�� ��ȯ�ϴ� swap()�Լ� (������ ���� ȣ��)
void swap(Circle& x, Circle& y) {
	int temp = x.getn();
	x.setn(y.getn());
	y.setn(temp);
}

int main() {
	Circle c1(10), c2(20); // �� Circle ��ü
	cout << "c1:" << c1.getn() << " ,c2:" << c2.getn() << endl;
	swap(c1, c2); // swap �Լ� ȣ��
	cout << "c1:" << c1.getn() << " ,c2:" << c2.getn() << endl; // ��ȯ �� ���
}