#include<ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

int pc=0;
char* skipcomma(char* str);
static int split(char *cmd_exec, int, int, int);
char *hf;
char ib[1024];
int len;
int fp=1;
pid_t pid;
int fd;
static char* args[512];
int nol;
int fwp;
int pid, or,evf, blf,ir;
int flag;

int status;
char crd[1000],hdd[1000][1000],*cmd_exec[100],rf[3000],cwd[1024], hv[2000], *irf, *orf;
extern char** environ;

static char* skipwhite(char* s);
void tc(char *com_exec);
void clear_variables();
void fileprocess ();
void trio(char *cmd_exec);
void tri(char *cmd_exec);
void tro(char *cmd_exec);
void fw();
void be();
void ev();
void sev();
void change_directory();
void parent_directory();
void echo_calling(char *echo_val);
void hewc();
void prompt();
void sigintHandler(int sig_num);
void with_pipe_execute();
static int command(int, int, int, char *cmd_exec);

void sigintHandler(int sig_num)
{
    signal(SIGINT, sigintHandler);
    fflush(stdout);
}
void clear_variables()
{
  nol=0;
  cwd[0] = '\0';
  pc=0;
    ir=0;
  blf=0;
  fp=0;
  fwp=0;
  or=0;
  
  ib[0]='\0';
  
  pid=0;
  evf=0;

    fd =0;
  flag=0;
  len=0;
}
  
void echo_calling(char *echo_val)
{
  char *str[10];
  int i=0;
  char env_val[1000];
  str[0]=strtok(echo_val," ");
  evf=0;
  char new_args[1024];
  str[1]=strtok(NULL, "");
  int index=0;
  strcpy(env_val, args[1]);
  if(!(str[1]!=NULL))
         {
          printf("\n");
          return;
         } 
  if (strchr(str[1], '$')) 
                  {
                  evf=1;
                  }
  
  memset(new_args, '\0', sizeof(new_args));
  i=0;
  for(int i=0;str[1][i]!='\0';i++){
     if(str[1][i]=='"')
      {
      index=0;     
      while(!(str[1][i]=='\0'))
          {
          if(!(str[1][i]=='"'))
                {
                new_args[index]=str[1][i];
                 flag=1;
                index++;
                }
      
          }             
      }
      else if(!(str[1][i]!=39))
      {
      index=0;
      while(!(str[1][i]=='\0'))
          {
          if(!(str[1][i]==39))
                {
                new_args[index]=str[1][i];
                 flag=1;
                index++;
                }
          
          }               
      }
      else if(!(str[1][i]=='"'))
        {
          new_args[index]=str[1][i];
          index++;
        }
  } 

new_args[index]='\0';
if(!((evf==0)&& (strcmp(args[1], new_args)==0)))
    {
     strcpy(args[1], new_args);
      if(evf==1)
                {
                ev();
                }
      else if(evf==0)
                {
                  printf("%s\n", new_args ); 
                }
    }
else   {
  printf("%s\n", new_args);
}
}

void sev()
{  
int n=1;
char *left_right[100];
if(!(args[1]!=NULL))
      {
        char** env;
        env=environ;
          while ( *env != 0)
          {
            char* value = *env;
            printf("declare -x %s\n", value); 
            env++;   
          }  
         return; 
      }
left_right[0]=strtok(args[1],"=");
while (!((left_right[n]=strtok(NULL,"="))==NULL))
      n++;
left_right[n]=NULL;
setenv(left_right[0], left_right[1], 0);
}

void fw()
{
  int str_len=0;
  char input_data[2000], no[10];;
  int fd_out;
  nol++;
  int rw;
  sprintf (no, "%d", nol ); 
  strcpy(input_data, " ");
  strcat(input_data, no);
  strcat(input_data, " ");
  strcat(input_data, ib);

  
  fd_out=open(hf,O_WRONLY|O_APPEND|O_CREAT,S_IRUSR|S_IWUSR);
  str_len = strlen(input_data);
  len=strlen(ib);
  rw=write(fd_out,input_data,str_len);
  if(rw<0) 
        {
          printf("Error in writing file\n");
          return;
        }
  close(fd_out);

}

void be()
{
  char *num_ch[10],*tbb[100],bang_val[1000];
  int index=0;
  int num;
  int n=1;
  int i=1;
  
   if(ib[i]=='-')
    {
        n=1;
        num_ch[0]=strtok(ib,"-");
        while (!((num_ch[n]=strtok(NULL,"-"))==NULL))
              n++;
        num_ch[n]=NULL;
        num = atoi(num_ch[1]);

        index = nol-num;
        strcpy(bang_val, hdd[index]);
              
    }
    if(ib[i]=='!')
        {
           strcpy(bang_val, hdd[nol-1]);
        }
  if(!(ib[i]=='-' && ib[i]=='!') )
    {
      num_ch[0]=strtok(ib,"!");
      num = atoi(num_ch[0]);
      strcpy(bang_val, hdd[num-1]);
    }
  tbb[0]=strtok(bang_val," ");
  while (!((tbb[n]=strtok(NULL,""))==NULL))
            n++;
  tbb[n]=NULL;
  strcpy(bang_val, tbb[1]);
  printf("%s\n", bang_val );
  strcpy(ib, bang_val);
    
}

