#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcpy_s()�Լ� ���� ����

struct std {
	int sno;
	char name[12];
};

int main(void) {

	struct std* p;

	p = (struct std*)malloc(2 * sizeof(struct std));

	if (p == NULL)
	{
		printf("�����Ҵ� ����\n");
		exit(1);
	}

	p[0].sno = 202202198;
	strcpy_s(p[0].name, sizeof(p[0].name), "������");

	p[1].sno = 30304;
	strcpy_s(p[1].name, sizeof(p[1].name), "��3������");

	for (int i = 0; i < 2; i++)
	{
		printf("�й� : %d\n", p[i].sno);
		printf("�̸� : %s\n", p[i].name);
	}
	free(p);

	return 0;
}
