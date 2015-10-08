/***********************************************************************************************
SGP ASSIGNMENT 2

ticktockforever.c

A program that restarts itself everytime a ctrl-C is typed. Demonstration through simple matrix multiplication


Authors : Shashi & Ishan

*************************************************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <setjmp.h>
#include <signal.h>

static jmp_buf env;
void sig_handler(int signo)
{
		
		sigset_t sig_set;
		sigemptyset(&sig_set);
		
		if(sigaddset(&sig_set,SIGINT)==0)
		{
  			 printf("\nsigaddset successfully added for SIGINT\n");
		}
		sigprocmask(SIG_UNBLOCK,&sig_set,NULL); //SIGINT signal is unmasked
	
 		if (signo == SIGINT)
		{
			printf("\nSIGINT signal handling routine: Restarting the application ");
			longjmp(env,1);
	        }
}

void main()
	{
		signal(SIGINT, sig_handler);
		int i,j;
		int arr1[3][3];
		int arr2[3][3];
		int arr3[3][3];
		//setting the restart point for jump

		if(setjmp(env)==0 )
				{
				signal(SIGINT, sig_handler);
				}
//Entering first matrix
		for (i=0;i<3;i++)
		{
			for (j=0;j<3;j++)
			{
				printf("\nEnter the value of %d*%d element",i+1,j+1);
				scanf("%d",&arr1[i][j]);
			}
			
		}
										
		printf("Displaying the array\n");
		for (i=0;i<3;i++)
		{
			for (j=0;j<3;j++)
			{
				printf("%d",arr1[i][j]);
				printf("\t");
			}
			printf("\n");
		}
//Entering the second Matrix
		printf("Enter the second matrix\n");
		i,j=0;
		for (i=0;i<3;i++)
		{
			for (j=0;j<3;j++)
			{
				printf("Enter the value of %d*%d element",i+1,j+1);
				scanf("%d",&arr2[i][j]);
			}
		}
										
		printf("Displaying the array\n");
		for (i=0;i<3;i++)
		{
			for (j=0;j<3;j++)
			{
				printf("%d",arr2[i][j]);
				printf("\t");
			}
			printf("\n");
		}
//Multiplying the two matrices
		i,j=0;
		int sum=0,k=0;
		for (i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{     
				for (k=0;k<3;k++)
				{
					sum = sum + arr1[i][k] * arr2[k][j];
				}
			arr3[i][j]=sum;
			sum=0;
			}
		}
		printf("Displaying multiplied matrices\n");
		i,j=0;
		for (i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{				
				printf("%d",arr3[i][j]);
				printf("\t");
			}
		printf("\n");
		}
	}
