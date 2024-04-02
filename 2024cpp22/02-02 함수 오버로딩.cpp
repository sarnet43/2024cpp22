#include <iostream>
//이름공간, std::을 안해도 된다.
using namespace std;
int mul(int a, int b) { 
	return a * b;
}
float mul(float a, float b) {
	return a * b;
}
int main() {
	cout << mul(2, 2) << endl;
	cout << mul(2.2f, 2.2f) << endl;
	
	return 0;
}