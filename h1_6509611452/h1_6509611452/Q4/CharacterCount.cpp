#include "CharacterCount.h"
#include <cctype>
#include <sstream>

CharacterCount::CharacterCount(char letter)
	: freq(0) 
	, letter(toupper(letter)) {}

void CharacterCount::setLetter(char ch) {
	this->letter = toupper(ch);
}

char CharacterCount::getLetter() {
	return this->letter;
}

int CharacterCount::getFreq() {
	return this->freq;
}

void CharacterCount::incFreq() {
	(this->freq)++;
}

void CharacterCount::addFreq(int count) {
	this->freq += count;
}

string CharacterCount::toString() {
	stringstream s;
	s << this->getLetter() << " " << "Freq: " << this->getFreq();
	return s.str();
}





