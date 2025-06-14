//Quiz.cpp: handles the logic and functionality of quiz
#include "Quiz.h"

//base constructor
Quiz::Quiz(FlashCardLinkedNode* deck) {
	copy = deck;
	wrong = 0;
	right = 0;
	nodes = {};

	insertAndRandomize();
}
//dummy constructor, used for study guide inheritance 
Quiz::Quiz() {}

//inserts nodes into vector, does not break deck chains to preserve original list structure
//results in each node being a linked list of its own, slightly memory inefficient but currently the best 
//solution we have come up with or found, randomizes the nodes by calling node randomizer 
void Quiz::insertAndRandomize() {
	FlashCardLinkedNode* curr = copy;

	while (curr != nullptr) {
		nodes.push_back(curr);
		curr = curr->next;
	}
	
	nodeRandomizer(nodes);
}
//aforementioned node randomizer, uses Fisher-Yates algorithm to randomize the vector, runs O(N),
//but allows us to avoid using the algorithm library, which we think isn't allowed in this class
void Quiz::nodeRandomizer(std::vector<FlashCardLinkedNode*>& v) {
	std::srand(std::time(0));

	//Fisher-Yates randomizing algorithm (found it online)
	for (int i = v.size() - 1; i > 0; --i) {
		int j = std::rand() % (i + 1);
		std::swap(v[i], v[j]);
	}
}
//same as node randomizer, but takes a vector of strings rather than node pointer,
//meaning it only works on the answers, unfortunately this is the most abstracted we can make these
//fucntions
void Quiz::answerRandomizer(std::vector<std::string>& a) {
	std::srand(std::time(0));

	for (int i = a.size() - 1; i > 0; --i) {
		int j = std::rand() % (i + 1);
		std::swap(a[i], a[j]);
	}
}
//contains function to check if the answer we are trying to place into the answer pool is already in there,
//allows us to avoid duplicate answers in the quiz process, which becomes a big problem with smaller decks
bool Quiz::vContains(std::string s, int index, std::vector<std::string> v) {
	if (index == v.size()) {
		return false;
	}
	else if (v[index] == s) {
		return true;
	}
	return vContains(s, index + 1, v);
}
//main quiz loop, least efficient part of the project, but steps have been taken to clean it up
//as much as possible, short of making it recursive, which didn't work out well when attempted
void Quiz::startQuiz() {
	std::vector<std::string> answers; //create vector to store answers 
	for (int i = 0; i < nodes.size(); i++) { //loop over the entire vector of questions once  
		std::string choice; //choice for answer 

		answers.push_back(nodes[i]->answer); //push the correct answer into the answer vector

		//this loop has high potential to be extremely inefficient with small decks, but works well with larger ones
		//loops and picks random nodes to get answers from, and as long as they are not duplicates, places them in the 
		//answers vector, repeates until the vector contains 4 unique answers
		while (answers.size() != 4) { 
			int index = std::rand() % nodes.size();
			if (!vContains(nodes[index]->answer, 0, answers)) {
				answers.push_back(nodes[index]->answer);
			}
		}
		
		//randomize the answers (ensures that the correct one is not always in the first slot)
		//and print out the question and answer choices for the user
		answerRandomizer(answers);
		std::cout << "Choose an answer (1-4)" << std::endl;
		
		std::cout << "Q: " << nodes[i]->question << std::endl;
		std::cout << "------" << std::endl;
		std::cout << "1. " << answers[0] << std::endl << "2. " << answers[1] << std::endl
			<< "3. " << answers[2] << std::endl << "4. " << answers[3] << std::endl;

		std::getline(std::cin, choice); //take user input

		//if the right answer is chosen, increment the right field (contatined in the quiz object)
		//and print out updated stats for this specific quiz/let the user know their answer was correct
		if (answers[stoi(choice) - 1] == nodes[i]->answer) {
			right++;
			std::cout << "Correct!" << std::endl << "Right Answers: " << right << std::endl
				<< "Wrong Answers: " << wrong << std::endl;
		}
		//if the wrong answer is chosen, increment the wrong field, but also increment the nodes wrongAmount field, needed for StudyGuide
		//then update stats/tell the user they were wrong
		else {
			wrong++;
			nodes[i]->wrongAmount += 1;
			std::cout << "Incorrect!" << std::endl << "Right Answers: " << right << std::endl
				<< "Wrong Answers: " << wrong << std::endl;
		}
		//empty the answers vector and repeat the process until all nodes are covered
		answers.clear();

	}
	//clear the nodes vector
	nodes.clear();
}
