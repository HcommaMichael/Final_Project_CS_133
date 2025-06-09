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
	FlashCardLinkedNode* copy;
	int wrong;
	int right;
	std::vector<FlashCardLinkedNode*> nodes;
public:
	Quiz();
	Quiz(FlashCardLinkedNode* deck);
	virtual void insertAndRandomize();
	virtual void startQuiz();
	virtual void nodeRandomizer(std::vector<FlashCardLinkedNode*>& v);
	virtual void answerRandomizer(std::vector<std::string>& a);
	virtual bool vContains(std::string s, int index, std::vector<std::string> v);
};



#endif
