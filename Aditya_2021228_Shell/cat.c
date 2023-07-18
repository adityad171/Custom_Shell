#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int  touch( int argc, char** argv ){
	int fDesc  = open(argv[1], O_RDWR | O_CREAT  );
	if(fDesc == -1){
		perror("cat failed");
		return -1;
	}
	return fDesc;
}

void main( int argc, char**argv){
	if(argc==1){
		printf("Less than required arguments\n");
		exit(1);
	}
	else if(argc==2){
		FILE * f;
		f = fopen(argv[1],"r");
		char c;
		c=fgetc(f);
		while(c!=EOF){
			printf("%c",c);
			c=fgetc(f);
		}
	}
	else{
		if(strcmp(argv[1],"-n")==0){
			for(int i=2;i<argc;i++){
				FILE * f;
		                f = fopen(argv[i],"r");
		                char c;
		                c=fgetc(f);
				printf("1)\t");
				fflush(stdout);
				int i=2;
		                while(c!=EOF){
		                        if(c=='\n'){
						printf("%c",c);
						printf("%d)\t",i++);
						fflush(stdout);
					}else{
						printf("%c",c);
						fflush(stdout);
					}
		                        c=fgetc(f);
				}
				printf("\n");
				printf("\n");
			}
		}
		else if(strcmp(argv[1],"-s")==0){
			for(int i=2;i<argc;i++){
                                FILE * f;
                                f = fopen(argv[i],"r");
                                char c;
                                c=fgetc(f);
                                int i=2;
                                while(c!=EOF){
                                        if(c=='\n'){
                                                printf("%c",c);
						while(c=='\n'){
							c=fgetc(f);
						}
						if(c!=EOF){
							printf("%c",c);
						}
                                        }else{
                                                printf("%c",c);
                                        }
					fflush(stdout);
                                        c=fgetc(f);
                                }
			}
                        printf("\n");
                        printf("\n");
			fflush(stdout);
		}
		else if(strcmp(argv[1],">")==0){
			if(argc>3){
				printf("Too many arguments");
				exit(1);
			}else{
				char* tP[]={"touch",argv[2]};
				int fDesc = touch(2,tP);
				char buffer[100];
				scanf("%s",buffer);
				write(fDesc,buffer,100);
			}
		}else{
			for(int i=1;i<argc;i++){
                                FILE * f;
                                f = fopen(argv[i],"r");
                                char c;
                                c=fgetc(f);
                                printf("1)\t");
                                int i=2;
                                while(c!=EOF){
                                        if(c=='\n'){
                                                printf("%c",c);
                                        }else{
                                                printf("%c",c);
                                        }
					fflush(stdout);
                                        c=fgetc(f);
                                }
                                printf("\n");
                                printf("\n");
				fflush(stdout);
                        }
		}
	}
}
