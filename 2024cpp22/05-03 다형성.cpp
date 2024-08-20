#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
	void walk(void) {
		cout << "걷다" << endl;
	}
	void bark(void) {
		cout << "짖다" << endl;
	}
	void eat(void) {
		cout << "먹다" << endl;
	}
	Animal(string name, unsigned int age, int leg_num)
		: name_(name), age_(age), leg_num_(leg_num) {}

private:
	string name_;
	unsigned int age_;
	int leg_num_;

};

void main(void) {
	Animal *animal = new Animal("요아조비", 8, 2);
	animal->bark();
	animal->walk();
	animal->eat();

	delete animal;
}