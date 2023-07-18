#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <pthread.h>

void sigsegv_handler(int sig)
{
    	printf("SIGSEGV recieved\n");
    	exit(1);
}

struct arg{
	int argc;
	char *argv[10];
};

void  cd( int argc, char** argv ){
	if (argc == 1){
		write(1,"Insufficient Number of Arguments\n",34);
	}
	else if(argc>2){
		printf("Too many arguments\n");
		fflush(stdout);
	}
	else{
		char * dir = argv[1];
		if(strcmp("~",dir)==0){
			dir="/home";
		}
		if(strcmp("/",dir)==0){
			dir="/root";
		}
		int status = chdir(dir);
		if (status==0){
				return;
		}
		else{
			perror("cd failed");
		}
	}
	return;
}

void pwd( int argc, char** argv ){
	if(argc==1){
		char s[100];
		printf("%s\n", getcwd(s, 100));
		fflush(stdout);
	}
	else if(argc==2){
		if(strcmp(argv[1],"-L")==0){
			printf("%s\n",getenv("PWD"));
			fflush(stdout);
		}
		else if(strcmp(argv[1],"-P")==0){
			char s[100];
			printf("%s\n", getcwd(s, 100));
			fflush(stdout);
		}
	}
	return;
}

void echo( int argc, char** argv){
	if(argc==1){
		write(1,"\n",2);
	}
	else if (argc==2){
		printf("%s\n",argv[1]);
		fflush(stdout);
	}
	else if(argc == 3){
		if(strcmp(argv[1],"-n")==0){
			printf("%s",argv[2]);
			fflush(stdout);
		}
		else if(strcmp(argv[1],"-E")==0){
			printf("%s\n",argv[2]);
			fflush(stdout);
		}
		else{
			printf("%s%s\n",argv[1],argv[2]);;
		}
	}else{
		if(strcmp(argv[1],"-n")==0){
			for(int i=2;i<argc;i++){
				printf("%s",argv[i]);
				fflush(stdout);
			}
		}
		else if(strcmp(argv[1],"-E")==0){
			for(int i=2;i<argc;i++){
				printf("%s",argv[i]);
				fflush(stdout);
			}
			printf("\n");
			fflush(stdout);
		}
		else{
			for(int i=2;i<argc;i++){
				printf("%s",argv[i]);
				fflush(stdout);
			}
			printf("\n");
			fflush(stdout);
		}
	}
	fflush(stdout);

}

void* ls(void* a1){
	struct arg* a = (struct arg*)a1;
	if(a->argc==1){
		char s[50]={'\0'};
		sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/ls'");
		system(s);
	}
	else if(a->argc ==2){
		char s[50]={'\0'};
		sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/ls' %s",a->argv[1]);
		system(s);
	}
	else if(a->argc==3){
		char s[50]={'\0'};
		sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/ls' %s %s",a->argv[1],a->argv[2]);
		system(s);
	}else if(a->argc==4){
		char s[50]={'\0'};
                sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/ls' %s %s %s",a->argv[1],a->argv[2],a->argv[3]);
                system(s);
	}else{
		printf("Too many arguments\n");
		fflush(stdout);
	}
}

void* mdir(void *a1){
	struct arg* a = (struct arg*)a1;
	if(a->argc==1){
		printf("No directory mentioned\n");
		fflush(stdout);
	}
	else if(a->argc ==2){
		char s[50]={'\0'};
		sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/mkdir' %s",a->argv[1]);
		system(s);
	}
	else if(a->argc==3){
		char s[50]={'\0'};
		sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/mkdir' %s %s",a->argv[1],a->argv[2]);
		system(s);
	}else{
		printf("Too many arguments\n");
		fflush(stdout);
	}
}
void* rm1(void* a1){
	struct arg* a = (struct arg*)a1;
	if(a->argc==1){
		printf("No directory mentioned\n");
		fflush(stdout);
	}
	else if(a->argc ==2){
		char s[50]={'\0'};
		sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/rm' %s",a->argv[1]);
		system(s);
	}
	else if(a->argc==3){
		char s[50]={'\0'};
		sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/rm' %s %s",a->argv[1],a->argv[2]);
		system(s);
	}else if(a->argc==4){
		char s[50]={'\0'};
                sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/rm' %s %s %s",a->argv[1],a->argv[2],a->argv[3]);
                system(s);
	}else{
		printf("Too many arguments\n");
		fflush(stdout);
	}
}

void* date(void* a1){
	struct arg* a = (struct arg*)a1;
	if(a->argc==1){
		char s[50]={'\0'};
		sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/date'");
		system(s);
	}
	else if(a->argc ==2){
		char s[50]={'\0'};
		sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/date' %s",a->argv[1]);
		system(s);
	}
	else if(a->argc==3){
		char s[50]={'\0'};
		sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/date' %s %s",a->argv[1],a->argv[2]);
		system(s);
	}else if(a->argc==4){
		char s[50]={'\0'};
                sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/date' %s %s %s",a->argv[1],a->argv[2],a->argv[3]);
                system(s);
	}else{
		printf("Too many arguments\n");
		fflush(stdout);
	}
}

