#include "types.h"
#include "memlayout.h"

#define MTIME ((volatile uint64 *)CLINT_MTIME)

extern uint64 kbd_int_count;
extern uint64 sys_call_count;


uint64
sys_kbdint() {
  return kbd_int_count;
}

uint64
sys_countsyscall() {
  return sys_call_count;
}


uint64
sys_datetime()
{
  return *MTIME / 10000000;
}
