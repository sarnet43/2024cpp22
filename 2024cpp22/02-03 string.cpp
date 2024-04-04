#include <stdio.h>

int main(void) {
	char str[30] = "develop hungry";
	char str2[30];
	int i = 0;
	//str에 있는 내용을 str2에 복사.
	//'\0'을 만날때까지
	for (; str[i] != '\0'; i++) 
		str2[i] = str[i];
	str2[i] = str[i]; //널문자 ('\0')복사 

	printf("%s", str2);

}