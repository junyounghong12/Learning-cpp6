#define _CRT_SECURE_NO_WARNINGS // ���� ���� ��� �޽����� ��Ȱ��ȭ
#include<iostream>
#include<cstring>
using namespace std;

class Book {
    char* title; // ���� ���ڿ� 
    int price; // ���� 
public:
    Book(const Book& b);
    /* (2)��
    Book::Book(const Book& b){
    this->title = b.title;
    this->price = b.price;
    }
    */
    Book(const char* title, int price);
    ~Book();
    void set(const char* title, int price);
    void show() { cout << title << ' ' << price << "��" << endl; }
};
Book::Book(const Book& b) { // (3)��
    int size = strlen(b.title);
    this->title = new char[size + 1];
    strcpy(this->title, b.title);
    this->price = b.price;
}
Book::Book(const char* title, int price) { // (1)��
    int size = strlen(title);
    this->title = new char[size + 1];
    strcpy(this->title, title);
    this->price = price;
}
Book::~Book() { // (1)��
    delete[] title;
}
void Book::set(const char* title, int price) { // (1)��
    if (this->title) 
        delete[] this->title;
    this->price = price;
    int size = strlen(title);
    this->title = new char[size + 1];
    strcpy(this->title, title);
}

int main() {
    Book cpp("��ǰ C++", 10000);
    Book java = cpp; // ���� ������ ȣ��� 
    java.set("��ǰ�ڹ�", 12000);
    cpp.show();
    java.show();
}
