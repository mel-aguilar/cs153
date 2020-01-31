#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void
cat(int fd)
{
  int n;

  while((n = read(fd, buf, sizeof(buf))) > 0) {
    if (write(1, buf, n) != n) {
      printf(1, "cat: write error\n");
      exit(0);	//exit with error because error is specified in line above  
    }
  }
  if(n < 0){
    printf(1, "cat: read error\n");
    exit(0);	//exit with error because error is specified in line above  
  }
}

int
main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1){
    cat(0);
    exit(0);	//exit with no error, no error specified
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      printf(1, "cat: cannot open %s\n", argv[i]);
      exit(0);	//exit with error because error is specified in line above
    }
    cat(fd);
    close(fd);
  }
  exit(0);	//closes with no error here because no error is reached here
}
