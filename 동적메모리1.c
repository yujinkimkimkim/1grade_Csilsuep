#include <stdio.h>
#include <stdlib.h> //malloc() �Լ� ����ϱ� ���� ����, �޸� ������ ��쿡 NULL �� ��ȯ
int main(void) {
	int input = 0;
	int* p;

	scanf_s("%d", &input);
	p = (int*)malloc(input * sizeof(int));

	if (p == NULL)
	{
		printf("�����Ҵ� ���� �߻�\n");
		exit(1); //��ȣ �� 1�� ������ ���� �ǹ�
	}
	int sum = 0;
	for (int i = 0; i < input; i++)
	{
		scanf_s("%d", &p[i]); 
		sum += p[i]; // *(p+i)
	}

	printf("%d", sum);
	free(p); //�޸� ���� ����

	return 0;
}