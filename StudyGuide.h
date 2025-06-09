#ifndef STUDY_GUIDE_H
#define STUDY_GUIDE_H

#include "FlashcardLinkedNode.h"
#include "Quiz.h"
#include <queue>

class StudyGuide: public Quiz{
private:
	std::priority_queue<FlashCardLinkedNode*, std::vector<FlashCardLinkedNode*>, Comparator> studyPriority;
	FlashCardLinkedNode* wrongDeck;
	std::vector<std::string> answerPool;
public:
	StudyGuide(FlashCardLinkedNode* deck);
	virtual void createCopy(FlashCardLinkedNode* deck);
	virtual void constructorHelper();
	void startQuiz() override;
	
};


#endif
