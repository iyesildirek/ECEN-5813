/*========================================================================
** ring.h
** Circular buffer
** ECEN5813
**========================================================================*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#ifndef RING_H
#define RING_H

/****Function Prototypes****/

ring_t* init( int length );

/*Return 0 for success and -1 for failure*/
int insert( ring_t *ring, char data );
int rm( ring_t *ring, char *data );
/*Remove() renamed to rm() to avoid name issue*/

/* Entries should return the number of elements present in the circular buffer*/
/* The number of elements that are entered but not removed from the circular list*/
int entries( ring_t *ring );

#endif