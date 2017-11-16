#include <stdio.h>

int main (int argc, char *argv[])
{
	int i = 0;

	printf("Number of arguments provided: %d.\n", argc);

	if (argc <= 0) {
		// this never fires, as the first arg is always the name of the compiled code
		printf("You don't have any arguments.\n");
	} else if (argc == 1) {
		printf("You only have one argument, which is: %s.\n", argv[0]);
	} else if (argc > 1 && argc < 4) {
		printf("Here's your arguments:\n");

		for (i = 0; i < argc; i++) {
			printf("%s", argv[i]);
		}

		printf("\n");
	} else {
		printf("You have too many arugments.\n");
	}

	return 0;
}
