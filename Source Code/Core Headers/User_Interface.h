#ifndef USER_INTERFACE


#include <stdio.h>
#include <stdlib.h>






//================================ Header and Menu ==============================================================================

void Note(){

        printf("\n\tNote : This program was built to Handle all the basic tasks of The club and it's managed totally by admins.\n");
        printf("\tIf you have any query Try to contact the Moderators.\n");

}

void Header(char *version)
{
        printf("\n\t \t /////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("\t \t //                                                                                     //\n");
        printf("\t \t //                      Welcome to The Vid Club Handler %s                            //\n",version);
        printf("\t \t //                                                                                     //\n");
        printf("\t \t /////////////////////////////////////////////////////////////////////////////////////////\n");
}


void Login_Menu()
{
        printf("\n\nIf you're a new user try signing up first, otherwise you're welcome to start using the Vid handler!!\n\n");
        printf("\t \t \t \t==========================\n");
        printf("\t \t \t \t|         Menu           |\n");
        printf("\t \t \t \t==========================\n");
        printf("\n\t \t \t \t 1-Sign in \n \n");
        printf("\n\t \t \t \t 2-Sign up \n \n");
        printf("\n\t \t \t \t 3-Exit\n \n");
}



//=========================   Admin Menus =================================================================

void ADMIN_Menu(char *name,char *status)
{
        printf("\n\n###########################################     Welcome %s    ################################### STATUS : %s \n\n\n", name,status);
        printf("\t \t \t \t==========================\n");
        printf("\t \t \t \t|         Menu           |\n");
        printf("\t \t \t \t==========================\n");
        printf("\n\t \t \t \t 1-Manage Accounts \n \n");
        printf("\n\t \t \t \t 2-Manage Films  \n \n");
        printf("\n\t \t \t \t 3-Manage Borrowings\n \n");
        printf("\n\t \t \t \t 4-Log out\n \n");
        printf("\n\t \t \t \t 5-Exit\n \n");
}


void Account_ADMIN_Menu(char *name,char *status)
{
        printf("\n\n###########################################     Welcome %s    ################################### STATUS : %s \n\n\n", name,status);
        printf("\t \t \t \t==========================\n");
        printf("\t \t \t \t|         Menu           |\n");
        printf("\t \t \t \t==========================\n");
        printf("\n\t \t \t \t 1-Add a new member \n \n");
        printf("\n\t \t \t \t 2-Modify Members info \n \n");
        printf("\n\t \t \t \t 3-Adherents list \n \n");
        printf("\n\t \t \t \t 4-Delete Members infos \n \n");
        printf("\n\t \t \t \t 5-Back\n \n");

}



void FILM_ADMIN_Menu(char *name,char *status)
{

        printf("\n\n###########################################     Welcome %s    ################################### STATUS : %s \n\n\n", name,status);
        printf("\t \t \t \t==========================\n");
        printf("\t \t \t \t|         Menu           |\n");
        printf("\t \t \t \t==========================\n");
        printf("\n\t \t \t \t 1-Add films \n \n");
        printf("\n\t \t \t \t 2-Modify films \n \n");
        printf("\n\t \t \t \t 3-Delete films\n \n");
        printf("\n\t \t \t \t 4-Films list \n \n");
        printf("\n\t \t \t \t 5-Back \n \n");
}



void Borrow_ADMIN_Menu(char *name,char *status)
{
        printf("\n\n###########################################     Welcome %s    ################################### STATUS : %s \n\n\n", name,status);
        printf("\t \t                                 |  While borrowing , Make sure to follow the rules below :\n");
        printf("\t \t  ==========================     |                              \n");
        printf("\t \t  |         Menu           |     |\t\t    BORROWING GUIDELINES :\n");
        printf("\t \t  ==========================     |\t\t    ----------------------\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t  1-Browse All Films \t\t | + Each member has a threshold for the number of films he can borrow :\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t  2-My Films \t\t\t |      -Kid = 1 Film\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t  3-Borrow Films \t\t |      -Adolescent = 2 Films\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t  4-Return Films \t\t |      -Adult = 3 Films\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t  5-Borrowed films list          | + Members can only borrow A film adapted to their age category ! \n");
        printf("\t \t                 \t\t ____________________________________________________________________\n");
        printf("\n\t \t  6-Borrowers list \n \n");
        printf("\n\t \t  7-Films Lent by a specific member \n \n");
        printf("\n\t \t  8-Back \n \n");

}





//========================== Adherant Menus =============================================================

void Adherant_Menu(char *name,char *status)
{
        printf("\n\n###########################################     Welcome %s    ################################### STATUS : %s \n\n\n", name,status);
        printf("\t \t \t \t==========================\n");
        printf("\t \t \t \t|         Menu           |\n");
        printf("\t \t \t \t==========================\n");
        printf("\n\t \t \t \t 1-My account \n \n");
        printf("\n\t \t \t \t 2-Add films  \n \n");
        printf("\n\t \t \t \t 3-Manage Borrowings\n \n");
        printf("\n\t \t \t \t 4-Log out\n \n");
        printf("\n\t \t \t \t 5-Exit\n \n");
}


//TODO:ADD Show account info

void Account_Adherant_Menu(char *name,char *status)
{
        printf("\n\n###########################################     Welcome %s    ################################### STATUS : %s \n\n\n", name,status);
        printf("\t \t \t \t==========================\n");
        printf("\t \t \t \t|         Menu           |\n");
        printf("\t \t \t \t==========================\n");
        printf("\n\t \t \t \t 1-Modify my Infos \n \n");
        printf("\n\t \t \t \t 2-Delete Account \n \n");
        printf("\n\t \t \t \t 3-Back\n \n");

}


void Borrow_Adherant_Menu(char *name,char *status)
{

        printf("\n\n###########################################     Welcome %s    ################################### STATUS : %s \n\n\n", name,status);
        printf("\t \t                                 |  While borrowing , Make sure to follow the rules below :\n");
        printf("\t \t  ==========================     |                              \n");
        printf("\t \t  |         Menu           |     |\t\t    BORROWING GUIDELINES :\n");
        printf("\t \t  ==========================     |\t\t    ----------------------\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t  1-Browse All Films \t\t |+ Each member has a threshold for the number of films he can borrow :\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t  2-My Films \t\t\t |      -Kid = 1 Film\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t  3-Borrow Films \t\t |      -Adolescent = 2 Films\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t  4-Return Films \t\t |      -Adult = 3 Films\n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t                 \t\t |                                                                      \n");
        printf("\t \t  5-Back \t\t         |+ Members can only borrow A film adapted to their age category ! \n \n");
}





#define USER_INTERFACE
#endif
