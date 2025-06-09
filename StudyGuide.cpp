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

	studyPriority.push(front);
	constructorHelper();

}
