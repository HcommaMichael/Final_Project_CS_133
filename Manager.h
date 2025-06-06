#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "FlashCard.h"
#include <fstream>

class Manager{
    private:
    FlashCardLinkedNode* deck;
    std::string name;
    public:
    Manager(FlashCardLinkedNode* deck, std::string name);
    void saveCards(std::ofstream& file);
    void loadCards(std::ifstream& file);
    FlashCardLinkedNode* getDeck();
    std::string getName();
};


#endif
