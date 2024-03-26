#include <iostream>
//이름공간, std::을 안해도 된다.
using namespace std;
void call_by_pointer(int* val) {
	//새로운 지역변수 val을 만들고  val가 가리키고 있는 대상의 값을 바꾼다.
	*val = 10;
}
int main() {
	int num = 4; 
	//num의 값은 바뀐다
	call_by_pointer(&num);
	cout << num;
	return 0;
}	