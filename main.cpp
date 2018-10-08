/*
 * Dealer.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: billliu
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "Dealer.h"
#include "Card.h"
#include "DeckOfCards.h"

using namespace std;

const int SIZE_OF_HAND = 5;

Dealer::Dealer() {
	// TODO Auto-generated constructor stub

}

Dealer::~Dealer() {
	// TODO Auto-generated destructor stub
}

void dealHand(DeckOfCards &deck, Card hand[SIZE_OF_HAND]) { //or Card hand[SIZE_OF_HAND] Card *hand 
  for (int i = 0; i < SIZE_OF_HAND; i++) {
    hand[i] = deck.dealCard();
  }
}

void printHand(Card *hand) {
  for (int i = 0; i < SIZE_OF_HAND; i++) {
    cout << hand[i].toString() << endl;
  }
  cout << endl;
}

void sortHand(Card *hand) {
  int max;
  Card temp;
  
  for (int i = SIZE_OF_HAND - 1; i > 0; i--) {
    max = i;
    
    for (int j = 0; j < i; j++) {
      if (hand[j].getRank() > hand[max].getRank()) {
        max = j;
      }
    }
    
    temp = hand[i];
    hand[i] = hand[max];
    hand[max] = temp;
  }
}

string getHandValue(Card *hand, int *handRank, int *high) {
  bool ifFlush = false; 
  bool ifStraight = false;
  int count = 0;
  
  //Check for flush 
  ifFlush = true;
  for (int i = 0; i < SIZE_OF_HAND - 1; i++) {
    if (hand[i].getSuit() != hand[i+1].getSuit()) {
      ifFlush = false;
    }
  }
  
  //Check for straight 
  ifStraight = true;
  for (int j = 0; j < SIZE_OF_HAND - 1; j++) {
    if ((hand[j].getFace() + 1) != hand[j + 1].getFace()) {
      ifStraight = false;
    }
  }
  
  //Straight or royal flush 
  if (ifFlush && ifStraight) { 
    if (hand[SIZE_OF_HAND - 1].getFace() == 13) {
      *handRank = 1;
      *high = hand[SIZE_OF_HAND - 1].getFace();
      return "Royal Flush";
    }
    else {
      *handRank = 2;
      *high = hand[SIZE_OF_HAND - 1].getFace();
      return "Straight Flush";
    }
  }
  
  //Four of a kind
  else if (hand[0].getFace() == hand[1].getFace() && hand[1].getFace() == hand[2].getFace() && hand[2].getFace() == hand[3].getFace()) { //Check for four cards in a row 
    *handRank = 3;
    *high = hand[3].getFace();
    return "Four of a Kind";
  }
  else if (hand[1].getFace() == hand[2].getFace() && hand[2].getFace() == hand[3].getFace() && hand[3].getFace() == hand[4].getFace()) {
    *handRank = 3;
    *high = hand[4].getFace();
    return "Four of a Kind";
  }
  
  //Full house
  else if (hand[0].getFace() == hand[1].getFace() && hand[2].getFace() == hand[3].getFace() && hand[3].getFace() == hand[4].getFace()) { //Check if two cards and three cards are same
    *handRank = 4;
    *high = hand[4].getFace();
    return "Full House";
  }
  else if (hand[0].getFace() == hand[1].getFace() && hand[1].getFace() == hand[2].getFace() && hand[3].getFace() == hand[4].getFace()) {
    *handRank = 4;
    *high = hand[2].getFace();
    return "Full House";
  }
  
  //Flush 
  else if (ifFlush) {
    *handRank = 5;
    *high = hand[SIZE_OF_HAND - 1].getFace();
    return "Flush";
  }
  
  //Straight 
  else if (ifStraight) {
    *handRank = 6;
    *high = hand[SIZE_OF_HAND - 1].getFace();
    return "Straight";
  }
  
  //Three of a kind 
  else if (hand[0].getFace() == hand[1].getFace() && hand[1].getFace() == hand[2].getFace()) { //Check for three cards in a row 
    *handRank = 7;
    *high = hand[2].getFace();
    return "Three of a Kind";
  }
  else if (hand[1].getFace() == hand[2].getFace() && hand[2].getFace() == hand[3].getFace()) {
    *handRank = 7;
    *high = hand[3].getFace();
    return "Three of a Kind";
  }
  else if (hand[2].getFace() == hand[3].getFace() && hand[3].getFace() == hand[4].getFace()) {
    *handRank = 7;
    *high = hand[4].getFace();
    return "Three of a Kind";
  }
  
  //Two pair 
  else if (hand[0].getFace() == hand[1].getFace() && hand[2].getFace() == hand[3].getFace()) { //Check for two pairs anywhere
    *handRank = 8;
    *high = hand[3].getFace();
    return "Two Pair";
  }
  else if (hand[0].getFace() == hand[1].getFace() && hand[3].getFace() == hand[4].getFace()) {
    *handRank = 8;
    *high = hand[4].getFace();
    return "Two Pair";
  }
  else if (hand[1].getFace() == hand[2].getFace() && hand[3].getFace() == hand[4].getFace()) {
    *handRank = 8;
    *high = hand[4].getFace();
    return "Two Pair";
  }
  
  //Pair 
  else if (hand[0].getFace() == hand[1].getFace()) { //Check for any pairs
   *handRank = 9;
   *high = hand[1].getFace();
    return "Pair";
  }
  else if (hand[1].getFace() == hand[2].getFace()) {
    *handRank = 9;
    *high = hand[2].getFace();
    return "Pair";
  }
  else if (hand[2].getFace() == hand[3].getFace()) {
    *handRank = 9;
    *high = hand[3].getFace();
    return "Pair";
  }
  else if (hand[3].getFace() == hand[4].getFace()) {
    *handRank = 9;
    *high = hand[4].getFace();
    return "Pair";
  }
  
  //High card 
  else {
    *handRank = 10;
    *high = hand[SIZE_OF_HAND - 1].getFace();
    return "High Card";
  }
}

string getWinner(Card *playerHand, Card *computerHand, int *playerRank, int *computerRank, int *playerHighest, int *computerHighest) {
  if (*playerRank < *computerRank) { //Normally, if anyone has a higher hand rank numerical value, they win
    return "The player has won with a " + getHandValue(playerHand, playerRank, playerHighest) + ", beating a " + getHandValue(computerHand, computerRank, computerHighest) + "!";
  }
  else if (*playerRank > *computerRank) { //getSFace???
    return "The computer has won with a " + getHandValue(computerHand, computerRank, computerHighest) + ", beating a " + getHandValue(playerHand, playerRank, playerHighest) + "!";
  }
  else { //However, if they have the same type of hand, the rank of the cards themselves have to be compared, apart from the ones without ties 
    if (*playerHighest > *computerHighest) {
      return "Both the player and the computer have a " + getHandValue(playerHand, playerRank, playerHighest) + ", but the player wins with a " + playerHand[0].getSFace(*playerHighest) + ", beating a " + playerHand[0].getSFace(*computerHighest) + "!";
    }
    else if (*playerHighest < *computerHighest) {
      return "Both the player and the computer have a " + getHandValue(playerHand, playerRank, playerHighest) + ", but the computer wins with a " + playerHand[0].getSFace(*computerHighest) + ", beating a " + playerHand[0].getSFace(*playerHighest) + "!";
    }
    else {
      return "Both the player and the computer have the same " + getHandValue(playerHand, playerRank, playerHighest) + ", ending in a tie!";
    }
  }
}

void swapCards(Card playerHand[SIZE_OF_HAND], Card computerHand[SIZE_OF_HAND], DeckOfCards &deck, int *playerRank, int *playerHighest, int *computerRank, int *computerHighest, int *computerSwaps) {
  bool ifSwap[SIZE_OF_HAND];
  string in;
  
  for (int i = 0; i < SIZE_OF_HAND; i++) {
    cout << "Enter Y or N to switch card #" << (i + 1) << ":";
    cin >> in;
    if (in == "Y") {
      ifSwap[i] = true;
    }
    else {
      ifSwap[i] = false;
    }
  }
  
  for (int j = 0; j < SIZE_OF_HAND; j++) {
    if (ifSwap[j]) {
      playerHand[j] = deck.dealCard();
    }
  }
  
  //AI Strategy
  if (*computerRank == 7) {
    for (int k = 0; k < SIZE_OF_HAND; k++) {
      if (computerHand[k].getFace() != *computerHighest) {
        computerHand[k] = deck.dealCard();
        *computerSwaps = *computerSwaps + 1;
      }
    }
  }
  else if (*computerRank == 9) {
    for (int m = 0; m < SIZE_OF_HAND; m++) {
      if (computerHand[m].getFace() != *computerHighest) {
        computerHand[m] = deck.dealCard();
        *computerSwaps = *computerSwaps + 1;
      }
    }
  }
  else if (*computerRank == 10) {
    for (int h = 0; h < SIZE_OF_HAND - 1; h++) {
      computerHand[h] = deck.dealCard();
      *computerSwaps = *computerSwaps + 1;
    }
  }
  
  sortHand(playerHand);
	sortHand(computerHand);
	
	string tempX = getHandValue(playerHand, playerRank, playerHighest);
	//cout << getHandValue(playerHand, playerRank, playerHighest) << endl;
  //printHand(playerHand);
  
  string tempY = getHandValue(computerHand, computerRank, computerHighest);
  //cout << getHandValue(computerHand, computerRank, computerHighest) << endl;
  //printHand(computerHand);
}

int main() {
	DeckOfCards d; //Create DeckOfCards object, which contains array of object Card 
	
	for (int i = 0; i < 7; i++) { //Shuffle d 7 times
	  d.shuffle();
	}
	
	//d.printDeck(); //Print out deck in string form
	
	Card *playerHand; //Array of card objects for player hand
	playerHand = new Card[SIZE_OF_HAND];
	
	Card *computerHand; //Array of card objects for computer hand 
	computerHand = new Card[SIZE_OF_HAND]; 
	
	dealHand(d, playerHand);
	dealHand(d, computerHand);
	
	sortHand(playerHand);
	sortHand(computerHand);
	
	int playerRank = 0;
	int *pPlayer = &playerRank;
	int computerRank = 0;
	int *pComputer = &computerRank;
	
	int playerHighest = 0; //Represents value of highest pair or highest card 
	int *pPlayerHighest = &playerHighest;
	int computerHighest = 0;
	int *pComputerHighest = &computerHighest;
	
	
	//cout << getHandValue(playerHand, pPlayer, pPlayerHighest) << endl;
	//cout << playerRank << endl;
	//cout << playerHighest << endl;
	//printHand(playerHand);
  
	//cout << getHandValue(computerHand, pComputer, pComputerHighest) << endl;
	//cout << computerRank << endl;
	//cout << computerHighest << endl;
	//printHand(computerHand);
	
	int computerSwaps = 0;
	int *pSwaps = &computerSwaps;
	
	//Text
	cout << "Welcome to 5-Card Draw Poker!" << endl;
	cout << "This game will simulate one round of 5-Card Draw with a computer opponent, so do your best!" << endl;
	cout << endl;
	cout << "You have been dealt the following cards: " << endl;
	cout << endl;
	printHand(playerHand);
	cout << "With your current hand, you have a " << getHandValue(playerHand, pPlayer, pPlayerHighest) << "." << endl;
	
	string temp = getHandValue(computerHand, pComputer, pComputerHighest);
	
	cout << endl;
	cout << "You may choose to swap any number of cards from your hand: " << endl;
	cout << endl;
	
	swapCards(playerHand, computerHand, d, pPlayer, pPlayerHighest,pComputer, pComputerHighest, pSwaps);
	
	cout << endl;
	cout << "After swapping, you have been dealt the following cards: " << endl;
	cout << endl;
	printHand(playerHand);
	cout << "The computer has chosen to swap " << computerSwaps << " card(s). After swapping, the computer has been dealt the following cards: " << endl;
	cout << endl;
	printHand(computerHand);
	
	cout << getWinner(playerHand, computerHand, pPlayer, pComputer, pPlayerHighest, pComputerHighest) << endl;
	
	delete[] playerHand; //Deleting player hand array of cards 
	delete[] computerHand; //Deleting computer hand array of cards 
	
	//TODO
	//Betting function 
	
	return 0;
}
