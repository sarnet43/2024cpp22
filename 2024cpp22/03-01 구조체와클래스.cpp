#include <iostream>
#include <string>
using namespace std;
struct Student {

	int hakbun_;
	string name_;

 };
int main(void) {
	Student jisu;
	//구조체는 default가 pubic이다. 
	jisu.hakbun_ = 2202;
	jisu.name_ = "나지수";

	return 0;

}