#include <stdio.h>
#include <string.h>
int main(void) {
	char str[30] = "develop hungry";
	char str2[30];
	int i = 0;
	//str에 있는 내용을 str2에 복사.
	//'\0'을 만날때까지
	strcpy(str2, str); //보안 취약

	printf("%s", str2);

}