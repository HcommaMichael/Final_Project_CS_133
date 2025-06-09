#ifndef STUDY_GUIDE_H
#define STUDY_GUIDE_H

#include "FlashcardLinkedNode.h"
#include <queue>

class StudyGuide {
private:
	std::priority_queue<FlashCardLinkedNode*, std::vector<FlashCardLinkedNode*>, Comparator> studyPriority;
	FlashCardLinkedNode* wrongDeck;
public:
	StudyGuide(FlashCardLinkedNode* deck);
	void createCopy(FlashCardLinkedNode* deck);
	void constructorHelper();
};


#endif

