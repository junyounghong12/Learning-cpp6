#include<iostream>
#include<string>
using namespace std;

class Book {
    string title; // ���� ���ڿ� 
    int price; //����
public:
    Book(string title, int price);
    void set(string title, int price);
    void show() { cout << title << ' ' << price << "��" << endl; }
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
    Book cpp("��ǰ C++", 10000);
    Book java = cpp;
    java.set("��ǰ�ڹ�", 12000);
    cpp.show();
    java.show();
}
