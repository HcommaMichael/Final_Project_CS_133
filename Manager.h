
#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "FlashCard.h"
#include <fstream>

class Manager {
private:
    FlashCardLinkedNode* deck;
    std::string name;
    int size = 0;
public:
    Manager(FlashCardLinkedNode* deck, std::string name); //constructor for manager taking in deck and name
    void saveCards(std::ofstream& file); //function that saves the cards currently in the deck
    void loadCards(std::ifstream& file); //function that loads cards from a specified file
    FlashCardLinkedNode* getDeck(); //returns the deck
    std::string getName(); //returns the name
    int getSize(); //returns the size
};


#endif

