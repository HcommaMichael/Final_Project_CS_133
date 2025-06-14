
#include <string>
#include "FlashcardLinkedNode.h"


FlashCardLinkedNode::FlashCardLinkedNode(std::string question, std::string answer) : FlashCardLinkedNode(question, answer, nullptr) {}

FlashCardLinkedNode::FlashCardLinkedNode(std::string question, std::string answer, FlashCardLinkedNode* next) {
    this->question = question;
    this->answer = answer;
    this->next = next;
    this->wrongAmount = 0;
}
