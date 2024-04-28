#include <iostream>
using namespace std;

// (1)���α׷� �ϼ�
class Dept {
	int size; // Scores �迭�� ũ��
	int* scores; // ���� �Ҵ� ���� ���� �迭�� �ּ�
public:
	Dept(int size) { // ������
		this->size = size;
		scores = new int[size];
	}
	Dept(const Dept& dept) { // ���� ������
		this->size = dept.size;
		this->scores = new int[(this->size)];
		for (int i = 0; i < (this->size); i++)
			this->scores[i] = dept.scores[i];
	}
	~Dept() { delete[] scores; } // �Ҹ���
	int getSize() { return size; }
	void read() { // size ��ŭ Ű���忡�� ������ �о� scores �迭�� ����
		cout << size << "�� ���� �Է�>> ";
		for (int i = 0; i < size; i++) // �ݺ���
			cin >> scores[i];
	}
	bool isOver60(int index) { // index�� �л��� ������ 60���� ũ�� true ����
		if (scores[index] > 60)
			return true;
		else
			return false;
	}
};

// (2)���� �����ڰ� ������ dept.scores�� com.scores ������. countPass() �Լ� ����� dept.scores �����Ҵ���� ����
// (2)main()�Լ� ����� com.scores �����Ҵ������ �����Ǹ� ���� ���� �߻�
int countPass(Dept dept) 
// dept �а��� 60�� �̻����� ����ϴ� �л��� �� ���� 
// (2)��������� ȣ��
// (3)Dept & dept�� ������ ���� ���� �߻����� ����
{
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10); // �� 10���� �ִ� �а� com
	com.read(); // �� 10���� �л����� ������ Ű����κ��� �о� scores �迭�� ����
	int n = countPass(com); // com �а��� 60�� �̻����� ����� �л��� ���� ����
	cout << "60�� �̻��� " << n << "��";
}