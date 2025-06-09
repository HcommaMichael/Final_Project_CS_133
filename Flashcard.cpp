#include "Flashcard.h"
#include <iostream>

flashCard::flashCard(std::string topic){
    name = topic;
}
void flashCard::addFlashcard(std::string q, std::string a){
    if(deck == nullptr){
        deck = new FlashCardLinkedNode(q, a);
    }else{
        FlashCardLinkedNode* temp = deck;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new FlashCardLinkedNode(q, a);
    }
    size++;
}
void flashCard::removeFlashcard(int index){
    FlashCardLinkedNode* temp = deck;
    for(int i = 0; i < index - 2; i++){
        temp = temp->next;
    }   
    temp = temp->next;

}
void flashCard::editFlashcard(int index){
    FlashCardLinkedNode* temp = deck;
    std::string input;
    for(int i = 0; i < index - 1; i++){
        temp = temp->next;
    }   
    std::cout << "Would you like to edit your question (q), answer (a), or both (b) ";
    getline(std::cin, input);
    if(tolower(input[0]) == 'q'){
        std::cout << "What would you like to change about: " << temp->question << ": ";
        getline(std::cin, input);
        temp->question = input;
    }else if (tolower(input[0]) == 'a'){
        std::cout << "What would you like to change about " << temp->answer << ": ";
        getline(std::cin, input);
        temp->answer = input;
    }else if(tolower(input[0]) == 'b'){
        std::cout << "What would you like to change about " << temp->question << ": ";
        getline(std::cin, input);
        temp->question = input;
        std::cout << "What would you like to change about " << temp->answer << ": ";
        getline(std::cin, input);
        temp->answer = input;
    }
}
void flashCard::printDeck(){
    FlashCardLinkedNode* temp = deck;
    while(temp != nullptr){
        std::cout << temp->question << " " << temp->answer << std::endl;
        temp = temp->next;
    }
}

int flashCard::getSize(){
    return size;
}

FlashCardLinkedNode* flashCard::getDeck(){
    return deck;
}

void flashCard::changeDeck(FlashCardLinkedNode* deck){
    this->deck = deck;
}

std::string flashCard::getName(){
    return name;
}

std::string flashCard::changeName(std::string name){
    this->name = name;
}