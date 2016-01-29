#define _POSIX_SOURCE
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <ctype.h>
#include  <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define SENT_SIZE 1024
#define SENT_BREAK_SIZE 64
#define DELIMITERS "(,)"

void *myquit(void *p);
void *mymul(void *p);
void *mysum(void *p);
void *mysub(void *p);
void *mydiv(void *p);
void *mysprime(void *p);
void *mybprime(void *p);
void *mylcm(void *p);
void *mygcd(void *p);
void *myls(void *p);

void myFunct_quit(char **var2);
void myFunct_mul(char **var2);
void myFunct_sum(char **var2);
void myFunct_sub(char **var2);
void myFunct_div(char **var2);
void myFunct_sprime(char **var2);
void myFunct_bprime(char **var2);
void myFunct_lcm(char **var2);
void myFunct_gcd(char **var2);
void myFunct_ls(char **var2);

int cal_gcd(int p,int q);
int cal_lcm(int p,int q);

// Start of the myFunct_ls() function
// Computes the ls command
int para_ls_count;
void myFunct_ls(char **var2)
{ 
	char **var;
	var = (char **)var2;
	int para_count;
	for (para_count = 0; var[para_count] != NULL; para_count++);
	para_ls_count = para_count;
	pthread_t t1;
	pthread_attr_t a1;
	pthread_attr_init(&a1);
	int testvar = pthread_create(&t1,&a1,myls,var);
	if(testvar!=0)
	{
		printf("Thread creation failed !!! : myFunct_ls()\n");
	}
		pthread_join(t1,NULL);
}

void *myls(void *p)
{
	char **var2;
	var2 = (char **)p;
	if(para_ls_count>=1)
	{
		if(para_ls_count<=1)
		{
			char *const argum[] = {"/usr/bin/bash", NULL};
			execvp("ls", argum);
		}
		else
		{
			printf("Incorrect Syntax!!! Usage is  : ls // Takes no parameters\n");
		}
	}
	else
	{
		printf("Incorrect Syntax!!!! Usage is  : ls // Takes no parameters\n");
	}
	pthread_exit(0);
}

// Start of the myFunct_gcd() function
// Computes the GCD
int res_gcd,para_gcd_count;
void myFunct_gcd(char **var2)
{ 
	char **var;
	var = (char **)var2;
	int para_count;
	for (para_count = 0; var[para_count] != NULL; para_count++);
	para_gcd_count = para_count;
	pthread_t t1;
	pthread_attr_t a1;
	pthread_attr_init(&a1);
	int testvar = pthread_create(&t1,&a1,mygcd,var);
	if(testvar!=0)
	{
		printf("Thread creation failed !!! : myFunct_gcd()\n");
	}
		pthread_join(t1,NULL);
}

void *mygcd(void *p)
{
	char **var2;
	var2 = (char **)p;
	if(para_gcd_count>=3)
	{
		if(para_gcd_count<=7)
		{
			res_gcd = atoi(var2[1]);
			for(int i=1;i<para_gcd_count;i++)
			{
				if(!(atof(var2[i])==(float)atoi(var2[i])))
				{
					printf("This function takes INTEGER values only!!!! Try again\n");
					pthread_exit(0);
				}
				int z = atoi(var2[i]);
				res_gcd = cal_gcd(res_gcd,z);
			}
			printf("GCD obtained is : %d\n",res_gcd);
		}
		else
		{
			printf("Incorrect Syntax!!! Usage is  : gcd(paramater1, paramater2,.... ) // This function can take maximum of 6 parameters only.\n");
		}
	}
	else
	{
		printf("Incorrect Syntax!!!! Usage is  : gcd(paramater1, paramater2,....) // minimum of 2 parameters\n");
	}
	pthread_exit(0);
}


