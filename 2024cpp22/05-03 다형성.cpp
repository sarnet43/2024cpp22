#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
	virtual void walk(void) {
		cout << "걷다" << endl;
	}
	virtual void bark(void) {
		cout << "짖다" << endl;
	}
	virtual void eat(void) {
		cout << "먹다" << endl;
	}
	Animal(string name, unsigned int age, int leg_num)
		: name_(name), age_(age), leg_num_(leg_num) {
		cout << "이름 " << name << endl;
		cout << "나이 " << age << endl;
		cout << "다리 갯수 " << leg_num << endl;

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
	
	void bark() override { cout << "울프울프" << endl; }
	void eat() override { cout << "왕" << endl; }
	void walk() override { cout << "촵촵촵촵" << endl; }
private:
	int loyalty_;
};
void main(void) {
	Animal *animal = new Animal("요아조비", 8, 2);
	animal->bark();
	animal->walk();
	animal->eat();

	delete animal;

	animal = new Dog("마루", 5, 2, 100);
	animal->bark();
	animal->eat();
	animal->walk();

	delete animal;
}