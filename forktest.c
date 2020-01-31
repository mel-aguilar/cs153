// Test that fork fails gracefully.
// Tiny executable so that the limit can be filling the proc table.

#include "types.h"
#include "stat.h"
#include "user.h"

#define N  1000

void
printf(int fd, const char *s, ...)
{
  write(fd, s, strlen(s));
}

void
forktest(void)
{
  int n, pid;

  printf(1, "fork test\n");

  for(n=0; n<N; n++){
    pid = fork();
    if(pid < 0)
      break;
    if(pid == 0)
      exit(0); 	///because pid corresponds to a child and i think you want to exit the child process normally
  }

  if(n == N){
    printf(1, "fork claimed to work N times!\n", N);
    exit(0);	//because this file chicks to see if fork "fails gracefully" and we dont really use anything in this file, then we could just exit normally after displaying comments
  }

  for(; n > 0; n--){
    if(wait(0) < 0){
      printf(1, "wait stopped early\n");
      exit(0);
    }
  }

  if(wait(0) != -1){
    printf(1, "wait got too many\n");
    exit(0);
  }

  printf(1, "fork test OK\n");
}

int
main(void)
{
  forktest();
  exit(0);
}
