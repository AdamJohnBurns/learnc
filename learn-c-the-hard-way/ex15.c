#include <stdio.h>

void render_names_1 (char **firstName);
void render_names_2 (char **firstName);
void render_names_2_reversed (char **lastName);

int main2 (int argc, char *argv[])
{
	printf("\n");

	// create arrays
	int ages[] = { 23, 43, 12, 89, 2};
	char *names[] = {
		"Alannlongnametesttttttt", "Frank", "Mary", "John", "lisa"
	};

	// safely (and in a cross platform way) get size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	// first way using indexing
	for (i = 0; i < count; i++) {
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}
	printf("\n---\n\n");

	// set pointers to start of the arrays
	int *cur_age = ages; // create pointer that points at ages

	char **cur_name = names; // create a pointer that points at names.
	// names is two dimensional (as its an array of strings), so we need **
	// because it's already a pointer - we need a pointer to a -pointer to a char-

	// second way using pointers
	for (i = 0; i < count; i++) {
		printf("%s is %d years old.\n", 
			*(cur_name + i), // this is the same as name[i] - adding i offsets the pointer
			*(cur_age + i));
	}
	printf("\n---\n\n");

	// third way, pointers are just arrays
	// the synatax to access an element of an array is the same for pointers and arrays, as below
	for (i = 0; i < count; i++) {
		printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
	}
	printf("\n---\n\n");

	// fourth way with pointers in complex way
	for (cur_name = names, cur_age = ages; // initialize pointers to begining of arrays
		(cur_age - ages) < count; // pointer arithmatic, compare distance of
					  // current age to start of array
		cur_name++, cur_age++) { // iterate the pointer as in the above array style
					 // they now point to the next item in the array

		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}

	printf("\n---\n\n");

	// reverse of fourth
	cur_name = names;
	printf("val = %s\n", *(cur_name + count - 1)); // test to get the last in list

	for (int offset = count - 1;
		 offset >= 0;
		 offset--) {
		printf("%s lived\n", *(cur_name + offset));
	}

	printf("\n---\n\n");

	// using a function with a while loop
	render_names_1(names);
	render_names_2(names);
    int end = sizeof(names) / sizeof(names[0]) - 1;
	render_names_2_reversed(names + end);

	printf("\n");

	// C sees your computer as a fluid set of bytes
	// a pointer points to a memory address where something is stored, and has a type
	// specifier so it knows the size of it (eg where the data ends)
	// pointers give you direct access to raw blocks of memory
	// pointer arithmatic allows accessing the next address in a sequence (eg an array)

	// pointers don't really need to be used for performance anymore. for most things
	// arrays should be used

	// pointers and arrays can use the same synatax, but they're not the same thing. C
	// just allows you to interact with them in similar ways.

	// *my_ptr // value of whatever my_ptr points at
	// *(my_ptr+1) // value of the next item 
	// &my_ptr // address of the thing
	// my_ptr++ // increment pointer ot next address



	// breaking it
	// cur_name = names;
	
	return 0;
}

void render_names_1 (char **firstName)
{

	while (*firstName != NULL) {
		printf("render_names_1(): %s\n", *firstName);
		firstName++;
	}
}
 
void render_names_2 (char **firstName)
{
	do {
		printf("render_names_2(): %s\n", *firstName);
		firstName++;
	} while (*firstName != NULL);
}

void render_names_2_reversed (char **lastName)
{
     do {
        printf("render_names_2_reversed(): %s\n", *lastName);
         lastName--;
     } while (*lastName != NULL);
}
