#include "Quiz.h"

Quiz::Quiz(FlashCardLinkedNode* deck) {
	copy = deck;
	wrong = 0;
	right = 0;
	nodes = {};
}
void Quiz::insertAndRandomize() {
	FlashCardLinkedNode* curr = copy;
	while (curr != nullptr) {
		FlashCardLinkedNode* temp = curr->next;
		curr->next = nullptr;
		nodes.push_back(curr);
		curr = temp;
	}

	nodeRandomizer(nodes);
}
void Quiz::nodeRandomizer(std::vector<FlashCardLinkedNode*> v) {
	std::srand(std::time(0));

	//Fisher-Yates randomizing algorithm (found it online)
	for (int i = v.size() - 1; i > 0; --i) {
		int j = std::rand() % (i + 1);
		std::swap(v[i], v[j]);
	}
}
void Quiz::answerRandomizer(std::vector<std::string> a) {
	std::srand(std::time(0));

	//Fisher-Yates randomizing algorithm (found it online)
	for (int i = a.size() - 1; i > 0; --i) {
		int j = std::rand() % (i + 1);
		std::swap(a[i], a[j]);
	}
}
void Quiz::startQuiz() {
	for (int i = 0; i < nodes.size() - 1; i++) {
		std::vector<std::string> answers;
		std::string choice;
		
		answers.push_back(nodes[i]->answer);
		
		for (int j = 0; j < 3; j++) {
			int index = std::rand() % nodes.size() - 1;
			answers.push_back(nodes[index]->answer);
		}

		answerRandomizer(answers);
		
		std::cout << "Q: " << nodes[i]->question << std::endl;
		std::cout << "1. " << answers[0] << std::endl << "2. " << answers[1] << std::endl
				<< "3. " << answers[2] << std::endl << "4. " << answers[3] << std::endl;

		std::getline(std::cin, choice);

		if (answers[stoi(choice) - 1] == nodes[i]->answer) {
			right++;
			std::cout << "Correct!" << std::endl << "Right Answers: " << right << std::endl
				<< "Wrong Answers: " << wrong << std::endl;
		}
		else {
			wrong++;
			std::cout << "Incorrect!" << std::endl << "RIght Answers: " << right << std::endl
				<< "Wrong Answers: " << wrong << std::endl;
		}
	}
}
