/*
 * Card.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: billliu
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

#include "Card.h"

const char *Card::faces[] = {"Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
const char *Card::suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

Card::Card() { //Default Constructor
	// TODO Auto-generated constructor stub
}

Card::Card(int face, int suit) { //Constructor receiving face and suit
	this->face = face;
	this->suit = suit;
}

Card::~Card() { //Default Destructor
	// TODO Auto-generated destructor stub
}

string Card::toString() { //Returning card in form of "face of suit"
	stringstream ss;

	ss << faces[face];
	ss << " of ";
	ss << suits[suit];

	string info = ss.str();

	return info;
}

void Card::setFace(int f) { //sets face from index
  face = f;
}

void Card::setSuit(int s) { //sets suit from index
  suit = s;
}

int Card::getFace() { //gets face index
  return face;
}

int Card::getSuit() { //gets suit index
  return suit;
}

int Card::getRank() { //gets card ranking for sorting purposes
  return (face * 10) + suit;
}

string Card::getSFace(int i) {
  return faces[i];
}




