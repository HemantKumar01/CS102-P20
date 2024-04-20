#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
int height = 25, width = 50, fruitX, fruitY, flag, gameEnd, score;
int x, y, p, k;
int tailX[100], tailY[100];
int piece = 0;
void makeLogic()
{
    int i;
    int prevX, prevY, preve2X, preve2Y;
    prevX = tailX[0];
    prevY = tailY[0];
    tailX[0] = x;
    tailY[0] = y;
    for (i = 0; i <= piece; i++)
    {
        preve2X = tailX[i];
        preve2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = preve2X;
        prevY = preve2Y;
    }
    switch (flag)
    {
    case 1:
    {
        x--;
        break;
    }
    case 2:
    {
        x++;
        break;
    }
    case 3:
    {
        y--;
        break;
    }
    case 4:
    {
        y++;
        break;
    }
    }
    if (x == 0 || x == height || y == 0 || y == width)
    {
        gameEnd = 1;
    }
    if (x == fruitX && y == fruitY)
    {
    lebel3:
        fruitX = rand() % height;
        if (fruitX == 0)
            goto lebel3;

    lebel4:
        fruitY = rand() % width;
        if (fruitY == 0)
            goto lebel4;
        score += 10;
        piece++;
    }
}
void input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'w':
        {
            flag = 1;
            break;
        }
        case 's':
        {
            flag = 2;
            break;
        }
        case 'a':
        {
            flag = 3;
            break;
        }
        case 'd':
        {
            flag = 4;
            break;
        }
        case 'x':
        {
            exit(0);
        }
        }
    }
}
void setup()
{
    x = height / 2;
    y = width / 2;

lebel1:
    fruitX = rand() % height;
    if (fruitX == 0)
        goto lebel1;

lebel2:
    fruitY = rand() % width;
    if (fruitY == 0)
        goto lebel2;
    gameEnd = 0;
    score = 0;
    piece++;
}

void draw()
{
    system("cls"); // alternative of clrscr() function;
    int i, j;
    for (i = 0; i <= height; i++)
    {
        for (j = 0; j <= width; j++)
        {
            if (i == 0 || i == height || j == 0 || j == width)
            {
                printf("#");
            }
            else
            {
                if (i == x && j == y)
                {
                    printf("0");
                }
                else if (i == fruitX && j == fruitY)
                {
                    printf("o");
                }
                else
                {
                    p = 0;
                    for (k = 0; k < piece; k++)
                    {
                        if (i == tailX[k] && j == tailY[k])
                        {
                            printf("o");
                            p = 1;
                        }
                    }
                    if (!p)
                    {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
    printf("Your score is\t %d", score);
}

int main()
{
    setup();
    while (gameEnd != 1)
    {
        input();
        draw();
        makeLogic();
        Sleep(75);
    }
}