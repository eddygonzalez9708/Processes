// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // waitpid needs to be included separately 

int main(void)
{
    // Your code here
    int rc = fork(); 
    if (rc < 0) { // fork failed; exit 
        fprintf(stderr, "Fork Failed\n"); 
        exit(1); 
    }
    else if (rc == 0) { // child process satisfies this branch 
        printf("Hello"); 
    }
    else {
        waitpid(rc, NULL, 0); // waitpid call added here 
        printf("\nGoodBye"); 
    }

    return 0;
}
