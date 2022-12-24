#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

#define X_MAX 79
#define Y_MAX 24

void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void move_arrow_key(COORD* pos, int x_b, int y_b)
{
    int key = 0;

    for (int i = 9; i > 0; i--) {
        pos[i].X = pos[i - 1].X;
        pos[i].Y = pos[i - 1].Y;
    }
  
    while (key !=_kbhit)
    {
        key = _getch();

        switch (key)
        {
        case 72: //위
            pos->Y--;
            if (pos->Y < 1)
                pos->Y = 1;
            break;
        case 80: //아래
            pos->Y++;
            if (pos->Y > y_b)
                pos->Y = y_b;
            break;
        case 75: //왼쪽
            pos->X--;
            if (pos->X < 1)
                pos->X = 1;
            break;
        case 77: //오른쪽
            pos->X++;
            if (pos->X > x_b)
                pos->X = x_b;
            break;
        default:
            return;
        }

        system("cls");
        for (int i = 0; i < 10; i++) {
            gotoxy(pos[i].X, pos[i].Y);
            printf("■");
        }

    }

}

int main(void)
{
    printf("화살표를 이용한 문자열 이동 프로그램\n");
    Sleep(1000);
    system("cls");
    int x = 40;
    int y = 12;
    COORD pos[10];
    for (int i = 0; i < 10; i++) {
        pos[i].X = x;
        pos[i].Y = y--;
    }

    do
    {
        move_arrow_key(pos, X_MAX, Y_MAX);
    } while (1);

    return 0;
}
