#ifndef _FLASHCARDNODE_H_
#define _FLASHCARDNODE_H_

#include <string>
#include <iostream>

class FlashcardNode{
    private:
    std::string question;
    std::string answer;
    FlashcardNode* next;
    public:
    FlashcardNode(std::string q, std::string a);
    std::string getQuestion();
    std::string getAnswer();
};

#endif
