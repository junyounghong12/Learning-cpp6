#include<iostream>
using namespace std;

bool bigger(int a, int b, int& big) { // �Ű����� big�� ������ ���� ���� ���
    //���ǹ� 
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
    cout << "�� ���� �Է�>>"; // ���ù�
    cin >> a >> b; // �Է�
    if (!bigger(a, b, big))
        cout << "ū ������ : " << big; // ���
    else
        cout << "����";
}
