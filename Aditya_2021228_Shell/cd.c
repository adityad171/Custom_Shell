#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void where(void)
{
    char buffer[1024];

    if (getcwd(buffer, sizeof(buffer)) == NULL)
    {
        abort();
    }

    printf("current dir: %s\n",buffer);

    printf("environment variable: %s\n",getenv("PWD"));

}

int main()

{
    system("rm -rf subdir");

    if (mkdir("subdir", 0700)){
        abort();
    }

    printf("before changing dir:\n");

    where();

    if (chdir("subdir")){
        abort();
    }

    printf("after  changing dir:\n");

    where();
} 