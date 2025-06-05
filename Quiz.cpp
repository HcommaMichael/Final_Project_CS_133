#include "Quiz.h"

Quiz::Quiz(FlashCardLinkedNode* deck) {
	copy = deck;
	wrong = 0;
	right = 0;
	nodes = {};
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

	for (int i = a.size() - 1; i > 0; --i) {
		int j = std::rand() % (i + 1);
		std::swap(a[i], a[j]);
	}
}
bool Quiz::vContains(std::string s, int index, std::vector<std::string> v) {
	if (index == v.size()) {
		return false;
	}
	else if (v[index] == s) {
		return true;
	}
	return vContains(s, index + 1, v);
}
void Quiz::startQuiz() {
	for (int i = 0; i < nodes.size(); i++) {
		std::vector<std::string> answers;
		std::string choice;
		
		answers.push_back(nodes[i]->answer);
		
		while(answers.size() != 4) {
			int index = std::rand() % nodes.size();
			if (!vContains(nodes[index]->answer, 0, answers)) {
				answers.push_back(nodes[index]->answer);
			}
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
			nodes[i]->wrongAmount++;
			wrong++;
			nodes[i]->wrongAmount += 1;
			std::cout << "Incorrect!" << std::endl << "Right Answers: " << right << std::endl
				<< "Wrong Answers: " << wrong << std::endl;
		}
	}
}