void ev()
{
  char *value;
  char env_val[1000];
  int index=0;
    for(int i=1;args[1][i]!='\0';i++){
    env_val[index]=args[1][i];
                   index++;
  }
  env_val[index]='\0';
  value=getenv(env_val);

  if(value){
    printf("%s\n", value);
  }   
  else printf("\n");
}


void fileprocess ()
{
  int fd;
  hf=(char *)malloc(100*sizeof(char));
  strcpy(hf,crd);
  strcat(hf, "/");
  strcat(hf, "history.txt"); 
  fd=open(hf, O_RDONLY|O_CREAT,S_IRUSR|S_IWUSR);
  int bytes_read=0, i=0, x=0, index=0;
  char buffer[1], temp_data[1000];

    while (bytes_read == sizeof (buffer)){
bytes_read = read (fd, buffer, sizeof (buffer));
int i=0;
while(!(i>=bytes_read)){
temp_data[index]=buffer[i];
                    index++;
                    if(!(buffer[i]!='\n'))
                        {
                          temp_data[index-1]='\0';
                          index=0;
                          strcpy(hdd[x], temp_data);
                          
                          nol++; 
                          temp_data[0]='\0';
                          x++;
                        }
    i++;
}
    }
    close (fd); 
}

void parent_directory()
{
if (getcwd(cwd, sizeof(cwd)) == NULL)
        perror("getcwd() error");
else{
  printf("%s\n", cwd );
    }
       
}

void change_directory()
{
char *h="/home";   
if ((strcmp(args[1], "/")==0)||(strcmp(args[1], "")==0) )
        chdir(h);

else if(args[1]==NULL)
        chdir(h);

else if(chdir(args[1])<0)
    printf("bash: cd: %s: No such file or directory\n", args[1]);

}
void trio(char *cmd_exec)
{
  char *io_token[100];
  char *new_cmd_exec1;  
  new_cmd_exec1=strdup(cmd_exec);
  int m=1;
  io_token[0]=strtok(new_cmd_exec1,"<");       
  while((io_token[m]=strtok(NULL,">"))!=NULL)
        m++;
  io_token[1]=skipwhite(io_token[1]);
  io_token[2]=skipwhite(io_token[2]);
  irf=strdup(io_token[1]);
  orf=strdup(io_token[2]);
  tc(io_token[0]);
  
}


static int split(char *cmd_exec, int input, int first, int last)
{
    char *new_cmd_exec1;  
    new_cmd_exec1=strdup(cmd_exec);
      {
        int m=1;
        args[0]=strtok(cmd_exec," ");       
        while((args[m]=strtok(NULL," "))!=NULL)
              m++;
        args[m]=NULL;
        if (!(args[0] == NULL)) 
            {
            if (strcmp(args[0], "echo") != 0) 
                    {
                      cmd_exec = skipcomma(new_cmd_exec1);
                      int m=1;
                      args[0]=strtok(cmd_exec," ");       
                      while((args[m]=strtok(NULL," "))!=NULL)
                                m++;
                      args[m]=NULL;

                    }
            if (strcmp(args[0], "exit") == 0) 
                                exit(0);
            
            if(strcmp("cd",args[0])==0)
                    {
                    change_directory();
                    return 1;
                    }
            else if(strcmp("pwd",args[0])==0)
                    {
                    parent_directory();
                    return 1;
                    }
            }
        }
    return command(input, first, last, new_cmd_exec1);
}


void tri(char *cmd_exec)
{
  char *new_cmd_exec1;
  char *ito[100];  
  new_cmd_exec1=strdup(cmd_exec);
  int m=1;
  ito[0]=strtok(new_cmd_exec1,"<");       
  while(!((ito[m]=strtok(NULL,"<"))==NULL))
        m++;
  ito[1]=skipwhite(ito[1]);
  irf=strdup(ito[1]);
  tc(ito[0]);
}

void hewc()
{
  int start_index;
  int  i;
  int num;
  
   if(args[1]==NULL)
      {
        i=0;
        while(i<nol-1){
          printf("%s\n", hdd[i] );
          i++;
        }
        printf(" %d %s\n", nol, hv );
      }
  else if(blf==1)
        {
          i=0;
          while(i<nol){
            printf("%s\n", hdd[i] ); 
            i++;
          }
        }
  else
      {
        if(args[1]!=NULL)
        num = atoi(args[1]);
        if(num>nol) 
        {
          i=0;
        while(i<nol-1){
          printf("%s\n", hdd[i] );
          i++;
        }
          printf(" %d %s\n", nol, hv );
        }
        start_index=nol-num;
        i=0;
        while(i<nol-1){
          printf("%s\n", hdd[i] );
          i++;
        }
          printf(" %d %s\n", nol, hv );
      } 

}

void tc(char *com_exec)
{
int m=1;
args[0]=strtok(com_exec," ");       
while((args[m]=strtok(NULL," "))!=NULL)
        m++;
}

