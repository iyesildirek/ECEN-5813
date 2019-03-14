/*
Write a program that prints three random fortunes or quotes from an initialized array 
of at least three possible strings declared in the program. Your program can use the 
following C library function calls to randomize output:

Indicate in comments in your code how to modify the program to add additional possible 
response strings. Full credit is given for extensible solutions requiring only addition 
of new strings with no additional bookkeeping modifications.
*/

/****Header Files****/

#include<stdio.h>
#include<stdint.h> 
#include<string.h>

/****Global Variables****/


/****Function Prototypes****/



/****Main Code****/

int main()
{
	char *fortune[] = {"one", "two","three","four","five","six","seven","eight"};
	int length = sizeof(fortune) / sizeof(int);
	srand(time(NULL)); 
	/*seed the pseudo-random number generator*/
	for (int i = 0; i < 3; i++) {
		if (fortune == NULL)
		{
			printf("Null fortune provided");
		}
		int r = rand();
		/* generate a pseudo-random number, r,  in the range 0 to RAND_MAX inclusive.
		 * You may assume RAND_MAX is much greater than 3 and is less than or equal to
		 * the largest positive integer. */
		int randNum = r % length;
		char *temp[1] = { " " };
		*temp = *(fortune + randNum);
		printf("The random string[%d] is: %s from index: [%d]\n", i+1, *temp,randNum);
	}
	return 0;
}


/****Function Definitions****/



