#include <stdio.h>

int main (int argc, char *argv[])
{
	printf("\n");

	int i = 0;

	if (argc <= 1) {
		printf("No arguments given!\n");
	}

	argv[1] = "edited!";

	// loop through arguments
	// arg[1] is always the name of the program
	for (i = 0; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}

	// NULL is a macro "#define NULL (void *)0"
	// which is used for comparing if a pointer is a null pointer
	// note a null character '\0' is different
	char *states[] = { "NSW", NULL, "TAS" };
	int num_states = 3;

	for (i = 0; i < num_states; i++) {
		printf("state %d: %s\n", i, states[i]);
	}

	printf("\n");

	return 0;
}
