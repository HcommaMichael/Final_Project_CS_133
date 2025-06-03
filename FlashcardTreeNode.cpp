#include "FlashcardTreeNode.h"

FlashcardTreeNode::FlashcardTreeNode(std::string q, std::string a) : question(q), answer(a){}

std::string FlashcardTreeNode::getQuestion(){
    return question;
}

std::string FlashcardTreeNode::getAnswer(){
    return answer;
}
