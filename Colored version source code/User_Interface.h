#ifndef USER_INTERFACE


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>







//================================ Header and Menu ==============================================================================

void Note(){

        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 10);
        printf("\n\tNote : This program was built to Handle all the basic tasks of The club and it's managed totally by admins.\n");
        printf("\tIf you have any query Try to contact the Moderators.\n");
        SetConsoleTextAttribute(hStdOut, 15);
}

void Header(char *version)
{
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 9);
        printf("\nENSA KENITRA :     ");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
        SetConsoleTextAttribute(hStdOut, 9);
        printf("==============\t   ");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\xB2\xB2\xB2                                                                                     \xB2\xB2\xB2\n");
        printf("By:");
        SetConsoleTextAttribute(hStdOut, 14);
        printf("Zakaria Azzouzi ");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\xB2\xB2\xB2                     Welcome to The Vid Club Handler %s                             \xB2\xB2\xB2\n",version);
        SetConsoleTextAttribute(hStdOut, 14);
        printf("Ouadrhiri Idrissi  ");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\xB2\xB2\xB2                                                                                     \xB2\xB2\xB2\n");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("& ");
        SetConsoleTextAttribute(hStdOut, 14);
        printf("Frikich Rania    ");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
}


void Login_Menu()
{
        printf("\n\nIf you're a new user try signing up first, otherwise you're welcome to start using the Vid handler!!\n\n");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 14);
        printf("\t \t \t \t==========================\n");
        printf("\t \t \t \t|         Menu           |\n");
        printf("\t \t \t \t==========================\n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\n\t \t \t \t 1-Sign in \n \n");
        printf("\n\t \t \t \t 2-Sign up \n \n");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("\n\t \t \t \t 3-Exit\n \n");
        SetConsoleTextAttribute(hStdOut, 15);

}



//=========================   Admin Menus =================================================================

void ADMIN_Menu(char *name,char *status)
{
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

        print_Date();
        SetConsoleTextAttribute(hStdOut, 9);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   Welcome %s    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2",name);
        SetConsoleTextAttribute(hStdOut, 10);
        printf(" STATUS : %s \n\n\n",status);
        SetConsoleTextAttribute(hStdOut, 14);
        printf("\t \t \t \t==========================\n");
        printf("\t \t \t \t|         Menu           |\n");
        printf("\t \t \t \t==========================\n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\n\t \t \t \t 1-Manage Accounts \n \n");
        printf("\n\t \t \t \t 2-Manage Films  \n \n");
        printf("\n\t \t \t \t 3-Manage Borrowings\n \n");
        printf("\n\t \t \t \t 4-Log out\n \n");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("\n\t \t \t \t 5-Exit\n \n");
        SetConsoleTextAttribute(hStdOut, 15);
}


void Account_ADMIN_Menu(char *name,char *status)
{
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        print_Date();
        SetConsoleTextAttribute(hStdOut, 9);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   Welcome %s    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2",name);
        SetConsoleTextAttribute(hStdOut, 10);
        printf(" STATUS : %s \n\n\n",status);
        SetConsoleTextAttribute(hStdOut, 14);
        printf("\t \t \t \t==========================\n");
        printf("\t \t \t \t|         Menu           |\n");
        printf("\t \t \t \t==========================\n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\n\t \t \t \t 1-Add a new member \n \n");
        printf("\n\t \t \t \t 2-Modify Members info \n \n");
        printf("\n\t \t \t \t 3-Adherents list \n \n");
        printf("\n\t \t \t \t 4-Delete Members infos \n \n");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("\n\t \t \t \t 5-Back\n \n");
        SetConsoleTextAttribute(hStdOut, 15);

}



void FILM_ADMIN_Menu(char *name,char *status)
{

        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        print_Date();
        SetConsoleTextAttribute(hStdOut, 9);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   Welcome %s    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2",name);
        SetConsoleTextAttribute(hStdOut, 10);
        printf(" STATUS : %s \n\n\n",status);
        SetConsoleTextAttribute(hStdOut, 14);
        printf("\t \t \t \t==========================\n");
        printf("\t \t \t \t|         Menu           |\n");
        printf("\t \t \t \t==========================\n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\n\t \t \t \t 1-Add films \n \n");
        printf("\n\t \t \t \t 2-Modify films \n \n");
        printf("\n\t \t \t \t 3-Delete films\n \n");
        printf("\n\t \t \t \t 4-Films list \n \n");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("\n\t \t \t \t 5-Back \n \n");
        SetConsoleTextAttribute(hStdOut, 15);
}



