#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main(void)
{
	int number[25] = { 0 };
	int N;
	int number_cnt[10] = { 0 };
	int idx = 0;
	int max = 0;
	int min = 0;
	srand((unsigned)time(NULL));

	clock_t start;
	clock_t now;

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
	start = clock();

	char input = '0';

	while (input != 'q')
	{
		now = clock();

		if (((double)now - start) / CLOCKS_PER_SEC >= 8)
		{
			printf("you're lose");
			break;
		}
		input = _getch();

		if (min == atoi(&input))
		{
			printf("great\n");
			break;
		}
		else if (input == 'q')
		{
			exit(0);
		}
		else
		{
			printf("틀력ㅆ습니당\n");
		}
	}
	return 0;
}