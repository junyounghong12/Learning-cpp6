#include <iostream>
using namespace std;

class Circle {
	int r; // private 멤버 변수
public:
	Circle(int r) { this->r = r; } // 생성자
	int getn() { return r; } // r 반환
	void setn(int r) { this->r = r; } // r 설정
};

// 두 Circle 객체를 교환하는 swap()함수 (참조에 의한 호출)
void swap(Circle& x, Circle& y) {
	int temp = x.getn();
	x.setn(y.getn());
	y.setn(temp);
}

int main() {
	Circle c1(10), c2(20); // 두 Circle 객체
	cout << "c1:" << c1.getn() << " ,c2:" << c2.getn() << endl;
	swap(c1, c2); // swap 함수 호출
	cout << "c1:" << c1.getn() << " ,c2:" << c2.getn() << endl; // 교환 후 출력
}