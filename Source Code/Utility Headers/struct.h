#ifndef STRUCT_H_INCLUDED


#include "constant.h"


//################################# Structures #####################################################################################


//======================= Structure for Members ===================================================================


//Member infos
typedef struct Member_infos
{
        char Member_firstname[MAX_INFO_INPUT];
        char Member_lastname[MAX_INFO_INPUT];
        char Member_adress[MAX_INFO_INPUT];
        char Member_phonenumb[MAX_INFO_INPUT];
        char Member_category[MAX_CATEGORIE_TYPES];

} Member_infos;


//Member credentials
typedef struct Member_credentials
{
        int Member_ID;
        char Member_Login[MAX_LOGIN];
        char Member_Password[MAX_PASSWORD];
        int Encryption_Key;
        char Member_Status[MAX_INFO_INPUT]; //Admin or Normal adherant

} Member_credentials;




//============================ Structure for films ===========================================================
typedef struct Film_Infos
{
        char Code[MAX_FILM_CODE];
        char Title[MAX_FILM_TITLE];
        int Copies_numb;
        char Type[MAX_CATEGORIE_TYPES];
        char Adaptation[MAX_CATEGORIE_TYPES];
        char Ownership[MAX_LOGIN]; //It indicates who the film belongs to

} Film_Infos;


//============================ Structure for Loans =============================================================

typedef struct Borrowing_Infos
{
   int Member_ID;
   char Film_Code[MAX_FILM_CODE];
   char Date[MAX_DATE_SIZE];
   int Borrowed_Numb; //It marks the number of copies borrowed by any Member


} Borrowing_Infos ;









//########################################## Enums for switch ####################################################################

//Login  Menu

enum {
  SIGN_IN = 1,SIGN_UP,LOGIN_EXIT
};


// Adherant Menu

enum {
  MY_ACCOUNT = 1,ADD_FILM_ADHERANT,MANAGE_BORROWINGS,LOG_OUT_ADHERANT,ADHERANT_EXIT
};

enum {
  MODIFY_INFOS = 1,DELETE_ACCOUNT,BACK_ACCOUNT
};

enum {
  BROWSE_FILMS = 1,MY_FILMS,BORROW_FILM ,RETURN_FILM,BACK_BORROWING
};


// ADMIN Menu


enum {
  MANAGE_ACCOUNTS = 1,MANAGE_FILMS,MANAGE_BORROWINGs,LOG_OUT_ADMIN,ADMIN_EXIT
};

enum {
  ADD_MEMBER = 1,MODIFY_MEMBER,ADHERENT_LIST,DELETE_ACCOUNT_ADMIN,BACK_ACCOUNT_ADMIN
};

enum {
  ADD_FILMS = 1,MODIFY_FILMS,DELETE_FILMS ,FILMS_LIST,BACK_FILMS
};

enum {
  BROWSE_FILMS_ADMIN = 1,MY_FILMS_ADMIN,BORROW_FILM_ADMIN ,RETURN_FILM_ADMIN,BORROWED_FILMS_LIST,BORROWERS_LIST,SPECIFIC_MEMBER_FILMS,BACK_BORROWING_ADMIN
};





#define STRUCT_H_INCLUDED
#endif
