#include "chess.h"


int main(){
	player player1;
	player player2;
	piece board[8][8];
	int i,j;
	char playerMove[20] = "B1-C1";

	player1.color = 1;
	player2.color = 0;
	
	init(&player1);
	init(&player2);

	//initialize board to empty spaces
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			board[i][j].player = 0;
			board[i][j].name = ' ';
		}
	}

	move(player1, playerMove);
}