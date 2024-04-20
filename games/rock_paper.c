#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

struct GameState
{
    char userChoice[10];
    char compChoice[10];
    int userScore;
    int compScore;
};
// above code is  structure which is taking input from user and comp
// like rock paper and scissor and storing them in userchoice and compchoice.
//.and then when game is over it is storing sscores of user and comp in userscore and compscore

void printRock()
{
    printf("    ");
    printf("\033[37;100m");
    printf("______\n");
    printf("\033[0m");
    printf(" ");
    printf("\033[37;100m");
    printf("__/ **** \\__\n");
    printf("\033[0m");
    printf("\033[37;100m");
    printf("|===*####*+++\\\n");
    printf("\033[0m");
    printf("\033[37;100m");
    printf("\\___****____|\n");
    printf("\033[0m");
    printf("  ");
    printf("\033[37;100m");
    printf("==\\______/\n");
    printf("\033[0m");
}
// above code is a function which prints the rock with background colour of grey with escape codes
void printPaper()
{
    printf("\033[47m");
    printf(" ___________ \n");
    printf("|-----------|\n");
    printf("|-----------|\n");
    printf("|-----------|\n");
    printf("|-----------|\n");
    printf("|-----------|\n");
    printf("|-----------|\n");
    printf("|___________|\n");
    printf("\033[0m");
}
// above code is a function which prints the paper with   escape codes
void printScissor()
{
    printf("   \\        /\n");
    printf("   \\\\      //\n");
    printf("    \\\\    //\n");
    printf("     \\\\  //\n");
    printf("      \\\\//\n");
    printf("       /\\ \n");
    printf("      //\\\\\n");
    printf("     //  \\\\     \n");
    printf("    //    \\\\ \n");
    printf("  (   )  (   ) \n");
    printf(" (___)    (___)   \n");
}
// above code is a function which prints the scissor with  escape codes
void printHand()
{
    printf("    _______\n");
    printf("---'   ____)\n");
    printf("      (_____)\n");
    printf("      (_____)\n");
    printf("      (____)\n");
    printf("---.__(___)\n");
}
// above code is a function which prints the hand

void printHand1()
{
    printf("\n");
    printf("\n");
    printf("    _______\n");
    printf("---'   ____)\n");
    printf("      (_____)\n");
    printf("      (_____)\n");
    printf("      (____)\n");
    printf("---.__(___)\n");
}
// above code is a function which prints the hand1

void rockPaperScissor()
{
    int ok = 1;
    struct GameState game;
    game.userScore = 0;
    game.compScore = 0;
    // initially score of both comp and user is 0
    srand(time(NULL));
    printf("welcome to rock scissor paper game play and enjoy:)\n");
    while (ok)
    {
        int validChoice = 0;
        while (!validChoice)
        {
            printf("Choose rock (r), paper (p), or scissor (s): ");
            scanf("%s", game.userChoice);
            if (strcmp(game.userChoice, "r") == 0 ||
                strcmp(game.userChoice, "p") == 0 ||
                strcmp(game.userChoice, "s") == 0)
            {
                validChoice = 1;
            }
            else
            {
                printf("Invalid input. Please enter 'r', 'p', or 's'.\n");
            }
            // checking whether the user has chosen valid choice or not
        }
        int r = rand() % 3;
        if (r == 0)
        {
            strcpy(game.compChoice, "r");
        }
        else if (r == 1)
        {
            strcpy(game.compChoice, "p");
        }
        else
        {
            strcpy(game.compChoice, "s");
        }
        // In above code  computer is generating a random number using rand fuction
        // and divide it by 3 to so that it may have three choices 0,1,2 after that
        // according to remainder obtained it is making compchoice
        system("cls");
        printHand();
        usleep(500000);
        system("cls");
        printHand1();
        usleep(500000);
        system("cls");
        printHand();
        usleep(500000);
        system("cls");
        // above code is printing hands using two different function hand and hand1 so that motion of hand is visible
        printf("\033[31m");
        printf("User Choice: \n");
        printf("\033[0m]");
        if (strcmp(game.userChoice, "r") == 0)
        {
            printRock();
        }
        else if (strcmp(game.userChoice, "p") == 0)
        {
            printPaper();
        }
        else if (strcmp(game.userChoice, "s") == 0)
        {
            printScissor();
        }
        // above code is printing userchoice

        printf("\n\n\n");
        printf("\033[34m");
        printf("Computer Choice: \n");

        if (strcmp(game.compChoice, "r") == 0)
        {
            printRock();
        }
        else if (strcmp(game.compChoice, "p") == 0)
        {
            printPaper();
        }
        else if (strcmp(game.compChoice, "s") == 0)
        {
            printScissor();
        }
        // above code is printing compchoice
        if (strcmp(game.userChoice, game.compChoice) == 0)
        {
            printf("Oh!!! It's a tie.\n");
        }
        // if userchoice and compchoice are same then it is a tie
        else if ((strcmp(game.userChoice, "r") == 0 && strcmp(game.compChoice, "p") == 0) ||
                 (strcmp(game.userChoice, "p") == 0 && strcmp(game.compChoice, "s") == 0) ||
                 (strcmp(game.userChoice, "s") == 0 && strcmp(game.compChoice, "r") == 0))
        {
            printf("That's a win for me.\n");
            game.compScore++;
        }
        // checking the computer winning criteria if comp wins then increasing compscore by 1
        else
        {
            printf("You got this one.\n");
            game.userScore++;
        }
        // if above both conditions fails then user wins the game

        sleep(2);
        printf("Wanna play again? (1 for Yes, 0 for No): ");
        scanf("%d", &ok);
        system("cls");
    }
    printf("\nIt is %d for you %d for me", game.userScore, game.compScore);
}

int main()
{
    srand(time(NULL));
    rockPaperScissor();
}