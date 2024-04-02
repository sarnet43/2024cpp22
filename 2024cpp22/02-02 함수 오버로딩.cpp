#include <iostream>
//이름공간, std::을 안해도 된다.
using namespace std;
int int_mul(int a, int b) { 
	return a * b;
}
float float_mul(float a, float b) {
	return a * b;
}
int main() {
	cout << int_mul(2, 2) << endl;
	cout << float_mul(2.2f, 2.2f) << endl;
	
	return 0;
}