static char* skipwhite(char* s)
{
  while (isspace(*s)) ++s;
  return s;
}

char* skipcomma(char* str)
{
  int i=0, j=0;
  char temp[1000];
  while(!(str[i++]=='\0'))
            {
              if(!(str[i-1]=='"'))
                    temp[j++]=str[i-1];
            }
        temp[j]='\0';
        str = strdup(temp);
  
  return str;
}


void tro(char *cmd_exec)
{
  char *o_token[100];
  char *new_cmd_exec1;  
  new_cmd_exec1=strdup(cmd_exec);
  int m=1;
  o_token[0]=strtok(new_cmd_exec1,">");       
  while(!((o_token[m]=strtok(NULL,">"))==NULL))
          m++;
  o_token[1]=skipwhite(o_token[1]);
  orf=strdup(o_token[1]); 
  tc(o_token[0]);   
  
}


static int command(int input, int first, int last, char *cmd_exec)
{
  int ret;
  int mypipefd[2];
  int output_fd;
  ret = pipe(mypipefd);
  int input_fd;
  if(ret == -1)
      {
        perror("pipe");
        return 1;
      }
  pid = fork();
 
  if (pid == 0) 
  { 
    if (input!=0 && last==0 && first==0 ) 
    {
      dup2(input, 0);
      dup2(mypipefd[1], 1);
    } 
    else if (input==0 && last==0 && first==1 ) 
    {
      dup2( mypipefd[1], 1 );
    }
    else 
    {
      dup2(input, 0);
    }
    if (strchr(cmd_exec, '>')) 
        {
          or=1;
          tro(cmd_exec);
        }
    else if (strchr(cmd_exec, '<')) 
        {
          ir=1;
          tri(cmd_exec);
        }
    else if (strchr(cmd_exec, '>') && strchr(cmd_exec, '<')) 
            {
              or=1;
              ir=1;
              
              trio(cmd_exec);
            }
    
    if(!(or != 1))
                {                    
                        output_fd= creat(orf, 0644);
                        if (output_fd < 0)
                          {
                          fprintf(stderr, "Failed to open %s for writing\n", orf);
                          return(EXIT_FAILURE);
                          }
                        dup2(output_fd, 1);
                        close(output_fd);
                        or=0;
                }
    if(!(ir != 1))
                  {
                         input_fd=open(irf,O_RDONLY, 0);
                         if (input_fd < 0)
                          {
                          fprintf(stderr, "Failed to open %s for reading\n", irf);
                          return(EXIT_FAILURE);
                          }
                        dup2(input_fd, 0);
                        close(input_fd);
                        ir=0;
                  }
     if (strcmp(args[0], "export") == 0)
                  {
                  sev();
                  return 1;
                  }
    if(execvp(args[0], args)<0) printf("%s: command not found\n", args[0]);
              exit(0);
    
     if (strcmp(args[0], "history") == 0)
             {
              hewc();
              } 
    else if (strcmp(args[0], "echo") == 0)
              {
              echo_calling(cmd_exec);
              } 
     
  }
  else 
  {
     waitpid(pid, 0, 0);  
   }
 
  if (last == 1)
    close(mypipefd[0]);
  if (input != 0) 
    close(input);
  close(mypipefd[1]);
  return mypipefd[0];

}



void prompt()
{
  char shell[1000];
   if (!(getcwd(cwd, sizeof(cwd)) != NULL)){
    perror("getcwd() error");
   }
        
   else{
    {
          strcpy(shell, "Aditya's Shell");
          strcat(shell, "$ ");

          printf("%s", shell);
        }
   }
       

}
void with_pipe_execute()
{

int  n=1, input=0, i, first=1;

cmd_exec[0]=strtok(ib,"|");

while ((cmd_exec[n]=strtok(NULL,"|"))!=NULL)
      n++;
cmd_exec[n]=NULL;
pc=n-1;
i=0;
while(i<n-1)
    {
      input = split(cmd_exec[i], input, first, 0);
      i++;
      first=0;
    }
input=split(cmd_exec[i], input, first, 1);
input=0;
return;

}
int main()
{   
    int status;
    char ch[2]={"\n"};
    signal(SIGINT, sigintHandler);
    getcwd(crd, sizeof(crd));
    
    int i=1;
    while (i)
    {
      clear_variables();
      prompt();
      fgets(ib, 1024, stdin);
      if(strcmp(ib, ch)==0)
            {
              continue;
            }
      if(!(ib[0]=='!'))
            {
                fileprocess();
                fw(); 
            }         
      len = strlen(ib);
      ib[len-1]='\0';
      strcpy(hv, ib);
      if(!(strcmp(ib, "exit") != 0)) 
            {
              flag = 1;
              break;
            }
      if(!(ib[0]!='!'))
              {
                fileprocess();
                blf=1;
                be();
              }
      with_pipe_execute();
      waitpid(pid,&status,0);
         
    }  
    if(flag==1)
      {
      printf("Thank You...\n");
      exit(0);       
      return 0;
      }
return 0;
}