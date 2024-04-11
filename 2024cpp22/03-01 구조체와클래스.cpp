#include <iostream>
#include <string>
using namespace std;
class Student {
public: 
	//생성자 : 객체가 생성될 때 호출되는 함수
	//생성자는 반환형이 없다. 
	Student() {
		hakbun_ = 2222;
		name_ = "이미림";
	}
	Student(int hakbun, string name) {
		hakbun_ = hakbun;
		name_ = name;
	}
	//클래스의 멤버를 출력, 함수이름 : show
	void show(void) {
		cout << hakbun_<< " ";
		cout << name_ << endl;

}
private:
	int hakbun_;
	string name_;
	
 };
int main(void) {
	//동적할당 : 메모리는 heap에서 할당, 실행(런타임)시 메모리 크기가 정해짐
	Student* jisu = new Student(2202, "나지수");

	//정적할당 : 메모리는 stack할당 , 컴파일시 메모리 크기가 정해짐
	Student mirim = Student();
	jisu->show();
	mirim.show();

	//동적할당 해제
	delete jisu;
	return 0;

}