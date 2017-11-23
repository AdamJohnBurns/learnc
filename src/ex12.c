#include <stdio.h>

int main (int argc, char *argv[])
{
	printf("\n");

	int areas[] = { 10, 12, 13, 14, 20 };
	areas[0] = 100;
	
	// to C, both the below ways of making an array are identical
	char name[] = "Zed"; // note this is 4 bytes long, because of the terminating /0
	char full_name[] = {
		'Z','e','d',
		' ','A','.',' ',
		'S','h','a','w','\0'
	};	

	name[0] = 'T'; // chars need to use '. using " means a string, which inserts the /0
	full_name[0] = 'T';

	// areas[0] is an int, and full_name[4] is a char, so it converts the int to a charcode
	full_name[4] = areas[0];

	//note: on some system architectures %u might be needed instead of
	// %ld, since it will use unsigned ints

	printf("sizeof() = \"How big is this thing in bytes?\"\n\n");

	// note because different system architectures might have differently sized variables
	// (eg on a 32/64 bit system), best to always use sizeof(int) instead of hard
	// coding magic numbers
	// for example, back on 16 bit, ints were 2 bytes
	// on 32 its (usually)  4
	// on 64 its often 4 as well
	printf("The size of an int: %ld\n", sizeof(int));
	printf("The size of areas (int[]): %ld\n", sizeof(areas));
	printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));
	printf("The first area is %d, the 2nd %d.\n\n", areas[0], areas[2]);

	printf("The size of a char: %ld\n", sizeof(char));
	printf("The size of name (char[]): %ld\n", sizeof(name));
	printf("The number of chars: %ld\n\n", sizeof(name) / sizeof(char));

	printf("The size of full_name(char[]): %ld\n", sizeof(full_name));
	printf("The number of chars: %ld\n", sizeof(full_name) / sizeof(char));

	// the \ are escape characters to output " in the string
	printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

	printf("\n");
	return 0;
}
