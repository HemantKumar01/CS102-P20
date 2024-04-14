/*
1.The game will begin with any dice value.
2.If a 6(six) is appeared then a chance is awarded to that player.
3.Only the location of current player is shown on the board,
    the location of other player is mentioned below the board.
4.Snakes:- 99 to  1, 65 to 40, 25 to 9.
5.Ladder:- 70 to 93, 60 to 83, 13 to 42.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int dice()
{
    srand(time(NULL));
    int dice = rand() % 6 + 1;
    return dice;
}
int player1(int p1)
{
    printf("Snakes:- 99 to  1, 65 to 40, 25 to 9.     ");
    printf("Ladder:- 70 to 93, 60 to 83, 13 to 42.\n");
    printf("Player1 turn to play\n");
    printf("Press any number to roll dice\n");
    int ch = scanf("%d", &ch);
    if (ch)
    {
        int a = dice();
        printf("Dice = %d \n", a);
        p1 = p1 + a;
        if (p1 > 100)
        {
            p1 = p1 - a;
        }
        while (a == 6)
        {
            printf("Player1 gets another turn to play\n");
            printf("Press any number to roll dice\n");
            int x = scanf("%d", &x);
            a = dice();
            printf("Dice = %d \n", a);
            p1 = p1 + a;
            if (p1 > 100)
            {
                p1 = p1 - a;
            }
        }
        if (p1 == 99)
        {
            p1 = 1;
        }
        if (p1 == 65)
        {
            p1 = 40;
        }
        if (p1 == 25)
        {
            p1 = 9;
        }
        if (p1 == 13)
        {
            p1 = 42;
        }
        if (p1 == 60)
        {
            p1 = 83;
        }
        if (p1 == 70)
        {
            p1 = 93;
        }
        return p1;
    }
    else
    {
        printf("Wrong Input\n");
        return p1;
    }
}
int player2(int p2)
{
    printf("Snakes:- 99 to  1, 65 to 40, 25 to 9.     ");
    printf("Ladder:- 70 to 93, 60 to 83, 13 to 42.\n");
    printf("Player2 turn to play\n");
    printf("Press any number to roll dice\n");
    int ch = scanf("%d", &ch);
    if (ch == 1)
    {
        int a = dice();
        printf("Dice = %d \n", a);
        p2 = p2 + a;
        if (p2 > 100)
        {
            p2 = p2 - a;
        }
        while (a == 6)
        {
            printf("Player2 gets another turn to play\n");
            printf("Press any number to roll dice\n");
            int x = scanf("%d", &x);
            a = dice();
            printf("Dice = %d \n", a);
            p2 = p2 + a;
            if (p2 > 100)
            {
                p2 = p2 - a;
            }
        }
        if (p2 == 99)
        {
            p2 = 1;
        }
        if (p2 == 65)
        {
            p2 = 40;
        }
        if (p2 == 25)
        {
            p2 = 9;
        }
        if (p2 == 13)
        {
            p2 = 42;
        }
        if (p2 == 60)
        {
            p2 = 83;
        }
        if (p2 == 70)
        {
            p2 = 93;
        }
        return p2;
    }
    else
    {
        printf("Wrong Input\n");
        return p2;
    }
}
int main()
{
    printf("1.The game will begin with any dice value.\n");
    printf("2.If a 6(six) is appeared then a chance is awarded to that player.\n");
    int p1, p2, c = 0;
    while (p2 < 100 && p1 < 100)
    {
        if (c % 2 == 0)
        {
            p1 = player1(p1);
            printf("Player1 = %d\n", p1);
            printf("Player2 = %d\n", p2);
        }
        else
        {
            p2 = player2(p2);
            printf("Player1 = %d\n", p1);
            printf("Player2 = %d\n", p2);
        }
        c++;
        for (int i = 1; i <= 100; i++)
        {
            if (i < 10)
            {
                if (i == p1)
                {
                    printf("P1  ");
                }
                else if (i == p2)
                {
                    printf("P2  ");
                }
                else
                {
                    printf("0%d  ", i);
                }
            }
            else
            {
                if (i == p1)
                {
                    printf("P1  ");
                }
                else if (i == p2)
                {
                    printf("P2  ");
                }
                else
                {
                    printf("%d  ", i);
                }
            }
            if (i % 10 == 0)
            {
                printf("\n");
            }
        }
    }
    if (p1 == 100)
    {
        printf("Player1 Wins\n");
    }
    else
    {
        printf("Player2 Wins\n");
    }
}