// Start of the myFunct_lcm() function
// Computes the LCM
int res_lcm,para_lcm_count;
void myFunct_lcm(char **var2)
{ 
	char **var;
	var = (char **)var2;
	int para_count;
	for (para_count = 0; var[para_count] != NULL; para_count++);
	para_lcm_count = para_count;
	pthread_t t1;
	pthread_attr_t a1;
	pthread_attr_init(&a1);
	int testvar = pthread_create(&t1,&a1,mylcm,var);
	if(testvar!=0)
	{
		printf("Thread creation failed !!! : myFunct_lcm()\n");
	}
		pthread_join(t1,NULL);
}

int cal_gcd(int p,int q)
{
	if ( p % q==0)
	{
		return q;
	}

	return cal_gcd(q, p % q);
}

int cal_lcm(int p,int q)
{
	int pr,fact,vi;
	fact = cal_gcd(p,q);
	if (fact==q)
	{
		vi = p;
	}
	else
	{
		vi = (p*q)/fact;
	}
	return vi;
}

void *mylcm(void *p)
{
	char **var2;
	var2 = (char **)p;
	if(para_lcm_count>=3)
	{
		if(para_lcm_count<=7)
		{
			res_lcm = 1;
			for(int i=1;i<para_lcm_count;i++)
			{
				if(!(atof(var2[i])==(float)atoi(var2[i])))
				{
					printf("This function takes INTEGER values only!!!! Try again\n");
					pthread_exit(0);
				}
				int z = atoi(var2[i]);
				res_lcm = cal_lcm(res_lcm,z);
			}
			printf("LCM obtained is : %d\n",res_lcm);
		}
		else
		{
			printf("Incorrect Syntax!!! Usage is  : lcm(paramater1, paramater2,.... ) // This function can take maximum of 6 parameters only.\n");
		}
	}
	else
	{
		printf("Incorrect Syntax!!!! Usage is  : lcm(paramater1, paramater2,....) // minimum of 2 parameters\n");
	}
	pthread_exit(0);
}



// Start of the myFunct_bprime() function
// Computes the largest prime number
int res_bprime,para_bprime_count;
void myFunct_bprime(char **var2)
{ 
	char **var;
	var = (char **)var2;
	int para_count;
	for (para_count = 0; var[para_count] != NULL; para_count++);
	para_bprime_count = para_count;
	pthread_t t1;
	pthread_attr_t a1;
	pthread_attr_init(&a1);
	int testvar = pthread_create(&t1,&a1,mybprime,var);
	if(testvar!=0)
	{
		printf("Thread creation failed !!! : myFunct_bprime()\n");
	}
		pthread_join(t1,NULL);
}

void *mybprime(void *p)
{
	char **var2;
	var2 = (char **)p;
	if(para_bprime_count>=3)
	{
		if(para_bprime_count<=7)
		{
			int pick_first,countvar1=0;
			for(int i=1;i<para_bprime_count;i++) 
			{
				if(!(atof(var2[i])==(float)atoi(var2[i])))
				{
					printf("This function takes INTEGER values only!!!! Try again\n");
					pthread_exit(0);
				}
				res_bprime = atoi(var2[i]);
				int countvar=0;
				for(int j=2;j<=res_bprime;j++)
				{
					if(!(res_bprime % j == 0 && j!=res_bprime))
					{
						//prime
						countvar++;						
					}
				}
				if(countvar==(res_bprime-1))
				{
					pick_first = res_bprime;
				}
				else
				{
					countvar1++;
				}
			}
			if(countvar1==(para_bprime_count-1))
			{
				printf("Enter prime numbers only\n");
				pthread_exit(0);
			}
			res_bprime = pick_first;
			for(int i=1;i<para_bprime_count;i++)
			{
					int countvar2=0;
					for(int j=2; j<=atoi(var2[i]);j++)
					{
						if(!(atoi(var2[i]) % j == 0 && j!=atoi(var2[i])))
						{
							countvar2++;
						}
					}
					if(countvar2==(atoi(var2[i])-1))
					{
						if(res_bprime<atoi(var2[i]))
						{
							res_bprime = atoi(var2[i]);
						}
					}	
			}
			printf("Biggest prime number obtained is : %d\n",res_bprime);
		}
		else
		{
			printf("Incorrect Syntax!!! Usage is  : sprime(paramater1, paramater2,.... ) // This function can take maximum of 6 parameters only.\n");
		}
	}
	else
	{
		printf("Incorrect Syntax!!!! Usage is  : sprime(paramater1, paramater2,....) // minimum of 2 parameters to compare\n");
	}
	pthread_exit(0);

}

