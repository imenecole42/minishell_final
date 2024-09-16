#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

/*int main(int ac, char **av)
{
   (void)ac;
    (void)av;
    printf("Hi there\n");
    printf("EOF = %d\n", EOF);*/

    //executing an ls command
    //char *av2[] = {"ls", "-la", NULL};
    //execvp(av2[0], av2);
    //printf("...and done\n");

    /*(void)ac;
    (void)av;
    pid_t   childpid;
    printf("before fork: %d\n", getpid());
    //fork creates a child ans returns its process ID
    childpid = fork();
    printf("after fork: %d\n", getpid());
    exit(0);
}*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


