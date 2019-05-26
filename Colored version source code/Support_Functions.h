#ifndef SUPPORT_FUNCTIONS



#include "constant.h"
#include "randomize.h"
#include "conio.h"
#include "filelib.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//                             Member Support functions                                                   //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////



//=========================== Member Input ==================================================================================

//Credentials input

//Function used :
int CHECK_IF_LOGIN_TAKEN(FILE *pfile, char *Login);
int CHECK_IF_PASSWORD_IS_NON_VALID(char *password);
void HIDE_PASSWORD(char *password);
int Encrypt_Password(char *password);

void Credentials_Input(Member_credentials *ADHERANT_CREDENTIALS,FILE* pFILE_DATABASE)
{


        int flag_Login;
        int flag_Password;
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

        //Checking if the Login is already taken
        printf("Choose a Login :\n");
        SetConsoleTextAttribute(hStdOut, 10);
        gets(ADHERANT_CREDENTIALS->Member_Login);
        SetConsoleTextAttribute(hStdOut, 15);
        while (flag_Login = CHECK_IF_LOGIN_TAKEN(pFILE_DATABASE, ADHERANT_CREDENTIALS->Member_Login))
        {

                SetConsoleTextAttribute(hStdOut, 12);
                printf("This Login is already taken\n");
                SetConsoleTextAttribute(hStdOut, 15);
                printf("Choose a Login :\n");
                SetConsoleTextAttribute(hStdOut, 10);
                gets(ADHERANT_CREDENTIALS->Member_Login);
                SetConsoleTextAttribute(hStdOut, 15);
        }

        //Checking for the validity of the password
        printf("Choose a password (6 characters minimum) :\n");
        SetConsoleTextAttribute(hStdOut, 10);
        HIDE_PASSWORD(ADHERANT_CREDENTIALS->Member_Password);
        SetConsoleTextAttribute(hStdOut, 15);
        while (flag_Password = CHECK_IF_PASSWORD_IS_NON_VALID(ADHERANT_CREDENTIALS->Member_Password))
        {
                SetConsoleTextAttribute(hStdOut, 12);
                printf("\nOnly letters and numbers should be used in the password\n");
                SetConsoleTextAttribute(hStdOut, 15);
                printf("Choose a password (6 characters minimum) :\n");
                SetConsoleTextAttribute(hStdOut, 10);
                HIDE_PASSWORD(ADHERANT_CREDENTIALS->Member_Password);
                SetConsoleTextAttribute(hStdOut, 15);
        }


        ADHERANT_CREDENTIALS->Encryption_Key = Encrypt_Password(ADHERANT_CREDENTIALS->Member_Password);

}



//Infos input

void Infos_Input(Member_infos *ADHERANT_INFOS)
{



        /*Taking input by fgets to avoid buffer overflow
         * The downside of using fgets is that it stores the newline character before terminating the string
         * So we must filter out all the additional '\n'*/



        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);


        printf("\nEnter your first name :\n");
        SetConsoleTextAttribute(hStdOut, 10);
        fgets(ADHERANT_INFOS->Member_firstname, MAX_INFO_INPUT, stdin);
        strtok(ADHERANT_INFOS->Member_firstname, "\n");
        SetConsoleTextAttribute(hStdOut, 15);

        printf("Enter your Last name :\n");
        SetConsoleTextAttribute(hStdOut, 10);
        fgets(ADHERANT_INFOS->Member_lastname, MAX_INFO_INPUT, stdin);
        strtok(ADHERANT_INFOS->Member_lastname, "\n");
        SetConsoleTextAttribute(hStdOut, 15);

        printf("Enter your Adress :\n");
        SetConsoleTextAttribute(hStdOut, 10);
        fgets(ADHERANT_INFOS->Member_adress, MAX_INFO_INPUT, stdin);
        strtok(ADHERANT_INFOS->Member_adress, "\n");
        SetConsoleTextAttribute(hStdOut, 15);

        printf("Enter your phone number:\n");
        SetConsoleTextAttribute(hStdOut, 10);
        fgets(ADHERANT_INFOS->Member_phonenumb, MAX_INFO_INPUT, stdin);
        strtok(ADHERANT_INFOS->Member_phonenumb, "\n");
        SetConsoleTextAttribute(hStdOut, 15);

        printf("Choose your age category (A:Adult/K:Kid/AD:Adolescent)\n");
        SetConsoleTextAttribute(hStdOut, 10);
        fgets(ADHERANT_INFOS->Member_category, MAX_CATEGORIE_TYPES, stdin);
        strtok(ADHERANT_INFOS->Member_category, "\n");
        SetConsoleTextAttribute(hStdOut, 15);

}


