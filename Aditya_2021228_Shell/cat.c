#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* ptr;
    printf("Enter the Name of the File: ");
	char ch;
    char s[100];
    
    scanf("%s\n",s);
	ptr = fopen(s, "r");

    if(!(NULL!=ptr)){
        printf("file can't be opened \n");
    }
    else{
	    printf("Contents of this file are:  \n");
        printf("\n");
    }

    while (ch != EOF){
        ch = fgetc(ptr);
		printf("%c\n", ch);
    }
	fclose(ptr);
}



