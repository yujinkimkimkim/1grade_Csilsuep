#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int number[25] = { 0 };
	int N;
	int number_cnt[10] = { 0 };
	int idx = 0;
	int max = 0;
	int min = 0;
	srand((unsigned)time(NULL));



	for (int i = 0; i < 25; i++)
	{
		N = rand() % 10;
		number[i] = N;  
		number_cnt[N]++;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", number[idx]);
			idx++;
		}
		printf("\n");
	}

	int temp = number_cnt[0];

	for (int i = 0; i < 9; i++)
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

	for (int i = 0; i < 9; i++)
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