//=========================== Checking If Login & Password valid ==========================================================


int CHECK_IF_LOGIN_TAKEN(FILE *pfile, char *Login)
{
        int error = 0;
        //Plays the role of a temporary buffer to test the login existence
        Member_credentials test;

        while ((fscanf(pfile, "%d    Name: %s   Password: %s   Status: %s\n", &test.Member_ID, test.Member_Login, test.Member_Password,test.Member_Status)) != EOF)
        {
                if (strcmp(test.Member_Login, Login) == 0)
                {
                        error = 1;
                        break;
                }
                else
                {
                        error = 0;
                }
        }


        rewind(pfile);
        return error;
}


//Check if the password is non valid

int CHECK_IF_PASSWORD_IS_NON_VALID(char *password)
{
        int flag;

        if (strlen(password) >= 6)
        {
                for (char *str = password; str < password + strlen(password) - 1; str++)
                {
                        flag = 1;

                        if ((*str >= 'a') && (*str <= 'z'))
                        {
                                flag = 0;
                        }
                        else if ((*str >= 'A') && (*str <= 'Z'))
                        {
                                flag = 0;
                        }
                        else if ((*(str) >= '0') && (*(str) <= '9'))
                        {
                                flag = 0;
                        }
                        else
                        {
                                flag = 1;
                                break;
                        }
                }
        }
        else
        {
                flag = 1;
        }


        return flag;
}


//============================ Password Handling  ===========================================================


//Hinding the password
void HIDE_PASSWORD(char *password)
{
        int i = 0;
        char c;

        while (1)
        {
                fflush(stdin);
                c = getch();
                if (c == ENTER)
                {
                        password[i] = '\0';
                        break;
                }
                else if (c == BACKSPACE)
                {
                        i--;
                        password[i] = '\0';
                        printf("\b \b");
                }
                else
                {
                        password[i] = c;
                        printf("*");
                        i++;
                }
        }
        password[i] = '\0';
}




//Used function :
int  myRand(int low, int high);

//Encrypting password
int Encrypt_Password(char *password)
{
        int Encryption_Key = myRand(1,5);
        char *str           = password;

        for (; *str != '\0'; str++)
        {
                *str += Encryption_Key;
        }

        return Encryption_Key;
}

//Decrypting the password
void Decrypt_Password(char *password,int Encryption_Key)
{

        char *str = password;

        for (; *str != '\0'; str++)
        {
                *str -= Encryption_Key;
        }
}




/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//                             FILM Support functions                                              //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////





//=============================== New FILM INPUT ==========================================================

//TODO:Add the option to add more than one film for admins

//Functions used :
int CHECK_IF_FILM_EXISTS(FILE *pfile, char *FILM_Title,char *FILM_Code);

