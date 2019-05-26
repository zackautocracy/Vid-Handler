#ifndef SWITCH_BODY

#include "Member_Functions.h"
#include "Film_Functions.h"
#include "Loan_Functions.h"
#include "User_Interface.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//                                   ADHERANT switches                                             //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////

int  Switch_Adherant_account_Menu(Member_credentials *ADHERANT_CREDENTIALS,Member_infos *ADHERANT_INFOS,int *loggedout){

        int Back = 0;
        while (Back == 0 && *loggedout == 0) {

                system("cls");

                Back = 0;

                int choice;

                Header("1.0");
                Account_Adherant_Menu(ADHERANT_CREDENTIALS->Member_Login,"ADHERANT");


                printf("Choose one of the options listed above :");
                scanf("%d", &choice);
                fflush(stdin);

                switch (choice) {

                case MODIFY_INFOS:

                        Modify_Or_Delete_Member('M', ADHERANT_CREDENTIALS, ADHERANT_INFOS);
                        printf("The infos has been modified successfully !\n");
                        key();

                        break;

                case DELETE_ACCOUNT:

                        printf("Are you sure you want to delete your account ? (y/n)\n");
                        {

                                fflush(stdin);
                                char c = getchar();
                                fflush(stdin);
                                if (c == 'y')
                                {
                                        Modify_Or_Delete_Member('D', ADHERANT_CREDENTIALS, ADHERANT_INFOS);
                                        *loggedout = 1;
                                        printf("\t \nYour account has been deleted successfully! \n");
                                        key();
                                        break;
                                }
                                else
                                {
                                        system("cls");
                                        continue;
                                }
                        }

                        break;

                case BACK_ACCOUNT:

                        Back = 1;
                        break;

                default:
                        printf("Undefined command\n");
                        key();
                }

        }

        return Back;

}






