
#include "Manager.h"
#include <iostream>

Manager::Manager(FlashCardLinkedNode* deck, std::string name){
    this->deck = deck;
    this->name = name;
}
void Manager::saveCards(std::ofstream& file){
    FlashCardLinkedNode* temp = deck;
    if(!file){
        throw "invalid file";
    }
    while(temp != nullptr){
        file << "Q: " << temp->question;
        file << "A: " << temp->answer << "\n";
        temp = temp->next;
    }
    file.close();
}
void Manager::loadCards(std::ifstream& file){
    std::string line;
    std::string sub;
    std::string sub2;
    int x;
    int y;
    FlashCardLinkedNode* temp = deck;
    if(!file){
        std::cout << "not working";
    }
    while(getline(file, line)){
        std::cout << line;
        if(deck == nullptr){
            x = line.find(" ");
            y = line.find("A");
            sub = line.substr(x, y);
            sub2 = line.substr(y+3);
            deck = new FlashCardLinkedNode(sub, sub2);
        }else{
            x = line.find(" ");
            y = line.find("A");
            sub = line.substr(x, y);
            sub2 = line.substr(y+3);
            temp->next = new FlashCardLinkedNode(sub, sub2);
            temp = temp->next;
        }
    }
    file.close();
}
FlashCardLinkedNode* Manager::getDeck(){
    return deck;
}

std::string Manager::getName(){
    return name;
}