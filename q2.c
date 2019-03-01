#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<string.h>
 
int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    
    int file = open("text", O_RDWR);
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("Child file value:%d\n", file);
        char text[10] = "child";
        char currentText[50];
        read(file, &currentText, 50);
        printf("Child current value:%s\n", currentText);
        write(file, text, strlen(text));
        close(file);
        char newText[50];
        read(file, &newText, 50);
        printf("Child changed value:%s\n", newText);
    } else {
        // parent goes down this path (original process)
        printf("Parent file value:%d\n", file);
        char text[10] = "parent";
        char currentText[50];
        read(file, &currentText, 50);
        printf("Parent current value:%s\n", currentText);
        write(file, text, strlen(text));
        close(file);
        char newText[50];
        read(file, &newText, 50);
        printf("Parent changed value:%s\n", newText);
    }
    return 0;
}
