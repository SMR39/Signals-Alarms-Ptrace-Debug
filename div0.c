/***********************************************************************************************
SGP ASSIGNMENT 2

div0.c

A program to demonstrate signal function to catch "divide by zero" exceptions

Authors : Ishan & Shashi

*************************************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sig_handler(int signo)//signal handling routine
{
  if (signo == SIGFPE)
    printf("received SIGFPE\n");
    psignal(signo,"Error");
    exit(1);
}

int main(void)
{
  int a=4 , b=0 ; 
	
  float c;

  (signal(SIGFPE, sig_handler));

    c = a/b ;
    return 0;
  
}

