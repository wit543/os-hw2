#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("Child value: %d\n", x);
        printf("Child value reference: %p\n", &x);
        x = 44;
        printf("Child changed value:%d\n", x);
        printf("Child value reference: %p\n", &x);
    } else {
        // parent goes down this path (original process)
        printf("Parent value: %d\n", x);
        printf("Parent value reference: %p\n", &x);
        x = 112;
        printf("Parent changed value: %d\n", x);
        printf("Parent value reference: %p\n", &x);
    }
    return 0;
}
