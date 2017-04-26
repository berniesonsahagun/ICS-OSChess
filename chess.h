#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p{
	char name;
	int player;
	char coordinate[2]; 
}piece;

typedef struct user{
	char name[30];
	piece listOfPieces[16];
	int isTurn;
	int color;	// 0 - black, 1 - white
}player;

void init(player * p){
	int i;
	char name;
	char coordinate[2];

	if((*p).color == 1){

		for(i=0; i<8; i++){
			(*p).listOfPieces[i].player = 1;
			name = 'P';
			(*p).listOfPieces[i].name = name;
			sprintf(coordinate, "B%d", i+1);
			strcpy((*p).listOfPieces[i].coordinate, coordinate);
		}

		for(i=0; i<8; i++){
			sprintf(coordinate, "A%d", i+1);

			strcpy((*p).listOfPieces[i+8].coordinate, coordinate);
			(*p).listOfPieces[i+8].player = 1;

			if(i==0 || i==7){
				name = 'R';
			}else if(i==1 || i==6){
				name = 'N';
			}else if(i==2 || i==5){
				name = 'B';
			}else if(i==3){
				name = 'Q';
			}else{
				name = 'K';
			}

			(*p).listOfPieces[i+8].name = name;
		}

	}else{
		for(i=0; i<8; i++){
			(*p).listOfPieces[i].player = 2;
			name = 'p';
			(*p).listOfPieces[i].name = name;
			sprintf(coordinate, "G%d", i+1);
			strcpy((*p).listOfPieces[i].coordinate, coordinate);
		}

		for(i=0; i<8; i++){
			sprintf(coordinate, "H%d", i+1);
			strcpy((*p).listOfPieces[i+8].coordinate, coordinate);
			(*p).listOfPieces[i+8].player = 2;

			if(i==0 || i==7){
				name = 'r';
			}else if(i==1 || i==6){
				name = 'n';
			}else if(i==2 || i==5){
				name = 'b';
			}else if(i==3){
				name = 'q';
			}else{
				name = 'k';
			}

			(*p).listOfPieces[i+8].name = name;
		}
	}
}

int findPiece(player p, int x, int y){
	int i=0;
	int x_coord, y_coord;
	
	for(i=0; i<16; i++){
		switch(p.listOfPieces[i].coordinate[0]){
			case 'A':	x_coord = 0;
						break;
			case 'B':	x_coord = 1;
						break;
			case 'C':	x_coord = 2;
						break;
			case 'D':	x_coord = 3;
						break;
			case 'E':	x_coord = 4;
						break;
			case 'F':	x_coord = 5;
						break;
			case 'G':	x_coord = 6;
						break;
			case 'H':	x_coord = 7;
						break;
		}
		switch(p.listOfPieces[i].coordinate[1]){
			case '1':	y_coord = 0;
						break;
			case '2':	y_coord = 1;
						break;
			case '3':	y_coord = 2;
						break;
			case '4':	y_coord = 3;
						break;
			case '5':	y_coord = 4;
						break;
			case '6':	y_coord = 5;
						break;
			case '7':	y_coord = 6;
						break;
			case '8':	y_coord = 7;
						break;
		}
		if(x_coord == x-1 && y_coord == y-1){
			return i+1;
		}
	}

	return 0;
	
}

void printBoard(player player1, player player2){
	char board[8][8];
	int i, j;
	int index=0;

	for(i=0; i<9; i++){
		if(i==0)	printf("\t1\t2\t3\t4\t5\t6\t7\t8");
		else{
			for(j=0; j<9; j++){
				if(j==0){
					switch(i){
						case 1:	printf("A\t");
								break;
						case 2:	printf("B\t");
								break;
						case 3:	printf("C\t");
								break;
						case 4:	printf("D\t");
								break;
						case 5:	printf("E\t");
								break;
						case 6:	printf("F\t");
								break;
						case 7:	printf("G\t");
								break;
						case 8:	printf("H\t");
								break;
					}
				}
				else{
					if(index = findPiece(player1, i, j)){
						printf("%c\t", player1.listOfPieces[index-1].name);
					}else if(index = findPiece(player2, i, j)){
						printf("%c\t", player2.listOfPieces[index-1].name);
					}else{
						printf(" \t");
					}
				}
			}
		}
		printf("\n");
	}
}