//Start of the myFunct_sprime() function
// Computes the smallest prime number
int res_sprime,para_sprime_count;
void myFunct_sprime(char **var2)
{ 
	char **var;
	var = (char **)var2;
	int para_count;
	for (para_count = 0; var[para_count] != NULL; para_count++);
	para_sprime_count = para_count;
	pthread_t t1;
	pthread_attr_t a1;
	pthread_attr_init(&a1);
	int testvar = pthread_create(&t1,&a1,mysprime,var);
	if(testvar!=0)
	{
		printf("Thread creation failed !!! : myFunct_sprime()\n");
	}
		pthread_join(t1,NULL);
}

void *mysprime(void *p)
{
	char **var2;
	var2 = (char **)p;
	if(para_sprime_count>=3)
	{
		if(para_sprime_count<=7)
		{
			int pick_first,countvar1=0;
			for(int i=1;i<para_sprime_count;i++) 
			{
				if(!(atof(var2[i])==(float)atoi(var2[i])))
				{
					printf("This function takes INTEGER values only!!!! Try again\n");
					pthread_exit(0);
				}
				res_sprime = atoi(var2[i]);
				int countvar=0;
				for(int j=2;j<=res_sprime;j++)
				{
					if(!(res_sprime % j == 0 && j!=res_sprime))
					{
						//prime
						countvar++;						
					}
				}
				if(countvar==(res_sprime-1))
				{
					pick_first = res_sprime;
				}
				else
				{
					countvar1++;
				}
			}
			if(countvar1==(para_sprime_count-1))
			{
				printf("Enter prime numbers only\n");
				pthread_exit(0);
			}
			res_sprime = pick_first;
			for(int i=1;i<para_sprime_count;i++)
			{
					int countvar2=0;
					for(int j=2; j<=atoi(var2[i]);j++)
					{
						if(!(atoi(var2[i]) % j == 0 && j!=atoi(var2[i])))
						{
							countvar2++;
						}
					}
					if(countvar2==(atoi(var2[i])-1))
					{
						if(res_sprime>atoi(var2[i]))
						{
							res_sprime = atoi(var2[i]);
						}
					}	
			}
			printf("Smallest prime number obtained is : %d\n",res_sprime);
		}
		else
		{
			printf("Incorrect Syntax!!! Usage is  : sprime(paramater1, paramater2,.... ) // This function can take maximum of 6 parameters only.\n");
		}
	}
	else
	{
		printf("Incorrect Syntax!!!! Usage is  : sprime(paramater1, paramater2,....) // minimum of 2 parameters to compare\n");
	}
	pthread_exit(0);
}



// Start of the myFunct_div() function
// Computes the division
int para_div_count;
void myFunct_div(char **var2)
{ 
	char **var;
	var = (char **)var2;
	int para_count;
	for (para_count = 0; var[para_count] != NULL; para_count++);
	para_div_count = para_count;
	pthread_t t1;
	pthread_attr_t a1;
	pthread_attr_init(&a1);
	int testvar = pthread_create(&t1,&a1,mydiv,var);
	if(testvar!=0)
	{
		printf("Thread creation failed !!! : myFunct_div()\n");
	}
		pthread_join(t1,NULL);
}

