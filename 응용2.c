#include<stdio.h>

int main(void)
{
	int binary[32] = { 0 };
	int complement[32] = { 0 };
	int N = 0;
	int i = 31;
	int count = 0;

	scanf_s("%d", &N);

	while (N > 0) //주어진 숫자의 이진수 
	{
		binary[i] = N % 2;
		N /= 2;
		i--;
	}

	for (i = 0; i < 32; i++) //1의 보수
	{
		if (binary[i] == 1)
		{
			complement[i] = 0;
		}
		else if (binary[i] == 0)
		{
			complement[i] = 1;
		}
	}


	for (i = 31; i >= 0; i--) //2의 보수
	{
		if (complement[i] + 1 == 2)
		{
			complement[i] = 0;
			continue;
		}
		else if (complement[i] + 1 == 1)
		{
			complement[i] = 1;
			break;
		}
	}



	for (i = 0; i < 32; i++) //다른 비트 개수 세기
	{
		if (binary[i] != complement[i])
			count++;
	}

	printf("%d", count);

	return 0;
}