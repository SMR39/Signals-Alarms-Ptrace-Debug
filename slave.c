/***********************************************************************************************
SGP ASSIGNMENT 2

slave.c

A simple program to demonstrate ptrace debugging tool which can retrieve the value of a variable from child

Authors : Shashi & Ishan

*************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <syscall.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>


int i=0 ;

void main()
{
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    printf ("the exec program process ID is %d\n", (int) getpid ());
    printf("address of i is : %p", (void *)&i); //type casting to void poniter

    for(i=0; i<10; i++)

    {
        sleep(2);
        printf("\n %d \n",i);

    }
  EXIT_SUCCESS;
}

