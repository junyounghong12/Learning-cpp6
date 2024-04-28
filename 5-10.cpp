#include <iostream>
#include <string>
using namespace std;

class Buffer {
	string text; // 멤버 변수
public:
	Buffer(string text) { this->text = text; } // 생성자
	void add(string next) { text += next; } // text에 next 문자열 덧붙이기
	void print() { cout << text << endl; } // 출력
};

Buffer& append(Buffer& b, string t) { // Buffer 객체에 문자열을 추가하고 Buffer 객체에 대한 참조를 반환
	b.add(t);
	return b;
}

int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys"); // buf의 문자열에 "Guys" 덧붙임
	temp.print(); // "HelloGuys" 출력
	buf.print(); // "HelloGuys" 출력
}