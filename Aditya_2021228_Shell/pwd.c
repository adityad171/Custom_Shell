#include <unistd.h>
#include <stdio.h>
int main() {
    char cwd[1024];
    chdir("change dir to");
    getcwd(cwd, sizeof(cwd));
    printf("Current working dir: %s\n", cwd);
}