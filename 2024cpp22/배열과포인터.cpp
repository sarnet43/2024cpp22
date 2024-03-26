#include <stdio.h>

int main() {
	int arr[4] = {1,2,3};
	char str[4] = "asd";

	printf("%d  %d\n", &arr[0], &arr[1]); //주소값 4바이트만큼의 차이
	printf("%d  %d\n", &str[0], &str[1]); //주소값 1바이트만큼의 차이

	return 0;
}	