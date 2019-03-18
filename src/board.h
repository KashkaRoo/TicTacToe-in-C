/*
 * board.h
 *
 *  Created on: Mar 17, 2019
 *      Author: Kashka
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARDSIZE 9

typedef struct player Player;
typedef struct game Game;
struct player {
	char piece;
	int wins;
	int losses;
	int ties;
};

struct game {
	char board[BOARDSIZE];
	int taken;
};
void initializeBoard(Game* game);
void initializePlayers(Player* pX, Player* pY);
/** sets each board element to '-'**/
void clearBoard(Game* game);
/** check if board contains win **/
int checkIfWin(Game* game, Player* p);
/** add choice to board **/
void placeChoice(Game* game, Player* player, int choice);
/** choose who goes first **/
int firstPick();
/** prints current board **/
void printBoard(Game* game);
/** get user's choice **/
int getChoice(Game* game);
/** prints numbers in grid for user help **/
void printBoardHelp();
void printScore(Player* pX, Player* pO);
#endif /* BOARD_H_ */
