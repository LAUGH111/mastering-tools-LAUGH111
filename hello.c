#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<limits.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(int argc, char *argv[], char *env[])
{
  struct stat stc,stt;
  int i;
  char *tmp,buf[12345],src[1024],aim[1024];

  int fps,qwe;//文件

  realpath(argv[1],src);
  realpath(argv[2],aim); 
  stat(src,&stc);
  if (S_ISDIR(stc.st_mode))
  {perror("源文件是目录形式！");exit(1);}
  else
  {
    fps=open(src,O_RDONLY);
    if(fps==-1)
    {perror("源文件打开失败！");exit(1);}

  }
  stat(aim,&stt);
  if (S_ISDIR(stt.st_mode))
  {
    tmp=strrchr(src,'/');
    strcat(aim,tmp);
  }
  qwe=open(aim,O_CREAT|O_RDWR,stc.st_mode);
  if(qwe==-1)
  {perror("目标文件创建失败！");exit(1);}
  while((i=read(fps,buf,65535))>0)
  {write(qwe,buf,i);
  }
  close(fps);
  close(qwe);
  return 0;
}



