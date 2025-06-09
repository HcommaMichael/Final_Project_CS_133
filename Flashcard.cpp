#include "Flashcard.h"
#include <iostream>

flashCard::flashCard(std::string topic) {
    name = topic;
}
FlashCardLinkedNode* flashCard::addCardHelper(FlashCardLinkedNode* curr) {
    if (curr->next == nullptr) {
        return curr;
    }
    else{
        return addCardHelper(curr->next);
    }
}
void flashCard::addFlashcard(std::string q, std::string a) {
    deck = new FlashCardLinkedNode(q, a, deck);

    /*if (deck == nullptr) {
        deck = new FlashCardLinkedNode(q, a);
    }
    else {
        FlashCardLinkedNode* temp = addCardHelper(deck);
        //FlashCardLinkedNode* temp = deck;
        /*while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        temp->next = new FlashCardLinkedNode(q, a);
    }*/
    size++;
}
void flashCard::removeFlashCardHelper(int index, int target, FlashCardLinkedNode* curr) {
    if (index == target - 2) {
        FlashCardLinkedNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
    else {
        removeFlashCardHelper(index + 1, target, curr->next);
    }
}
void flashCard::removeFlashcard(int index) {
    FlashCardLinkedNode* temp = deck;
    
    removeFlashCardHelper(0, index, temp);

    /*for (int i = 0; i < index - 2; i++) {
        temp = temp->next;
    }
    temp = temp->next;*/

}
void flashCard::editFlashcard(int index) {
    FlashCardLinkedNode* temp = deck;
    std::string input;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    std::cout << "Would you like to edit your question (q), answer (a), or both (b) ";
    getline(std::cin, input);
    if (tolower(input[0]) == 'q') {
        std::cout << "What would you like to change about: " << temp->question;
        getline(std::cin, input);
        temp->question = input;
    }
    else if (tolower(input[0]) == 'a') {
        std::cout << "What would you like to change about: " << temp->answer;
        getline(std::cin, input);
        temp->answer = input;
    }
    else if (tolower(input[0]) == 'b') {
        std::cout << "What would you like to change about: " << temp->question;
        getline(std::cin, input);
        temp->question = input;
        std::cout << "What would you like to change about: " << temp->answer;
        getline(std::cin, input);
        temp->answer = input;
    }
}
void flashCard::printDeckHelper(FlashCardLinkedNode* curr) {
    if (curr == nullptr) {
        return;
    }

    std::cout << curr->question << " " << curr->answer << std::endl;
    printDeckHelper(curr->next);
}
void flashCard::printDeck() {
    FlashCardLinkedNode* temp = deck;

    printDeckHelper(temp);
}

int flashCard::getSize() {
    return size;
}

FlashCardLinkedNode* flashCard::getDeck() {
    return deck;
}
