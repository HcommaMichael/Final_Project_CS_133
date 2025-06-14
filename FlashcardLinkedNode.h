#ifndef _FLASHCARDLINKEDNODE_H_
#define _FLASHCARDLINKEDNODE_H_

#include <string>
//total public class, for ease of access, only accessed by protected members
class FlashCardLinkedNode {
public:
    std::string question; //field for question
    std::string answer; //field for answer 
    int wrongAmount; //field to track how many times question has been answered wrong in the quiz
    FlashCardLinkedNode* next; //next pointer
    
    FlashCardLinkedNode(std::string question, std::string answer); //constructor for nullptr node

    FlashCardLinkedNode(std::string question, std::string answer, FlashCardLinkedNode* next); //constructor for node with next pointer, allows noide to be linked at creation
};

//comparator to be used in our priority queue for study guide
//max-heap sorting
struct Comparator {
    bool operator()(FlashCardLinkedNode* n1, FlashCardLinkedNode* n2) {
        return n1->wrongAmount < n2->wrongAmount;
    }
};



#endif
