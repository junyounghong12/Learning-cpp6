#define _CRT_SECURE_NO_WARNINGS // 보안 관련 경고 메시지를 비활성화
#include<iostream>
#include<cstring>
using namespace std;

class Book {
    char* title; // 제목 문자열 
    int price; // 가격 
public:
    Book(const Book& b);
    /* (2)답
    Book::Book(const Book& b){
    this->title = b.title;
    this->price = b.price;
    }
    */
    Book(const char* title, int price);
    ~Book();
    void set(const char* title, int price);
    void show() { cout << title << ' ' << price << "원" << endl; }
};
Book::Book(const Book& b) { // (3)답
    int size = strlen(b.title);
    this->title = new char[size + 1];
    strcpy(this->title, b.title);
    this->price = b.price;
}
Book::Book(const char* title, int price) { // (1)답
    int size = strlen(title);
    this->title = new char[size + 1];
    strcpy(this->title, title);
    this->price = price;
}
Book::~Book() { // (1)답
    delete[] title;
}
void Book::set(const char* title, int price) { // (1)답
    if (this->title) 
        delete[] this->title;
    this->price = price;
    int size = strlen(title);
    this->title = new char[size + 1];
    strcpy(this->title, title);
}

int main() {
    Book cpp("명품 C++", 10000);
    Book java = cpp; // 복사 생성자 호출됨 
    java.set("명품자바", 12000);
    cpp.show();
    java.show();
}
