#ifndef FILELIB

#include "struct.h"
#include "randomize.h"
#include <string.h>




//############################ Basic FILE Handling ####################################################################################


//Count occurence of a Word in a file and returns 0 if the word does not exist

int CHECK_IF_EXIST(const char *word,FILE *fptr)
{
        char str[BUFFER_SIZE];
        char *pos;

        int index, count;

        count = 0;

        // Read line from file till end of file.
        while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
        {
                index = 0;

                // Find next occurrence of word in str
                while ((pos = strstr(str + index, word)) != NULL)
                {
                        // Index of word in str is
                        // Memory address of pos - memory
                        // address of str.
                        index = (pos - str) + 1;

                        count++;
                }
        }

        return count;
}



//This function search for the line of a specific word in a file It's very useful

int SEARCH_ID(const char *word,FILE *fptr)
{
        char str[BUFFER_SIZE];
        char *pos;

        int line = 0;
        int col = -1;

        rewind(fptr);

        while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
        {
                line += 1;

                // Find first occurrence of word in str
                pos = strstr(str, word);

                if (pos != NULL)
                {
                        // First index of word in str is
                        // Memory address of pos - memory
                        // address of str.
                        col = (pos - str);
                        break;
                }
        }


        // If word is not found then set line to 0
        if (col == -1)
                line = 0;

        rewind(fptr);

        return line;
}


//Counting lines in a file

int linecount(FILE *pfile)
{
        int count = 0;
        char c;

        rewind(pfile);
        while ((c = fgetc(pfile)) != EOF)
        {
                if (c == '\n')
                {
                        count++;
                }
        }
        rewind(pfile);
        return count;
}


// Check if the file pointer is valid

void nullcheck(FILE *pf, char *FILENAME)
{
        if (!pf)
        if (pf == NULL)
        {
                printf("Unable to open %s \n", FILENAME);
                printf("Please check whether the file exists or you have read/write privilege\n");
                exit(EXIT_FAILURE);
        }
        //printf("%s opened successfully\n \n", FILENAME);
}


//Function to read the file

void readfile(FILE *fp)
{
        char c;

        while ((c = fgetc(fp)) != EOF)
        {
                printf("%c", c);
        }
}

//Delete a specific line

void DELETE_LINE(FILE *srcFile, FILE *tempFile, const int line)
{
        char buffer[BUFFER_SIZE];
        int count = 1;
        rewind(srcFile);

        while ((fgets(buffer, BUFFER_SIZE, srcFile)) != NULL)
        {
                /* If current line is not the line user wanted to remove */
                if (line != count)
                        fputs(buffer, tempFile);

                count++;
        }
}





//Customize the filename for each user

