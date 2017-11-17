#include <stdio.h>

int main (int argc, char *argv[])
{
	int numbers[4] = { 0 }; // init first element to 0, default all other elements to \0
	// note that in C you CANNOT do = {}, you must provide at least one value
	// however you can do the above in C++
	char name[4] = { 'a' }; // first element is a, rest are \0

	// print them raw
	printf("RAW:\n");

	printf("numbers each: %d %d %d %d\n",
		numbers[0], numbers[1], numbers[2], numbers[3]);

	printf("name each: %c %c %c %c\n",
		name[0], name[1], name[2], name[3]);

	printf("name full: %s\n", name);

	// set up numbers
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;

	// set up name
	name[0] = 'Z';
	name[1] = 'e';
	name[2] = 'd';
	name[3] = '\0';

	// then print initialized
	printf("INITIALIZED:\n");


	printf("numbers each: %d %d %d %d\n",
		numbers[0], numbers[1], numbers[2], numbers[3]);

	printf("name each: %c %c %c %c\n",
		name[0], name[1], name[2], name[3]);

	printf("name full: %s\n", name);

	// another way to use name
	printf("ANOTHER WAY\n");
	char *another = "Zed";

	printf("another: %s\n", another);

	printf("another each: %c %c %c %c\n",
		another[0], another[1], another[2], another[3]);

	return 0;
}
