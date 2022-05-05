/* 
Dummy program definition, creates a number of child process
as mentioned by the user and consumes CPU time for testing
our system calls and scheduling.
*/

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char * argv[]) {
  int pid;
  int k, n;
  unsigned long int x, z;

  if (argc < 2)
    n = 1; //Default
  else
    n = atoi(argv[1]);
  if (n < 0 || n > 20)
    n = 2;
  x = 0;
  pid = 0;

  for (k = 0; k < n; k++) {
    pid = fork();
    if (pid < 0) {
      printf(1, "%d failed in fork!\n", getpid());
    } else if (pid > 0) {
      // parent
      printf(1, "Parent %d creating child %d\n", getpid(), pid);
      wait();
    } else {
      printf(1, "Child %d created\n", getpid());
      for (z = 0; z < 2147483648LL; z++)
        x = x + 3.89 * 89.54; //Useless calculation to consume CPU Time
      break;
    }
  }
  exit();
}
