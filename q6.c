#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        // int status;
        // int wc = waitpid(0, &status, WUNTRACED);
        // printf("hello, I am child (wc:%d, status:%d pid:%d)\n", wc, status, (int) getpid());
        printf("hello, I am child (pid:%d)\n", (int) getpid());
	sleep(1);
    } else {
        // parent goes down this path (original process)
        int status;
        int wc = waitpid(0, &status, WUNTRACED);
        printf("hello, I am parent of %d (wc:%d) (status: %d) (pid:%d)\n",
	       rc, wc, status, (int) getpid());
        // printf("hello, I am parent of %d (pid:%d)\n",
	    //    rc, (int) getpid());
    }
    return 0;
}
