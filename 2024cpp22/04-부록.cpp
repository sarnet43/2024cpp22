#include <iostream>
#include <string>

using namespace std;

class Animal {
protected: // private에서 protected로 변경
    string name;
    int age;

public:
    Animal(string _name, int _age) : name(_name), age(_age) {}

    virtual void sound() = 0; // 순수 가상 함수로 변경
    virtual ~Animal() {} // 가상 소멸자 추가
};

class Dog : public Animal {
public:
    Dog(string _name, int _age) : Animal(_name, _age) {}

    void bark() {
        cout << "왈 왈" << endl;
    }

    void sound() override {
        bark();
    }
};

int main() {
    Dog myDog("Buddy", 3);

    myDog.sound();

    return 0;
}
