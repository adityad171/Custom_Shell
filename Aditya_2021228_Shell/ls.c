#include<stdio.h>
#include<dirent.h>
int main()
{
char dirname[10];
DIR*p;
struct dirent *d;
printf("directory name:\n");
scanf("%s",dirname);
p=opendir(dirname);
if(p==NULL)
  {
  perror("Cannot find directory");
  }
while(d==readdir(p))
  printf("%s\n",d->d_name);
}