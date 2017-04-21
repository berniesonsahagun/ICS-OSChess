#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p{
	char name[10];
	int player;
	int points; 
}piece;

typedef struct user{
	char name[30];
	piece listOfPieces[16];
	int points;
}player;