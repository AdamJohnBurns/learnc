#include <stdio.h>

int main (int argc, char *argv[])
{
	int numbers[4] = { 0 }; // init first element to 0, default all other elements to \0
	// (which is 0 numerically, but a nul character)
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
	// note that C doesn't see a difference between a string and a char array
	name[0] = 'Z';
	name[1] = 'e';
	name[2] = 'd';
	name[3] = '\0'; // FORGETTING THIS AT THE END OF STRINGS IS A MAJOR CAUSE OF BUGS
	// the requirement of C strings to end with \0 makes them very fiddly and often
	// not worth using

	// then print initialized
	printf("INITIALIZED:\n");


	printf("numbers each: %d %d %d %d\n",
		numbers[0], numbers[1], numbers[2], numbers[3]);

	printf("name each: %c %c %c %c\n",
		name[0], name[1], name[2], name[3]);

	printf("name full: %s\n", name);

	// another way to use name
	printf("ANOTHER WAY\n");

	// this is the best practise way to use strings
	char *another = "Two";

	printf("another: %s\n", another);

	printf("another each: %c %c %c %c\n",
		another[0], another[1], another[2], another[3]);

	// a char is 1 byte
	// an int is 4 bytes (standard signed)
	char fakeInt[4] = {'1','2','3','4'};

	fakeInt[0] = 5;
	fakeInt[1] = 0;
	fakeInt[2] = 0;
	fakeInt[3] = 0;

	printf("fakeInt (string) = %s, fakeInt (int) = %d\n", fakeInt, (int)fakeInt);

	return 0;
}
