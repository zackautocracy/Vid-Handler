#ifndef FILM_FUNCTIONS


#include <string.h>
#include <stdlib.h>
#include "filelib.h"
#include "struct.h"
#include "constant.h"
#include "Support_Functions.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//                              FILM Handling                                                      //
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////

//This assignment marks The owner of the film


//############################ New FILM ###################################################################

//Used functions :
void Film_Infos_Input(Film_Infos *FILM,FILE *pFILM_DATABASE);

void Add_Film(Film_Infos *FILM,char *Owner){

        FILE *pFILM_DATABASE = NULL;
        //Opening the file
        pFILM_DATABASE = fopen(_FILM_DATABASE_FILE, "a+");
        nullcheck(pFILM_DATABASE, _FILM_DATABASE_FILE);

        Film_Infos_Input(FILM,pFILM_DATABASE);

        //Appending New Film Infos to the file
        int Film_ID = linecount(pFILM_DATABASE) + 1;


        fprintf(pFILM_DATABASE, "%d    |Code: %s   |Title: %s   |Type: %s   |Available copies: %d   |Adaptation: %s   |Ownership: %s\n", Film_ID,FILM->Code, FILM->Title,FILM->Type,FILM->Copies_numb,FILM->Adaptation,Owner);

        fclose(pFILM_DATABASE);
        pFILM_DATABASE = NULL;
}




//############################ Modify & Delete  FILM #######################################################################

//Used functions :
int SEARCH_ID(const char *word,FILE *fptr);

void Film_Infos_Input(Film_Infos *FILM,FILE *pFILM_DATABASE);
void CHANGE_OR_DELETE_FILM_DATABASE_LINE(char Delete_Modify,Film_Infos *FILM,FILE *srcFile, FILE *tempFile, const int line);


void Modify_Or_Delete_Film(char Delete_Modify,Film_Infos *FILM)
{

        FILE *pSOURCE_FILM_DATABASE = NULL;


        pSOURCE_FILM_DATABASE = fopen(_FILM_DATABASE_FILE, "r");
        nullcheck(pSOURCE_FILM_DATABASE, _FILM_DATABASE_FILE);

        rewind(pSOURCE_FILM_DATABASE);

        //Opening the files to update the Films's infos
        //The approach we took to create a replica where to transfer the updated data and then renaming it
        //We know it's not efficient in large databases ,in that case we would use a language more adapted to the task as "SQL"
        FILE *pDest_FILM_DATABASE   = fopen("DATABASE_replica.txt", "w");


        int Film_ID;
        char Film_Buffer[MAX_FILM_TITLE];
        do {
                printf("Enter the Title of the Film u want to Modify/Delete the info for (Must exist !):\n");
                printf("Warning !: (Use Underscores rather than Whitespace)\n\n");
                gets(Film_Buffer);
        } while((Film_ID = SEARCH_ID(Film_Buffer,pSOURCE_FILM_DATABASE)) == 0);
        //The user will keep looping until he provides a Film that exists in the database


        //D : DELETE & M : MODIFY
        if (Delete_Modify == 'D') {

                CHANGE_OR_DELETE_FILM_DATABASE_LINE('D',FILM,pSOURCE_FILM_DATABASE,pDest_FILM_DATABASE,Film_ID);

        }else if(Delete_Modify == 'M') {

                Film_Infos_Input(FILM,pSOURCE_FILM_DATABASE);
                CHANGE_OR_DELETE_FILM_DATABASE_LINE('M',FILM,pSOURCE_FILM_DATABASE,pDest_FILM_DATABASE, Film_ID);
        }


        fclose(pSOURCE_FILM_DATABASE);
        pSOURCE_FILM_DATABASE = NULL;

        //Removing the old files
        remove(_FILM_DATABASE_FILE);
        fclose(pDest_FILM_DATABASE);

        rename("DATABASE_replica.txt", _FILM_DATABASE_FILE);
}


//############################ Display Films by type #######################################################################

//Function used :
void Display_Specific_Type_Film(Film_Infos *FILM,FILE *pFILE_DATABASE,char *Film_Type);

void Display_Film_By_Type(Film_Infos *FILM){


        FILE *pFILM_DATABASE = NULL;
        //Opening the file
        pFILM_DATABASE = fopen(_FILM_DATABASE_FILE, "r");
        nullcheck(pFILM_DATABASE, _FILM_DATABASE_FILE);

        printf("\n\n#####################################  Documentary Films #####################################################\n\n\n\n");
        Display_Specific_Type_Film(FILM,pFILM_DATABASE,"D");

        printf("##########################################  Western Films ####################################################\n\n\n\n");
        Display_Specific_Type_Film(FILM,pFILM_DATABASE,"W");

        printf("######################################### Science Fiction Films ##############################################\n\n\n\n");
        Display_Specific_Type_Film(FILM,pFILM_DATABASE,"S");

        printf("#########################################  Crime Films #######################################################\n\n\n\n");
        Display_Specific_Type_Film(FILM,pFILM_DATABASE,"C");

        printf("############################################  Anime  #########################################################\n\n\n\n");
        Display_Specific_Type_Film(FILM,pFILM_DATABASE,"AN");

        fclose(pFILM_DATABASE);
        pFILM_DATABASE = NULL;

}







#define FILM_FUNCTIONS
#endif
