#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct String {
	char *data;
	int length;
}String;

void initString(String &string){
	string.data = (char*)malloc(sizeof(char)*MAXSIZE);
	string.length = 0;
}

void createString(String &string) {

	printf("请输入字符串,以回车键结束\n");
	int n = 0;
	char c;
	do
	{	
		scanf_s("%c", &c);
		string.data[n] = c;
		n++;
	} while (c != '\n'); 
	string.length = n;
}
void showString(String string) {
	for (int i = 0;i <string.length;i++) {
		printf("%c", string.data[i]);
	}
	printf("\n");
}

int stringMatching(String s1, String s2) {
	int i = 0, j = 0;
	for (;i < s1.length-1, j <s2.length-1;) {
			if (s1.data[i] == s2.data[j]) {
				i++;
				j++;
				continue;
			}
			else {
				i = i - j + 2;
				j = 0;
				continue;
			}

		}
	if (i > s1.length) {
		return -1;
	 }
	else {
		return i - j + 1;
	}

}

int main() {
	String s1,s2;
	initString(s1);
	initString(s2);
	printf("请输入主串的信息:\n");
	createString(s1);
	printf("请输入子串的信息:\n");
	createString(s2);
	int n = 0;
	n = stringMatching(s1, s2);
	if (n == -1) {
		printf("不匹配\n");
	}
	else
		printf("匹配，该子串出现在主串的第一个位置是：%d\n", n);
	return 0;
}