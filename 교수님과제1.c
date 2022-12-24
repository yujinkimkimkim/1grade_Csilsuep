#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>

void draw_sqaure()  //기본 사각형 그리기
{
	int i = 0;
	unsigned char a = 0xA6, b[7];
	for (i = 1; i < 7; i++)
	{
		b[i] = 0xA0 + i;
	}

	printf("%c%c ", a, b[3]);
	for (i = 0; i < 40; i++)
		printf("%c%c ", a, b[1]);
	printf("%c%c \n", a, b[4]);
	for (i = 0; i < 25; i++)
	{
		printf("%c%c\t\t\t\t\t\t\t\t\t\t  ", a, b[2]);
		printf("%c%c\n", a, b[2]);
	}
	printf("%c%c ", a, b[6]);
	for (i = 0; i < 40; i++)
		printf("%c%c ", a, b[1]);
	printf("%c%c", a, b[5]);


	printf("\n");
}

void gotoxy(int x, int y) //입력한 좌표로 이동하는 함수
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void moving(int* x, int* y, int* move) //공의 움직임 부여
{
	switch (*move)
	{
	case 1: //왼쪽 아래 끝
		*x -= 1;
		*y -= 1;
		if (*x < 2) //왼쪽
		{
			*x = 2;
			*move = 2;
		}
		if (*y < 2) //아래
		{
			*y = 2;
			*move = 4;
		}
		break;
	case 2: //오른쪽 아래 끝
		*x += 2;
		*y -= 1;
		if (*x > 150) //오른쪽
		{
			*x = 150;
			*move = 1;
		}
		if (*y < 2) //아래
		{
			*y = 2;
			*move = 3;
		}
	case 3: //오른쪽 위 끝
		*x += 2;
		*y += 1;
		if (*x > 150) //오른쪽
		{
			*x = 150;
			*move = 4;
		}
		if (*y > 25) //위
		{
			*y = 25;
			*move = 2;
		}
	case 4: //왼쪽 위 끝
		*x -= 2;
		*y += 1;
		if (*x < 2) //왼쪽
		{
			*x = 2;
			*move = 3;
		}
		if (*y > 25) //위
		{
			*y = 25;
			*move = 1;
		}
		break;
	}
}

void print_ball(char* ball, int x, int y)
{
	gotoxy(x, y);
	printf("%s", ball);
	Sleep(40);
	gotoxy(x, y);
	printf("  ");
}

int main(void)
{
	char ball[3] = "○";
	int move, x, y;
	srand((unsigned)time(NULL));
	draw_sqaure();
	x = 40;
	y = 10;
	move = rand() % 4 + 1; //움직임 무작위 선정

	while (!_kbhit()) //키보드 누르면 종료
	{
		moving(&x, &y, &move);
		print_ball(ball, x, y);
	}

	return 0;

}