void Film_Infos_Input(Film_Infos *FILM,FILE *pFILM_DATABASE){

        /*Taking input by fgets to avoid buffer overflow
         * The downside of using fgets is that it stores the newline character before terminating the string
         * So we must filter out all the additional '\n'*/

        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 10);
        printf("Note : You can only add New films to the collection ,Contact Admins for more infos\n\n");
        SetConsoleTextAttribute(hStdOut, 15);

        printf("\nEnter The Film code (6 Capital letters) :\n");
        SetConsoleTextAttribute(hStdOut, 10);
        fgets(FILM->Code, MAX_FILM_CODE, stdin);
        strtok(FILM->Code, "\n");
        SetConsoleTextAttribute(hStdOut, 15);

        fflush(stdin);
        printf("Enter The film title :\n");
        SetConsoleTextAttribute(hStdOut, 10);
        fgets(FILM->Title, MAX_FILM_TITLE, stdin);
        strtok(FILM->Title, "\n");
        SetConsoleTextAttribute(hStdOut, 15);


        //User will keep looping until he provides a valid new Film
        int Existant_FILM;
        while (Existant_FILM = CHECK_IF_FILM_EXISTS(pFILM_DATABASE,FILM->Title,FILM->Code)) {

                SetConsoleTextAttribute(hStdOut, 12);
                printf("This Film already exists (Make sure That your film code is unique)\n");
                SetConsoleTextAttribute(hStdOut, 15);
                printf("\nEnter The Film code (6 Capital letters) :\n");
                SetConsoleTextAttribute(hStdOut, 10);
                fgets(FILM->Code, MAX_FILM_CODE, stdin);
                strtok(FILM->Code, "\n");
                SetConsoleTextAttribute(hStdOut, 15);

                fflush(stdin);
                printf("Enter The film title (Use Underscores rather than Whitespace):\n");
                SetConsoleTextAttribute(hStdOut, 10);
                fgets(FILM->Title, MAX_FILM_TITLE, stdin);
                strtok(FILM->Title, "\n");
                SetConsoleTextAttribute(hStdOut, 15);
        }


        printf("How many copies of the Film you currently have :\n");
        SetConsoleTextAttribute(hStdOut, 10);
        scanf("%d",&FILM->Copies_numb);
        fflush(stdin);
        SetConsoleTextAttribute(hStdOut, 15);

        printf("Enter The Film type :\n");
        printf("W : western\nD : documentary\nS : science fiction\nC : Crime\nAN : Anime\nO : Other.\n");
        SetConsoleTextAttribute(hStdOut, 10);
        fgets(FILM->Type, MAX_CATEGORIE_TYPES, stdin);
        strtok(FILM->Type, "\n");
        SetConsoleTextAttribute(hStdOut, 15);

        fflush(stdin);
        printf("Enter the Film Adaptation :\n");
        printf("ALL : Anyone\nA : Adult\nK : Kid\nAD : Adolescent.\n");
        SetConsoleTextAttribute(hStdOut, 10);
        fgets(FILM->Adaptation, MAX_CATEGORIE_TYPES, stdin);
        strtok(FILM->Adaptation, "\n");
        SetConsoleTextAttribute(hStdOut, 15);

}




//============================= Checking if the FILM is valid ======================================================


int CHECK_IF_FILM_EXISTS(FILE *pfile, char *FILM_Title,char *FILM_Code)
{
        int error = 0;
        //Plays the role of a temporary buffer to test the login existence
        Film_Infos test;


        int Film_ID;

        while ((fscanf(pfile, "%d    |Code: %s   |Title: %s   |Type: %s   |Available copies: %d   |Adaptation: %s   |Ownership: %s\n", &Film_ID, test.Code, test.Title,test.Type,&test.Copies_numb,test.Adaptation,test.Ownership)) != EOF)
        {
                //If the film exists within the database it means whether The code or the title is redundant
                if (strcmp(test.Title, FILM_Title) == 0  || strcmp(test.Code, FILM_Code) == 0 )
                {
                        error = 1;
                        break;
                }
                else
                {
                        error = 0;
                }
        }


        rewind(pfile);
        return error;
}



//======================= Display A specific type of films =====================================================================


