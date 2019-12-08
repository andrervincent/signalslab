bool done = false;
int seconds = 0;

void alarmHandler(int signum)
{ 
  done = true;
}

void endHandler(int signum){
  printf("Program execution took %d seconds\n", seconds);
  exit(1);
}
int main(int argc, char * argv[])
{
  signal(SIGINT,endHandler);
  while (true) {
    signal(SIGALRM,alarmHandler); //register handler to handle SIGALRM
    alarm(1); //Schedule a SIGALRM for 1 second
    while(!done); //busy wait for signal to be delivered
    seconds++;
    done = false;
  }
  return 0; //never reached
}