void* cat(void* a1){
	struct arg* a = (struct arg*)a1;
	if(a->argc==1){
		char s[50]={'\0'};
		sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/cat'");
		system(s);
	}
	else if(a->argc ==2){
		char s[50]={'\0'};
		sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/cat' %s",a->argv[1]);
		system(s);
	}
	else if(a->argc==3){
		char s[50]={'\0'};
		sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/cat' %s %s",a->argv[1],a->argv[2]);
		system(s);
	}else if(a->argc==4){
		char s[50]={'\0'};
                sprintf(s,"'/mnt/c/VS Code/OS_Assignment1/A1shell/cat' %s %s %s",a->argv[1],a->argv[2],a->argv[3]);
                system(s);
	}else{
		printf("Too many arguments\n");
		fflush(stdout);
	}
}

int main()
{
    	printf("My PID is %d\n", getpid());
	signal(SIGSEGV, sigsegv_handler);

    	while(1){
		write(1,"cShell>>",9);
		char* buffer=(char*)malloc(sizeof(char)*51);;
		read(0,buffer,50);
		buffer=strtok(buffer,"\n");
		char * rest =  NULL;
		int argc = 0;
		char* argv[10];
		char* token = NULL;
        	char *tokenCommand = strtok(buffer," ");
        	while(tokenCommand!=NULL){
            		argv[argc] = tokenCommand;
            		tokenCommand = strtok(NULL," ");
            		++argc;
		}
		if(strcmp(argv[argc-1],"&t")!=0){
			if(strcmp("cd",argv[0]) == 0){
				cd(argc,argv);
			}
			else if(strcmp("pwd",argv[0]) == 0){
				pwd(argc,argv);
			}
			else if(strcmp("echo",argv[0])==0){
				echo(argc,argv);
			}
			else if(strcmp("ls",argv[0])==0){
				int status;
				int pid = fork();
				if(pid == 0){
//					argv[argc]=NULL;
//					execv("/mnt/c/VS Code/OS_Assignment1/A1shell/ls", argv);
//					exit(0);
					if(argc==1){
						execl("/mnt/c/VS Code/OS_Assignment1/A1shell/ls",argv[0],NULL);
					}
					else if(argc==2){
						execl("/mnt/c/VS Code/OS_Assignment1/A1shell/ls",argv[0],argv[1],NULL);
					}
					else if(argc==3){
						execl("/mnt/c/VS Code/OS_Assignment1/A1shell/ls",argv[0],argv[1],argv[2],NULL);
					}else if(argc==4){
						 execl("/mnt/c/VS Code/OS_Assignment1/A1shell/ls",argv[0],argv[1],argv[2],argv[3],NULL);
					}else{
						write(1,"Too many arguments\n",24);
					}
					exit(0);
				}
				else if (pid > 0){
					wait(&status);
				}
				fflush(stdout);
			}
			else if(strcmp("mkdir",argv[0])==0){
				int status;
				int pid = fork();
				if(pid == 0){
//					argv[argc]=NULL;
//					execv("/mnt/c/VS Code/OS_Assignment1/A1shell/mkdir", argv);
//					exit(0);
					if(argc==1){
                                                execl("/mnt/c/VS Code/OS_Assignment1/A1shell/mkdir",argv[0],NULL);
                                        }
                                        else if(argc==2){
                                                execl("/mnt/c/VS Code/OS_Assignment1/A1shell/mkdir",argv[0],argv[1],NULL);
                                        }
                                        else if(argc==3){
                                                execl("/mnt/c/VS Code/OS_Assignment1/A1shell/mkdir",argv[0],argv[1],argv[2],NULL);
                                        }else if(argc==4){
                                                 execl("/mnt/c/VS Code/OS_Assignment1/A1shell/mkdir",argv[0],argv[1],argv[2],argv[3],NULL);
                                        }else{
                                                write(1,"Too many arguments\n",24);
                                        }
                                        exit(0);
				}
				else if (pid > 0){
					wait(&status);
				}
				fflush(stdout);
			}
			else if(strcmp("cat",argv[0])==0){
				int status;
				int pid = fork();
				if(pid == 0){
//					argv[argc]=NULL;
//					execv("/mnt/c/VS Code/OS_Assignment1/A1shell/cat", argv);
//					exit(0);
					if(argc==1){
                                                execl("/mnt/c/VS Code/OS_Assignment1/A1shell/cat",argv[0],NULL);
                                        }
                                        else if(argc==2){
                                                execl("/mnt/c/VS Code/OS_Assignment1/A1shell/cat",argv[0],argv[1],NULL);
                                        }
                                        else if(argc==3){
                                                execl("/mnt/c/VS Code/OS_Assignment1/A1shell/cat",argv[0],argv[1],argv[2],NULL);
                                        }else if(argc==4){
                                                 execl("/mnt/c/VS Code/OS_Assignment1/A1shell/cat",argv[0],argv[1],argv[2],argv[3],NULL);
                                        }else{
                                                write(1,"Too many arguments\n",24);
                                        }
                                        exit(0);
				}
				else if (pid > 0){
					wait(&status);
				}
				fflush(stdout);
			}
			else if(strcmp("rm",argv[0])==0){
				int status;
				int pid = fork();
				if(pid == 0){
//					argv[argc]=NULL;
//					execv("/mnt/c/VS Code/OS_Assignment1/A1shell/rm", argv);
//					exit(0);
					if(argc==1){
                                                execl("/mnt/c/VS Code/OS_Assignment1/A1shell/rm",argv[0],NULL);
                                        }
                                        else if(argc==2){
                                                execl("/mnt/c/VS Code/OS_Assignment1/A1shell/rm",argv[0],argv[1],NULL);
                                        }
                                        else if(argc==3){
                                                execl("/mnt/c/VS Code/OS_Assignment1/A1shell/rm",argv[0],argv[1],argv[2],NULL);
                                        }else if(argc==4){
                                                 execl("/mnt/c/VS Code/OS_Assignment1/A1shell/rm",argv[0],argv[1],argv[2],argv[3],NULL);
                                        }else{
                                                write(1,"Too many arguments\n",24);
                                        }
                                        exit(0);
				}
				else if (pid > 0){
					wait(&status);
				}
				fflush(stdout);
			}
			else if(strcmp("date",argv[0])==0){
				int status;
				int pid = fork();
				if(pid == 0){
//					argv[argc]=NULL;
//					execv("/mnt/c/VS Code/OS_Assignment1/A1shell/date", argv);
//					exit(0);
					if(argc==1){
                                                execl("/mnt/c/VS Code/OS_Assignment1/A1shell/date",argv[0],NULL);
                                        }
                                        else if(argc==2){
                                                execl("/mnt/c/VS Code/OS_Assignment1/A1shell/date",argv[0],argv[1],NULL);
                                        }
                                        else if(argc==3){
                                                execl("/mnt/c/VS Code/OS_Assignment1/A1shell/date",argv[0],argv[1],argv[2],NULL);
                                        }else if(argc==4){
                                                 execl("/mnt/c/VS Code/OS_Assignment1/A1shell/date",argv[0],argv[1],argv[2],argv[3],NULL);
                                        }else{
                                                write(1,"Too many arguments\n",24);
                                        }
                                        exit(0);
				}
				else if (pid > 0){
					wait(&status);
				}
				fflush(stdout);
			}
			else{
				write(1,"Invalid command\n",16);
			}
		}
		else{
			argc--;
			if(strcmp("cd",argv[0]) == 0){
				cd(argc,argv);
			}
			else if(strcmp("pwd",argv[0]) == 0){
				pwd(argc,argv);
			}
			else if(strcmp("echo",argv[0])==0){
				echo(argc,argv);
			}
			else if(strcmp("ls",argv[0])==0){
				pthread_t p1;
                                argv[argc]=NULL;
                                struct arg a;
                                a.argc=argc;
                                for(int i=0;i<=argc;i++){
                                        a.argv[i]=argv[i];
                                }
                                pthread_create(&p1,NULL,ls,(void*)&a);
                                pthread_join(p1,NULL);
			}
			else if(strcmp("mkdir",argv[0])==0){
				pthread_t p1;
				argv[argc]=NULL;
				struct arg a;
				a.argc=argc;
				for(int i=0;i<=argc;i++){
					a.argv[i]=argv[i];
				}
				pthread_create(&p1,NULL,mdir,(void*)&a);
				pthread_join(p1,NULL);
				fflush(stdout);
			}
			else if(strcmp("cat",argv[0])==0){
				pthread_t p1;
				argv[argc]=NULL;
				struct arg a;
				a.argc=argc;
				for(int i=0;i<=argc;i++){
					a.argv[i]=argv[i];
				}
				pthread_create(&p1,NULL,cat,(void*)&a);
				pthread_join(p1,NULL);
			}
			else if(strcmp("rm",argv[0])==0){
				pthread_t p1;
                                argv[argc]=NULL;
                                struct arg a;
                                a.argc=argc;
                                for(int i=0;i<=argc;i++){
                                        a.argv[i]=argv[i];
                                }
                                pthread_create(&p1,NULL,rm1,(void*)&a);
                                pthread_join(p1,NULL);
			}
			else if(strcmp("date",argv[0])==0){
				pthread_t p1;
                                argv[argc]=NULL;
                                struct arg a;
                                a.argc=argc;
                                for(int i=0;i<=argc;i++){
                                        a.argv[i]=argv[i];
                                }
                                pthread_create(&p1,NULL,date,(void*)&a);
                                pthread_join(p1,NULL);
			}
			else{
				write(1,"Invalid command\n",16);
			}
		}
	}
}

