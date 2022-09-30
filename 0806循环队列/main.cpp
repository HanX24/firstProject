#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define Maxsize 5//������ĸ�Ԫ�أ���һ��Ҫ

typedef int ELemType;
typedef struct {
	ELemType data[Maxsize];//ѭ�����У����洢Maxsize-1��Ԫ�ء���Ҫ����һ��Ԫ���ж϶����Ƿ����ˡ�
	int front, near;//near��ӣ�front����
}SQueue;

//��ʼ��
void InitQueue(SQueue &Q) {
	Q.front = 0;
	Q.near = 0;
}

//�ж��Ƿ�Ϊ��
bool isEmpty(SQueue  Q) {
	if (Q.front == Q.near) {//����ҪΪ0��ֻ��Ҫ������ֵ��ͬ�ͱ�ʾָ��ͬһ����㡣
		return true;
	}
	return false;
}

//��ӹ���
bool EnQueue(SQueue& Q, ELemType x) {//����Ҫ����  ���x�����ֵ �����Բ��� ����&
	if ((Q.near + 1) % Maxsize == Q.front) {
		return false;//��������[����Ϊ������Ȧ���ν�������
	}
	Q.data[Q.near] = x;
	Q.near = (Q.near + 1) % Maxsize;//����ƶ�һλ
	return true;
}

//���ӹ���
bool Dequeue(SQueue& Q, ELemType &x) {
	if (Q.front == Q.near) {
		return false;//����Ϊ��
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % Maxsize;
	return true;
}

int main() {
	SQueue Q;
	bool ret;//���շ���ֵ
	ELemType m;
	InitQueue(Q);
	ret = isEmpty(Q);
	if (ret) {
		printf("����Ϊ��\n");
	}
	else
	{
		printf("���в�Ϊ��");
	}
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	EnQueue(Q, 5);
	ret=EnQueue(Q, 6);
	if (ret) {
		printf("��ӳɹ�\n");
	}
	else
	{
		printf("���ʧ��\n");
	}
	ret = EnQueue(Q, 7);//�����Ԫ�أ�������󳤶�Maxsize
	if (ret) {
		printf("��ӳɹ�\n");
	}
	else
	{
		printf("���ʧ��\n");
	}

	//���Ӳ���
	ret = Dequeue(Q, m);
	if (ret) {
		printf("���ӳɹ�\n");
		printf("%d", m);
	}
	else
	{
		printf("����ʧ��\n");
	}


	InitQueue(Q);
}