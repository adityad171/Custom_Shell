#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

void main(int argc, char** argv){

	struct dirent *directory;
	char s[100];	
	DIR* dir = opendir(getcwd(s,100));
	if(dir==NULL){
		perror("ls failed");
		exit(1);
	}
	directory=readdir(dir);
	if(argc==1){
		while(directory!=NULL){
			if(directory->d_name[0]!='.'){
				printf("%s\t",directory->d_name);
			}
			directory=readdir(dir);
		}
		printf("\n");
		exit(0);
	}
	else if(argc==2){
		if(strcmp(argv[1],"-a")==0){
			while(directory!=NULL){
				printf("%s\t",directory->d_name);
				directory=readdir(dir);
			}
			printf("\n");
		}
		else if(strcmp(argv[1],"-A")==0){
			while(directory!=NULL){
				if(directory->d_name[0]=='.'){
					if(directory->d_name[1]!='.'&&directory->d_name[1]!='\0'){
						printf("%s\t",directory->d_name);
					}
				}
				else{
					printf("%s\t",directory->d_name);
				}
				directory=readdir(dir);
			}
			printf("\n");
		}
		else{
			printf("Wrong flag\n");
			exit(1);
		}
		exit(0);
	}else{
		printf("Too many arguments\n");
		exit(1);
	}
}
