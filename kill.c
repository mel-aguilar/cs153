#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  int i;

  if(argc < 2){
    printf(2, "usage: kill pid...\n");
    exit(0);	//because kill terminates a process, so we want to make sure that upon exiting kill will do its job
  }
  for(i=1; i<argc; i++)
    kill(atoi(argv[i]));
  exit(0);
}
