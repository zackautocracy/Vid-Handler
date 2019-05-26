#ifndef RANDOMIZE_H
#include <time.h>

//======================= Random Module =========================================================================

int  myRand(int  low, int  high)
{
   srand(time(NULL));
   return rand() % (high - low + 1) + low;;
}


void key()
{
   printf("\nPress any key to continue...");
   fflush(stdin);
   getchar();
   fflush(stdin);
   system("cls");
}


void delay(int sec_numb)
{
   // Converting time into milli_seconds
   int milisec_numb = 1000 * sec_numb;

   // Storing start time
   clock_t start_time = clock();

   // looping till required time is not acheived
   while (clock() < start_time + milisec_numb)
   {
   }
}



char *Current_Date()
{
        time_t t;

        struct tm   *tmp;
        static char MY_TIME[MAX_DATE_SIZE];

        time(&t);

//localtime() uses the time pointed by t ,
// to fill a tm structure with the
// values that represent the
// corresponding local time.

        tmp = localtime(&t);

// using strftime to display time
        strftime(MY_TIME, sizeof(MY_TIME), "%x", tmp);
        return MY_TIME;
}


#define RANDOMIZE_H
#endif
