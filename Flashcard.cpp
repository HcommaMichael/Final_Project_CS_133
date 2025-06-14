#include "Flashcard.h"
#include <iostream>

flashCard::flashCard(std::string topic) {
    name = topic; //constructor assigns name to the topic user inputted
}
FlashCardLinkedNode* flashCard::traversalHelper(FlashCardLinkedNode* curr, int index, int target) {
    if (index == target - 1) { //if the index equals target - 1, then it returns the current node in the linked list
        return curr;
    }
    else { //otherwise it will recursively go through the linked list until target - 1 is reached
        return traversalHelper(curr->next, index + 1, target);
    }
}
void flashCard::addFlashcard(std::string q, std::string a) {
    deck = new FlashCardLinkedNode(q, a, deck); //adds flash card to front of deck while shifting the rest of the deck back 1

    size++; //increments the size of the deck by 1
}
void flashCard::removeFlashCardHelper(int index, int target, FlashCardLinkedNode* curr) {
    if (index == target - 2) { //if the index is equal to target - 2 assign temp to the next node then skip the temp node and delete to free memory
        FlashCardLinkedNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
    else { //otherwise recursively go through linked list until index equals target - 2
        removeFlashCardHelper(index + 1, target, curr->next);
    }
}
void flashCard::removeFlashcard(int index) {
    FlashCardLinkedNode* temp = deck;

    removeFlashCardHelper(0, index, temp); //using the deck and index calls helper function

}
void flashCard::editFlashcard(int index) {
    FlashCardLinkedNode* curr = deck;
    FlashCardLinkedNode* temp = traversalHelper(curr, 0, index); //traverses through the linked list and assigns temp to the node wanting to be edited
    std::string input;
    std::cout << "Would you like to edit your question (q), answer (a), or both (b) ";
    getline(std::cin, input); //takes in input of whether the user would like to change the question answer or both
    if (tolower(input[0]) == 'q') {
        std::cout << "What would you like to change about \"" << temp->question << "\"? ";
        getline(std::cin, input); //takes input from user and changes the question
        temp->question = input;
    }
    else if (tolower(input[0]) == 'a') {
        std::cout << "What would you like to change about \"" << temp->answer << "\"? ";
        getline(std::cin, input); //takes input from user and changes the answer
        temp->answer = input;
    }
    else if (tolower(input[0]) == 'b') {
        std::cout << "What would you like to change about \"" << temp->question << "\"? ";
        getline(std::cin, input); //takes input from user and changes the question
        temp->question = input;
        std::cout << "What would you like to change about \"" << temp->answer << "\"? ";
        getline(std::cin, input); //takes input from user and changes the answer
        temp->answer = input;
    }
}
void flashCard::printDeckHelper(FlashCardLinkedNode* curr, int i) {
    if (curr == nullptr) { //recursively goes through deck until it reaches the end, outputting the question and answer for the flash cards
        return;
    }

    std::cout << i << ". " << "Q: " << curr->question << " | A: " << curr->answer << std::endl;
    printDeckHelper(curr->next, i += 1);
}
void flashCard::printDeck() {
    FlashCardLinkedNode* temp = deck;

    printDeckHelper(temp, 1);
}

int flashCard::getSize() {
    return size;
}

FlashCardLinkedNode* flashCard::getDeck() {
    return deck;
}
void flashCard::changeDeck(FlashCardLinkedNode* deck) {
    this->deck = deck;
}

std::string flashCard::getName() {
    return name;
}

void flashCard::changeName(std::string name) {
    this->name = name;
}
void flashCard::changeSize(int size) {
    this->size = size;
}
