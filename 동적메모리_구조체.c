#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcpy_s()함수 원형 선언

struct std {
	int sno;
	char name[12];
};

int main(void) {

	struct std* p;

	p = (struct std*)malloc(2 * sizeof(struct std));

	if (p == NULL)
	{
		printf("동적할당 실패\n");
		exit(1);
	}

	p[0].sno = 202202198;
	strcpy_s(p[0].name, sizeof(p[0].name), "김유진");

	p[1].sno = 30304;
	strcpy_s(p[1].name, sizeof(p[1].name), "고3김유진");

	for (int i = 0; i < 2; i++)
	{
		printf("학번 : %d\n", p[i].sno);
		printf("이름 : %s\n", p[i].name);
	}
	free(p);

	return 0;
}
