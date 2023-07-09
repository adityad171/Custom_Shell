#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int check;
    char str[20];
    printf("Directory name: ");
    scanf("%s",str);
	char* dirname = str;
	check = mkdir(dirname,0777);
	if (!check)
		printf("dir created\n");
	else {
		printf("directory creation failed\n");
		exit(1);
	}
	system("dir");
}