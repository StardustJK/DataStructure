#include<stdio.h>
#include<stdlib.h>
/*
Լɪ��Joeph�������һ�������ǣ����Ϊ1,2,��,n��n���˰�˳ʱ�뷽��Χ��һȦ��
ÿ�˳���һ�����루����������һ��ʼ��ѡһ����������Ϊ��������ֵm���ӵ�һ���˿�ʼ��˳ʱ�뷽����1��ʼ˳����������mʱֹͣ������
��m���˳��У�������������Ϊ�µ�mֵ��������˳ʱ�뷽���ϵ���һ���˿�ʼ���´�1�����������ȥ��ֱ��������ȫ������Ϊֹ��
�����һ�������������˳��
*/
typedef struct JC{
	int number;
	int psw;
	struct JC *next;

}JCnode,*JCList;

//û��ͷ���
void create_JC(JCList &L,int n) {
	JCList p, q;
	L = (JCList)malloc(sizeof(JCnode));
	L->next = NULL;
	L->number = 1;
	printf("���������룺\n");
	scanf_s("%d", &L->psw);
	p = L;
	for (int j = 2;j <= n;j++) {
		q = (JCList)malloc(sizeof(JCnode));
		printf("���������룺\n");
		q->number = j;
		scanf_s("%d", &q->psw);
		q->next = p->next;
		p->next = q;
		p = q;
	}
	p->next = L;//ָ���һ�������γɻ�
}
int getLen(JCList L) {
	JCList p;
	p = L;
	if (p == NULL) {
		return 0;
	}
	int e = L->number;
	p = p->next;
	int i = 1;
	for (;p!=NULL;i++,p=p->next) {
		if (e==p->number)
			break;
	}
	return i;
}
int delete_JC(JCList &L,int i) {
	int psw;
	for (int j = getLen(L);j > 1;j--) {
		L = L->next;
	}
	JCList q;
	q = L->next;//���ɾ����
	psw = q->psw;
	L->next = L->next->next;
	free(q);
	return psw;

}

void showCircle(JCList L) {
	JCList p;
	p = L;
	for (int j = 1;j <= getLen(L);j++) {
		
		printf("(%d)number:%d  password:%d\n", j, p->number, p->psw);
		p = p->next;
	}

}

void result(JCList L, int m) {
	if (getLen(L) == 1) {
		printf("%d", L->number);
		exit(0);
	}
	for (;m > 0;m--) {
		L = L->next;
	}
	printf("%d\n", L->number);
	result(L, delete_JC(L, 1));
	
}

int main() {
	JCList L;
	int n,m;
	printf("������n��\n");
	scanf_s("%d", &n);
	create_JC(L,n);
	showCircle(L);
	printf("�������ʼֵm\n");
	scanf_s("%d", &m);
	printf("���Ϊ��\n");
	result(L, m-1);
}