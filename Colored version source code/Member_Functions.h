#ifndef MEMBER_FUNCTIONS

#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "filelib.h"
#include "struct.h"
#include "constant.h"
#include "Support_Functions.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//                              Member handling                                                    //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////




//############################ New Member ###################################################################




//functions used :
void Infos_Input(Member_infos *ADHERANT_INFOS);
void Credentials_Input(Member_credentials *ADHERANT_CREDENTIALS,FILE* pFILE_DATABASE);
int Encrypt_Password(char *password);

int Add_Member(Member_credentials *ADHERANT_CREDENTIALS,Member_infos *ADHERANT_INFOS)
{
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        /*Signin up operation :
         * We chose to to extend the hierarchy of the club so we devided the user into 2 major Status
         * - Admins & Normal Users*/

        int IS_ADMIN;

        Member_credentials Temp;

        SetConsoleTextAttribute(hStdOut, 10);
        printf("Are you a new Admin for the club (y/n)?\n");
        char c = getchar();
        SetConsoleTextAttribute(hStdOut, 15);
        fflush(stdin);
        IS_ADMIN = (c == 'y') ? 1 : 0;

        //For storing members infos we chose to seperate the infos into 2 files for more content clarity
        // 1- The database that will hold Login/ID/Passwords
        // 2-The infos that will store adress/phonenumber ....

        FILE *pFILE_DATABASE = NULL;
        FILE *pFILE_INFOS    = NULL;

        pFILE_DATABASE = fopen(_MEMBER_DATABASE_FILE, "a+");
        pFILE_INFOS    = fopen(_MEMBER_INFOS_FILE, "a+");

        nullcheck(pFILE_DATABASE, _MEMBER_DATABASE_FILE);
        nullcheck(pFILE_INFOS, _MEMBER_INFOS_FILE);

//======================= Storing credentials ===============================



        Credentials_Input(&Temp,pFILE_DATABASE);



        //Must retrieve the ID number(file position)
        Temp.Member_ID = linecount(pFILE_DATABASE) + 1;

        //Assigning the Status
        if (IS_ADMIN == 1)
        {
                strcpy(Temp.Member_Status, "ADMIN");
        }
        else
        {
                strcpy(Temp.Member_Status, "ADHERANT");
        }



//======================= Storing Infos  =================================



        //After inputting the password it get's directly encrypted and then written into the database
        //This is how we chose to implement the concept of encryption :
        //1-A random random Which will be our "Encryption_Key "is generated every time the user try to input his/her Password
        //2-An Encryption function will take the password and browse through it's characters and add the random numbs to it's ASCIII value
        //3-Now that our string "Password is Encrypted" We must to store it somewhere as it will be unique because it's randomly generated
        //The most obfuscated solution we could think of is as follows :
        //We will write the Encryption key as a character in the file right in the beginning of our password ,It will be hard to notice it


        Infos_Input(ADHERANT_INFOS);

        //Appending Infos/credentials to the file
        //                              Here is the trick mentioned above
        fprintf(pFILE_DATABASE, "%d    Name: %s   Password: %c%s   Status: %s\n", Temp.Member_ID, Temp.Member_Login,Temp.Encryption_Key, Temp.Member_Password, Temp.Member_Status);

        fprintf(pFILE_INFOS, "%d    FirstName: %s  |LastName: %s  |Adress: %s  |PhoneNumb: %s  |Category: %s\n", Temp.Member_ID, ADHERANT_INFOS->Member_firstname, ADHERANT_INFOS->Member_lastname, ADHERANT_INFOS->Member_adress, ADHERANT_INFOS->Member_phonenumb, ADHERANT_INFOS->Member_category);

        fclose(pFILE_DATABASE);
        fclose(pFILE_INFOS);
        pFILE_DATABASE = NULL;
        pFILE_INFOS    = NULL;

        //The return must inform us about the admin privilege
        return IS_ADMIN;
}






//############################ Sign-in Operation #######################################################################


//Functions used :
void HIDE_PASSWORD(char *password);
void Decrypt_Password(char *password,int Encryption_Key);

