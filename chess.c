#include "chess.h"


int main(){
	/**
		1. Show menu
		2. Enter player1 and player2 name
		3. Initialize game board
		4. Play
		5. Check for invalid moves
		6. Exit or finish game
	**/

	player player1;
	player player2;

	player1.color = 1;
	player2.color = 0;

	init(&player1);
	init(&player2);

	printBoard(player1, player2);
}