void *mydiv(void *p)
{
	char **var2;
	var2 = (char **)p;
	if(para_div_count==3)
	{
		if(atoi(var2[2])==0)
		{
			fprintf(stderr,"Division cannot be performed, as we get divide by zero exception\n");
		}
		else
		{
			float res_div = (atof(var2[1]))/(atof(var2[2]));
			printf("Quotient obtained is : %f\n",res_div);
		}
	}
	else
	{
		printf("Incorrect Syntax!!!! Usage is  : div(paramater1, paramater2) // Takes minimum of 2 parameters\n");
	}
	pthread_exit(0);
}

// Start of the myFunct_sub() function
// Computes the difference
int para_sub_count;
float res_sub;
void myFunct_sub(char **var2)
{ 
	char **var;
	var = (char **)var2;
	int para_count;
	for (para_count = 0; var[para_count] != NULL; para_count++);
	para_sub_count = para_count;
	pthread_t t1;
	pthread_attr_t a1;
	pthread_attr_init(&a1);
	int testvar = pthread_create(&t1,&a1,mysub,var);
	if(testvar!=0)
	{
		printf("Thread creation failed !!! : myFunct_sub()\n");
	}
		pthread_join(t1,NULL);
}

void *mysub(void *p)
{
	char **var2;
	var2 = (char **)p;
	if(para_sub_count>=3)
	{
		if(para_sub_count<=7)
		{
			res_sub = atof(var2[1]);
			for(int i=2;i<para_sub_count;i++)
			{
				float z = atof(var2[i]);
				res_sub = res_sub - z;
			}
			printf("Difference obtained is : %f\n",res_sub);
		}
		else
		{
			printf("Incorrect Syntax!!! Usage is  : sub(paramater1, paramater2,.... ) // This function can take maximum of 6 parameters only.\n");
		}
	}
	else
	{
		printf("Incorrect Syntax!!!! Usage is  : sub(paramater1, paramater2,....) // minimum of 2 parameters\n");
	}
	pthread_exit(0);
}


// Start of the myFunct_quit() function
// Exists the program
int para_quit_count;
void myFunct_quit(char **var2)
{ 
	char **var;
	var = (char **)var2;
	int para_count;
	for (para_count = 0; var[para_count] != NULL; para_count++);
	para_quit_count = para_count;
	pthread_t t1;
	pthread_attr_t a1;
	pthread_attr_init(&a1);
	int testvar = pthread_create(&t1,&a1,myquit,var);
	if(testvar!=0)
	{
		printf("Thread creation failed !!! : myFunct_quit()\n");
	}
		pthread_join(t1,NULL);
}

void *myquit(void *p)
{
	char **var2;
	var2 = (char **)p;
	if(para_quit_count!=1)
	{
		printf("Incorrect Syntax!!!! Usage is  : quit // No parameters required\n");
	}
	else
	{
		printf("Bye !!!\n");
		//exit(EXIT_SUCCESS);
		pthread_exit(0);
	}
	pthread_exit(0);
}

// Start of the myFunct_mul() function
// Computes the product
int para_mul_count;
float res_mul;
void myFunct_mul(char **var2)
{ 
	char **var;
	var = (char **)var2;
	int para_count;
	for (para_count = 0; var[para_count] != NULL; para_count++);
	para_mul_count = para_count;
	pthread_t t1;
	pthread_attr_t a1;
	pthread_attr_init(&a1);
	int testvar = pthread_create(&t1,&a1,mymul,var);
	if(testvar!=0)
	{
		printf("Thread creation failed !!! : myFunct_mul()\n");
	}
		pthread_join(t1,NULL);
}

void *mymul(void *p)
{
	char **var2;
	var2 = (char **)p;
	if(para_mul_count>=3)
	{
		if(para_mul_count<=7)
		{
			res_mul = 1;
			for(int i=1;i<para_mul_count;i++)
			{
				float z = atof(var2[i]);
				res_mul = res_mul * z;
			}
			printf("Product obtained is : %f\n",res_mul);
		}
		else
		{
			printf("Incorrect Syntax!!! Usage is  : mul(paramater1, paramater2,.... ) // This function can take maximum of 6 parameters only.\n");
		}
	}
	else
	{
		printf("Incorrect Syntax!!!! Usage is  : mul(paramater1, paramater2,....) // minimum of 2 parameters\n");
	}
	pthread_exit(0);
}


