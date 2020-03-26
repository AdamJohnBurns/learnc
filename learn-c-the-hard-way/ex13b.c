#include <stdio.h>
#include <stdlib.h> // for system()

int main (int argc, char *argv[]) {
	// writing a program that runs my own program... mindblown.gif
	system("./ex13 my test args");

	// system() is in general not a good function, as while the function itself is
	// cross platform, different platforms might require different commands
	// eg ls on osx vs dir on win

	return 0;
}
