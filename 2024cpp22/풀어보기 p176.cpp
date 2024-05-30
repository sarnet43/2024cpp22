#include <iostream>
#include <string>
using namespace std;
class Person {
public:
	Person(string name, int hakbun)
		:name_(name), hakbun_(hakbun) {
	}
	~Person() {
	}
	void printshow() {
		cout << name_ << "의 학번은 " << hakbun_ << endl;
		
	}
private:
	string name_;
	int hakbun_;
};
class Student : public Person {
public:
	Student(string name, int hakbun, string university) : Person(name, hakbun), university_(university){

	}
	~Student() {
	}
	void printshow() {
		cout << university_ << " ";
		Person::printshow();
	}
private:
	string university_;
};

int main(void) {
	Student* stu = new Student("SUA", 2209, "mirim");
	stu->printshow();
	delete stu;
	return 0;
}