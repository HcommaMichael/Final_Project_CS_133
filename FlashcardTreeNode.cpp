#include "FlashcardTreeNode.h"

FlashcardNode::FlashcardNode(std::string q, std::string a) : question(q), answer(a){}

std::string FlashcardNode::getQuestion(){
    return question;
}

std::string FlashcardNode::getAnswer(){
    return answer;
}
