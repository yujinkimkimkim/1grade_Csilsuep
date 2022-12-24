#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define D 20

typedef struct NODE {
	struct NODE* link;
	char name[D];
	int num;
}NODE;

int main(void)
{
	NODE* list = NULL;
	NODE* p_prev = NULL, * p, * p_next;
	char arr[D];

	while (1)
	{
		printf("품목 입력 : ");
		gets_s(arr, D);
		if ((arr[0] == 'Q') || (arr[0] == 'q'))
			break;

		p = (NODE*)malloc(sizeof(NODE));
		strcpy_s(p->name, sizeof(p->name), arr);

		printf("수량 입력 : ");
		gets_s(arr, D);
		p->num = atoi(arr);

		if (list == NULL)
			list = p;
		else
			p_prev->link = p;
		p->link = NULL;
		p_prev = p;
	}

	p = list;
	while (p != NULL)
	{
		printf("[%s, %d]", p->name, p->num);
		p = p->link;
		if (p != NULL)
			printf("->");
	}

	p = list;
	while (p != NULL)
	{
		p_next = p->link;
		free(p);
		p = p_next;
	}

	return 0;
}