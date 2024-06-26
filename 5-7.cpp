#include<iostream>
using namespace std;

class MyIntStack {
    int p[10]; // 최대 10개의 정수 저장
    int tos; // 스택의 꼭대기를 가리키는 인덱스
public:
    MyIntStack();
    bool push(int n); // 정수 n 푸시. 꽉 차 있으면 false, 아니면 true 리턴
    bool pop(int& n); // 팝하여 n에 저장. 스택이 비어 있으면 false, 아니면 true 리턴
};

MyIntStack::MyIntStack() { tos = 0; }

bool MyIntStack::push(int n) {
    // 조건문 이용
    if (tos > 9)
        return false;
    else {
        p[tos] = n;
        tos++;
        return true;
    }
}

bool MyIntStack::pop(int& n) { // 참조에 의한 호출
    // 조건문 이용
    if (tos == 0)
        return false;
    else {
        tos--;
        n = p[tos];
        return true;
    }
}

int main() {
    MyIntStack a;
    for (int i = 0; i < 11; i++) { // 11개를 푸시하면, 마지막에는 stack full이 된다.
        if (a.push(i)) cout << i << ' '; // 푸시된 값 에코
        else cout << endl << i + 1 << " 번 째 stack full" << endl;
    }
    int n;
    for (int i = 0; i < 11; i++) { // 11개를 팝하면, 마지막에는 stack 가 된다.
        if (a.pop(n)) cout << n << ' '; // 팝 한 값 출력
        else cout << endl << i + 1 << " 번 째 stack empty";
    }
    cout << endl;
}
