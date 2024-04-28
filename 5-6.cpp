#include <iostream>
#include <string>
using namespace std;

char& find(char a[], char c, bool& success) {
	int index = 0;
	while (a[index] != '\0') { // while 반복문
		// 문자열 a에서 문자 c를 찾으면 문자 c가 있는 공간에 대한 참조를 리턴
		if (a[index] == c) {
			success = true;
			return a[index];
		}
		index++;
	}
	success = false; //문자 c를 찾을 수 없다면 success 참조 매개 변수에 false를 설정
}

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M을 발견할 수 없다" << endl;
		return 0;
	}
	loc = 'm'; //‘M’위치에 'm' 기록
	cout << s << endl; //“mike"가 출력됨
}