void Display_Specific_Type_Film(Film_Infos *FILM,FILE *pFILE_DATABASE,char *Film_Type){

        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

        rewind(pFILE_DATABASE);

        int Film_ID = 0;
        Film_Infos test;

        while ((fscanf(pFILE_DATABASE, "%d    |Code: %s   |Title: %s   |Type: %s   |Available copies: %d   |Adaptation: %s   |Ownership: %s\n", &Film_ID, test.Code, test.Title,test.Type,&test.Copies_numb,test.Adaptation,test.Ownership)) != EOF)
        {
                if (strcmp(test.Type,Film_Type)== 0)
                {
                        printf("\t\tTitle: ");
                        SetConsoleTextAttribute(hStdOut, 12);
                        printf("%s   ",test.Title);
                        SetConsoleTextAttribute(hStdOut, 15);
                        printf("|Available copies: ");
                        if (test.Copies_numb == 0) {
                                SetConsoleTextAttribute(hStdOut, 12);
                                printf("%d  ",test.Copies_numb);
                        }else {
                                SetConsoleTextAttribute(hStdOut, 10);
                                printf("%d  ",test.Copies_numb);
                        }
                        SetConsoleTextAttribute(hStdOut, 15);
                        printf("|Adaptation: ");
                        SetConsoleTextAttribute(hStdOut, 14);
                        printf("%s\n\n",test.Adaptation);
                        SetConsoleTextAttribute(hStdOut, 15);
                }
        }

        rewind(pFILE_DATABASE);

}




/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//                             LOAN Support functions                                              //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////




//=========================== Updating the borrowing info ====================================================

//Used functions :
int CHANGE_COPIES_NUMB_LINE(char Borrow_Return,Member_infos *ADHERANT_INFOS,Borrowing_Infos *LOAN,Film_Infos *FILM,FILE *srcFile, FILE *tempFile, const int line);

void  Update_Borrowing_Infos(char Borrow_Return,Member_infos *ADHERANT_INFOS,Borrowing_Infos *LOAN,Film_Infos *FILM){

        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        int REMAINING_COPIES;

        FILE *pSOURCE_FILM_DATABASE = NULL;


        pSOURCE_FILM_DATABASE = fopen(_FILM_DATABASE_FILE, "r");
        nullcheck(pSOURCE_FILM_DATABASE, _FILM_DATABASE_FILE);

        rewind(pSOURCE_FILM_DATABASE);

        FILE *pDest_FILM_DATABASE   = fopen("DATABASE_replica.txt", "w");


        int Film_ID;
        char Film_Buffer[MAX_FILM_TITLE];


        while (1) {
                int Stuck = 0;
                do {

                        printf("\nEnter the Title of the Film u want to Borrow/Return (Must exist !):\n");
                        SetConsoleTextAttribute(hStdOut, 12);
                        printf("Warning !: (Use Underscores rather than Whitespace)\n\n");
                        SetConsoleTextAttribute(hStdOut, 10);
                        gets(Film_Buffer);
                        SetConsoleTextAttribute(hStdOut, 15);
                } while((Film_ID = SEARCH_ID(Film_Buffer,pSOURCE_FILM_DATABASE)) == 0);
                //The user will keep looping until he provides a Film that exists in the database

                // B : Borrow / R : Return
                if (Borrow_Return == 'B') {

                        //The memeber will be stuck on the loop if he doesn't follow the borrowings guidelines
                        REMAINING_COPIES = CHANGE_COPIES_NUMB_LINE('B',ADHERANT_INFOS,LOAN,FILM,pSOURCE_FILM_DATABASE,pDest_FILM_DATABASE,Film_ID);
                        switch (REMAINING_COPIES) {
                        case -1:

                                SetConsoleTextAttribute(hStdOut, 12);
                                printf("\nThis film is not available at the moment contact ADMINS for more information\n");
                                SetConsoleTextAttribute(hStdOut, 15);
                                printf("Choose another film \n");
                                Stuck = 1;
                        case -2:
                                SetConsoleTextAttribute(hStdOut, 12);
                                printf("\nThis film is not adapted to your category ,Browse the list of films for more information \n");
                                SetConsoleTextAttribute(hStdOut, 15);
                                printf("Choose another film \n");
                                Stuck = 1;

                        }

                        if (Stuck == 1)
                        {
                                continue;
                        }
                        else {
                                //The user will break out of the loop if he provides an available film
                                break;
                        }
                }else if (Borrow_Return == 'R') {

                        CHANGE_COPIES_NUMB_LINE('R',ADHERANT_INFOS,LOAN,FILM,pSOURCE_FILM_DATABASE,pDest_FILM_DATABASE,Film_ID);
                        break;
                }

        }

        fclose(pSOURCE_FILM_DATABASE);
        pSOURCE_FILM_DATABASE = NULL;

        //Removing the old files
        remove(_FILM_DATABASE_FILE);
        fclose(pDest_FILM_DATABASE);

        rename("DATABASE_replica.txt", _FILM_DATABASE_FILE);

}



