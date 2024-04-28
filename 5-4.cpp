#include<iostream>
using namespace std;

bool bigger(int a, int b, int& big) { // 매개변수 big은 참조에 의한 전달 방식
    //조건문 
    if (a == b)
        return true;
    if (a > b)
        big = a;
    else
        big = b;
    return false;
}

int main() {
    int a, b, big;
    cout << "두 정수 입력>>"; // 지시문
    cin >> a >> b; // 입력
    if (!bigger(a, b, big))
        cout << "큰 정수는 : " << big; // 출력
    else
        cout << "같음";
}
