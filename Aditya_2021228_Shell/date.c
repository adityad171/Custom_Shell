#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <error.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

void main(int argc, char** argv){
	if(argc==1){
		time_t t;
		time(&t);
		printf("%s",ctime(&t));
	}
	else if(argc==2){
		time_t t;
		time(&t);
		if(strcmp(argv[1],"-u")==0){
			fflush(stdout);
			struct tm* info=gmtime(&t);
			char* dform=(char*)malloc(sizeof(char)*40);;
			strftime(dform,40,"%a %b %d %H:%M:%S UTC 2022 ",info);
			printf("%s\n",dform);
			fflush(stdout);
		}else{
			printf("Wrong flag");
			fflush(stdout);
		}
	}
	else if(argc==3){
		if(strcmp(argv[1],"-r")==0){
			struct stat t;
			stat(argv[2],&t);
			printf("%s",ctime(&t.st_ctime));
		}
		else{
			printf("Wrong flag\n");
			fflush(stdout);
		}
	}
	else{
		printf("Too many arguments\n");
		fflush(stdout);
	}
	fflush(stdout);
}
