#include <iostream>
#include <string>
using namespace std;

char& find(char a[], char c, bool& success) {
	int index = 0;
	while (a[index] != '\0') { // while �ݺ���
		// ���ڿ� a���� ���� c�� ã���� ���� c�� �ִ� ������ ���� ������ ����
		if (a[index] == c) {
			success = true;
			return a[index];
		}
		index++;
	}
	success = false; //���� c�� ã�� �� ���ٸ� success ���� �Ű� ������ false�� ����
}

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M�� �߰��� �� ����" << endl;
		return 0;
	}
	loc = 'm'; //��M����ġ�� 'm' ���
	cout << s << endl; //��mike"�� ��µ�
}