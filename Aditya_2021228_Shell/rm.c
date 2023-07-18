#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
	if(argc==1){
		printf("No file mentioned\n");
	}
	else{
		if(strcmp(argv[1],"-i")==0){
			for(int i=2;i<argc;i++){
				printf("Remove file '%s'?",argv[i]);
				char in[10]={'\0'};
				scanf("%s",in);
				if(strcmp(in,"y")==0){
					int status = remove(argv[i]);
					if(status!=0){
						perror("rm failed");
						exit(1);
					}
				}
			}
		}
		else if(strcmp(argv[1],"-f")==0){
			for(int i=1;i<argc;i++){
                                int status = remove(argv[i]);
                        }
		}
		else{
			for(int i=1;i<argc;i++){
				int status = remove(argv[i]);
				if(status!=0){
					perror("rm failed");
					exit(1);
				}
			}
		}
	}
}
