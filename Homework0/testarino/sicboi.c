#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/utsname.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <string.h>

#include <pwd.h>

//#include <math.h>

//#include "testdefs.h"


/*
#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define MAXLENGTH 128
*/


/*
	Super Inefficient Checkfiles with Basic Output and Input
	                      (SIC BOI!)

	To use the SIC BOI:
	  replace the text in var 't' with what you want in your test file.
	  replace the first argument to open, below, with what you want
	   your testfile name to be.

	  .. do not duplicate any of the coding here. This is a quick,
	 dumb, inefficient and unsafe block of code that I popped together
	 quickly to generate some test files.
*/

int main( int argc, char* argv[])
{
	//... no error checking for maximal cool!
	// ... just do it right the first time, every time... woooo!


	char t[] = "text to write";
	int i = 0;
 	int max = strlen(t);

	int fd = open("./filename", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);

	while( i < max)
	{
		write( fd, t+i, 1);
		++i;
	}


	close(fd);


	return 0;
}


