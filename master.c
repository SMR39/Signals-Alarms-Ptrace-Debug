/***********************************************************************************************
SGP ASSIGNMENT 2

master.c

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



int main()
{

    int wait_val;           /*  child's return value        */
    int pid,err;                /*  child's process id          */
    int data;
    int ret;

    void *p ;              // p is declared as Void pointer


    switch (pid = fork())
    {
    case -1:
        perror("fork");
        break;
    case 0:
        /*  child process starts        */
        err = execl("slave", "slave", NULL);
	if (err != 0)
        {
            perror("Error with exec call");
            abort();
        }
        break;
        /*  child process ends  */

    default:
        /*  parent process starts       */
        sleep(5);
        /* Send SIGSTOP to child.     */
        ret = kill(pid, SIGSTOP);

        if (ret != 0)
        {
            perror("kill");
            abort();
        }
        printf("\nenter the address\n", p);
        scanf("%p",&p);
        printf("Address sent tp ptrace is %p", p);
        data = ptrace(PTRACE_PEEKTEXT, pid,p,0);
        if (data== -1)
        {
            perror("ptrace");
        }
        printf ("\nthe value of i is %d \n" ,data);
        ret = ptrace(PTRACE_CONT, pid, NULL, 0);
        wait(&wait_val);

        if (WIFEXITED(wait_val))                                             //checks for normal exit
        {
            printf("\nChild terminated with exit status --> %d\n", WEXITSTATUS(wait_val));
        }
        else
        {
            printf("\nChild terminate abnormally\n");
        }

    }


    return 0;
}