//===================== Create a customized file for the user =====================================================================



//This file will keep record of all the films borrowed by a specific user with the date of borrowing respectively
//We had two options :
//1- Relying on the Film Structure to hold The film name when A user try to borrow a film
//2- (less efficient) Not use the film structure instead we retrieve the film name by it's Unique code that holds the reference to it
//-> The latter approach will invoke a search algorithms which will add a O(n) complexity uselessly
//We preferred to integrate the film structure (More efficient)
//Consequences => You will notice the film title will be stored in the structure in the CHANGE_COPIES_NUMB_LINE function

//Used functions :
char *Customize_Name(char *name);

int Customize_File(char Borrow_Return,Borrowing_Infos *LOAN,Film_Infos *FILM,char *Borrower){

        //Retrieve the User Login to customize the file
        char *Borrower_File = Customize_Name(Borrower);
        FILE *pSOURCE_Borrower_File = fopen(Borrower_File, "a+");
        nullcheck(pSOURCE_Borrower_File,Borrower_File);
        rewind(pSOURCE_Borrower_File);

        //We distinguish the The borrowing and the return cases :
        //1- If the user try to borrow a file His customized file will get updated and a new film is added
        //2- If the user try to return a file The line which contains the borrowed film in his file will be removed
        int FILM_ID;

        if (Borrow_Return == 'B') {

                int ALREADY_BORROWED = 0;


                if(CHECK_IF_EXIST(FILM->Title,pSOURCE_Borrower_File) != 0) {
                        ALREADY_BORROWED = 1;
                        return ALREADY_BORROWED;
                }

                FILM_ID = linecount(pSOURCE_Borrower_File) + 1;
                fprintf(pSOURCE_Borrower_File,"Borrowed FILM: %s   |FILM Code: %s   |Date of Borrowing: %s\n",FILM->Title,LOAN->Film_Code,LOAN->Date);

                fclose(pSOURCE_Borrower_File);
                pSOURCE_Borrower_File = NULL;

                return ALREADY_BORROWED;

        } else if (Borrow_Return == 'R') {

                int DOES_NOT_EXIST = 0;

                //Retrieving the film ID
                //The user might try to return a film he didn't borrow So we must check
                if((FILM_ID = SEARCH_ID(FILM->Title,pSOURCE_Borrower_File)) == 0) {
                        DOES_NOT_EXIST = 1;
                        return DOES_NOT_EXIST;
                }

                //If the file contains only one film we should remove it directly
                if (linecount(pSOURCE_Borrower_File) == 1) {
                        fclose(pSOURCE_Borrower_File);
                        pSOURCE_Borrower_File = NULL;

                        remove(Borrower_File);
                        //Otherwise we delete the specific film from the file
                }else {

                        FILE *pDest_Borrower_FILE   = fopen("Borrower_replica.txt", "w");

                        DELETE_LINE(pSOURCE_Borrower_File,pDest_Borrower_FILE,FILM_ID);


                        fclose(pSOURCE_Borrower_File);
                        pSOURCE_Borrower_File = NULL;

                        //Removing the old files
                        remove(Borrower_File);
                        fclose(pDest_Borrower_FILE);
                        pDest_Borrower_FILE = NULL;

                        rename("Borrower_replica.txt", Borrower_File);

                }

                return DOES_NOT_EXIST;
        }
}


//===================== Create The borrowers file =========================================================

