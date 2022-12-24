#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	char title[30];
}st;

int main(void)
{
	//typedef로 선언한 구조체 예제

	st* pt;
	int input = 0;
	int num;
	scanf_s("%d", &input);
	getchar();

	pt = (st*)malloc(input * sizeof(st));

	for (int i = 0; i < input; i++)
	{
		gets_s(pt[i].title, sizeof(pt[i].title));//변수 뒤에 ,하고서 얼마만큼 크기의 바이트 수 입력받을지 입력해줘야 함
		/*
		scanf_s("%d", &num);
		getchar();*/ //보니까 scanf_s 하고서 getchar해줘야 하는건 맞는데 gets_s쓰고서 바로 다음에 getchar하면 오류남
	} 

	for (int i = 0; i < input; i++)
		puts(pt[i].title);

	for (int i = 0; i < input; i++)
		printf("%s\n",pt[i].title);

	free(pt);
	//puts만 gets_s 입력받을 때 문자열 끝 \0을 출력할 때 \n으로 변환해줌
	//gets_s랑 puts는 문자열만 쓸 수 있음, puts("")가 강제 개행하는 거 더 빠름
	return 0;
}