#include <stdio.h>
//배열의 모든 요소를 0으로 바꿔주는 함수
void erase(int* ptr, int length) {
	for (int i = 0; i <length; i++) {
		ptr[i] = 0;
		//*(ptr+i) = 0;
	}
}
int main() {
	int arr[4] = {1,2,3,4};
	int length = sizeof(arr) / sizeof(arr[0]);
	erase(arr, length);
	for (int i = 0; i < 4; i++) printf("%d\n", arr[i]);//배열의 모든 요소를 출력
	return 0;
}	