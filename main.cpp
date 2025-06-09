#include "Flashcard.h"
#include "FlashcardLinkedNode.h"
#include "Quiz.h"
#include "Manager.h"
#include "StudyGuide.h"
#include <iostream>

const std::string PREFIX = "C:\\Users\\admin\\OneDrive\\Desktop\\CS 133\\Final Project\\";

int main(){

    bool quit = false;
    std::string name;
    std::string input;
    std::string index;
    flashCard* deck = new flashCard("");
    std::cout << "Welcome user to the terrible clone of Quizlet!!!!! \n Would you like to load a deck (l) or create a new deck (n) "; 
    getline(std::cin, input);
    Manager* mainManager = new Manager(nullptr, "");
    if(tolower(input[0]) == 'l'){
        std::cout << "Please input the name of your file: ";
        getline(std::cin, input);
        std::string filePath = PREFIX + input;
        std::ifstream file(filePath);
        mainManager->loadCards(file);
        deck->changeDeck(mainManager->getDeck());
        deck->changeName(mainManager->getName());
        deck->changeSize(mainManager->getSize());
    }else if (tolower(input[0]) == 'n'){
        std::cout << "Please input a name for your deck: ";
        getline(std::cin, name);
        deck = new flashCard(name);
    }else{
        throw "input must be l or n";
    }

    while (!quit) {
        std::string question;
        std::string answer;
        deck->printDeck();
        std::cout << "Add (a), edit (e), delete (d) flashcard, get quizzed (q), save (s) or terminate (t) ";
        getline(std::cin, input);
        if(tolower(input[0]) == 'a'){
            std::cout << "Q: ";
            getline(std::cin, question);
            std::cout << std::endl << "A: ";
            getline(std::cin, answer);

            deck->addFlashcard(question, answer);
        } else if(tolower(input[0]) == 'e'){
            deck->printDeck();
            std::cout << "Which card number would you like to edit? ";
            getline(std::cin, index);
            deck->editFlashcard(stoi(index));
        } else if(tolower(input[0]) == 'd'){
            deck->printDeck();
            std::cout << "Which card number would you like to delete? ";
            getline(std::cin, index);
            deck->removeFlashcard(stoi(index));
        } else if(tolower(input[0]) == 'q'){
            if(deck->getSize() < 4){
                throw "deck size must be larger than or equal to 4";
            }else{
                Quiz* quiz = new Quiz(deck->getDeck());
                quiz->startQuiz();
                std::cout << "Would you like to requiz yes (y) or no (n): ";
                getline(std::cin, input);
                if(tolower(input[0]) == 'y'){
                    StudyGuide* guide = new StudyGuide(deck->getDeck());
                    guide->startQuiz();
                }
            }
        } else if(tolower(input[0]) == 't'){
            quit = true;
        } else if(tolower(input[0]) == 's'){
            Manager* manager = new Manager(deck->getDeck(), deck->getName());
            std::cout << "Please input the name of your file: ";
            getline(std::cin, input);
            std::string filePath = PREFIX + input;
            std::ofstream file(filePath);
            manager->saveCards(file);
        } else{
            throw "not a valid input try again";
        }
        
    }
    
    

    return 0;
}
