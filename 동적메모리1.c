#include <stdio.h>
#include <stdlib.h> //malloc() 함수 사용하기 위해 선언, 메모리 부족할 경우에 NULL 값 반환
int main(void) {
	int input = 0;
	int* p;

	scanf_s("%d", &input);
	p = (int*)malloc(input * sizeof(int));

	if (p == NULL)
	{
		printf("동적할당 오류 발생\n");
		exit(1); //괄호 안 1은 비정상 종료 의미
	}
	int sum = 0;
	for (int i = 0; i < input; i++)
	{
		scanf_s("%d", &p[i]); 
		sum += p[i]; // *(p+i)
	}

	printf("%d", sum);
	free(p); //메모리 누수 방지

	return 0;
}