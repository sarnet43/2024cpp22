#include <stdio.h>
#include <string.h>
int main(void) {
	//기존 문자열에다가 추가
	char str[30] = "c";
	strcat(str, "add");

	printf("%s",str);


}