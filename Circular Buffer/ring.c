/*========================================================================
** Circular buffer
** ECEN5813
**========================================================================*/

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
* @file ring.c
* @brief This source file contains a c program to implement a circular ring buffer.
*
* @author Ismail Yesildirek
* @date March 18 2019
* @version 1.0
*
*/

/*
* Reference "Implementing Circular Buffer in C" for implementation strategy. 
* https://embedjournal.com/implementing-circular-buffer-embedded-c/
*/

typedef struct
{
	char *Buffer;
	int Length; /*Max size*/
	int Ini; /*head*/
	int Outi; /*tail*/
	int count; /*# of char buffer*/
	char circularQueue[10];
} ring_t;

/****Header Files****/
#include "ring.h"

/****Global Variables****/
#define TRUE 1
#define FALSE 0
const static int bufferSize = 10;
char data[10] = { "          " };
int queueFull = 0;

/****Main Code****/
int main(void)
{
	ring_t *buffer_struct = malloc(sizeof(ring_t));
	int insertStatus, rmStatus, entryStatus, userInput;
	int insertFlag = 0;
	char charInput;

	/*Initialize buffer and set length*/
	buffer_struct = init(bufferSize);

	/*Add data to empty buffer*/
	if ((buffer_struct != NULL) || (buffer_struct->Buffer != NULL) || (buffer_struct->circularQueue != NULL) || \
		(buffer_struct->count != NULL) || (buffer_struct->Ini != NULL) || (buffer_struct->Length != NULL) || \
		(buffer_struct->Outi != NULL))
	{
		printf("This program creates a circular buffer of size %d\n", bufferSize);
		while (1)
		{
			printf("Please enter 0 to insert, 1 to remove, 2 to check the number of entries in the circular buffer or 3 to exit\n");
			scanf(" %d", &userInput);
			if (userInput == 0)
			{
				printf("Please enter a char for the circular buffer: ");
				scanf(" %c", &charInput);
				//insertStatus = insert(buffer_struct, data[0]);
				insertStatus = insert(buffer_struct, charInput);
			//	printf("Char *buffer is: %s",buffer_struct->Buffer);
			}
			else if (userInput == 1)
			{
				rmStatus = rm(buffer_struct, &(buffer_struct->Buffer));
			}
			else if (userInput == 2)
			{
				entryStatus = entries(buffer_struct);
				printf("The number of entries are %d\n", entryStatus);
			}
			else if (userInput == 3)
			{
				printf("Good Bye!\n");
				return 0;
			}
			else
			{
				printf("Enter a valid command (0, 1, or 2\n");
			}
			//	printf("The address of buffre_struct is: %x\n", &buffer_struct);
		}
	}
	else
	{
		printf("NULL pointer provided\n");
	}
	return 0;
}

/****Function Definitions****/

ring_t* init(int length)
{
	ring_t *temp = malloc(sizeof(ring_t));
	temp->Length = length;
	temp->Buffer = "a  ";
	temp->Ini = 0;
	temp->Outi = 0;
	temp->count = 0;
	temp->circularQueue[length];
	return temp;
}

int insert(ring_t *ring, char data)
{
	if ((ring != NULL) || (ring->Buffer != NULL) || (ring->circularQueue != NULL) || \
		(ring->count != NULL) || (ring->Ini != NULL) || (ring->Length != NULL) || \
		(ring->Outi != NULL))
	{
		/*Next head index*/
		int nextIndex = ring->Ini + 1;

		/*Check if buffer is full*/
		if (nextIndex == ring->Outi)
		{
		printf("Circular Buffer is Full. Remove an item with the rm()\n");
		return -1;
		}

		/*Check if head index needs to circle back in buffer*/
		else if (nextIndex >= ring->Length)
		{
			nextIndex = 0;
		}

		else
		{
			//do nothing
		}
		ring->circularQueue[ring->Ini] = data; /*Add data to queue position Ini*/
		ring->count++;	/*number of insert()*/
		ring->Ini++; /*increment queue index*/
		return 0;
}
	else
	{
		printf("NULL pointer provided\n");
		return -1;
	}
}

int rm(ring_t *ring, char *data)
{
	if ((ring != NULL) || (ring->Buffer != NULL) || (ring->circularQueue != NULL) || \
		(ring->count != NULL) || (ring->Ini != NULL) || (ring->Length != NULL) || \
		(ring->Outi != NULL))
	{
		/*Next tail index*/
		int nextIndex = ring->Outi + 1;
		
		/*Check if buffer is empty*/
		if (ring->Ini == ring->Outi)
		{
			printf("Circular Buffer is Empty. Add an item with the insert()\n");
			return -1;
		}

		/*Check if tail index needs to circle back in buffer*/
		else if (nextIndex >= ring->Length)
		{
			nextIndex = 0;
		}
		else
		{
			//do nothing
		}

		/*Read char and store in *Buffer prior to clearing buffer[Ouit]*/
		*data = ring->circularQueue[ring->Outi];
		ring->circularQueue[ring->Outi] = '0'; /*clear buffer*/
		ring->Outi++;
		ring->count--;	/*Reduce number of insert()*/
		return 0;
	}
	else
	{
		printf("NULL pointer provided\n");
		return -1;
	}
}

int entries(ring_t *ring)
{
	if ((ring != NULL) || (ring->Buffer != NULL) || (ring->circularQueue != NULL) || \
		(ring->count != NULL) || (ring->Ini != NULL) || (ring->Length != NULL) || \
		(ring->Outi != NULL))
	{
		int temp;
		temp = ring->count;
		return temp;
	}
	else
	{
		printf("NULL pointer provided\n");
		return -1;
	}
}
