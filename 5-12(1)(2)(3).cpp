#include <iostream>
using namespace std;

// (1)프로그램 완성
class Dept {
	int size; // Scores 배열의 크기
	int* scores; // 동적 할당 받을 정수 배열의 주소
public:
	Dept(int size) { // 생성자
		this->size = size;
		scores = new int[size];
	}
	Dept(const Dept& dept) { // 복사 생성자
		this->size = dept.size;
		this->scores = new int[(this->size)];
		for (int i = 0; i < (this->size); i++)
			this->scores[i] = dept.scores[i];
	}
	~Dept() { delete[] scores; } // 소멸자
	int getSize() { return size; }
	void read() { // size 만큼 키보드에서 정수를 읽어 scores 배열에 저장
		cout << size << "개 점수 입력>> ";
		for (int i = 0; i < size; i++) // 반복문
			cin >> scores[i];
	}
	bool isOver60(int index) { // index의 학생의 성적이 60보다 크면 true 리턴
		if (scores[index] > 60)
			return true;
		else
			return false;
	}
};

// (2)복사 생성자가 없으면 dept.scores와 com.scores 동일함. countPass() 함수 종료시 dept.scores 동적할당공간 해제
// (2)main()함수 종료시 com.scores 동적할당공간도 해제되며 실행 오류 발생
int countPass(Dept dept) 
// dept 학과에 60점 이상으로 통과하는 학생의 수 리턴 
// (2)복사생성자 호출
// (3)Dept & dept로 수정시 실행 오류 발생하지 않음
{
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10); // 총 10명이 있는 학과 com
	com.read(); // 총 10명의 학생들의 성적을 키보드로부터 읽어 scores 배열에 저장
	int n = countPass(com); // com 학과에 60점 이상으로 통과한 학생의 수를 리턴
	cout << "60점 이상은 " << n << "명";
}