#include <stdio.h>
#include <stdlib.h>
#include "Body_Switch.h"



//Declaring the structures to hold Members infos
Member_infos       ADHERANT_INFOS;
Member_credentials ADHERANT_CREDENTIALS;

//Declaring the structure to store Film infos
Film_Infos FILM;

//Declaring the structure to store the Borrowing Infos
Borrowing_Infos LOAN = { .Borrowed_Numb = 0 };


//TODO:Random selection of FILMs/Top 10/By type
//TODO:Rebuild the program
//BUG:If the admin changes the infos of a member (privilege escalation).

int main()
{
   while (1)
   {
      MAIN_Switch(&LOAN, &FILM, &ADHERANT_CREDENTIALS, &ADHERANT_INFOS);
   }
   return 0;
}
