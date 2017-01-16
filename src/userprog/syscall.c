#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f)
{
  int syscall_no = ((int *)f->esp)[0];

  switch(syscall_no)
  {
  case SYS_WRITE:
  {
	 int descriptor = ((int *)f->esp)[1];
	 char * buf = (char *)((int *)f->esp)[2];
	 int len = ((int *)f->esp)[3];

	if(1 == descriptor)
	{
		putbuf(buf, len);
		f->eax = len;
		return;
	}

	break;
  }
  case SYS_MAP_PG_0:
	  thread_current()->use_pg0 = true;
	  break;
  case SYS_UNMAP_PG_0:
	  thread_current()->use_pg0 = false;
	  break;
  }

  printf ("system call!\n");
  thread_exit ();
}

void
syscal_write(void){
	printf ("1\n");
	thread_exit ();
}
