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

int absoluteVal(int num){
	return num < 0 ? (num * -1) : num;
}

void init(player * p){
	int i;
	char name;
	char coordinate[2];

	if((*p).color == 1){
		(*p).isTurn = 1;
		for(i=0; i<8; i++){
			(*p).listOfPieces[i].player = 1;
			(*p).listOfPieces[i].isMoved = 0;
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
		(*p).isTurn = 0;
		for(i=0; i<8; i++){
			(*p).listOfPieces[i].player = 2;
			(*p).listOfPieces[i].isMoved = 0;
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

void setCoordinate(piece * p, int x, int y){
	switch(x){
		case -1:	(*p).coordinate[0] = '0';
					break; 
		case 1: (*p).coordinate[0] = 'A';
				break;
		case 2: (*p).coordinate[0] = 'B';
				break;
		case 3: (*p).coordinate[0] = 'C';
				break;
		case 4: (*p).coordinate[0] = 'D';
				break;
		case 5: (*p).coordinate[0] = 'E';
				break;
		case 6: (*p).coordinate[0] = 'F';
				break;
		case 7: (*p).coordinate[0] = 'G';
				break;
		case 8: (*p).coordinate[0] = 'H';
				break;		
	}
	switch(y){
		case -1:	(*p).coordinate[0] = '0';
					break;
		case 1: (*p).coordinate[1] = '1';
				break;
		case 2: (*p).coordinate[1] = '2';
				break;
		case 3: (*p).coordinate[1] = '3';
				break;
		case 4: (*p).coordinate[1] = '4';
				break;
		case 5: (*p).coordinate[1] = '5';
				break;
		case 6: (*p).coordinate[1] = '6';
				break;
		case 7: (*p).coordinate[1] = '7';
				break;
		case 8: (*p).coordinate[1] = '8';
				break;		
	}
}

void translateCoordinate(char coordinate[2], int * x, int * y){
	switch(coordinate[0]){
			case '0':	*x = -1;
						break;
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
		case '0':	*x = -1;
					break;
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

void printPieces(player p){
	int i;
	for(i=0; i<16; i++){
		printf("Name: %c\t\t Coordinate: %s\n", p.listOfPieces[i].name, p.listOfPieces[i].coordinate);
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
			}else{
				board[i][j].name = ' ';
				board[i][j].player = 0;
				
			}
		}
	}
}

int isValid(piece board[8][8], player p, piece toMove, int xtoMove, int ytoMove, int xtoGo, int ytoGo){
	int index;
	int i, xstart, ystart, xiterator, yiterator;
	int isEnemy = board[xtoGo][ytoGo].player != 0 ? absoluteVal(board[xtoGo][ytoGo].player - toMove.player) : 0;

	if(xtoMove == xtoGo && ytoMove == ytoGo)	return 0;

	if(toMove.name == 'K' || toMove.name == 'k'){
		if(absoluteVal(xtoMove - xtoGo) <= 1 && absoluteVal(ytoMove - ytoGo) <= 1){
			if(board[xtoGo][ytoGo].name == ' ' || isEnemy){
				return 1;
			}
		}
		return 0;
	}else if(toMove.name == 'Q' || toMove.name == 'q'){
		if(xtoMove == xtoGo){
			yiterator = ytoGo > ytoMove ? 1 : -1;
			for(ystart = ytoMove+1; ystart != ytoGo; ystart += yiterator){
				if(board[xtoMove][ystart].name != ' ')	return 0;
			}
		}else if(ytoMove == ytoGo){
			xiterator = xtoGo > xtoMove ? 1 : -1;
			for(xstart = xtoMove+1; xstart != xtoGo; xstart += xiterator){
				if(board[xstart][ytoMove].name != ' ')	return 0;
			}
		}else if(absoluteVal(xtoMove - xtoGo) == absoluteVal(ytoMove - ytoGo)){
			xiterator = xtoGo > xtoMove ? 1 : -1;
			yiterator = xtoGo > xtoMove ? 1 : -1;
			xstart = xtoMove+1;
			ystart = ytoMove+1;

			while(xstart != xtoGo && ystart != ytoGo){
				printf("%c\n",board[xstart][ystart]);
				if(board[xstart][ystart].name != ' ')	return 0;

				xstart += xiterator;
				ystart += yiterator;
			}
		}else{
			return 0;
		}

		if(board[xtoGo][ytoGo].name == ' ' || isEnemy)	return 1;
	}else if(toMove.name == 'R' || toMove.name == 'r'){
		if(xtoMove == xtoGo){
			yiterator = ytoGo > ytoMove ? 1 : -1;
			for(ystart = ytoMove+1; ystart != ytoGo; ystart += yiterator){
				if(board[xtoMove][ystart].name != ' ')	return 0;
			}
		}else if(ytoMove == ytoGo){
			xiterator = xtoGo > xtoMove ? 1 : -1;
			for(xstart = xtoMove+1; xstart != xtoGo; xstart += xiterator){
				if(board[xstart][ytoMove].name != ' ')	return 0;
			}
		}else{
			return 0;
		}
		if(board[xtoGo][ytoGo].name == ' ' || isEnemy)	return 1;
	}else if(toMove.name == 'B' || toMove.name == 'b'){
		if(absoluteVal(xtoMove - xtoGo) == absoluteVal(ytoMove - ytoGo)){
			xiterator = xtoGo > xtoMove ? 1 : -1;
			yiterator = xtoGo > xtoMove ? 1 : -1;
			xstart = xtoMove+1;
			ystart = ytoMove+1;

			while(xstart != xtoGo && ystart != ytoGo){
				if(board[xstart][ystart].name != ' ')	return 0;

				xstart += xiterator;
				ystart += yiterator;
			}
		}else{
			return 0;
		}
		if(board[xtoGo][ytoGo].name == ' ' || isEnemy)	return 1;
	}else if(toMove.name == 'N' || toMove.name == 'n'){
		if((absoluteVal(xtoMove - xtoGo) == 2 && absoluteVal(ytoMove - ytoGo) == 1) || (absoluteVal(xtoMove - xtoGo) == 1 && absoluteVal(ytoMove - ytoGo) == 2)){
			if(board[xtoGo][ytoGo].name == ' ' || isEnemy)	return 1;
		}
		return 0;
	}else{
		if(p.color == 1){
			if(xtoGo - xtoMove == 1){
				if(board[xtoGo][ytoGo].name == ' ')	return 1;
			}else if(absoluteVal(ytoGo - ytoMove) == 1 && xtoGo - xtoMove == 1){
				if(isEnemy)	return 1;
			}else if(!toMove.isMoved){
				if(xtoGo - xtoMove == 2){
					if(board[xtoMove+1][ytoMove].name == ' ' && board[xtoGo][ytoGo].name == ' ')	return 1;
				}
			}
			return 0;
		}else{
			if(xtoGo - xtoMove == -1){
				if(board[xtoGo][ytoGo].name == ' ')	return 1;
			}else if(absoluteVal(ytoGo - ytoMove) == 1 && xtoGo - xtoMove == -1){
				if(isEnemy)	return 1;
			}else if(!toMove.isMoved){
				if(xtoGo - xtoMove == -2){
					if(board[xtoMove-1][ytoMove].name == ' ' && board[xtoGo][ytoGo].name == ' ')	return 1;
				}
			}
			return 0;
		}
	}
	
	return 0;
}

int isCheck(piece board[8][8], player p1, player p2){
	int i;
	int xtoMove, ytoMove, xtoGo, ytoGo;

	for(i=0; i<16; i++){
		if(p1.listOfPieces[i].name == 'K' || p1.listOfPieces[i].name == 'k')	{
			translateCoordinate(p1.listOfPieces[i].coordinate, &xtoGo, &ytoGo);
			break;
		}
	}

	for(i=0; i<16; i++){
		translateCoordinate(p2.listOfPieces[i].coordinate, &xtoMove, &ytoMove);
		if(isValid(board, p1, p2.listOfPieces[i], xtoMove, ytoMove, xtoGo, ytoGo)){
			return 1;
		}
	}

	return 0;
}

int isMate(piece board[8][8], player p1, player p2){
	int i,j,k;
	int xtoMove, ytoMove;
	for(i=0; i<16; i++){
		translateCoordinate(p1.listOfPieces[i].coordinate, &xtoMove, &ytoMove);

		for(j=0; j<8; j++){
			for(k=0; k<8; k++){
				if(isValid(board, p1, p1.listOfPieces[i], xtoMove, ytoMove, j, k)){
					setCoordinate(&((p1).listOfPieces[i]), j+1, k+1);
					loadBoard(board, p1, p2);
					if(!isCheck(board, p1, p2)){
						setCoordinate(&((p1).listOfPieces[i]), xtoMove+1, ytoMove+1);
						loadBoard(board, p1, p2);
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

int move(piece board[8][8], player *p, player *p2, char * move){
	const char s[2] = "-";
	char *token;
	int xtoMove, ytoMove, index;
	int xtoGo, ytoGo;
	piece toMove;
	
	token = strtok(move, s);
	translateCoordinate(token, &xtoMove, &ytoMove);

	token = strtok(NULL, s);
	translateCoordinate(token, &xtoGo, &ytoGo);

	if(index = findPiece((*p), xtoMove, ytoMove)){
		if(index == -1)	index += 1;
		toMove = (*p).listOfPieces[index];

		if(isValid(board, (*p), toMove, xtoMove, ytoMove, xtoGo, ytoGo)){
			setCoordinate(&((*p).listOfPieces[index]), xtoGo+1, ytoGo+1);
			loadBoard(board, *p, *p2);

			if(isMate(board, *p, *p2)){
				printf("Game Over! %s wins\n", (*p2).name);
				return -1;
			}

			if(isCheck(board, *p, *p2)){
				setCoordinate(&((*p).listOfPieces[index]), xtoMove+1, ytoMove+1);
				loadBoard(board, *p, *p2);
				printf("You are checked\n");
				return 0;
			}

			if(board[xtoGo][ytoGo].player != 0 && absoluteVal(board[xtoGo][ytoGo].player - toMove.player) == 1){
				index = findPiece((*p2), xtoGo, ytoGo);		
				setCoordinate(&((*p).listOfPieces[index]), -1, -1);
				(*p2).listOfPieces[index].name = 'X';
			};

			return 1;
		}
	}
	return 0;
	printf("Invalid move\n");
}