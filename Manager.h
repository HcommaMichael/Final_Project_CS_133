#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "FlashCard.h"
#include <fstream>

class Manager{
    private:
    flashCard* deck;
    public:
    Manager(flashCard* deck);
    void saveCards(std::ofstream file);
    void loadCards(std::ifstream file);
    flashCard* getDeck();
};


#endif
