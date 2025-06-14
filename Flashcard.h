#ifndef _FLASHCARD_H_
#define _FLASHCARD_H_

#include <string>
#include "FlashcardLinkedNode.h"

class flashCard{
    private:
    FlashCardLinkedNode* deck = nullptr;
    std::string name;
    int size = 0;
    public:
    flashCard(std::string topic);
    void addFlashcard(std::string q, std::string a);
    void removeFlashcard(int index);
    void editFlashcard(int index);
    void printDeck();
    int getSize();
    FlashCardLinkedNode* getDeck();
    void changeDeck(FlashCardLinkedNode* deck);
    std::string getName();
    std::string changeName(std::string name);
    int changeSize(int size);
};




#endif