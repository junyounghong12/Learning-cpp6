#include<iostream>
#include<string>
using namespace std;

class Book {
    string title; // 제목 문자열 
    int price; //가격
public:
    Book(string title, int price);
    void set(string title, int price);
    void show() { cout << title << ' ' << price << "원" << endl; }
};
Book::Book(string title, int price) {
    this->title = title;
    this->price = price;
}
void Book::set(string title, int price) {
    this->title = title;
    this->price = price;
}

int main() {
    Book cpp("명품 C++", 10000);
    Book java = cpp;
    java.set("명품자바", 12000);
    cpp.show();
    java.show();
}
