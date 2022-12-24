#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>

int com = 0;
int user = 1;

void gotoxy(int x, int y) //좌표 이동
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void intro_game(void) //게임 소개
{
	system("cls");
	printf("50을 넘어라 게임\n\n");
	printf("컴퓨터와 사용자가 번갈아가며\n");
	printf("숫자를 입력하되 1~10사이의\n");
	printf("중복되지 않는 숫자를 입력하여\n\n");
	printf("최초로 50을 넘기면 승자가 됩니다\n");
	printf("컴퓨터가 먼저 시작합니다\n");
	printf("아무키나 누르면 시작합니다");
	_getch();
}

int computer_number(int i, int input[]) //컴퓨터 숫자 입력
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

int user_number(int i, int input[]) //사용자 숫자 입력
{
	int j, number, again = 0;
	do
	{
		gotoxy(1, 7);
		printf("사용자 숫자 입력 후 Enter>>");
		scanf_s("%d", &number);
		for (j = 0; j < 10; j++)
		{
			if (input[j] == number) //중복 숫자 처리
			{
				gotoxy(1, 8);
				printf("중복된 숫자를 입력했습니다\n");
				again = 1;
				break;

			}

		}
	} while (again == 1);


	input[user] = number;
	return input[user];
}

void number_display(int i, int input[], int sum) //입력한 숫자 표
{
	int j, c = 0, u = 1;
	gotoxy(1, 2);
	printf("컴퓨터 숫자: ");
	for (j = 0; j <= i; j++)
	{
		printf("%2d ", input[c]);
		c += 2;
	}
	gotoxy(1, 3);
	printf("사용자 숫자: ");
	for (j = 0; j <= i; j++)
	{
		printf("%2d ", input[u]);
		u += 2;
	}
	gotoxy(1, 5);
	printf("현재 합계: %3d\n", sum);
}

void conclusion(int check) //결과보여주는 함수
{
	if (check == 1)
		printf("컴퓨터가 이겼습니다\n");
	else
		printf("사용자가 이겼습니다\n");
}

void press_any_key(void) //아무키나 누르면 다음 게임으로 넘어감
{
	gotoxy(1, 10);
	printf("아무키나 누르시오..");
	_getch();
}

void game_control(void) //게임에 필요한 함수들 조합한 함수
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

int main(void) //메인
{
	srand((unsigned)time(NULL));
	intro_game();
	game_control();

	return 0;
}