char *Customize_Name(char *name)
{
        static char buffer[10];

        strcpy(buffer, name);
        strcat(buffer, "_Borrowed_FILMS.txt");

        return buffer;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//                              Member handling                                                    //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////



//############################ Member file handling  ###################################################################

//Changing a specific line in the file

//=========================== Changing/Deleting The Database FILE line =============================================================

void CHANGE_OR_DELETE_DATABASE_LINE(char Delete_Modify,Member_credentials *ADHERANT_CREDENTIALS,FILE *srcFile, FILE *tempFile, const int line)
{
        //A temporary buffer to hold the values
        Member_credentials test;

        int count = 1;

        if (Delete_Modify == 'D') {

                while ((fscanf(srcFile, "%d    Name: %s   Password: %c%s   Status: %s\n", &test.Member_ID, test.Member_Login,&test.Encryption_Key, test.Member_Password,test.Member_Status)) != EOF)
                {
                        //To delete we jump the line of the member
                        if (count < line)
                        {
                                fprintf(tempFile, "%d    Name: %s   Password: %c%s   Status: %s\n", test.Member_ID, test.Member_Login,test.Encryption_Key, test.Member_Password,test.Member_Status);
                        }
                        else if (count > line) {  // shift the ID number by 1

                                fprintf(tempFile, "%d    Name: %s   Password: %c%s   Status: %s\n", test.Member_ID - 1, test.Member_Login,test.Encryption_Key,test.Member_Password,test.Member_Status);
                        }
                        count++;
                }
        }else if (Delete_Modify == 'M') {

                while ((fscanf(srcFile, "%d    Name: %s   Password: %c%s   Status: %s\n", &test.Member_ID, test.Member_Login,&test.Encryption_Key, test.Member_Password,test.Member_Status)) != EOF)
                {
                        //If the line corresponds to the actual position in the file we rewrite the data
                        if (count == line)
                        {
                                fprintf(tempFile, "%d    Name: %s   Password: %c%s   Status: %s\n", test.Member_ID, ADHERANT_CREDENTIALS->Member_Login,ADHERANT_CREDENTIALS->Encryption_Key, ADHERANT_CREDENTIALS->Member_Password, test.Member_Status);
                        }
                        else
                        {
                                fprintf(tempFile, "%d    Name: %s   Password: %c%s   Status: %s\n",test.Member_ID, test.Member_Login,test.Encryption_Key, test.Member_Password,test.Member_Status);
                        }


                        count++;
                }

        }



}


//========================= Changing/Deleting The info file line ============================================================================================

void CHANGE_OR_DELETE_INFOS_LINE(char Delete_Modify,Member_infos *ADHERANT_INFOS,FILE *srcFile, FILE *tempFile, const int line)
{
        //A temporary buffer to hold the values
        Member_infos test;
        int ID_temp;
        int count = 1;

        if (Delete_Modify == 'D') {

                while ((fscanf(srcFile, "%d    FirstName: %s  |LastName: %s  |Adress: %s  |PhoneNumb: %s  |Category: %s\n", &ID_temp, test.Member_firstname, test.Member_lastname, test.Member_adress, test.Member_phonenumb, test.Member_category)) != EOF)
                {
                        //To delete we jump the line of the member
                        if (count < line)
                        {
                                fprintf(tempFile, "%d    FirstName: %s  |LastName: %s  |Adress: %s  |PhoneNumb: %s  |Category: %s\n", ID_temp, test.Member_firstname, test.Member_lastname, test.Member_adress, test.Member_phonenumb, test.Member_category);
                        }
                        else if (count > line) {  // shift the ID number by 1

                                fprintf(tempFile, "%d    FirstName: %s  |LastName: %s  |Adress: %s  |PhoneNumb: %s  |Category: %s\n", ID_temp - 1, test.Member_firstname, test.Member_lastname, test.Member_adress, test.Member_phonenumb, test.Member_category);
                        }
                        count++;
                }
        }else if (Delete_Modify == 'M') {

                while ((fscanf(srcFile, "%d    FirstName: %s  |LastName: %s  |Adress: %s  |PhoneNumb: %s  |Category: %s\n", &ID_temp, test.Member_firstname, test.Member_lastname, test.Member_adress, test.Member_phonenumb, test.Member_category)) != EOF)
                {
                        //If the line corresponds to the actual position in the file we rewrite the data
                        if (count == line)
                        {
                                fprintf(tempFile, "%d    FirstName: %s  |LastName: %s  |Adress: %s  |PhoneNumb: %s  |Category: %s\n", ID_temp, ADHERANT_INFOS->Member_firstname, ADHERANT_INFOS->Member_lastname, ADHERANT_INFOS->Member_adress, ADHERANT_INFOS->Member_phonenumb, ADHERANT_INFOS->Member_category);
                        }
                        else
                        {
                                fprintf(tempFile, "%d    FirstName: %s  |LastName: %s  |Adress: %s  |PhoneNumb: %s  |Category: %s\n", ID_temp, test.Member_firstname, test.Member_lastname, test.Member_adress, test.Member_phonenumb, test.Member_category);
                        }
                        count++;
                }
        }
}





/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//                              FILM Handling                                                      //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////






//############################ Film file handling  ###################################################################



//=====================Changing/Deleting The Film Database line =============================================================

void CHANGE_OR_DELETE_FILM_DATABASE_LINE(char Delete_Modify,Film_Infos *FILM,FILE *srcFile, FILE *tempFile, const int line){

        //A temporary buffer to hold the values
        Film_Infos test;
        int Film_ID;
        int count = 1;

        if (Delete_Modify == 'D') {

                while ((fscanf(srcFile, "%d    |Code: %s   |Title: %s   |Type: %s   |Available copies: %d   |Adaptation: %s   |Ownership: %s\n", &Film_ID, test.Code, test.Title,test.Type,&test.Copies_numb,test.Adaptation,test.Ownership)) != EOF)
                {
                        //To delete we jump the line of the member
                        if (count < line)
                        {
                                fprintf(tempFile, "%d    |Code: %s   |Title: %s   |Type: %s   |Available copies: %d   |Adaptation: %s   |Ownership: %s\n", Film_ID, test.Code, test.Title,test.Type,test.Copies_numb,test.Adaptation,test.Ownership);
                        }
                        else if (count > line) { // shift the ID number by 1

                                fprintf(tempFile, "%d    |Code: %s   |Title: %s   |Type: %s   |Available copies: %d   |Adaptation: %s   |Ownership: %s\n", Film_ID-1, test.Code, test.Title,test.Type,test.Copies_numb,test.Adaptation,test.Ownership);
                        }
                        count++;
                }
        }else if (Delete_Modify == 'M') {
                //Claiming ownership
                printf("Who The film belongs to ?:\n");
                fflush(stdin);
                fgets(FILM->Ownership, MAX_LOGIN, stdin);
                strtok(FILM->Ownership, "\n");

                while ((fscanf(srcFile, "%d    |Code: %s   |Title: %s   |Type: %s   |Available copies: %d   |Adaptation: %s   |Ownership: %s\n", &Film_ID, test.Code, test.Title,test.Type,&test.Copies_numb,test.Adaptation,test.Ownership)) != EOF)
                {
                        //If the line corresponds to the actual position in the file we rewrite the data
                        if (count == line)
                        {
                                fprintf(tempFile, "%d    |Code: %s   |Title: %s   |Type: %s   |Available copies: %d   |Adaptation: %s   |Ownership: %s\n", Film_ID,FILM->Code, FILM->Title,FILM->Type,FILM->Copies_numb,FILM->Adaptation,FILM->Ownership);
                        }
                        else
                        {
                                fprintf(tempFile, "%d    |Code: %s   |Title: %s   |Type: %s   |Available copies: %d   |Adaptation: %s   |Ownership: %s\n", Film_ID, test.Code, test.Title,test.Type,test.Copies_numb,test.Adaptation,test.Ownership);
                        }
                        count++;
                }

        }
}



/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//                              Loan handling                                                      //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////



//############################ Loan file handling  ###################################################################


//===================== Changing the copies numb in Film Database  =============================================================

int CHANGE_COPIES_NUMB_LINE(char Borrow_Return,Member_infos *ADHERANT_INFOS,Borrowing_Infos *LOAN,Film_Infos *FILM,FILE *srcFile, FILE *tempFile, const int line){

        //A temporary buffer to hold the values
        Film_Infos test;
        int Film_ID;
        int REMAINING_COPIES;
        int count = 1;

        rewind(srcFile);
        //Before Updating the line we must Check if Is there any Available copies
        while (fscanf(srcFile,"%d    |Code: %s   |Title: %s   |Type: %s   |Available copies: %d   |Adaptation: %s   |Ownership: %s\n",&Film_ID, test.Code, test.Title,test.Type,&test.Copies_numb,test.Adaptation,test.Ownership)) {
                //If the line corresponds to the actual position in the file we rewrite the data
                if (count == line)
                {
                        //We check if the memeber has the correct category for the film
                        if (strcmp(test.Adaptation,"ALL") == 0) {

                                LOAN->Borrowed_Numb = test.Copies_numb;
                                break;
                        }else if (strcmp(ADHERANT_INFOS->Member_category,test.Adaptation) != 0 ) {

                                return -2;
                        }else  {

                                LOAN->Borrowed_Numb = test.Copies_numb;
                                break;
                        }

                }
                count++;

        }
        rewind(srcFile);

        count = 1;

        if (LOAN->Borrowed_Numb > 0) {

                while ((fscanf(srcFile, "%d    |Code: %s   |Title: %s   |Type: %s   |Available copies: %d   |Adaptation: %s   |Ownership: %s\n", &Film_ID, test.Code, test.Title,test.Type, &test.Copies_numb,test.Adaptation,test.Ownership)) != EOF)
                {
                        //If the line corresponds to the actual position in the file we rewrite the data
                        if (count == line)
                        {
                                //The user might borrow or return the film
                                if (Borrow_Return == 'B')
                                {
                                        //We need to preserve The owner & the film
                                        strcpy(FILM->Ownership,test.Ownership);
                                        strcpy(FILM->Title,test.Title);
                                        //Storing Valuable infos for the customizable files
                                        strcpy(LOAN->Film_Code,test.Code);
                                        strcpy(LOAN->Date, Current_Date());


                                        REMAINING_COPIES = test.Copies_numb - 1;

                                        fprintf(tempFile, "%d    |Code: %s   |Title: %s   |Type: %s   |Available copies: %d   |Adaptation: %s   |Ownership: %s\n", Film_ID,test.Code, test.Title,test.Type,REMAINING_COPIES,test.Adaptation,test.Ownership);
                                }else if (Borrow_Return == 'R')
                                {
                                        strcpy(FILM->Title,test.Title);

                                        //Increasing the remaining copies
                                        REMAINING_COPIES = test.Copies_numb + 1;
                                        fprintf(tempFile, "%d    |Code: %s   |Title: %s   |Type: %s   |Available copies: %d   |Adaptation: %s   |Ownership: %s\n", Film_ID,test.Code, test.Title,test.Type,REMAINING_COPIES,test.Adaptation,test.Ownership);
                                }

                        }
                        else
                        {
                                fprintf(tempFile, "%d    |Code: %s   |Title: %s   |Type: %s   |Available copies: %d   |Adaptation: %s   |Ownership: %s\n", Film_ID, test.Code, test.Title,test.Type,test.Copies_numb,test.Adaptation,test.Ownership);
                        }
                        count++;
                }

                return REMAINING_COPIES;
        }else {

                return -1;
        }


}







#define FILELIB
#endif