//Used functions :
char *Customize_Name(char *name);

void Borrowers_Record(char Borrow_Return,Borrowing_Infos *LOAN,char *Borrower){

        FILE *pSOURCE_Borrower_File = fopen(_BORROWERS_DATABASE_FILE, "a+");
        nullcheck(pSOURCE_Borrower_File,_BORROWERS_DATABASE_FILE);
        rewind(pSOURCE_Borrower_File);

        //This file will deal with two operations :
        //1- Append a new borrower to the list
        //2- Delete a specific borrower after he returns all the films

        //To distinguish which operation will take place we simply need
        //to see whether the specific file associated with the borrower exists or notice

        char *Borrower_File = Customize_Name(Borrower);
        FILE *pBorrower_USER_file = fopen(Borrower_File, "r");


        if ( Borrow_Return == 'B' && pBorrower_USER_file != NULL) {
                //The file exists which means we should ADD the borrower to the database
                if (CHECK_IF_EXIST(Borrower,pSOURCE_Borrower_File) == 0) {
                        LOAN->Member_ID = linecount(pSOURCE_Borrower_File) + 1;

                        fprintf(pSOURCE_Borrower_File,"%d    Borrower Name: %s   |Last Date of Borrowing: %s\n",LOAN->Member_ID,Borrower,LOAN->Date);
                }
                fclose(pSOURCE_Borrower_File);
                pSOURCE_Borrower_File = NULL;
        }
        else if (Borrow_Return == 'R' && pBorrower_USER_file == NULL) {

                //TODO:CHECK Later
                //The file doesn't  exist we must delete the borrower line

                //If the file contains only one Borrower we should remove it directly
                if (linecount(pSOURCE_Borrower_File) == 1) {

                        fclose(pSOURCE_Borrower_File);
                        pSOURCE_Borrower_File = NULL;

                        remove(_BORROWERS_DATABASE_FILE);

                        //Otherwise we delete the specific film from the file
                }else {

                        FILE *pDest_Borrower_FILE   = fopen("Borrower_replica.txt", "w");

                        LOAN->Member_ID =  SEARCH_ID(Borrower,pSOURCE_Borrower_File);


                        DELETE_LINE(pSOURCE_Borrower_File,pDest_Borrower_FILE,LOAN->Member_ID);

                        fclose(pSOURCE_Borrower_File);
                        pSOURCE_Borrower_File = NULL;

                        //Removing the old files
                        remove(_BORROWERS_DATABASE_FILE);
                        fclose(pDest_Borrower_FILE);

                        rename("Borrower_replica.txt", _BORROWERS_DATABASE_FILE);
                }
        }

        fclose(pBorrower_USER_file);
        fclose(pSOURCE_Borrower_File);
        pSOURCE_Borrower_File = NULL;
}


//===================== Create The films file =========================================================

