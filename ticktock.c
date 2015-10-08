/***********************************************************************************************
SGP ASSIGNMENT 2

ticktock.c

A simple program that displays its progress periodically, every second. 

Authors : Ishan & Shashi

*************************************************************************************************/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sig_handler(int signo)
	{
	  	if (signo == SIGALRM)
			printf("\nALARM\n");
		alarm(1);
	}

int main () 
	{

	signal(SIGALRM , sig_handler);//it connects to signal handling routine
	alarm(1);

	int i ;

		while(i<5)
                {
  		  sleep(1);
                  printf("\n%d\n",i);
                  i++ ;
		}
 	return 0;	
}
