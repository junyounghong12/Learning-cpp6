#include<iostream>
#include<cstring>
using namespace std;

class MyIntStack {
    int* p; // ���� �޸𸮷� ����� ������ 
    int size; // ������ �ִ� ũ�� 
    int tos; // ������ ž�� ����Ű�� �ε��� 
public:
    MyIntStack();
    MyIntStack(int size) { // �Ű������� �޴� ������
        p = new int[size]; // ���� �Ҵ�
        this->size = size;
        this->tos = 0; // 0���� �ʱ�ȭ
    }
    MyIntStack(const MyIntStack& s); // ���� ������ 
    ~MyIntStack() { delete[] p; } // �Ҹ���
    bool push(int n); // ���� n�� ���ÿ� Ǫ���Ѵ�.
        // ������ �� �� ������ false��, �ƴϸ� true ���� 
    bool pop(int& n); // ������ ž�� �ִ� ���� n�� ���Ѵ�.
        // ���� ������ ��� ������ false��, �ƴϸ� true ���� 
};
MyIntStack::MyIntStack(const MyIntStack& s) {
    this->size = s.size;
    this->tos = s.tos;
    this->p = new int[s.size];
    for (int i = 0; i < s.tos; i++) // �ݺ���
        this->p[i] = s.p[i]; // ���ο� ���ÿ� ����
}
bool MyIntStack::push(int n) {
    if (tos >= size) // ������ �� �� �ִ��� �Ǵ�
        return false;
    else {
        p[tos] = n;
        tos++;
        return true;
    }
}
bool MyIntStack::pop(int& n) {
    if (tos <= 0) // ������ ��� �ִ��� �Ǵ�
        return false;
    else {
        tos--;
        n = p[tos];
        return true;
    }
}

int main() {
    MyIntStack a(10);
    a.push(10);
    a.push(20);
    MyIntStack b = a; // ���� ���� 
    b.push(30);

    int n;
    a.pop(n); // ���� a �� 
    cout << "���� a���� ���� �� " << n << endl; // ���
    b.pop(n); // ���� b �� 
    cout << "���� b���� ���� �� " << n << endl; // ���
}