//Start of the myFunct_sum() function
// Computes the sum
int para_sum_count;
float res_sum;
void myFunct_sum(char **var2)
{ 
	char **var;
	var = (char **)var2;
	int para_count;
	for (para_count = 0; var[para_count] != NULL; para_count++);
	para_sum_count = para_count;
	pthread_t t1;
	pthread_attr_t a1;
	pthread_attr_init(&a1);
	int testvar = pthread_create(&t1,&a1,mysum,var);
	if(testvar!=0)
	{
		printf("Thread creation failed !!! : myFunct_sum()\n");
	}
		pthread_join(t1,NULL);
}

void *mysum(void *p)
{
	char **var2;
	var2 = (char **)p;
	if(para_sum_count>=3)
	{
		if(para_sum_count<=7)
		{
			res_sum = 0;
			for(int i=1;i<para_sum_count;i++)
			{
				float z = atof(var2[i]);
				res_sum = res_sum + z;
			}
			printf("Sum obtained is : %f\n",res_sum);
		}
		else
		{
			printf("Incorrect Syntax!!! Usage is  : sum(paramater1, paramater2,.... ) // This function can take maximum of 6 parameters only.\n");
		}
	}
	else
	{
		printf("Incorrect Syntax!!!! Usage is  : sum(paramater1, paramater2,....) // minimum of 2 parameters\n");
	}
	pthread_exit(0);
}

// Start of the myFunctCalls() function
// Identifying the shell commands

int myFunctCalls(char **var2)
{	
	int para_count;
	for (para_count = 1; var2[para_count] != NULL; para_count++)
	{
		/*if(atoi(var2[para_count])<=INT_MAX && atoi(var2[para_count])>=INT_MIN)
		{

		}
		else
		{
			printf("Entered numbers are out of range!!! Try again\n");
			return 1;
		}*/

		if (!strspn(var2[para_count],"0123456789")==strlen(var2[para_count])) 
		{
		   	printf("Enter numbers as parameters!!! Try again\n");
			return 1;
		} 
		else
		{
			if(isalpha((int)*var2[para_count]))
			{
				printf("Entered is alphanumeric!!! Try again\n");
				return 1;
			}
		}
	}	

	char *var_sum = "sum";
	char *var_mul = "mul";
	char *var_quit = "quit";
	char *var_lcm ="lcm";
	char *var_bprime = "bprime";
	char *var_sub = "sub";
	char *var_gcd = "gcd";
	char *var_sprime = "sprime";
	char *var_div = "div";
	char *var_ls = "ls";
	
	pthread_t t1[10];
	pthread_attr_t a1[10];
	pid_t  pip_check;

	pip_check = fork();
	if(pip_check == 0)
	{
		if(strcmp(var2[0],var_sum)==0)
		{
			myFunct_sum(var2);
			return 1;
		}
		else if(strcmp(var2[0],var_mul)==0)
		{
			myFunct_mul(var2);
			return 1;
		}
		else if(strcmp(var2[0],var_quit)==0)
		{
			myFunct_quit(var2);
			kill(pip_check, SIGTERM);
			return 0;
		}
		else if(strcmp(var2[0],var_sub)==0)
		{
			myFunct_sub(var2);
			return 1;
		}
		else if(strcmp(var2[0],var_div)==0)
		{
			myFunct_div(var2);
			return 1;
		}
		else if(strcmp(var2[0],var_sprime)==0)
		{
			myFunct_sprime(var2);
			return 1;
		}
		else if(strcmp(var2[0],var_bprime)==0)
		{
			myFunct_bprime(var2);
			return 1;
		}
		else if(strcmp(var2[0],var_lcm)==0)
		{
			myFunct_lcm(var2);
			return 1;
		}
		else if(strcmp(var2[0],var_gcd)==0)
		{
			myFunct_gcd(var2);
			return 1;
		}
		else if(strcmp(var2[0],var_ls)==0)
		{
			myFunct_ls(var2);
			return 1;
		}
		else
		{
			printf("Command entered doesn't exist in out system!!!! Try Again.\n");
			return 1;
		}
	}
	else if(pip_check > 0)
	{
		int parent_flag;
		waitpid(pip_check, &parent_flag, 0);
		//printf("This is the parent thread\n");
		if(parent_flag == 0)
		{
			//printf("Process in the subthread terminated without errors\n");
		}
		if(parent_flag == 1)
		{
			printf("Process in the subthread terminated with errors\n");
		}
	}
	else
	{
		printf("Error creating threads\n");
	}
}

