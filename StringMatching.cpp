//string match �ı����㷨

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct String {
	char *data;
}String;

void initString(String &string) {
	string.data = (char*)malloc(sizeof(char)*MAXSIZE);
	string.data[0] = 0;
}

void createString(String &string) {

	printf("�������ַ���,�Իس�������\n");
	int n = 0;
	char c;
	while (true)
	{

		scanf_s("%c", &c);
		if (c == '\n')
			break;
		n++;
		string.data[n] = c;

	}
	string.data[0] = n;
}
void showString(String string) {
	for (int i = 1;i <=string.data[0];i++) {
		printf("%c", string.data[i]);
	}
	printf("\n");
}

int forcesMatch2(String s1, String s2) {
	int i = 1, j = 1;
	for (;i <=s1.data[0]&&j <=s2.data[0];) {
		if (s1.data[i] == s2.data[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 2;
			j = 1;
		}

	}
	if (j > s2.data[0]) {
		return i-s2.data[0];
	}
	else {
		return -1;
	}

}

int main() {
	String s1, s2;
	initString(s1);
	initString(s2);
	printf("��������������Ϣ:\n");
	createString(s1);
	showString(s1);
	printf("�������Ӵ�����Ϣ:\n");
	createString(s2);
	showString(s2);
	int n = 0;
	n = forcesMatch2(s1, s2);
	if (n == -1) {
		printf("��ƥ��\n");
	}
	else
		printf("ƥ�䣬���Ӵ������������ĵ�һ��λ���ǣ�%d\n", n);
	return 0;
}