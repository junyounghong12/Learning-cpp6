#include<iostream>
using namespace std;

class MyIntStack {
    int p[10]; // �ִ� 10���� ���� ����
    int tos; // ������ ����⸦ ����Ű�� �ε���
public:
    MyIntStack();
    bool push(int n); // ���� n Ǫ��. �� �� ������ false, �ƴϸ� true ����
    bool pop(int& n); // ���Ͽ� n�� ����. ������ ��� ������ false, �ƴϸ� true ����
};

MyIntStack::MyIntStack() { tos = 0; }

bool MyIntStack::push(int n) {
    // ���ǹ� �̿�
    if (tos > 9)
        return false;
    else {
        p[tos] = n;
        tos++;
        return true;
    }
}

bool MyIntStack::pop(int& n) { // ������ ���� ȣ��
    // ���ǹ� �̿�
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
    for (int i = 0; i < 11; i++) { // 11���� Ǫ���ϸ�, ���������� stack full�� �ȴ�.
        if (a.push(i)) cout << i << ' '; // Ǫ�õ� �� ����
        else cout << endl << i + 1 << " �� ° stack full" << endl;
    }
    int n;
    for (int i = 0; i < 11; i++) { // 11���� ���ϸ�, ���������� stack �� �ȴ�.
        if (a.pop(n)) cout << n << ' '; // �� �� �� ���
        else cout << endl << i + 1 << " �� ° stack empty";
    }
    cout << endl;
}
