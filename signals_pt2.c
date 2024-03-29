/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

bool done = false;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  done = true;
  
}

int main(int argc, char * argv[])
{
  while (true) {
    signal(SIGALRM,handler); //register handler to handle SIGALRM
    alarm(1); //Schedule a SIGALRM for 1 second
    while(!done); //busy wait for signal to be delivered
    printf("Turing was right!\n");
    done = false;
  }
  return 0; //never reached
}
