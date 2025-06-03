#ifndef _FLASHCARDNODE_H_
#define _FLASHCARDNODE_H_

#include <string>
#include <iostream>

class FlashcardTreeNode{
    private:
    std::string question;
    std::string answer;
    int priority;
    FlashcardTreeNode* left;
    FlashcardTreeNode* right;
    public:
    FlashcardTreeNode(std::string q, std::string a);
    std::string getQuestion();
    std::string getAnswer();
};

#endif