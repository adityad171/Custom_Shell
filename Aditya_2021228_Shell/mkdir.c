#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void main(int argc, char** argv){
	if(argc==1){
		printf("No directory mentioned\n");
		exit(1);
	}
	else if(argc==2){
		int status = mkdir(argv[1],0777);
		if(status==0){
			exit(0);
		}
		else{
			perror("mkdir failed");
			exit(1);
		}
	}
	else if(argc==3){
		if(strcmp(argv[1],"-v")==0){
			int status = mkdir(argv[2],0777);
			if(status==0){
				printf("mkdir: created directory '%s'\n",argv[2]);
				exit(0);
			}
			else{
				perror("mkdir failed");
				exit(1);
			}
		}
		else if(strcmp(argv[1],"-p")==0){
			printf("Yes");
			int status = mkdir(argv[2],0777);
			if(status==0){
				exit(0);
			}
			else{
				char *rest;
				char* ad1 = strtok_r(argv[2],"/",&rest);
				status = mkdir(ad1,0777);
				if(status==0){
					printf("%s\n",ad1);
					printf("Y1");
				}
				chdir(ad1);
				char s[100];
				printf("%s\n",getcwd(s,100));
				char * ptr = strchr(rest,'/');
				while(1){
					char buffer[20];
					strcpy(buffer,rest);
					ad1 = strtok_r(buffer,"/",&rest);
					ptr = strchr(rest,'/');
					mkdir(ad1,0777);
					chdir(ad1);
					char s[100];
					printf("%s\n",getcwd(s,100));
					if(ptr==NULL){
						break;
					}
				}
				char buffer[20];
				strcpy(buffer,rest);
				ad1 = strtok_r(buffer,"/",&rest);
				mkdir(ad1,0777);
				exit(0);
			}
		}
		else{
			printf("Wrong flag\n");
			fflush(stdout);
		}
	}
}