int Sign_In_Member(Member_credentials *ADHERANT_CREDENTIALS,Member_infos *ADHERANT_INFOS)
{
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        Member_credentials test;
        Member_infos test_infos;
        int Temp_ID;
        int flag = 0;


        //Opening the file
        FILE *pFILE_DATABASE = NULL;
        FILE *pFILE_INFOS = NULL;

        pFILE_DATABASE = fopen(_MEMBER_DATABASE_FILE, "r");
        pFILE_INFOS = fopen(_MEMBER_INFOS_FILE,"r");
        nullcheck(pFILE_DATABASE, _MEMBER_DATABASE_FILE);
        nullcheck(pFILE_INFOS,_MEMBER_INFOS_FILE);

        //Log in credentials
        printf("Enter your Login :\n");
        SetConsoleTextAttribute(hStdOut, 10);
        gets(ADHERANT_CREDENTIALS->Member_Login);
        SetConsoleTextAttribute(hStdOut, 15);
        printf("Enter your password :\n");
        SetConsoleTextAttribute(hStdOut, 10);
        HIDE_PASSWORD(ADHERANT_CREDENTIALS->Member_Password);



        //Checking credentials
        while ((fscanf(pFILE_DATABASE, "%d    Name: %s   Password: %c%s   Status: %s\n",&test.Member_ID, test.Member_Login,&test.Encryption_Key,test.Member_Password, test.Member_Status)) != EOF && (fscanf(pFILE_INFOS, "%d    FirstName: %s  |LastName: %s  |Adress: %s  |PhoneNumb: %s  |Category: %s\n", &Temp_ID, test_infos.Member_firstname, test_infos.Member_lastname, test_infos.Member_adress, test_infos.Member_phonenumb, test_infos.Member_category)) != EOF )
        {
                //Each iteration we decrypt the stored password and compare it with the original input
                Decrypt_Password(test.Member_Password,test.Encryption_Key);

                if ((strcmp(ADHERANT_CREDENTIALS->Member_Login, test.Member_Login) == 0) && (strcmp(ADHERANT_CREDENTIALS->Member_Password, test.Member_Password) == 0))
                {
                        //Storing the Member ID & Status in Runtime memory because it hold the reference of the member from which we can make any changes
                        ADHERANT_CREDENTIALS->Member_ID = test.Member_ID;
                        strcpy(ADHERANT_CREDENTIALS->Member_Status,test.Member_Status);
                        strcpy(ADHERANT_INFOS->Member_category,test_infos.Member_category);

                        flag     = 1;
                        break;
                }
        }


        fclose(pFILE_DATABASE);
        fclose(pFILE_INFOS);
        pFILE_DATABASE = NULL;
        pFILE_INFOS = NULL;

        return flag;
}






//############################ Modify & Delete  Member #######################################################################





//Used functions :
int SEARCH_ID(const char *word,FILE *fptr);
//Modify/DELETE the member
void Credentials_Input(Member_credentials *ADHERANT_CREDENTIALS,FILE* pFILE_DATABASE);
void CHANGE_OR_DELETE_DATABASE_LINE(char Delete_Modify,Member_credentials *ADHERANT_CREDENTIALS,FILE *srcFile, FILE *tempFile, const int line);
void Infos_Input(Member_infos *ADHERANT_INFOS);
void CHANGE_OR_DELETE_INFOS_LINE(char Delete_Modify,Member_infos *ADHERANT_INFOS,FILE *srcFile, FILE *tempFile, const int line);


int  Modify_Or_Delete_Member(char Delete_Modify,Member_credentials *ADHERANT_CREDENTIALS,Member_infos *ADHERANT_INFOS)
{

        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

        FILE *pSOURCE_DATABASE = NULL;
        FILE *pSOURCE_INFOS    = NULL;

        //This variable will help us to find out if the ADMIN tried to delete his own account or not
        //It's necessary to choose whether the ADMIN will be redirected to the login page or not
        int IS_ADMIN = 0;


        pSOURCE_DATABASE = fopen(_MEMBER_DATABASE_FILE, "r");
        pSOURCE_INFOS    = fopen(_MEMBER_INFOS_FILE, "r");
        nullcheck(pSOURCE_DATABASE, _MEMBER_DATABASE_FILE);
        nullcheck(pSOURCE_INFOS, _MEMBER_INFOS_FILE);
        rewind(pSOURCE_DATABASE);
        rewind(pSOURCE_INFOS );
        //Opening the files to update the member's infos
        //The approach we took to create a replica where to transfer the updated data and then renaming it
        //We know it's not efficient in large databases ,in that case we would use a language more adapted to the task as "SQL"
        FILE *pDest_DATABASE   = fopen("DATABASE_replica.txt", "w");
        FILE *pDest_INFOS   = fopen("INFOS_replica.txt", "w");



        //If The member is an admin he can change/delete any user's info
        if (strcmp(ADHERANT_CREDENTIALS->Member_Status,"ADMIN") == 0)
        {
                int Login_ID = 0;
                char Login_Buffer[MAX_LOGIN];
                do {
                        printf("Enter the Login of the user u want to Modify/Delete the info for (Must exist):\n");
                        SetConsoleTextAttribute(hStdOut, 10);
                        gets(Login_Buffer);
                        SetConsoleTextAttribute(hStdOut, 15);
                } while((Login_ID = SEARCH_ID(Login_Buffer,pSOURCE_DATABASE)) == 0);
                //The admin will keep looping until he provides a valid Login

                printf("Login ID = %d \n",Login_ID);


                //D : DELETE & M : MODIFY
                if (Delete_Modify == 'D') {

                        if (strcmp(Login_Buffer,ADHERANT_CREDENTIALS->Member_Login) == 0) {
                                IS_ADMIN = 1;
                        }

                        CHANGE_OR_DELETE_DATABASE_LINE('D',ADHERANT_CREDENTIALS,pSOURCE_DATABASE,pDest_DATABASE, Login_ID);
                        CHANGE_OR_DELETE_INFOS_LINE('D',ADHERANT_INFOS,pSOURCE_INFOS,pDest_INFOS,Login_ID);

                }else if(Delete_Modify == 'M') {

                        //We created a temp structure holder to not overwrite my initial ADMIN Infos

                        Member_credentials Temp;

                        Credentials_Input(&Temp,pSOURCE_DATABASE);



                        Infos_Input(ADHERANT_INFOS);
                        CHANGE_OR_DELETE_DATABASE_LINE('M',&Temp,pSOURCE_DATABASE,pDest_DATABASE, Login_ID);
                        CHANGE_OR_DELETE_INFOS_LINE('M',ADHERANT_INFOS,pSOURCE_INFOS,pDest_INFOS,Login_ID);
                }
        }else {  //the adherant can only change his infos
                if (Delete_Modify == 'D') {

                        CHANGE_OR_DELETE_DATABASE_LINE('D',ADHERANT_CREDENTIALS,pSOURCE_DATABASE,pDest_DATABASE,ADHERANT_CREDENTIALS->Member_ID);
                        CHANGE_OR_DELETE_INFOS_LINE('D',ADHERANT_INFOS,pSOURCE_INFOS,pDest_INFOS,ADHERANT_CREDENTIALS->Member_ID);

                }else if(Delete_Modify == 'M') {



                        Credentials_Input(ADHERANT_CREDENTIALS,pSOURCE_DATABASE);




                        Infos_Input(ADHERANT_INFOS);
                        CHANGE_OR_DELETE_DATABASE_LINE('M',ADHERANT_CREDENTIALS,pSOURCE_DATABASE,pDest_DATABASE,ADHERANT_CREDENTIALS->Member_ID);
                        CHANGE_OR_DELETE_INFOS_LINE('M',ADHERANT_INFOS,pSOURCE_INFOS,pDest_INFOS,ADHERANT_CREDENTIALS->Member_ID);
                }
        }


        fclose(pSOURCE_DATABASE);
        fclose(pSOURCE_INFOS);
        pSOURCE_DATABASE = NULL;
        pSOURCE_INFOS = NULL;
        //Removing the old files
        remove(_MEMBER_DATABASE_FILE);
        remove(_MEMBER_INFOS_FILE);

        fclose(pDest_DATABASE);
        fclose(pDest_INFOS);

        rename("DATABASE_replica.txt", _MEMBER_DATABASE_FILE);
        rename("INFOS_replica.txt", _MEMBER_INFOS_FILE);


        return IS_ADMIN;

}



