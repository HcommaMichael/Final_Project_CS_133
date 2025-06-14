#ifndef _FLASHCARD_H_
#define _FLASHCARD_H_

#include <string>
#include "FlashcardLinkedNode.h"

class flashCard {
private:
    FlashCardLinkedNode* deck = nullptr; //linked list of deck
    std::string name; //name of deck
    int size = 0; //size of deck
public:
    flashCard(std::string topic); //constructor for flash card
    void addFlashcard(std::string q, std::string a); //function that adds flashcard to front of deck
    FlashCardLinkedNode* traversalHelper(FlashCardLinkedNode* curr, int index, int target); //helepr function that goes through linked list until it reaches a certain index
    void removeFlashcard(int index); //removes a card from deck including freeing its memory
    void removeFlashCardHelper(int index, int target, FlashCardLinkedNode* curr); //helper function for removing flashcards
    void editFlashcard(int index); //function so user can edit their flash cards
    void printDeck(); //outputs the questions and answers of the deck
    void printDeckHelper(FlashCardLinkedNode* curr, int i); //helper function for printing the deck
    int getSize();
    FlashCardLinkedNode* getDeck();
    void changeDeck(FlashCardLinkedNode* deck);
    std::string getName();
    void changeName(std::string name);
    void changeSize(int size);
};




#endif