int Switch_Adherant_Borrowing_Menu(Borrowing_Infos *LOAN,Film_Infos *FILM,Member_credentials *ADHERANT_CREDENTIALS,Member_infos *ADHERANT_INFOS){


        int Back = 0;
        while (Back == 0) {

                system("cls");

                Back = 0;
                int DIDNT_BORROW = 0;
                int choice;

                Header("1.0");
                Borrow_Adherant_Menu(ADHERANT_CREDENTIALS->Member_Login,"ADHERANT");


                printf("Choose one of the options listed above :");
                scanf("%d", &choice);
                fflush(stdin);

                switch (choice) {

                case BROWSE_FILMS:

                        system("cls");
                        Header("1.0");
                        Display_Film_By_Type(FILM);
                        key();
                        break;

                case MY_FILMS:

                        DIDNT_BORROW = Display_Personal_Borrowed_Films(ADHERANT_CREDENTIALS->Member_Login);
                        if (DIDNT_BORROW  == 1) {
                                printf("You didn't borrow anything at the moment !\n");
                                key();
                                continue;
                        }
                        key();
                        break;

                case BORROW_FILM:

                        //Before any borrowing operation we must Check if The Member Reached his MAX borrows
                {
                        int MAX_BORROWS_REACHED = Checking_Max_Borrows(ADHERANT_CREDENTIALS->Member_Login,ADHERANT_INFOS->Member_category);

                        if (MAX_BORROWS_REACHED  == 1) {
                                printf("You Reached The maximum number of films you're allowed to borrow !\n");
                                printf("If you wish to borrow any other film consider returning one first \n");
                                key();

                        }else {

                                Borrow_Return_Film('B',ADHERANT_INFOS,LOAN,FILM, ADHERANT_CREDENTIALS->Member_Login);
                                printf("The borrowing operation has been successful ! \n");
                                key();
                        }

                }

                break;

                case RETURN_FILM:

                        DIDNT_BORROW = Check_If_Borrows(ADHERANT_CREDENTIALS->Member_Login);
                        if (DIDNT_BORROW  == 1) {
                                printf("You didn't borrow anything at the moment !\n");
                                key();
                                continue;
                        }
                        Borrow_Return_Film('R',ADHERANT_INFOS,LOAN,FILM, ADHERANT_CREDENTIALS->Member_Login);
                        printf("The Return operation has been successful ! \n");
                        key();

                        break;
                case BACK_BORROWING:

                        Back = 1;
                        break;

                default:
                        printf("Undefined command\n");
                        key();
                }

        }

        return Back;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//                                   ADMIN switches                                                //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////



int  Switch_ADMIN_account_Menu(Member_credentials *ADHERANT_CREDENTIALS,Member_infos *ADHERANT_INFOS,int *loggedout){

        int Back = 0;
        while (Back == 0 && *loggedout == 0) {

                system("cls");

                Back = 0;

                int choice;

                Header("1.0");
                Account_ADMIN_Menu(ADHERANT_CREDENTIALS->Member_Login,"ADMIN");


                printf("Choose one of the options listed above :");
                scanf("%d", &choice);
                fflush(stdin);

                switch (choice) {

                case ADD_MEMBER:

                        Add_Member(ADHERANT_CREDENTIALS,ADHERANT_INFOS);
                        printf("\t\t \n The new member has been added successfully\n");
                        key();

                        break;

                case MODIFY_MEMBER:

                        Modify_Or_Delete_Member('M', ADHERANT_CREDENTIALS, ADHERANT_INFOS);
                        printf("\nThe infos has been modified successfully !\n");
                        key();

                        break;

                case ADHERENT_LIST:

                        system("cls");
                        Header("1.0");
                        Member_Alpha_Display();
                        key();

                        break;

                case DELETE_ACCOUNT_ADMIN:

                        printf("Are you sure you want to proceed to the next step ? (y/n)\n");
                        {

                                fflush(stdin);
                                char c = getchar();
                                fflush(stdin);
                                if (c == 'y')
                                {
                                        int IS_ADMIN = Modify_Or_Delete_Member('D', ADHERANT_CREDENTIALS, ADHERANT_INFOS);
                                        //If the admin deleted his own account he will be redirected to the login page
                                        if (IS_ADMIN == 1) {
                                                *loggedout = 1;
                                        }

                                        printf("\t \nThe account has been deleted successfully! \n");
                                        key();
                                        break;
                                }
                                else
                                {
                                        system("cls");
                                        continue;
                                }
                        }

                        break;

                case BACK_ACCOUNT_ADMIN:

                        Back = 1;
                        break;

                default:
                        printf("Undefined command\n");
                        key();
                }

        }

        return Back;

}





int Switch_ADMIN_FILM_Menu(Film_Infos *FILM,Member_credentials *ADHERANT_CREDENTIALS){


        int Back = 0;
        while (Back == 0 ) {

                system("cls");

                Back = 0;
                int choice;

                Header("1.0");
                FILM_ADMIN_Menu(ADHERANT_CREDENTIALS->Member_Login,"ADMIN");


                printf("Choose one of the options listed above :");
                scanf("%d", &choice);
                fflush(stdin);

                switch (choice) {

                case ADD_FILMS:

                        Add_Film(FILM, ADHERANT_CREDENTIALS->Member_Login);
                        printf("The film has been added successfully\n");
                        key();
                        break;

                case MODIFY_FILMS:

                        Modify_Or_Delete_Film('M', FILM);
                        printf("The film has been modified successfully\n");
                        key();
                        break;

                case DELETE_FILMS:

                        Modify_Or_Delete_Film('D', FILM);
                        printf("The film has been deleted successfully\n");
                        key();
                        break;

                case FILMS_LIST:

                        system("cls");
                        Header("1.0");
                        Display_Film_By_Type(FILM);
                        key();
                        break;

                case BACK_FILMS:

                        Back = 1;
                        break;

                default:
                        printf("Undefined command\n");
                        key();
                }
        }

        return Back;
}





int Switch_ADMIN_Borrowing_Menu(Borrowing_Infos *LOAN,Film_Infos *FILM,Member_credentials *ADHERANT_CREDENTIALS,Member_infos *ADHERANT_INFOS){


        int Back = 0;
        while (Back == 0) {

                system("cls");

                Back = 0;
                int DIDNT_BORROW = 0;
                int choice;

                Header("1.0");
                Borrow_ADMIN_Menu(ADHERANT_CREDENTIALS->Member_Login,"ADMIN");


                printf("Choose one of the options listed above :");
                scanf("%d", &choice);
                fflush(stdin);

                switch (choice) {

                case BROWSE_FILMS_ADMIN:

                        system("cls");
                        Header("1.0");
                        Display_Film_By_Type(FILM);
                        key();
                        break;

                case MY_FILMS_ADMIN:

                        DIDNT_BORROW = Display_Personal_Borrowed_Films(ADHERANT_CREDENTIALS->Member_Login);
                        if (DIDNT_BORROW  == 1) {
                                printf("You didn't borrow anything at the moment !\n");
                                key();
                                continue;
                        }
                        key();
                        break;

                case BORROW_FILM_ADMIN:

                {
                        int MAX_BORROWS_REACHED = Checking_Max_Borrows(ADHERANT_CREDENTIALS->Member_Login,ADHERANT_INFOS->Member_category);
                        if (MAX_BORROWS_REACHED  == 1) {
                                printf("You Reached The maximum number of films you're allowed to borrow !\n");
                                printf("If you wish to borrow any other film consider returning one first \n");
                                key();

                        }else {

                                Borrow_Return_Film('B',ADHERANT_INFOS,LOAN,FILM, ADHERANT_CREDENTIALS->Member_Login);
                                printf("The borrowing operation has been successful ! \n");
                                key();
                        }

                }

                break;

                case RETURN_FILM_ADMIN:

                        DIDNT_BORROW = Check_If_Borrows(ADHERANT_CREDENTIALS->Member_Login);
                        if (DIDNT_BORROW  == 1) {
                                printf("You didn't borrow anything at the moment !\n");
                                key();
                                continue;
                        }
                        Borrow_Return_Film('R',ADHERANT_INFOS,LOAN,FILM, ADHERANT_CREDENTIALS->Member_Login);
                        printf("The Return operation has been successful ! \n");
                        key();

                        break;


                case BORROWED_FILMS_LIST:

                        DIDNT_BORROW = Display_Borrowed_Films();
                        if (DIDNT_BORROW  == 1) {
                                printf("The list is empty !\n");
                                key();
                                continue;
                        }
                        key();
                        break;

                case BORROWERS_LIST:

                        DIDNT_BORROW = Display_Borrowers();
                        if (DIDNT_BORROW  == 1) {
                                printf("The list is empty !\n");
                                key();
                                continue;
                        }
                        key();
                        break;

                case SPECIFIC_MEMBER_FILMS:
                {
                        char Owner[MAX_LOGIN];
                        printf("Enter the Owner you want to see its stats\n");
                        gets(Owner);
                        DIDNT_BORROW = Display_Lent_Films_By_Owner(Owner);
                        if (DIDNT_BORROW  == 1) {
                                printf("There is no films assigned to members by this owner\n");
                                key();
                                continue;
                        }
                }
                        key();
                        break;

                case BACK_BORROWING_ADMIN:

                        Back = 1;
                        break;

                default:
                        printf("Undefined command\n");
                        key();
                }

        }

        return Back;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//                                   Main  switch                                                  //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////


void MAIN_Switch(Borrowing_Infos *LOAN,Film_Infos *FILM,Member_credentials *ADHERANT_CREDENTIALS,Member_infos *ADHERANT_INFOS)
{


        //================== Sign_in & Sign_up operations ============================================================

        system("cls");
        int loggedin  = 0;
        int loggedout = 0;

        while (loggedin == 0) //user can break out of the loop only if he sign in or exit
        {
                int choice;

                // User interface
                Header("1.0");
                Note();
                Login_Menu();

                printf("Choose one of the options listed above :");
                scanf("%d", &choice);
                fflush(stdin);

                switch (choice)
                {
                case SIGN_IN:
                {
                        int status = Sign_In_Member(ADHERANT_CREDENTIALS,ADHERANT_INFOS);
                        if (status == 1)
                        {
                                printf("\t\t \n Sign in operation was successful\n");
                                loggedin = 1;
                        }
                        else
                        {
                                printf("\t\t \n Sign in operation failed...\n\n");
                                printf("\t\t Login or Password incorrect\n");
                                key();

                                continue;
                        }
                }
                break;

                case SIGN_UP:

                        Add_Member(ADHERANT_CREDENTIALS,ADHERANT_INFOS);
                        printf("\t\t \n Sign up operation was successful\n");
                        printf("\t\t Now you must sign in to access your account\n");

                        key();

                        break;

                case LOGIN_EXIT:
                        exit(1);


                default:
                        printf("You must be logged-in in order to do any operation\n");
                        key();
                }


        }

        system("cls");


//========================= THE MAIN MENU ==================================================================
//We have two cases : ADMIN or Normal ADHERANT

        if (strcmp(ADHERANT_CREDENTIALS->Member_Status, "ADMIN") == 0)
        {
                while (loggedout == 0)
                {
                        int choice;
                        int Back = 0;

                        system("cls");
                        Header("1.0");
                        ADMIN_Menu(ADHERANT_CREDENTIALS->Member_Login,"ADMIN");

                        printf("Choose one of the options listed above :");
                        scanf("%d", &choice);
                        fflush(stdin);

                        switch (choice)
                        {
                        case MANAGE_ACCOUNTS:

                                Back = Switch_ADMIN_account_Menu(ADHERANT_CREDENTIALS, ADHERANT_INFOS, &loggedout);
                                if (Back == 1)
                                {
                                        continue;
                                }

                                break;

                        case MANAGE_FILMS:

                                Back = Switch_ADMIN_FILM_Menu(FILM,ADHERANT_CREDENTIALS);
                                if (Back == 1)
                                {
                                        continue;
                                }

                                break;

                        case MANAGE_BORROWINGs:

                                Back = Switch_ADMIN_Borrowing_Menu(LOAN, FILM, ADHERANT_CREDENTIALS,ADHERANT_INFOS);
                                if (Back == 1)
                                {
                                        continue;
                                }

                                break;

                        case LOG_OUT_ADMIN:

                                loggedout = 1;

                                break;

                        case ADMIN_EXIT:
                                exit(1);

                        default:
                                printf("Undefined command\n");
                                key();
                        }
                        if (loggedout == 1)
                        {
                                system("cls");
                                Header("1.0");
                                printf("\n\n\n\n\n\n \t\tDon't forget to visit next time !!\n\n\n");
                                delay(3);
                                break;
                        }
                }
        }
        else
        {
                while (loggedout == 0)
                {          //The user can break out of the loop only if he loggout or exit
                        int choice;
                        int Back = 0;

                        system("cls");
                        Header("1.0");
                        Adherant_Menu(ADHERANT_CREDENTIALS->Member_Login,"ADHERANT");

                        printf("Choose one of the options listed above :");
                        scanf("%d", &choice);
                        fflush(stdin);

                        switch (choice)
                        {
                        case MY_ACCOUNT:

                                Back = Switch_Adherant_account_Menu(ADHERANT_CREDENTIALS, ADHERANT_INFOS, &loggedout);
                                if (Back == 1)
                                {
                                        continue;
                                }

                                break;

                        case ADD_FILM_ADHERANT:

                                Add_Film(FILM, ADHERANT_CREDENTIALS->Member_Login);
                                printf("The film has been added successfully\n");
                                key();

                                break;

                        case MANAGE_BORROWINGS:

                                Back = Switch_Adherant_Borrowing_Menu(LOAN, FILM, ADHERANT_CREDENTIALS,ADHERANT_INFOS);
                                if (Back == 1)
                                {
                                        continue;
                                }

                                break;

                        case LOG_OUT_ADHERANT:

                                loggedout = 1;

                                break;

                        case ADHERANT_EXIT:
                                exit(1);

                        default:
                                printf("Undefined command\n");
                                key();
                        }
                        if (loggedout == 1)
                        {
                                system("cls");
                                Header("1.0");
                                printf("\n\n\n\n\n\n \t\tDon't forget to visit next time !!\n\n\n");
                                delay(3);
                                break;
                        }
                }

        }
}





#define SWITCH_BODY
#endif
