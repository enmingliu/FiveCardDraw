/*
 * DeckOfCards.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: billliu
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string> 
#include <sstream>
#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "DeckOfCards.h"
#include "Card.h"

const int DeckOfCards::SIZE_OF_DECK = 52;

int DeckOfCards::currentCard = 0;

DeckOfCards::DeckOfCards() { //Default Constructor
	deck = new Card[SIZE_OF_DECK];
  for(int i = 0; i < SIZE_OF_DECK; i++) {
    deck[i].setFace(i/4);
    deck[i].setSuit(i%4);
	}
}

DeckOfCards::~DeckOfCards() { //Default Destructor
	delete[] deck;
}

void DeckOfCards::shuffle() { //Shuffles cards in deck
  srand(time(NULL));
  int random = 1;
  
  int tempFace = 0;
  int tempSuit = 0;
  
  for(int i = 0; i < SIZE_OF_DECK; i++) {
    random = rand() % (52) + 1;
    
    tempFace = deck[random].getFace();
    deck[random].setFace(deck[i].getFace());
    deck[i].setFace(tempFace);
    
    tempSuit = deck[random].getSuit();
    deck[random].setSuit(deck[i].getSuit());
    deck[i].setSuit(tempSuit);
  }
}

Card DeckOfCards::dealCard() { //Returns next card in deck
  currentCard++; 
  return deck[currentCard-1];
}

int DeckOfCards::getCurrentCard() {
  return currentCard;
}

bool DeckOfCards::moreCards() { //If there are any more cards to deal
  if (currentCard > SIZE_OF_DECK) {
    return false;
  }
  return true;
}

void DeckOfCards::printDeck() { //Print out deck in proper form
	for (int i = 0; i < SIZE_OF_DECK; i++) {
		cout << deck[i].toString() << endl;
	}
	cout << endl;
}

