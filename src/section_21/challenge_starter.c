#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game()
{

   printf("\nFinal score: %d\n", score);
   exit(0);
}

void error(char *msg)
{
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
}

void handle_alarm()
{
   printf("\nTime's up!.\n");
   raise(SIGINT);
}

void handle_sigint()
{
   printf("\nExiting ...");
   printf("\nFinal score: %d\n", score);
   exit(0);
}

int main()
{
   // Register the signal handler for SIGINT
   if (signal(SIGINT, handle_sigint) == SIG_ERR)
   {
      return EXIT_SUCCESS;
   }

   signal(SIGALRM, handle_alarm);
   srand(time(0));

   while (1)
   {
      int a = rand() % 11;
      int b = rand() % 11;

      char txt[4];

      printf("\nWhat is %d times %d: ", a, b);
      alarm(5);
      fgets(txt, 4, stdin);

      int answer = atoi(txt);

      if (answer == a * b)
      {
         score++;
         printf("Correct! Score at %d\n", score);
      }
      else
         printf("\nWrong! Score: %d\n", score);
   }

   return 0;
}
