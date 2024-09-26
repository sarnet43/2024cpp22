#include <iostream>


using namespace std;

void main(void) {
	
	//0 : 한식, 1 : 일식, 2 : 중식
	int style = 0;
	
	switch (style)
	{
	case 0:
		cout << "김치, 쌈, 비빔밥" << endl;
		break;
	case 1:
		cout << "초밥, 타코야끼" << endl;
		break;
	case 2:
		cout << "동파육, 마라탕후루" << endl;
	default:
		break;
	}
}