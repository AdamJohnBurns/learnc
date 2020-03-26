#include <stdio.h>
#include <ctype.h> // for isalpha() and isblank()
#include <string.h> // for strlen()

// forward declarations
// tells C you're using some functions later, without having to worry about
// the chicken/egg program of what to define first
int can_print_it (char ch);
void print_letters (char arg[], int len);

void print_arguments (int argc, char *argv[])
{
	int i = 0;

	for (i = 0; i < argc; i++) {
		int args_length = strlen(argv[i]);
		printf("Arg = %s, Args length = %d\n", argv[i], args_length);
		print_letters (argv[i], args_length);
	}
}

void print_letters (char arg[], int len) 
{
	int i = 0;

	//for (i = 0; arg[i] != '\0'; i++) {
	for (i = 0; i < len; i++) {
		char ch = arg[i];

		//if (can_print_it(ch)) {
		//if (isalpha(ch) || isblank(ch)) {
		if (isdigit(ch)) {
			printf("'%c' == %d  ", ch, ch);
		}
	}

	printf("\n\n");
}

int can_print_it (char ch)
{
	return isalpha(ch) || isblank(ch);
}

int main (int argc, char *argv[])
{
	printf("\n");
	print_arguments(argc, argv);
	printf("\n");
	return 0;
}
