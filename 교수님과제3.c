#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>

int com = 0;
int user = 1;

void gotoxy(int x, int y) //��ǥ �̵�
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void intro_game(void) //���� �Ұ�
{
	system("cls");
	printf("50�� �Ѿ�� ����\n\n");
	printf("��ǻ�Ϳ� ����ڰ� �����ư���\n");
	printf("���ڸ� �Է��ϵ� 1~10������\n");
	printf("�ߺ����� �ʴ� ���ڸ� �Է��Ͽ�\n\n");
	printf("���ʷ� 50�� �ѱ�� ���ڰ� �˴ϴ�\n");
	printf("��ǻ�Ͱ� ���� �����մϴ�\n");
	printf("�ƹ�Ű�� ������ �����մϴ�");
	_getch();
}

int computer_number(int i, int input[]) //��ǻ�� ���� �Է�
{
	int j, number;
	number = rand() % 10 + 1;
	for (j = 0; j < 10; j++)
	{
		if (input[j] == number)
			number = rand() % 10 + 1;

	}
	input[com] = number;
	return input[com];
}

int user_number(int i, int input[]) //����� ���� �Է�
{
	int j, number, again = 0;
	do
	{
		gotoxy(1, 7);
		printf("����� ���� �Է� �� Enter>>");
		scanf_s("%d", &number);
		for (j = 0; j < 10; j++)
		{
			if (input[j] == number) //�ߺ� ���� ó��
			{
				gotoxy(1, 8);
				printf("�ߺ��� ���ڸ� �Է��߽��ϴ�\n");
				again = 1;
				break;

			}

		}
	} while (again == 1);


	input[user] = number;
	return input[user];
}

void number_display(int i, int input[], int sum) //�Է��� ���� ǥ
{
	int j, c = 0, u = 1;
	gotoxy(1, 2);
	printf("��ǻ�� ����: ");
	for (j = 0; j <= i; j++)
	{
		printf("%2d ", input[c]);
		c += 2;
	}
	gotoxy(1, 3);
	printf("����� ����: ");
	for (j = 0; j <= i; j++)
	{
		printf("%2d ", input[u]);
		u += 2;
	}
	gotoxy(1, 5);
	printf("���� �հ�: %3d\n", sum);
}

void conclusion(int check) //��������ִ� �Լ�
{
	if (check == 1)
		printf("��ǻ�Ͱ� �̰���ϴ�\n");
	else
		printf("����ڰ� �̰���ϴ�\n");
}

void press_any_key(void) //�ƹ�Ű�� ������ ���� �������� �Ѿ
{
	gotoxy(1, 10);
	printf("�ƹ�Ű�� �����ÿ�..");
	_getch();
}

void game_control(void) //���ӿ� �ʿ��� �Լ��� ������ �Լ�
{
	int max = 50;
	int input[10] = { 0 };
	int i, sum = 0, win = 0, number;
	for (i = 0; i < 10; i++)
	{
		system("cls");
		number = computer_number(i, input);
		com += 2;
		sum += number;
		number_display(i, input, sum);
		if (max < sum)
		{
			win = 1;
			break;
		}
		number = user_number(i, input);
		user += 2;
		sum += number;
		number_display(i, input, sum);
		if (max < sum)
		{
			win = 2;
			break;
		}

		press_any_key();
	}
	conclusion(win);

}

int main(void) //����
{
	srand((unsigned)time(NULL));
	intro_game();
	game_control();

	return 0;
}