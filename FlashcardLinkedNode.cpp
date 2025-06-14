
#include <string>
#include "FlashcardLinkedNode.h"

//initialize a new node with a nullptr
FlashCardLinkedNode::FlashCardLinkedNode(std::string question, std::string answer) : FlashCardLinkedNode(question, answer, nullptr) {}

//initializes a new node with a non nullptr, used when adding to the front of a list mainly
FlashCardLinkedNode::FlashCardLinkedNode(std::string question, std::string answer, FlashCardLinkedNode* next) {
    this->question = question;
    this->answer = answer;
    this->next = next;
    this->wrongAmount = 0;
}
