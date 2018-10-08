/*
 * DeckOfCards.h
 *
 *  Created on: Mar 5, 2018
 *      Author: billliu
 */
#include <iostream>
#include <string>
#include "Card.h"

#ifndef DECKOFCARDS_H_
#define DECKOFCARDS_H_

using namespace std;

class DeckOfCards {
private:
	static const int SIZE_OF_DECK; //Number of cards in the deck
	static int currentCard; //Representing next card to deal
	Card *deck; //Array of card objects
public:
	DeckOfCards(); //Default Constructor
	virtual ~DeckOfCards(); //Default Destructor
	void shuffle(); //Shuffles cards in deck
	Card dealCard(); //Returns next card in deck
	bool moreCards(); //If there are any more cards to deal
	void printDeck(); //Print out deck in proper form
	
	int getCurrentCard();
};

#endif /* DECKOFCARDS_H_ */
