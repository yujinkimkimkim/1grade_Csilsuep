#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	int N, M;
	int limit[100] = { 0 };
	int yeon[100] = { 0 };
	int violation[100] = { 0 };
	int Max = 0;
	int N_section = 0;
	int M_section = 0;
	int N_v = 0;
	int M_v = 0;
	int temp = 0;

	scanf_s("%d %d", &N, &M);

	for (int i = 0; i < N; i++) //���� �ӵ� ����
	{
		scanf_s("%d %d", &N_section, &N_v);

		for (int j = temp; j < temp + N_section; j++)
		{
			limit[j] = N_v;
		}
		temp += N_section;
	}

	temp = 0;
	for (int i = 0; i < M; i++) //�����̰� �޸� �ӵ� ����
	{
		scanf_s("%d %d", &M_section, &M_v);

		for (int j = temp; j < temp + M_section; j++)
		{
			yeon[j] = M_v;
		}
		temp += M_section;
	}

	for (int i = 0; i < 100; i++) //�ӵ� �� ����
	{
		if (limit[i] < yeon[i])
		{
			violation[i] = yeon[i] - limit[i];
		}
	}

	for (int i = 0; i < 100; i++) //�ӵ� ���� ���� ū �� ����
	{
		if (violation[i] > Max)
		{
			Max = violation[i];
		}
	}

	printf("%d", Max);

	return 0;
}