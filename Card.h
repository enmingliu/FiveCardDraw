/*
 * Card.h
 *
 *  Created on: Mar 5, 2018
 *      Author: billliu
 */
#include <iostream>
#include <string>

#ifndef CARD_H_
#define CARD_H_

using namespace std;

class Card {
private:
	static const char *faces[]; //all string faces in static array
	static const char *suits[]; //all string suits in static array
	int face; //index of face
	int suit; //index of suit
public:
	Card(); //Default constructor
	Card(int face, int suit); //Constructor with face and suit
	virtual ~Card(); //Default destructor
	string toString(); //Returns card in form "face of suit"
	void setFace(int f); //sets face from index
	void setSuit(int s); //sets suit from index
	int getFace(); //gets face index
	int getSuit(); //gets suit index
	int getRank(); //gets card ranking for sorting purposes
  string getSFace(int i);
};

#endif /* CARD_H_ */
