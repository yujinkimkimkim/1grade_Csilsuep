#include <stdio.h>

int main()
{
	int input = 0, num[3] = {0}, min = 999999, temp;

	scanf_s("%d", &input);

	for (int i = 1; i <= input; i++)
	{
		for (int j = 1; j <= input; j++)
		{
			if (i * j > input)
				break;
			for (int k = 1; k <= input; k++)
			{
				if (i * j * k > input)
					break;
				else if (i * j * k < input)
					continue;
				else
				{
					temp = ( i * j + j * k + i * k ) * 2;
					if (min > temp)
					{
						min = temp;
						num[0] = i;
						num[1] = j;
						num[2] = k;
					}
				}
				break;
			}
		}
	}

	printf("%d %d %d", num[0], num[1], num[2]);
	return 0;
}