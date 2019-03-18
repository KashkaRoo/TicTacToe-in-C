/*
 * board.c
 *
 *  Created on: Mar 17, 2019
 *      Author: Kashka
 */
#include "board.h"

int randInRange (int min, int max) {
   // rand() returns a pseudo-random integer between 0 and RAND_MAX
   int r = rand();
   // we can use the value to get an integer within the range
   return min + r % (max - min + 1);
}

void printBoardHelp(){
	printf("Board Layout\n");
	printf(" 1 | 2 | 3 \n----------- \n 4 | 5 | 6 \n----------- \n 7 | 8 | 9 \n");
	printf("***********\n");
}

void initializePlayers(Player* pX, Player* pO){
	pX->losses = 0;
	pX->wins = 0;
	pX->ties = 0;
	pX->piece = 'X';
	pO->losses = 0;
	pO->wins = 0;
	pO->ties = 0;
	pO->piece = 'O';
}
/** sets each board element to '-'**/
void clearBoard(Game* game){
	int i;
	for (i = 0; i < BOARDSIZE; i++){
		game->board[i] = '-';
	}
	game->taken = 0;
}
void initializeBoard(Game* game){
	clearBoard(game);
	game->taken = 0;
}
/** check if board contains win returns 1 if win detected, 0 if valid game still in play, 2 if stale mate**/
int checkIfWin(Game* game, Player* p){
	/** EXPAND: make good for more board sizes? **/
	int i;
	//check row
	for (i=0; i <=7; i+=3){
		if((game->board[i] == p->piece) && (game->board[i+1] == p->piece) && (game->board[i+2] == p->piece)){
			return 1;
		}
	}
	//check column
	for (i=0; i <=2; i++){
		if((game->board[i] == p->piece) && (game->board[i+3] == p->piece) && (game->board[i+6] == p->piece)){
			return 1;
		}
	}
	//check diagonal
	if((game->board[0] == p->piece) && (game->board[4] == p->piece) && (game->board[8] == p->piece)){
		return 1;
	}
	if((game->board[2] == p->piece) && (game->board[4] == p->piece) && (game->board[6] == p->piece)){
		return 1;
	}
	//check stale mate
	if(game->taken == BOARDSIZE){
		return 2;
	}

	return 0;
}
/** add choice to board **/
void placeChoice(Game* game, Player* player, int choice){
	game->board[choice - 1] = player->piece;
	game->taken++;

}
/** choose who goes first **/
int firstPick(){
	srand((unsigned int) time(NULL));
	int first = randInRange (0, 1);
	return first;
}
/** prints current board **/
void printBoard(Game* game){
	printf(" %c | %c | %c \n----------- \n %c | %c | %c \n----------- \n %c | %c | %c \n", game->board[0], game->board[1], game->board[2],
															game->board[3], game->board[4], game->board[5],
															game->board[6], game->board[7], game->board[8]);
}

int getChoice(Game* game){
	int choice = 0;
	while(!choice){
		printf("Enter spot to place your piece: ");
		if (scanf("%d", &choice) != 1 || choice < 1 || choice > BOARDSIZE + 1){
			scanf("%*s");
			printf("INVALID SPOT: Try again, enter 1-9.\n");
			choice =0;
			//EXPAND: print board options
		}
		else if (game->board[choice - 1] != '-'){
			printf("SPOT ALREADY TAKEN: Try again.\n");
			choice = 0;
		}
	}
	return choice;
}
void printScore(Player* pX, Player* pO){
	printf("X Wins: %d Losses: %d Ties %d \n", pX->wins, pX->losses, pX->ties);
	printf("O Wins: %d Losses: %d Ties %d \n", pO->wins, pO->losses, pO->ties);
}