//############################ TODO: Display Single Member  #######################################################################



//############################ Display Members in Alphabetic order #######################################################################




void Member_Alpha_Display(){


        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        FILE *pFILE_DATABASE = fopen(_MEMBER_DATABASE_FILE, "r");
        nullcheck(pFILE_DATABASE, _MEMBER_DATABASE_FILE);
        rewind(pFILE_DATABASE);



        int Member_Number = linecount(pFILE_DATABASE);

        //We chose to make a dynamic structure array as a way to avoid any Stack overflows
        Member_credentials *test = (Member_credentials *)malloc(Member_Number * sizeof(Member_credentials));
        if (!test) {
                printf("Couldn't allocate memory\n");
                exit(EXIT_FAILURE);
        }

        int i = 0;
        while ((fscanf(pFILE_DATABASE, "%d    Name: %s   Password: %s   Status: %s\n",&test[i].Member_ID, test[i].Member_Login,test[i].Member_Password,test[i].Member_Status)) != EOF)
        {
                i++;
        }

        //Now the test buffer hold all the Members -> we just have to sort the array now
        for (int j = 0; j < Member_Number; j++) {
                for (int k = j + 1; k < Member_Number; k++) {
                        if (strcmp(test[j].Member_Login, test[k].Member_Login) > 0)
                        {
                                //swap
                                char temp[MAX_LOGIN];
                                //Swap logins names
                                strcpy(temp, test[j].Member_Login);
                                strcpy(test[j].Member_Login, test[k].Member_Login);
                                strcpy(test[k].Member_Login, temp);
                                //swap Status for each members
                                strcpy(temp, test[j].Member_Status);
                                strcpy(test[j].Member_Status, test[k].Member_Status);
                                strcpy(test[k].Member_Status, temp);

                        }
                }
        }

        //Now we can display the Members in alphabetic order

        for (int i = 0; i < Member_Number; i++) {
                SetConsoleTextAttribute(hStdOut, 6);
                printf("\n\n\t \t############################ Member ");
                SetConsoleTextAttribute(hStdOut, 12);
                printf("%d ",i+1);
                SetConsoleTextAttribute(hStdOut, 6);
                printf("######################################\n\n");
                SetConsoleTextAttribute(hStdOut, 15);
                printf("\t\t\tMember Login : ");
                SetConsoleTextAttribute(hStdOut, 12);
                printf("%s     ",test[i].Member_Login);
                SetConsoleTextAttribute(hStdOut, 15);
                printf("| Status : ");
                SetConsoleTextAttribute(hStdOut, 10);
                printf("%s \n",test[i].Member_Status);
                SetConsoleTextAttribute(hStdOut, 15);

        }

        fclose(pFILE_DATABASE);
        pFILE_DATABASE = NULL;
        free(test);
        test = NULL;

}





#define MEMBER_FUNCTIONS
#endif
