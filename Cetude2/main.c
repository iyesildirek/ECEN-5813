/*****************************************************************************
* Copyright (C) 2019 by Ismail Yesildirek
*
* Redistribution, modification or use of this software in source or binary
* forms is permitted as long as the files maintain this copyright. Users are
* permitted to modify this and use it to learn about the field of embedded
* software. Ismail Yesildirek and the University of Colorado are not
* liable for any misuse of this material.
*
*****************************************************************************/
/**
* @file main.c
* @brief This source file contains a c program to swap two string pointers and
* to reverse a string using pointer arithmetic.
*
* @author Ismail Yesildirek
* @date March 3 2019
* @version 1.2
*
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Function Prototypes */
void swap(char **str1, char **str2);
void reverse(char *src, size_t length);

int main(void)
{
	char *str1 = "Embedded System";
	char *str2 = "Principles of";
	// Call swap function here and pass "str1" and "str2" as a arguments
	swap(&str1, &str2);
	printf("Result of swap function -> %s %s\n", str1, str2);
	char src[] = "University of Colorado Boulder";
	// Call the reverse function here and pass "src" variable as an argument
	reverse(&src, strlen(src));
	printf("Result of reverse function -> %s\n", src);
	return 0;
}

void swap(char **str1, char **str2)
{
	// insert your code here
	printf("swap function()\n");
	printf("Prior to the swap function -> %s %s\n", *str1, *str2);
	char *temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void reverse(char *src, size_t length)
{
	// insert your code here
	printf("\n-----------------------------------------------------\n");
	printf("\nreverse function()\n");
	printf("Prior to the reverse function -> %s\n", src);
	char temp; 
	char *end = src + length-1; 

	/* 
	* For loop to move pointers towards the middle by a step 
	* and repeat swap operation above.
	*/

	for (int i = 0; i < (length / 2)-1; i++)
	{
		temp = *src;
		*src = *end;
		*end = temp;
		src++;
		end--;		
	}
}