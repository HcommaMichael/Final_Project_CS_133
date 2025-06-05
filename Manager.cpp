#include "Manager.h"

Manager::Manager(flashCard* deck){
    this->deck = deck;
}
void Manager::saveCards(std::ofstream file){
    FlashCardLinkedNode* temp = deck->getDeck();
    while(temp != nullptr){
        file << "Q: " << temp->question;
        file << "A: " << temp->answer;
        temp = temp->next;
    }
}
void Manager::loadCards(std::ifstream file){

}
flashCard* Manager::getDeck(){
    return deck;
}