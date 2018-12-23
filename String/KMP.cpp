/*
1.����������ƥ���㷨
2.��һ���ı���ƥ��
3.KMP�㷨
4.��next�ķ���
*/
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

int forceMatch1(String s1, String s2) {
	int i = 1, j = 1;
	for (;i <= s1.data[0] && j <= s2.data[0];) {
		if (s1.data[i] == s2.data[j]) {
			i++;
			j++;
		}
		else {
			i++;
			j = 1;
		}
	}
	if (j > s2.data[0]) {
		return i - s2.data[0];
	}
	else
		return -1;
}


int forceMatch2(String s1, String s2) {
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

void get_next(String s, int next[]) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i<=s.data[0]&&j<s.data[0])
	{
		if (s.data[i] == s.data[j] || j == 0) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];

		}

	}	
}

int KMP(String s1, String s2, int next[],int pos) {
	int i = pos, j = 1;
	while (i <= s1.data[0] && j <= s2.data[0]) {
		if (s1.data[i] == s2.data[j]||j==0) {
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j > s2.data[0]) {
		return i - s2.data[0];
	}
	else
		return -1;
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
	
	//�����㷨1
	n = forceMatch1(s1, s2);
	printf("forcematching 1\n");
	if (n == -1) {
		printf("��ƥ��\n");
	}
	else
		printf("ƥ�䣬���Ӵ������������ĵ�һ��λ���ǣ�%d\n", n);
	//�����㷨2
	n = forceMatch2(s1, s2);
	printf("forcematching 2\n");
	if (n == -1) {
		printf("��ƥ��\n");
	}
	else
		printf("ƥ�䣬���Ӵ������������ĵ�һ��λ���ǣ�%d\n", n);
	
	//���nextֵ

	int next[MAXSIZE];
	get_next(s2, next);
	printf("nextֵ\n");
	for (int i = 1;i <= s2.data[0];i++) {
		printf("%d", next[i]);
	}
	//KMP�㷨
	n = KMP(s1, s2, next,1);
	printf("\nKMP\n");
	if (n == -1) {
		printf("��ƥ��\n");
	}
	else
		printf("ƥ�䣬���Ӵ������������ĵ�һ��λ���ǣ�%d\n", n);
	return 0;
}