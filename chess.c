#include "chess.h"


int main(){
	player player1;
	player player2;
	piece board[8][8];
	int i,j;
	char playerMove[20];

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

	loadBoard(board, player1, player2);
	printBoard(board);

	while(1){
		if(player1.isTurn == 1 ? printf("Player 1's turn\n") : printf("Player 2's turn\n"))

		printf("Enter move: ");
		fgets(playerMove, 20, stdin);

		if(player1.isTurn == 1){
			while(move(board, &player1, &player2, playerMove)){
				printf("Enter move: ");
				fgets(playerMove, 20, stdin);
			}
		}else{
			while(move(board, &player2, &player1, playerMove)){
				printf("Enter move: ");
				fgets(playerMove, 20, stdin);
			}
		}

		player1.isTurn = player1.isTurn == 1 ? 0 : 1;
		player2.isTurn = player2.isTurn == 1 ? 0 : 1;

		loadBoard(board, player1, player2);
		printBoard(board);	
	}	
}