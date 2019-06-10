#include "systemcalldata.h"

struct sysCallData sys_data;

struct sysCallData m_calls[100];

int counts[23] = {0};
char *data_types[23] = {"void", "void", "void", "int", "int,void,char*", "int",
                     "char* ,char**", "int , struct", "char", "int", "void",
                     "int", "int", "void", "char*, int", "int,void,char*",".",
                     ".",".",".",".",".","."};
int index = 0;
int list_size = 0;

char *names[23] = {"fork","exit","wait","pipe","read","kill","exec","fstat","chdir","dup",
"getpid","sbrk","sleep","uptime","open","write","mknod","unlink",
"link","mkdir","close","invoked_syscalls","log_syscalls"};

int increase_data(struct sysCallData data)
{
  counts[data.id]++;
  if(index>=100){
    index=0;
  };
  m_calls[index] = data;
  index++;
  if(index > list_size){
    list_size = index;
  }
  return 0;
}
