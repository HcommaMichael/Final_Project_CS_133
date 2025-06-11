#ifndef _FLASHCARDLINKEDNODE_H_
#define _FLASHCARDLINKEDNODE_H_

#include <string>

class FlashCardLinkedNode {
    private:

    public:
    std::string question;
    std::string answer;
    int wrongAmount;
    FlashCardLinkedNode* next;
    
    FlashCardLinkedNode(std::string question, std::string answer);

    FlashCardLinkedNode(std::string question, std::string answer, FlashCardLinkedNode* next);
};

struct Comparator {
    bool operator()(FlashCardLinkedNode* n1, FlashCardLinkedNode* n2) {
        return n1->wrongAmount < n2->wrongAmount;
    }
};



#endif
