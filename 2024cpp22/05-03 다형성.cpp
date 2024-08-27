#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
	//순수 가상함수(추상메서드)
	virtual void walk(void) = 0;
	virtual void bark(void) = 0;
	virtual void eat(void) = 0;
	
	Animal(string name, unsigned int age, int leg_num)
		: name_(name), age_(age), leg_num_(leg_num) {
		cout << "이름 " << name << endl;
		cout << "나이 " << age << endl;
		cout << "다리 갯수 " << leg_num << endl;

	}
	virtual ~Animal() {
		cout << "Animal 소멸자" << endl;
	}

private:
	string name_;
	unsigned int age_;
	int leg_num_;

};
class Dog : public Animal {
public:
	Dog(string name, unsigned int age, int leg_num, int loyalty)
		:Animal(name, age, leg_num),loyalty_ (loyalty) {
		cout << "충성도 " << endl;
	}
	virtual ~Dog() {
		cout << "Dog 소멸자" << endl;
	}
	void bark() override { cout << "울프울프" << endl; }
	void eat() override { cout << "왕" << endl; }
	void walk() override { cout << "촵촵촵촵" << endl; }
	
private:
	int loyalty_;
};
void main(void) {
	// 추상클래스는 객체를 생성할 수 없다. (new Animal() 불가)
	Animal *animal = new Dog("마루", 5, 2, 100);
	animal->bark();
	animal->eat();
	animal->walk();

	delete animal;
}