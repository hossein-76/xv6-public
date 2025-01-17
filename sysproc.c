#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "systemcalldata.h"
int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
void
sys_invoked_syscalls(void)
{
  cprintf("%s\n", "hi from invoked_syscalls");
  int pid=1;
  // if(argint(0, &pid) < 0)
  //   cprintf("%s\n", "Error");

  cprintf("process:%d \n", pid);
  for(int i=0;i < list_size; i++)
  {
    if(m_calls[i].pid==pid){
      cprintf(" name: %s | id: $s | count: %d | date: %d/%d/%d | time: %d:%d | datatype: %s\n",
    names[m_calls[i].id -1 ], m_calls[i].id, counts[m_calls[i].id - 1],
    m_calls[i].year, m_calls[i].month, m_calls[i].day, m_calls[i].hour,
    m_calls[i].minute, data_types[m_calls[i].id -1]);
  }
  }
  cprintf("%s\n", "bye from invoked_syscalls");
}
void
sys_log_syscalls(void)
{
  for(int i=0;i < list_size; i++)
  {
    cprintf(" name: %s | id: $s | count: %d | date: %d/%d/%d | time: %d:%d | datatype: %s\n",
    names[m_calls[i].id -1 ], m_calls[i].id, counts[m_calls[i].id - 1],
    m_calls[i].year, m_calls[i].month, m_calls[i].day, m_calls[i].hour,
    m_calls[i].minute, data_types[m_calls[i].id -1]);
  }
  cprintf("%s\n", "byyyyyeeee");
}
