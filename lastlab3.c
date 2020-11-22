#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
	int pipefds[2];
	char *num;
	char buffer[5];
	
	if(pipe(pipefds) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid_t pid = fork();

	if(pid == 0){
	num = "1216\0";
	close(pipefds[0]);
	write(pipefds[1], num, 5);

	printf("Enter your number:\n");
	sleep(1);
	printf("Generating your num in child and sending to parent. .\n");
	sleep(2);
	exit(EXIT_SUCCESS);
}

	if(pid > 0) {
		wait(NULL);
		close(pipefds[1]);
		read(pipefds[0], buffer, 5);
		close(pipefds[0]);

		printf("Parent receive num '%s'\n", buffer);
	}

	return EXIT_SUCCESS;
}

			close(pipefds[0]);
			write(pipefds[1], num, NUM_LENGTH + 1);
	
			printf("Enter your number: ", );
			sleep(NUM_WAIT_INTERVAL);
			printf("%s\n", );
			sleep(NUM_WAIT_INTERVAL);
			exit(EXIT_SUCCESS);
	}

	if(pid > 0){
		wait(NULL);

		close(pipefds[1]);
		read(pipefds[0], buffer, NUM_LENGTH + 1);
		close(pipefds[0]);
		printf("'%s' is a prime number.\n\n", buffer);
	}
	}

	return EXIT_SUCCESS;
}
