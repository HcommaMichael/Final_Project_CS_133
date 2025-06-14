#ifndef STUDY_GUIDE_H
#define STUDY_GUIDE_H

#include "FlashcardLinkedNode.h"
#include "Quiz.h"
#include <queue>

class StudyGuide: public Quiz{
private:
	std::priority_queue<FlashCardLinkedNode*, std::vector<FlashCardLinkedNode*>, Comparator> studyPriority; // PQ used for max heap
	FlashCardLinkedNode* wrongDeck; //consumable copy containing only wrong answered nodes
	std::vector<std::string> answerPool; //vector holding all answers for entire deck, regardless of wrongAmount value

	//public member functions unique to StudyGuide, commented in StudyGuide.cpp
public:
	StudyGuide(FlashCardLinkedNode* deck);
	virtual void createCopy(FlashCardLinkedNode* deck);
	virtual void constructorHelper();
	void startQuiz() override;
	
};


#endif
