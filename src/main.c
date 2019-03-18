/*
 * main.c
 *
 *  Created on: Mar 17, 2019
 *      Author: Kashka
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"


int main (int argc, char* argv[]){
	Game* game = malloc(sizeof(Game));
	initializeBoard(game);
	printBoardHelp();
	Player* pX = malloc(sizeof(Player));
	Player* pO = malloc(sizeof(Player));
	initializePlayers(pX, pO);
	char playing = 'Y';

	while(playing == 'Y' || playing == 'y'){
		printBoard(game);
		printScore(pX, pO);
		int turn = firstPick();
		int choice;
		int check = -1;
		int round = 1;
		while(round){
			switch (turn){
			case 0:
				printf("Player X's Turn:\n");
				choice = getChoice(game);
				placeChoice(game, pX, choice);
				printf("\e[1;1H\e[2J");
				printBoard(game);
				check = checkIfWin(game, pX);
				if (check == 1){
					printf("X's Win!\n");
					pX->wins++;
					pO->losses++;
					clearBoard(game);
					round = 0;
					break;
				}
				else if (check == 2){
					printf("It's a tie!\n");
					pX->ties++;
					pO->ties++;
					clearBoard(game);
					round = 0;
					break;
				}
				turn++;
				break;

			case 1:
				printf("Player O's Turn:\n");
				choice = getChoice(game);
				placeChoice(game, pO, choice);
				printf("\e[1;1H\e[2J");
				printBoard(game);
				check = checkIfWin(game, pO);
				if (check == 1){
					printf("O's Win!\n");
					pO->wins++;
					pX->losses++;
					clearBoard(game);
					round = 0;
					break;
				}
				else if (check == 2){
					printf("It's a tie!\n");
					pX->ties++;
					pO->ties++;
					clearBoard(game);
					round = 0;
					break;
				}
				turn--;
				break;
			}
		}
		printf("Play again?(Y/N)\n");
		scanf("%s", &playing);
		printf("\e[1;1H\e[2J");
	}


}
