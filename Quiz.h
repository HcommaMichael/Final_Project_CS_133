#ifndef QUIZ_H_
#define QUIZ_H_

#include "FlashcardLinkedNode.h"
#include "Flashcard.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Quiz {
private:
	FlashCardLinkedNode* copy; //copy of linked list
	int wrong; //field to track wrong answer per quiz, different from wrongAmount
	int right; //field to track right answers per quiz
	std::vector<FlashCardLinkedNode*> nodes; //vector that holds the nodes to grab questions from
public:
	//constructors and member methods, all commented in Quiz.cpp
	Quiz();
	Quiz(FlashCardLinkedNode* deck);
	virtual void insertAndRandomize();
	virtual void startQuiz();
	virtual void nodeRandomizer(std::vector<FlashCardLinkedNode*>& v);
	virtual void answerRandomizer(std::vector<std::string>& a);
	virtual bool vContains(std::string s, int index, std::vector<std::string> v);
};



#endif
