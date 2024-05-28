﻿#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	Person(string name, int age)
		:name_(name), age_(age) {}
	void show_person() {
		cout << name_ << "의 나이는 " << age_ << "입니다." << endl;
	}
private:
	string name_;
	int age_;
};

class Student : public Person {
public:
	//부모 생성자가 먼저 호출
	Student(string name, int age, int id) : Person(name, age), id_(id) {

	}
	void show_person()
	{
		cout << id_ << " ";
		Person::show_person();//부모클래스의 멤버함수 호출
	}
private:
	int id_;
};
int main(void) {
	Student* stu = new Student("sua", 18, 2209);
	stu->show_person();
	return 0;
}