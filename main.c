

// GROUP 20
// Hemant Kumar - 2301CS20

#include <stdio.h>
#include <locale.h>

#define CLR_NORMAL "\x1B[0m"
#define CLR_RED "\x1B[31m"
#define CLR_GREEN "\x1B[32m"
#define CLR_YELLOW "\x1B[33m"
#define CLR_BLUE "\x1B[34m"
#define CLR_MAGENTA "\x1B[35m"
#define CLR_CYAN "\x1B[36m"
#define CLR_WHITE "\x1B[37m"
#define BOLD_ON "\033[1m"
#define UNDERLINE "\033[4m"

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

char *students = "Hemant Kumar              2301CS20\n"
                 "Sasmit Shashwat           2301AI20\n"
                 "Korak Basu                2301CB20\n"
                 "Namrata Patel             2301CB49\n"
                 "Anish Kumar Jugnu         2301CT20\n"
                 "Aravind Chowdary Dobbala  2301CE40\n"
                 "Vidhan Bansal             2301CE39\n"
                 "Sandeep Kumar             2301CS48\n"
                 "Prasad Kailas Mhaske      2301EE20\n"
                 "Priyanshu Gupta           2301EC20\n";

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");

    printf("%s%s%s", CLR_CYAN, banner_text, CLR_NORMAL);
    printf("%s%s%s%s", BOLD_ON, CLR_GREEN, "Project Group 20\n", CLR_NORMAL);
    printf("%s%s%s", CLR_CYAN, students, CLR_NORMAL);

    return 0;
}
