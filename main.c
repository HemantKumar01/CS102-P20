

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char gameName[50];
    char gamePath[50];
    char creator[40];
    int isGraphics;
} menu_item;

#define NUM_GAMES 7

#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"
#define UNDERLINE "\x1B[4m"
#define ITALIC "\x1B[3m"
#define CLR_WHITE "\x1B[37m"
#define CLR_RED "\x1B[31m"
#define CLR_GREEN "\x1B[32m"
#define CLR_YELLOW "\x1B[33m"
#define CLR_BLUE "\x1B[34m"
#define CLR_MAGENTA "\x1B[35m"
#define CLR_CYAN "\x1B[36m"
#define CLR_WHITE "\x1B[37m"
#define CLR_MAGENTA_BG "\x1B[45m"
#define CLR_CYAN_BG "\x1B[46m"
#define CLR_WHITE_BG "\x1B[47m"

char *banner_text = "\n"
                    " ██████╗███████╗ ██╗ ██████╗ ██████╗\n"
                    "██╔════╝██╔════╝███║██╔═████╗╚════██╗\n"
                    "██║     ███████╗╚██║██║██╔██║ █████╔╝\n"
                    "██║     ╚════██║ ██║████╔╝██║██╔═══╝\n"
                    "╚██████╗███████║ ██║╚██████╔╝███████╗\n"
                    " ╚═════╝╚══════╝ ╚═╝ ╚═════╝ ╚══════╝\n"
                    "\n"
                    "██████╗ ██████╗  ██████╗      ██╗███████╗ ██████╗████████╗\n"
                    "██╔══██╗██╔══██╗██╔═══██╗     ██║██╔════╝██╔════╝╚══██╔══╝\n"
                    "██████╔╝██████╔╝██║   ██║     ██║█████╗  ██║        ██║\n"
                    "██╔═══╝ ██╔══██╗██║   ██║██   ██║██╔══╝  ██║        ██║\n"
                    "██║     ██║  ██║╚██████╔╝╚█████╔╝███████╗╚██████╗   ██║\n"
                    "╚═╝     ╚═╝  ╚═╝ ╚═════╝  ╚════╝ ╚══════╝ ╚═════╝   ╚═╝\n"
                    "\n"
                    "\n";

void printPreText()
{
    system("cls");

    printf("%s%s%s", CLR_CYAN, banner_text, RESET);
    printf("%s%s%s%s", CLR_GREEN, BOLD, "Project Group 20\n\n", RESET);
}

char *getOptionString(char *gameName, char *creator, char *type)
{
    char *optionString = (char *)malloc(80 * sizeof(char));
    sprintf(optionString, "%s", gameName);
    int numSpacesRemaining = 20 - strlen(gameName);
    for (int i = 0; i < numSpacesRemaining; i++)
    {
        strcat(optionString, " ");
    }
    strcat(optionString, CLR_YELLOW);
    strcat(optionString, type);

    numSpacesRemaining = 10 - strlen(type);
    for (int i = 0; i < numSpacesRemaining; i++)
    {
        strcat(optionString, " ");
    }
    strcat(optionString, CLR_WHITE);
    strcat(optionString, creator);
    return optionString;
}
void showMenu()
{
    menu_item pong = {"Pong Game",
                      "pong.exe", "Hemant Kumar", 1};
    menu_item breakout = {"Breakout Game",
                          "breakout.exe", "Sasmit Shaswat", 1};
    menu_item snake_graphic = {"Snake Game",
                               "snake_g.exe", "Vidhan Bansal", 1};
    menu_item snake_terminal = {"Snake Game",
                                "snake_t.exe", "Prasad Mhaske", 0};
    menu_item tictactoe = {"Tic-Tac-Toe",
                           "tictactoe.exe", "Namrata Patel & Aravind Chowdary", 1};
    menu_item rock_paper = {"Rock Paper Scissor",
                            "rockpaper.exe", "Priyanshu", 0};
    menu_item apple = {"Catch The Apple",
                       "apple.exe", "Korak Basu", 1};
    menu_item menuitem[NUM_GAMES] = {pong, breakout, snake_graphic, apple, tictactoe, snake_terminal, rock_paper};
    char key, key2;
    int currentlySelectedItem = 1;
    while (1)
    {
        printPreText();
        printf("%s%s%s\n\n", CLR_YELLOW, "Which Game Do You Want to Play?", RESET);
        for (int i = 0; i < NUM_GAMES; i++)
        {
            if (i == currentlySelectedItem - 1)
            {
                printf("%s%s%s%s\n", CLR_WHITE, CLR_MAGENTA_BG, getOptionString(menuitem[i].gameName, menuitem[i].creator, (menuitem[i].isGraphics ? "Graphics" : "Terminal")), RESET);
            }
            else
            {
                printf("%s%s%s\n", CLR_CYAN, getOptionString(menuitem[i].gameName, menuitem[i].creator, (menuitem[i].isGraphics ? "Graphics" : "Terminal")), RESET);
            }
        }
        key = getch();
        key2 = 0;
        switch (key)
        {
        case -32:
            key2 = getch();
            break;
        case 13:
            char *command = (char *)malloc(strlen("cd dist && ") + strlen(menuitem[currentlySelectedItem - 1].gamePath) + 1);
            strcpy(command, "cd dist && ");
            strcat(command, menuitem[currentlySelectedItem - 1].gamePath);
            system(command);

            break;
        case 27:
            exit(0);
            break;
        default:
            continue;
        }

        if (key2 == 80) // down arrow key
        {
            currentlySelectedItem++;
        }
        else if (key2 == 72) // up arrow key
        {
            currentlySelectedItem--;
        }

        // make sure the selected item stays in range
        if (currentlySelectedItem < 1)
            currentlySelectedItem = 1;
        if (currentlySelectedItem > NUM_GAMES)
            currentlySelectedItem = NUM_GAMES;
    }
}

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");
    printPreText();
    showMenu();

    return 0;
}
