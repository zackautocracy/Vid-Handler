#ifndef RANDOMIZE_H
#include <time.h>
#include <windows.h>

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


void time_delay(int sec_numb)
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



char* Current_Date()
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


void print_Date()
{
   time_t    t;
   struct tm *tmp;
   char      MY_TIME[BUFFER_SIZE];

   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

   time(&t);

   //localtime() uses the time pointed by t ,
   // to fill a tm structure with the
   // values that represent the
   // corresponding local time.

   tmp = localtime(&t);

   // using strftime to display time
   strftime(MY_TIME, sizeof(MY_TIME), "%A %B %dth ", tmp);

    SetConsoleTextAttribute(hStdOut, 10);
    printf("\n\n%s",MY_TIME);
    SetConsoleTextAttribute(hStdOut, 15);

}


void DoProgress(char label[], int step, int total)
{
   //progress width
   const int pwidth = 72;

   //minus label len
   int width = pwidth - strlen(label);
   int pos   = (step * width) / total;


   int percent = (step * 100) / total;

   //set green text color, only on Windows
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
   printf("%s[", label);

   //fill progress bar with =
   for (int i = 0; i < pos; i++)
   {
      printf("%c", '#');
   }

   //fill progress bar with spaces
   printf("% *c", width - pos + 1, ']');
   printf(" %3d%%\r", percent);

   //reset text color, only on Windows
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);
}


void DoSome()
{
   int total = 500;
   int step  = 0;

   printf("\n");
   while (step < total)
   {
      //do some action
      time_delay(0.10);

      step += 1;

      DoProgress("Loading: ", step, total);
   }

   printf("\n");
}


#define RANDOMIZE_H
#endif