// Start of the get_run() function
// Implementing and creating the function call in shell created.
int get_run(char **var2)
{
	if(var2[0]==NULL)
	{
		return 1;
	}
	return myFunctCalls(var2);
}

// Start of the get_break_sent() function
// Splits based on delimiters
char **get_break_sent(char *var1)
{
	// Declaring the variables
	int size = SENT_BREAK_SIZE;
	int cursor = 0;
	char **var_char = malloc(size * sizeof(char*));
	char *var_char1;
	char **var_char2;
	// Checking the var_char
	if(!var_char)
	{
		printf("Exception occurred : get_break_sent(). Program Stopped !!!!\n");
		exit(EXIT_FAILURE);
	}
	// Splitting using delimiters
	var_char1 = strtok(var1, DELIMITERS);
	// Adding to array
	while(var_char1!=NULL)
	{
		var_char[cursor] = var_char1;
		cursor++;
		if(cursor >= size)
		{
			size = size + SENT_BREAK_SIZE;
			var_char2 = var_char;
			var_char = realloc(var_char, size * sizeof(char*));
			if (!var_char)
			{
				free(var_char2);
				printf("Exception occurred : get_break_sent(). Program Stopped !!!!\n");
				exit(EXIT_FAILURE);
			}
		}
		var_char1 = strtok(NULL, DELIMITERS);
	}
	var_char[cursor] = NULL;
	return var_char;
}

// Start of the get_sent() function
// Creates a char array of sentence typed
char *get_sent(void)
{
	// Declaring the variables
	int size = SENT_SIZE;
	int cursor = 0;
	char *arr = malloc(sizeof(char) * size);
	int cint;
	// Checkking the arr
	if(!arr)
	{
		printf("Exception occurred : get_sent(). Program Stopped !!!!");
		exit(EXIT_FAILURE);
	}
	// Looping through sentence to read charectors
	while(1)
	{
		cint = getchar();
		// Checking for end of the sentence
		if (cint == EOF || cint == '\n') 
		{
			arr[cursor] = '\0';
			  return arr;
		}
		else
		{
			arr[cursor] = cint;
		}
		cursor++;
	// Adding more memory if required
		if (cursor >= size)
		{
		  size = size+SENT_SIZE;
		  arr = realloc(arr, size);
		  if (!arr)
		  {
			printf("Exception occurred : get_sent(). Program Stopped !!!!");
			exit(EXIT_FAILURE);
		  }
		}
	}
}

// Start of the startFunct() 
// This function get the inputs and starts the execution
void startFunct()
{
	// Declaring the variables
	char *var1;
	char **var2;
	int var_check;
	
	// Looping and waits for next command
	do
	{
		printf("%s $>",getlogin());
		var1 = get_sent();
		var2 = get_break_sent(var1);
		var_check = get_run(var2);
		
		free(var1);
		free(var2);
		
	}while(var_check);
}

// Start of the program here i.e main() function
int main(int argc, char **argv)
{
	// Creating the seperate function for modularity
	startFunct();
	// return of the main function
	return EXIT_SUCCESS;
}
