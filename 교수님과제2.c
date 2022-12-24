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


	for (i = 0; i < 25; i++) //1부터 9까지 랜덤한 숫자 배열에 할당
	{
		N = rand() % 10;
		number[i] = N;
		number_cnt[N]++;
	}

	for (i = 0; i < 5; i++) //5x5배열로 출력
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", number[idx]);
			idx++;
		}

		printf("\n");
	}


	int temp = number_cnt[0];

	for (i = 0; i < 9; i++) //최대값 찾기
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

	for (i = 0; i < 9; i++) //최소값 찾기
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
	printf("가장 많이 나온 수: %d\n", max);
	printf("가장 적게 나온 수:%d\n", min);

	return 0;
}