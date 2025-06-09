#include "StudyGuide.h"

StudyGuide::StudyGuide(FlashCardLinkedNode* deck) {
	FlashCardLinkedNode* curr = deck;
	createCopy(curr);
}
void StudyGuide::createCopy(FlashCardLinkedNode* deck) {
	if (deck == nullptr) {
		return;
	}
	else if (deck->wrongAmount >= 1) {
		wrongDeck = new FlashCardLinkedNode(deck->question, deck->answer, wrongDeck);
		wrongDeck->wrongAmount = deck->wrongAmount;
		createCopy(deck->next);
	}
	else {
		createCopy(deck->next);
	}
}
void StudyGuide::constructorHelper() {
	if (wrongDeck == nullptr) {
		return;
	}
	FlashCardLinkedNode* front = wrongDeck;
	wrongDeck = wrongDeck->next;
	front->next = nullptr;

	answerPool.push_back(front->answer);
	studyPriority.push(front);
	constructorHelper();
}
void StudyGuide::startQuiz() {
	std::srand(std::time(0));
	std::vector<std::string> answers;
	while (!studyPriority.empty()) {
		answers.push_back(studyPriority.top()->answer);

		while (answers.size() != 4) {
			int index = std::rand() % answerPool.size();
			if (!vContains(answerPool[index], 0, answers)) {
				answers.push_back(answerPool[index]);
			}
		}
		answerRandomizer(answers);
		std::string choice;

		std::cout << "Q: " << studyPriority.top()->question << std::endl;
		std::cout << "1. " << answers[0] << std::endl << "2. " << answers[1] << std::endl
			<< "3. " << answers[2] << std::endl << "4. " << answers[3] << std::endl;

		std::getline(std::cin, choice);

		if (answers[stoi(choice) - 1] == studyPriority.top()->answer) {
			--studyPriority.top()->wrongAmount;
			std::cout << "Correct!" << std::endl;
		}
		else {
			std::cout << "Incorrect!" << std::endl << "The correct answer was: " <<
				studyPriority.top()->answer << std::endl;
		}
		answers.clear();

		if(studyPriority.top()->wrongAmount != 0){
			studyPriority.push(studyPriority.top());
			studyPriority.pop();
		}
		else {
			studyPriority.pop();
		}
	}
}

