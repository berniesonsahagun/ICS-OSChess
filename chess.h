#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p{
	char name;
	int player;
	char coordinate[2];
	int isMoved; 
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

void translateCoordinate(char coordinate[2], int * x, int * y){
	switch(coordinate[0]){
			case 'A':	*x = 0;
						break;
			case 'B':	*x = 1;
						break;
			case 'C':	*x = 2;
						break;
			case 'D':	*x = 3;
						break;
			case 'E':	*x = 4;
						break;
			case 'F':	*x = 5;
						break;
			case 'G':	*x = 6;
						break;
			case 'H':	*x = 7;
						break;
		}
	switch(coordinate[1]){
		case '1':	*y = 0;
					break;
		case '2':	*y = 1;
					break;
		case '3':	*y = 2;
					break;
		case '4':	*y = 3;
					break;
		case '5':	*y = 4;
					break;
		case '6':	*y = 5;
					break;
		case '7':	*y = 6;
					break;
		case '8':	*y = 7;
					break;
	}
}

int findPiece(player p, int x, int y){
	int i=0;
	int x_coord, y_coord;
	
	for(i=0; i<16; i++){
		translateCoordinate(p.listOfPieces[i].coordinate, &x_coord, &y_coord);
		if(x_coord == x && y_coord == y){
			if(i==0)	return -1;
			return i;
		}
	}

	return 0;
	
}

void printBoard(piece board[8][8]){
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
					printf("%c\t", board[i-1][j-1].name);
				}
			}
		}
		printf("\n");
	}
}

void loadBoard(piece board[8][8], player player1, player player2){
	int i,j;
	int index;

	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			if(index = findPiece(player1, i, j)){
				if(index == -1)	index += 1;
				board[i][j].name = player1.listOfPieces[index].name;
				board[i][j].player = player1.listOfPieces[index].player;
				strcpy(board[i][j].coordinate, player1.listOfPieces[index].coordinate);

			}else if(index = findPiece(player2, i, j)){
				if(index == -1)	index += 1;
				board[i][j].name = player2.listOfPieces[index].name;
				board[i][j].player = player2.listOfPieces[index].player;
				strcpy(board[i][j].coordinate, player2.listOfPieces[index].coordinate);
			}	
		}
	}
}

void move(player p, char * move){
	const char s[2] = "-";
	char *token;
	int xtoMove, ytoMove, index;
	int xtoGo, ytoGo;
	piece toMove;
	
	token = strtok(move, s);
	translateCoordinate(token, &xtoMove, &ytoMove);

	token = strtok(NULL, s);
	translateCoordinate(token, &xtoGo, &ytoGo);

	if(xtoMove == xtoGo && ytoMove == ytoGo)	return;

	if(index = findPiece(p, xtoMove, ytoMove)){
		if(index == -1)	index += 1;
		toMove = p.listOfPieces[index];

		if(toMove.name == 'K' || toMove.name == 'k'){
			if(abs(xtoMove - xtoGo) <= 1 && abs(ytoMove - ytoGo) <= 1){
				//valid
			}else{
				//invalid
			}
		}else if(toMove.name == 'Q' || toMove.name == 'q'){
			if(xtoMove == xtoGo || ytoMove == ytoGo || abs(xtoMove - xtoGo) == abs(ytoMove - ytoGo)){
				//valid
			}else{
				//invalid
			}
		}else if(toMove.name == 'R' || toMove.name == 'r'){
			if(xtoMove == xtoGo || ytoMove == ytoGo){
				//valid
			}else{
				//invalid
			}
		}else if(toMove.name == 'B' || toMove.name == 'b'){
			if(abs(xtoMove - xtoGo) == abs(ytoMove - ytoGo)){
				//valid
			}else{
				//invalid
			}
		}else if(toMove.name == 'N' || toMove.name == 'n'){
			if((abs(xtoMove - xtoGo) == 2 && abs(ytoMove - ytoGo) == 1) || (abs(xtoMove - xtoGo) == 1 && abs(ytoMove - ytoGo) == 2)){
				//valid
			}else{
				//invalid
			}
		}else{
			if(p.color == 1){
				if(){
					//valid
				}else{
					//invalid
				}
			}else{

			}
		}

	}else{
		printf("Invalid move");
	}
}