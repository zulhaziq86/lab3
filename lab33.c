#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

int main(void)
{

void sigint_handler(int sig);
char s[200];

if(signal(SIGINT, sigint_handler)==SIG_ERR){

	perror("signal");
	
	exit(1);

}

printf("Enter a string:\n");

if(fgets(s, 200,stdin)==NULL)

	perror("gets");
else

	printf("you entered:\n");

return 0;	

}

void sigint_handler(int sig)

{

printf("Jangan kacau saya!\n");

}
