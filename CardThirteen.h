#pragma once
#include "Card.h"


// [ CardThirteen ] Summary:
// Its Apply() Function: Decrements the value of the passing player�s wallet by value of fees and adds it to the card owner's wallet
// Its Parameters: The Wallet Value to decrease 
				// The card price to decrease from buyer
				// a pointer to the owner of the card

class CardThirteen :
	public Card
{
private:
	static int cardPrice;		// wallet value to decrease from buyer
	static int fees;			// wallet value to decrease from passing player 
	static Player* cardOwner;  // pointer to the card owner
	static int NumberOfCards;  // Number of CardTen objects used in resetting the values of cardprice and fees if all the cardthirteen objects are deleted
	static bool Saved_Before;   // a boolean that indicates if the fees and the cardPrice have been saved before
public:
	CardThirteen(const CellPosition& pos);
	void ReadCardParameters(Grid* pGrid);		// Reads the parameters of CardThirteen which is: cardPrice and fees
	void Apply(Grid* pGrid, Player* pPlayer);		// Applies the effect of CardThirteen on the passed Player
	bool isBought();		//self-implemented function to check if current card is bought or not
							//if card is not bought current player has the choice to buy the card or not
	void setfees(int f);     // setter for fees (used in editcard)
	void setcardPrice(int p);  //setter for cardPrice (used in editcard)
	virtual void Save(ofstream& OutFile, Type);	// Saves the GameObject parameters to the file

	virtual void Read(ifstream& Infile);	// Loads and Reads the GameObject parameters from the file
	virtual Card* getCpy(CellPosition pos);
	~CardThirteen();
};

