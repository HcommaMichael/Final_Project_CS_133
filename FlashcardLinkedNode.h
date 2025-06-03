#ifndef _FLASHCARDLINKEDNODE_H_
#define _FLASHCARDLINKEDNODE_H_

#include <string>

struct FlashCardLinkedNode {
    std::string question;
    std::string answer;
    FlashCardLinkedNode* next;
    
    FlashCardLinkedNode(std::string question, std::string answer);

    FlashCardLinkedNode(std::string question, std::string answer, FlashCardLinkedNode* next);
};



#endif