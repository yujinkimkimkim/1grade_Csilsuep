#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int min, max;
void game(void);

int main(void)
{
	clock_t start, now;

	char input = '0';
	char min_input, max_input;

	while (1)
	{
		printf("you can input 'q' if you want end => 'q'\n");
		input = _getch();
		if (input == 'q')
			break;
		else
		{
			system("cls");
			start = clock();
			game();
			while (1)
			{
				now = clock();
				if ((double)(now - start) / 1000 >= 10)
				{
					printf("10sec end\n");
					break;
				}

				printf("min = ");
				min_input = _getch();
				printf("%c\n", min_input);

				printf("max = ");
				max_input = _getch();
				printf("%c\n", max_input);

				if (min == atoi(&min_input) && max == atoi(&max_input))
				{
					printf("you are right\n");
					Sleep(1000);
					system("cls");
					break;
				}
				else
				{
					printf("you are lose\n");
					Sleep(1000);
					system("cls");
					break;
				}
			}
		}
	}
	return 0;

}

void game(void)
{
	int number[25] = { 0 };
	int number_idx[4] = { 0 };
	int n = 0, temp, idx = 0;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 25; i++)
	{
		n = rand() % 4;
		number[i] = n;
		number_idx[n]++;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d  ", number[idx]);
			idx++;
		}
		printf("\n");
	}
	printf("\n");

	temp = number_idx[0];
	for (int i = 0; i < 3; i++)
	{
		if (temp > number_idx[i + 1])
			continue;
		else
		{
			temp = number_idx[i + 1];
			max = i + 1;
		}
	}

	temp = number_idx[0];
	for (int i = 0; i < 3; i++)
	{
		if (temp < number_idx[i + 1])
			continue;
		else
		{
			temp = number_idx[i + 1];
			min = i + 1;
		}
	}
}