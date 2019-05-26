#ifndef LOAN_FUNCTIONS

#include <string.h>
#include <stdlib.h>
#include "filelib.h"
#include "struct.h"
#include "constant.h"
#include "Support_Functions.h"




/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//                              Loan Handling                                                      //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////



//The approach we took for borrowing films is as follows :
//1-The ADHERANT choose the film he want to borrow by it's Title
//2-A first new file will be customized for him to store the films he borrowed
//3-The second file will store The borrowers
//4-The last file will Keep track of the borrowed films and the available Copies_numb

//############################ Borrow/Return a FILM #########################################################



//Used Functions :

//1- It updates the number of actual remaining copies in the original FILM Database
void  Update_Borrowing_Infos(char Borrow_Return,Member_infos *ADHERANT_INFOS,Borrowing_Infos *LOAN,Film_Infos *FILM);
//2- It creates a custom file associated with the user and keep track of his/her personal borrowings
int Customize_File(char Borrow_Return,Borrowing_Infos *LOAN,Film_Infos *FILM,char *Borrower);
//3- It keeps track of the Borrowers
void Borrowers_Record(char Borrow_Return,Borrowing_Infos *LOAN,char *Borrower);
//4- It keeps track of all the borrowed films and the number of copies borrowed
void FILM_Record(char Borrow_Return,Borrowing_Infos *LOAN,Film_Infos *FILM);

void Borrow_Return_Film(char Borrow_Return,Member_infos *ADHERANT_INFOS,Borrowing_Infos *LOAN,Film_Infos *FILM,char *Borrower){


        //B : Borrow /R : Return
        if (Borrow_Return == 'B') {
                //Asks the user The film he wish to borrow or return
                //It updates the Available copies numb directly in the original film database
                Update_Borrowing_Infos('B',ADHERANT_INFOS, LOAN, FILM);
                int ALREADY_BORROWED = Customize_File('B',LOAN,FILM,Borrower);

                while (ALREADY_BORROWED == 1) {
                        printf("\nYou're trying to Borrow a film You already have !\n");
                        Update_Borrowing_Infos('B',ADHERANT_INFOS, LOAN, FILM);
                        ALREADY_BORROWED = Customize_File('B',LOAN,FILM,Borrower);
                }

                Borrowers_Record('B',LOAN,Borrower);
                FILM_Record('B',LOAN,FILM);


        }else if (Borrow_Return == 'R') {

                Update_Borrowing_Infos('R',ADHERANT_INFOS, LOAN, FILM);
                int DOES_NOT_EXIST = Customize_File('R',LOAN,FILM,Borrower);


                while (DOES_NOT_EXIST == 1) {
                        printf("\nYou're trying to Return a film You didn't Borrow !\n");
                        Update_Borrowing_Infos('R',ADHERANT_INFOS, LOAN, FILM);
                        DOES_NOT_EXIST = Customize_File('R',LOAN,FILM,Borrower);
                }

                Borrowers_Record('R',LOAN,Borrower);
                FILM_Record('R',LOAN,FILM);
        }

}

//############################ Borrower Guideline Checker #########################################################



int Checking_Max_Borrows(char *Borrower,char *Member_category){

        int MAX_BORROWS_REACHED = 0;
        char *Borrower_File = Customize_Name(Borrower);
        FILE *pBorrower_USER_file = fopen(Borrower_File, "r");




        if (pBorrower_USER_file != NULL) {

                if (strcmp(Member_category,"K") == 0 && linecount(pBorrower_USER_file) >= 1) {
                        MAX_BORROWS_REACHED = 1;

                }else if (strcmp(Member_category,"AD") == 0 && linecount(pBorrower_USER_file) >= 2 ) {
                        MAX_BORROWS_REACHED = 1;

                }else if (strcmp(Member_category,"A") == 0 && linecount(pBorrower_USER_file) >= 3 ) {
                        MAX_BORROWS_REACHED = 1;

                }

                fclose(pBorrower_USER_file);
                return MAX_BORROWS_REACHED;
        }
}


//############################ Display Borrowing  Infos #########################################################

//It displays all the Borrowed films

int  Display_Borrowed_Films(){

        int DOES_NOT_EXIST = 0;

        FILE *pFILM_File = fopen(_BORROWED_FILM_FILE,"r");

        if (pFILM_File == NULL) {
                DOES_NOT_EXIST  = 1;
                fclose(pFILM_File);
                return DOES_NOT_EXIST;
        }

        readfile(pFILM_File);

        fclose(pFILM_File);

        return DOES_NOT_EXIST;
}


int Display_Personal_Borrowed_Films(char *Borrower){

        int DOES_NOT_EXIST = 0;
        char *Borrower_File = Customize_Name(Borrower);
        FILE *pBorrower_USER_file = fopen(Borrower_File, "r");


        if (pBorrower_USER_file == NULL) {
                DOES_NOT_EXIST  = 1;
                fclose(pBorrower_USER_file);
                return DOES_NOT_EXIST;
        }

        readfile(pBorrower_USER_file);

        fclose(pBorrower_USER_file);

        return DOES_NOT_EXIST;



}


//It cheecks if the Specific borrower file exists

int Check_If_Borrows(char *Borrower){

        int DOES_NOT_EXIST = 0;
        char *Borrower_File = Customize_Name(Borrower);
        FILE *pBorrower_USER_file = fopen(Borrower_File, "r");


        if (pBorrower_USER_file == NULL) {
                DOES_NOT_EXIST  = 1;
                fclose(pBorrower_USER_file);
                return DOES_NOT_EXIST;
        }

        fclose(pBorrower_USER_file);

        return DOES_NOT_EXIST;
}



//It displays all the Borrowers

int  Display_Borrowers(){

        int DOES_NOT_EXIST = 0;

        FILE *pBorrowers_File = fopen(_BORROWERS_DATABASE_FILE,"r");

        if (pBorrowers_File == NULL) {
                DOES_NOT_EXIST  = 1;
                fclose(pBorrowers_File);
                return DOES_NOT_EXIST;
        }

        readfile(pBorrowers_File);

        fclose(pBorrowers_File);

        return DOES_NOT_EXIST;
}


//It displays all the films lent by a specific member

int  Display_Lent_Films_By_Owner(char *Owner){

        int DOES_NOT_EXIST = 0;

        int Temp_Numb;
        Film_Infos test;


        FILE *pFILM_File = fopen(_BORROWED_FILM_FILE,"r");

        if (pFILM_File == NULL  || CHECK_IF_EXIST(Owner,pFILM_File) == 0) {
                DOES_NOT_EXIST  = 1;
                fclose(pFILM_File);
                return DOES_NOT_EXIST;
        }

        rewind(pFILM_File);

        while (fscanf(pFILM_File,"Film title: %s   |Number of borrowed copies: %d   |Owned by: %s\n",test.Title,&Temp_Numb,test.Ownership) != EOF) {
                if (strcmp(Owner,test.Ownership) == 0) {
                        printf("\t\tFilm title: %s   |Number of borrowed copies: %d\n\n",test.Title,Temp_Numb);
                }
        }

        fclose(pFILM_File);


        return DOES_NOT_EXIST;
}
























#define LOAN_FUNCTIONS
#endif
