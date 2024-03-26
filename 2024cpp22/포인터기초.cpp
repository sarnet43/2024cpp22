#include <iostream>
//이름공간, std::을 안해도 된다.
using namespace std;
int main() {
	int num = 3;
	cout << num << endl; //3 (변수에 들어있는 값)
	cout << &num << endl; //변수에 메모리 공간에 할당 되어있는 주소

	int arr[5] = { 10,20,30,40,50 };
	cout << arr << endl; //배열이 메모리 공간에 할당되어있는 주소
	
}