#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
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
        printf("hello, I am child (pid:%d)\n", (int) getpid());

        // execl( "/bin/ls", "-l", NULL);  // runs ls
        // execlp("ls","ls","-l",NULL);// runs ls
        // char *env[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 };
        // execle("/bin/ls","-l",NULL, env);  // runs ls
        // char *cmd[] = { "ls", "-l", NULL};
        // execv("/bin/ls", cmd);  // runs ls
        // char *cmd[] = { "ls", "-l", NULL };
        // char *env[] = { "HOME=/usr/home", "LOGNAME=home", NULL};
        // execve ("/bin/ls", cmd, env); // runs ls
        char *cmd[] = { "ls", "-l", NULL};
        execvp( "ls", cmd);  // runs ls
        // char *cmd[] = { "ls", "-l", NULL };
        // char *env[] = { "HOME=/usr/home", "LOGNAME=home", NULL};
        // execvpe("ls",cmd,env);  // runs ls
        printf("this shouldn't print out");
    } else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
	       rc, wc, (int) getpid());
    }
    return 0;
}
