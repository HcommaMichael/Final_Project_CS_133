#include "Manager.h"
#include <iostream>

Manager::Manager(FlashCardLinkedNode* deck, std::string name) { //constructor that assigns the deck and name of the deck
    this->deck = deck;
    this->name = name;
}
void Manager::saveCards(std::ofstream& file) {
    FlashCardLinkedNode* temp = deck;
    if (!file) { //if the file can not be opened, throws a string exception below
        throw "invalid file";
    }
    while (temp != nullptr) { //while there are still cards then it will output to the file in the format of Q: questionA: answer
        file << "Q: " << temp->question;
        file << "A: " << temp->answer << "\n";
        temp = temp->next;
    }
    file.close(); //closes the file
}
void Manager::loadCards(std::ifstream& file) {
    std::string line;
    std::string sub;
    std::string sub2;
    int x;
    int y;
    FlashCardLinkedNode* temp = deck;
    if (!file) { //if the file can not be opened, throws a string exception below
        throw "invalid file";
    }
    while (getline(file, line)) { //while there are cards in the file, it will create new cards with the question and answers inside the file 
        if (deck == nullptr) { //assigns the first card
            x = line.find("Q: ");
            y = line.find("A: ");
            sub = line.substr(x + 3, y - (x + 3));
            sub2 = line.substr(y + 3);
            deck = new FlashCardLinkedNode(sub, sub2); //takes the question and answer without the Q: and A: and puts it into the deck
            temp = deck;
        }
        else { //assigns the rest of the cards
            x = line.find("Q: ");
            y = line.find("A: ");
            sub = line.substr(x + 3, y - (x + 3));
            sub2 = line.substr(y + 3);
            temp->next = new FlashCardLinkedNode(sub, sub2); //takes the question and answer without the Q: and A: and puts it into the deck
            temp = temp->next;
        }
        size++; //increments the size so the deck size is accurate
    }
    file.close();
}
FlashCardLinkedNode* Manager::getDeck() {
    return deck;
}

std::string Manager::getName() {
    return name;
}

int Manager::getSize() {
    return size;
}