void Borrow_ADMIN_Menu(char *name,char *status)
{
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        print_Date();
        SetConsoleTextAttribute(hStdOut, 9);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   Welcome %s    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2",name);
        SetConsoleTextAttribute(hStdOut, 10);
        printf(" STATUS : %s \n\n\n",status);
        SetConsoleTextAttribute(hStdOut, 14);
        printf("\t \t                                    While borrowing , Make sure to follow the rules below :\n");
        printf("\t \t  ==========================     ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("|                              \n");
        SetConsoleTextAttribute(hStdOut, 14);
        printf("\t \t  |         Menu           |     ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("|\t\t    BORROWING GUIDELINES :\n");
        SetConsoleTextAttribute(hStdOut, 14);
        printf("\t \t  ==========================     ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("|\t\t    ----------------------\n");
        printf("\t \t                 \t\t |                                                                      \n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\t \t  1-Browse All Films \t\t ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("| + Each member has a threshold for the number of films he can borrow :\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\t \t  2-My Films \t\t\t ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("|      -Kid = 1 Film\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\t \t  3-Borrow Films \t\t ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("|      -Adolescent = 2 Films\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\t \t  4-Return Films \t\t ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("|      -Adult = 3 Films\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\t \t  5-Borrowed films list          ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("| + Members can only borrow A film adapted to their age category ! \n");
        printf("\t \t                 \t\t ____________________________________________________________________\n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\n\t \t  6-Borrowers list \n \n");
        printf("\n\t \t  7-Films Lent by a specific member \n \n");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("\n\t \t  8-Back \n \n");
        SetConsoleTextAttribute(hStdOut, 15);
}





//========================== Adherant Menus =============================================================

void Adherant_Menu(char *name,char *status)
{
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        print_Date();
        SetConsoleTextAttribute(hStdOut, 9);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   Welcome %s    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2",name);
        SetConsoleTextAttribute(hStdOut, 10);
        printf(" STATUS : %s \n\n\n",status);
        SetConsoleTextAttribute(hStdOut, 14);
        printf("\t \t \t \t==========================\n");
        printf("\t \t \t \t|         Menu           |\n");
        printf("\t \t \t \t==========================\n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\n\t \t \t \t 1-My account \n \n");
        printf("\n\t \t \t \t 2-Add films  \n \n");
        printf("\n\t \t \t \t 3-Manage Borrowings\n \n");
        printf("\n\t \t \t \t 4-Log out\n \n");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("\n\t \t \t \t 5-Exit\n \n");
        SetConsoleTextAttribute(hStdOut, 15);
}


//TODO:ADD Show account info

void Account_Adherant_Menu(char *name,char *status)
{
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 9);
        printf("\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   Welcome %s    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2",name);
        SetConsoleTextAttribute(hStdOut, 10);
        printf(" STATUS : %s \n\n\n",status);
        SetConsoleTextAttribute(hStdOut, 14);
        printf("\t \t \t \t==========================\n");
        printf("\t \t \t \t|         Menu           |\n");
        printf("\t \t \t \t==========================\n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\n\t \t \t \t 1-Modify my Infos \n \n");
        printf("\n\t \t \t \t 2-Delete Account \n \n");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("\n\t \t \t \t 3-Back\n \n");
        SetConsoleTextAttribute(hStdOut, 15);

}


void Borrow_Adherant_Menu(char *name,char *status)
{

        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        print_Date();
        SetConsoleTextAttribute(hStdOut, 9);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   Welcome %s    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2",name);
        SetConsoleTextAttribute(hStdOut, 10);
        printf(" STATUS : %s \n\n\n",status);
        SetConsoleTextAttribute(hStdOut, 14);
        printf("\t \t                                    While borrowing , Make sure to follow the rules below :\n");
        printf("\t \t  ==========================     ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("|                              \n");
        SetConsoleTextAttribute(hStdOut, 14);
        printf("\t \t  |         Menu           |     ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("|\t\t    BORROWING GUIDELINES :\n");
        SetConsoleTextAttribute(hStdOut, 14);
        printf("\t \t  ==========================     ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("|\t\t    ----------------------\n");
        printf("\t \t                 \t\t |                                                                      \n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\t \t  1-Browse All Films \t\t ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("| + Each member has a threshold for the number of films he can borrow :\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\t \t  2-My Films \t\t\t ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("|      -Kid = 1 Film\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\t \t  3-Borrow Films \t\t ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("|      -Adolescent = 2 Films\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        SetConsoleTextAttribute(hStdOut, 15);
        printf("\t \t  4-Return Films \t\t ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("|      -Adult = 3 Films\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("\t \t  5-Back                         ");
        SetConsoleTextAttribute(hStdOut, 12);
        printf("| + Members can only borrow A film adapted to their age category ! \n");
        SetConsoleTextAttribute(hStdOut, 15);
}





#define USER_INTERFACE
#endif
