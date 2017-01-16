#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/malloc.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include "devices/timer.h"

void 
main_test(void){
	
	thread_create("test_execute_without_yielding", PRI_MIN, test_execute_without_yielding, &test_execute_without_yielding);
	
	//thread_create();
	
	//thread_create();
}

void
test_execute_without_yielding (void){
	for (int i = 0; i < 100000; i++){
		
	}
	
}

void
test_execute_1_yield (void){
	for (int i = 0; i < 50000; i++){
		;
	}
	thread_yield();
	for (int i = 0; i < 50000; i++){
		;
	}
}

void
test_execute_2_yield (void){

	for(int j = 0; j< 1000; j++)
	{
		for (int i = 0; i < 5000; i++){
			;
		}
		thread_yield();
	}
}