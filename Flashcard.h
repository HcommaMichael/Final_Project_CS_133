#ifndef _FLASHCARD_H_
#define _FLASHCARD_H_

#include <string>
#include "FlashcardLinkedNode.h"

class flashCard {
private:
    FlashCardLinkedNode* deck = nullptr;
    std::string name;
    int size = 0;
public:
    flashCard(std::string topic);
    void addFlashcard(std::string q, std::string a);
    FlashCardLinkedNode* traversalHelper(FlashCardLinkedNode* curr, int index, int target);
    void removeFlashcard(int index);
    void removeFlashCardHelper(int index, int target, FlashCardLinkedNode* curr);
    void editFlashcard(int index);
    void printDeck();
    void printDeckHelper(FlashCardLinkedNode* curr);
    int getSize();
    FlashCardLinkedNode* getDeck();
    void changeDeck(FlashCardLinkedNode* deck);
    std::string getName();
    void changeName(std::string name);
    void changeSize(int size);
};




#endif
