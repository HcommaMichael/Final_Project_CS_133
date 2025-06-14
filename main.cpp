#include "Flashcard.h"
#include "FlashcardLinkedNode.h"
#include "Quiz.h"
#include "Manager.h"
#include "StudyGuide.h"
#include <iostream>

// The path to save and load files
const std::string PREFIX = "C:\\Users\\micha\\source\\repos\\133_Final_Project\\";

// Display a message and read a line input from the user
std::string getUserInput(const std::string& message) {
    std::cout << message;
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int main() {
    // Main variables
    bool quit = false; // control the program
    std::string name;
    std::string input;
    std::string index;
    flashCard* deck = new flashCard("");
    // Welcome message and load existing or create your deck
    input = getUserInput("Welcome user to the terrible clone of Quizlet!!!!! \n Would you like to load a deck (l) or create a new deck (n) ");
    // Manager to handle loading and saving files
    Manager* mainManager = new Manager(nullptr, "");
    // Manages user's choice
    if (tolower(input[0]) == 'l') {
        // Load existing deck
        input = getUserInput("Please input the name of your file: ");
        std::string filePath = PREFIX + input;
        std::ifstream file(filePath);
        mainManager->loadCards(file);
        deck->changeDeck(mainManager->getDeck());
        deck->changeName(mainManager->getName());
        deck->changeSize(mainManager->getSize());
    }
    else if (tolower(input[0]) == 'n') {
        // Create a new deck
        name = getUserInput("Please input a name for your deck: ");
        deck = new flashCard(name);
    }
    else {
        // if input is not l or n then throws string exception below
        throw "input must be l or n";
    }
    // Main loop continues until user decides to quit
    while (!quit) {
        std::string question;
        std::string answer;
        deck->printDeck();
        // Display the menu and let the user choose what they want to do with the flashcards
        input = getUserInput("Add (a), edit (e), delete (d) flashcard, get quizzed (q), save (s) or terminate (t) ");
        if (tolower(input[0]) == 'a') {
            // Add a new flashcard
            question = getUserInput("Q: ");
            answer = getUserInput("A: ");
            deck->addFlashcard(question, answer);
        }
        else if (tolower(input[0]) == 'e') {
            // Edit existing flashcard
            deck->printDeck();
            index = getUserInput("Which card number would you like to edit? ");
            deck->editFlashcard(stoi(index));
        }
        else if (tolower(input[0]) == 'd') {
            // Delete flashcard
            deck->printDeck();
            index = getUserInput("Which card number would you like to delete? ");
            deck->removeFlashcard(stoi(index));
        }
        else if (tolower(input[0]) == 'q') {
            //Start a quiz mode need atleast 4 flashcards
            if (deck->getSize() < 4) { //if deck is under 4 flashcards throws string exception
                throw "deck size must be larger than or equal to 4";
            }
            else {
                Quiz* quiz = new Quiz(deck->getDeck());
                quiz->startQuiz();
                // Offer to user option to do the quiz again with questions they missed
                input = getUserInput("Would you like to requiz yes (y) or no (n): ");
                if (tolower(input[0]) == 'y') {
                    StudyGuide* guide = new StudyGuide(deck->getDeck());
                    guide->startQuiz();
                }
            }
        }
        else if (tolower(input[0]) == 't') {
            // Terminate the program (quit)
            quit = true;
        }
        else if (tolower(input[0]) == 's') {
            // Save deck to file
            Manager* manager = new Manager(deck->getDeck(), deck->getName());
            // Get the filename from the user
            input = getUserInput("Please input the name of your file: ");
            std::string filePath = PREFIX + input;
            std::ofstream file(filePath);
            manager->saveCards(file);
        }
        else {
            // Invalid input
            throw "not a valid input try again";
        }
    }
    return 0;
}