void FILM_Record(char Borrow_Return,Borrowing_Infos *LOAN,Film_Infos *FILM){


        FILE *pSOURCE_FILM_File = fopen(_BORROWED_FILM_FILE, "a+");
        nullcheck(pSOURCE_FILM_File,_BORROWED_FILM_FILE);
        rewind(pSOURCE_FILM_File);

        //The Borrowed films database will keep track of the borrowed films and the numbers of copies borrowed
        //It will deal with two cases :
        //1-Borrowing will increment the numbers of copies or append the film if it doesn't exist
        //2-Returning will decrement the copies numb and delete the film line if the copies are exhausted

        if (Borrow_Return == 'B') {
                //If the file does not exist already we must append it
                if (CHECK_IF_EXIST(FILM->Title,pSOURCE_FILM_File) == 0) {
                        LOAN->Borrowed_Numb = 1;
                        fprintf(pSOURCE_FILM_File,"Film title: %s   |Number of borrowed copies: %d   |Owned by: %s\n",FILM->Title,LOAN->Borrowed_Numb,FILM->Ownership);

                        fclose(pSOURCE_FILM_File);

                }else {
                        //We must update the number of borrowed copies
                        FILE *pDest_FILM_FILE   = fopen("FILM_replica.txt", "w");


                        Film_Infos test;
                        int count = 1;
                        int line = SEARCH_ID(FILM->Title,pSOURCE_FILM_File);
                        //printf("Line = %d \n", line);


                        while (fscanf(pSOURCE_FILM_File,"Film title: %s   |Number of borrowed copies: %d   |Owned by: %s\n",test.Title,&test.Copies_numb,test.Ownership) != EOF) {
                                //If the line corresponds to the actual position in the file we rewrite the data
                                if (count == line)
                                {
                                        fprintf(pDest_FILM_FILE, "Film title: %s   |Number of borrowed copies: %d   |Owned by: %s\n",test.Title,test.Copies_numb + 1,test.Ownership);
                                }
                                else
                                {
                                        fprintf(pDest_FILM_FILE, "Film title: %s   |Number of borrowed copies: %d   |Owned by: %s\n",test.Title,test.Copies_numb,test.Ownership);
                                }
                                count++;
                        }



                        fclose(pSOURCE_FILM_File);
                        remove(_BORROWED_FILM_FILE);

                        fclose(pDest_FILM_FILE);
                        rename("FILM_replica.txt",_BORROWED_FILM_FILE);
                }
        }else if (Borrow_Return == 'R') {

                //Retrieve the number of copies borrowed
                Film_Infos test;
                int line = SEARCH_ID(FILM->Title,pSOURCE_FILM_File);
                //printf("Line = %d \n", line);

                int count = 1;
                rewind(pSOURCE_FILM_File);

                while (fscanf(pSOURCE_FILM_File,"Film title: %s   |Number of borrowed copies: %d   |Owned by: %s\n",test.Title, &test.Copies_numb, test.Ownership) != EOF) {
                        //If the line corresponds to the actual position in the file we rewrite the data
                        if (count == line)
                        {
                                LOAN->Borrowed_Numb = test.Copies_numb;
                                break;
                        }
                        count++;

                }

                rewind(pSOURCE_FILM_File);

                //If the number of copies is of copies if bigger than 1 we should decrement it

                if (LOAN->Borrowed_Numb > 1) {

                        FILE *pDest_FILM_FILE   = fopen("FILM_replica.txt", "w");

                        int count = 1;

                        while (fscanf(pSOURCE_FILM_File,"Film title: %s   |Number of borrowed copies: %d   |Owned by: %s\n",test.Title,&test.Copies_numb,test.Ownership)  != EOF) {
                                //If the line corresponds to the actual position in the file we rewrite the data
                                if (count == line)
                                {
                                        fprintf(pDest_FILM_FILE, "Film title: %s   |Number of borrowed copies: %d   |Owned by: %s\n",test.Title,test.Copies_numb - 1,test.Ownership);

                                }
                                else
                                {
                                        fprintf(pDest_FILM_FILE, "Film title: %s   |Number of borrowed copies: %d   |Owned by: %s\n",test.Title,test.Copies_numb,test.Ownership);
                                }
                                count++;
                        }

                        fclose(pSOURCE_FILM_File);
                        remove(_BORROWED_FILM_FILE);

                        fclose(pDest_FILM_FILE);
                        rename("FILM_replica.txt",_BORROWED_FILM_FILE);

                }else {
                        //If all the films are returned
                        if (linecount(pSOURCE_FILM_File) == 1) {

                                fclose(pSOURCE_FILM_File);
                                remove(_BORROWED_FILM_FILE);
                        }else {
                                FILE *pDest_FILM_FILE   = fopen("FILM_replica.txt", "w");

                                DELETE_LINE(pSOURCE_FILM_File,pDest_FILM_FILE,line);

                                fclose(pSOURCE_FILM_File);
                                remove(_BORROWED_FILM_FILE);

                                fclose(pDest_FILM_FILE);
                                rename("FILM_replica.txt",_BORROWED_FILM_FILE);

                        }
                }


        }
}



#define SUPPORT_FUNCTIONS
#endif
