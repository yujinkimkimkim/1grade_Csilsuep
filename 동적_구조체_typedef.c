#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	char title[30];
}st;

int main(void)
{
	//typedef�� ������ ����ü ����

	st* pt;
	int input = 0;
	int num;
	scanf_s("%d", &input);
	getchar();

	pt = (st*)malloc(input * sizeof(st));

	for (int i = 0; i < input; i++)
	{
		gets_s(pt[i].title, sizeof(pt[i].title));//���� �ڿ� ,�ϰ� �󸶸�ŭ ũ���� ����Ʈ �� �Է¹����� �Է������ ��
		/*
		scanf_s("%d", &num);
		getchar();*/ //���ϱ� scanf_s �ϰ� getchar����� �ϴ°� �´µ� gets_s���� �ٷ� ������ getchar�ϸ� ������
	} 

	for (int i = 0; i < input; i++)
		puts(pt[i].title);

	for (int i = 0; i < input; i++)
		printf("%s\n",pt[i].title);

	free(pt);
	//puts�� gets_s �Է¹��� �� ���ڿ� �� \0�� ����� �� \n���� ��ȯ����
	//gets_s�� puts�� ���ڿ��� �� �� ����, puts("")�� ���� �����ϴ� �� �� ����
	return 0;
}