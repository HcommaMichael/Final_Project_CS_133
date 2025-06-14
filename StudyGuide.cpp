//StudyGuid.cpp: similar in many ways to quiz, therefor inherits from the Quiz class
#include "StudyGuide.h"

//recursive constructor, creates a consumable copy of the deck too ensure all nodes have a wrongAmount value > 1
StudyGuide::StudyGuide(FlashCardLinkedNode* deck) {
	FlashCardLinkedNode* curr = deck;
	createCopy(curr);
	constructorHelper();
}
//creates the deck copy, also pushes all answers into the total answer pool since StudyGuide does not 
//require a deck size of 4, which can cause issues in the main loop if not handled properly
void StudyGuide::createCopy(FlashCardLinkedNode* deck) {
	if (deck == nullptr) {
		return;
	}
	//case for wrongAmount > 1, constructs new node for wrongDeck, the consumable copy
	else if (deck->wrongAmount >= 1) {
		answerPool.push_back(deck->answer);
		wrongDeck = new FlashCardLinkedNode(deck->question, deck->answer, wrongDeck);
		wrongDeck->wrongAmount = deck->wrongAmount;
		createCopy(deck->next);
	}
	//case for wrongAmount < 1, skips node
	else {
		answerPool.push_back(deck->answer);
		createCopy(deck->next);
	}
}
//recursive constructor helper, assigns front to the consumable copy, severs each link and places singular nodes in the PQ
void StudyGuide::constructorHelper() {
	if (wrongDeck == nullptr) {
		return;
	}
	FlashCardLinkedNode* front = wrongDeck;
	wrongDeck = wrongDeck->next;
	front->next = nullptr;

	studyPriority.push(front);
	constructorHelper();
}
//almost exactly the same as the startQuiz in Quiz.cpp, needed updating to handle a priority queue
//does not randomize questions, and runs until the PQ is empty, or the user quits manually
//the contains and answer randomizing functions are directly inherited from Quiz
void StudyGuide::startQuiz() {
	std::srand(std::time(0));
	std::vector<std::string> answers;
	while (!studyPriority.empty()) {
		answers.push_back(studyPriority.top()->answer);

		while (answers.size() != 4 && answers.size() < answerPool.size()) {
			int index = std::rand() % answerPool.size();
			if (!vContains(answerPool[index], 0, answers)) {
				answers.push_back(answerPool[index]);
			}
		}
		answerRandomizer(answers);
		std::string choice;
		std::cout << "Choose an answer (1-4) or q to quit" << std::endl;
		std::cout << "Q: " << studyPriority.top()->question << std::endl;
		std::cout << "------" << std::endl;
		std::cout << "1. " << answers[0] << std::endl << "2. " << answers[1] << std::endl
			<< "3. " << answers[2] << std::endl << "4. " << answers[3] << std::endl << std::endl;
		std::cout << "Answer: ";
		std::getline(std::cin, choice);

		if (tolower(choice[0]) == 'q') {
			std::cout << "Better luck next time!" << std::endl;
			return;
		}

		else if (answers[stoi(choice) - 1] == studyPriority.top()->answer) {
			--studyPriority.top()->wrongAmount;
			std::cout << "Correct!" << std::endl;
		}
		else {
			std::cout << "Incorrect!" << std::endl << "The correct answer was: " <<
				studyPriority.top()->answer << std::endl;
		}
		answers.clear();

		FlashCardLinkedNode* top = studyPriority.top();
		studyPriority.pop();

		if (top->wrongAmount != 0) {
			studyPriority.push(top);
		}
	}
	std::cout << "You got them all!" << std::endl;
}

