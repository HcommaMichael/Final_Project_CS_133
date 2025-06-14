#include "Flashcard.h"
#include "FlashcardLinkedNode.h"
#include "Quiz.h"
#include "Manager.h"
#include "StudyGuide.h"
#include <iostream>

const std::string PREFIX = "C:\\Users\\micha\\source\\repos\\133_Final_Project\\";

// display a message and read a line input from the user
std::string getUserInput(const std::string& message) {
    std::cout << message;
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int main() {

    bool quit = false;
    std::string name;
    std::string input;
    std::string index;
    flashCard* deck = new flashCard("");
    input = getUserInput("Welcome user to the terrible clone of Quizlet!!!!! \n Would you like to load a deck (l) or create a new deck (n) ");
    Manager* mainManager = new Manager(nullptr, "");
    if (tolower(input[0]) == 'l') {
        input = getUserInput("Please input the name of your file: ");
        std::string filePath = PREFIX + input;
        std::ifstream file(filePath);
        mainManager->loadCards(file);
        deck->changeDeck(mainManager->getDeck());
        deck->changeName(mainManager->getName());
        deck->changeSize(mainManager->getSize());
    }
    else if (tolower(input[0]) == 'n') {
        name = getUserInput("Please input a name for your deck: ");
        deck = new flashCard(name);
    }
    else {
        throw "input must be l or n";
    }

    while (!quit) {
        std::string question;
        std::string answer;
        deck->printDeck();
        input = getUserInput("Add (a), edit (e), delete (d) flashcard, get quizzed (q), save (s) or terminate (t) ");
        if (tolower(input[0]) == 'a') {
            question = getUserInput("Q: ");
            answer = getUserInput("A: ");
            deck->addFlashcard(question, answer);
        }
        else if (tolower(input[0]) == 'e') {
            deck->printDeck();
            index = getUserInput("Which card number would you like to edit? ");
            deck->editFlashcard(stoi(index));
        }
        else if (tolower(input[0]) == 'd') {
            deck->printDeck();
            index = getUserInput("Which card number would you like to delete? ");
            deck->removeFlashcard(stoi(index));
        }
        else if (tolower(input[0]) == 'q') {
            if (deck->getSize() < 4) {
                throw "deck size must be larger than or equal to 4";
            }
            else {
                Quiz* quiz = new Quiz(deck->getDeck());
                quiz->startQuiz();
                input = getUserInput("Would you like to requiz yes (y) or no (n): ");
                if (tolower(input[0]) == 'y') {
                    StudyGuide* guide = new StudyGuide(deck->getDeck());
                    guide->startQuiz();
                }
            }
        }
        else if (tolower(input[0]) == 't') {
            quit = true;
        }
        else if (tolower(input[0]) == 's') {
            Manager* manager = new Manager(deck->getDeck(), deck->getName());
            input = getUserInput("Please input the name of your file: ");
            std::string filePath = PREFIX + input;
            std::ofstream file(filePath);
            manager->saveCards(file);
        }
        else {
            throw "not a valid input try again";
        }

    }

    return 0;
}
