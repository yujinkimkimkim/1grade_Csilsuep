#include<stdio.h>
#include<time.h>

int main(void)
{
	int i, j;
	int number[25] = { 0 };
	int N;
	int number_cnt[10] = { 0 };
	int idx = 0;
	int max = 0;
	int min = 0;
	srand((unsigned)time(NULL));


	for (i = 0; i < 25; i++) //1���� 9���� ������ ���� �迭�� �Ҵ�
	{
		N = rand() % 10;
		number[i] = N;
		number_cnt[N]++;
	}

	for (i = 0; i < 5; i++) //5x5�迭�� ���
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", number[idx]);
			idx++;
		}

		printf("\n");
	}


	int temp = number_cnt[0];

	for (i = 0; i < 9; i++) //�ִ밪 ã��
	{
		if (temp > number_cnt[i + 1])
		{
			continue;
		}
		else if (temp <= number[i + 1])
		{
			temp = number_cnt[i + 1];
			max = i + 1;
		}


	}

	temp = number_cnt[0];

	for (i = 0; i < 9; i++) //�ּҰ� ã��
	{
		if (temp < number_cnt[i + 1])
		{
			continue;
		}
		else if (temp >= number_cnt[i + 1])
		{
			min = i + 1;
			temp = number_cnt[i + 1];
		}

	}
	printf("���� ���� ���� ��: %d\n", max);
	printf("���� ���� ���� ��:%d\n", min);

	return 0;
}