#include "Document.h"
#include "CharacterCount.cpp"

using namespace std;
Document::Document() {
	arrChar = new CharacterCount[NO_CHAR];
	for (int i = 0; i < NO_CHAR; i++) {
		arrChar[i].setLetter((char)('A'+i));
	}
}

Document::~Document() {
	delete[] arrChar;
}

void Document::addSentence(string str) {
	auto a = str.c_str();
	string tmp;
	for (int i = 0; i < strlen(a); i++) {
		if (!(indexOfCharacter(a[i]) == -1)) {
			arrChar[indexOfCharacter(a[i])].incFreq();
			tmp.assign(1, toupper(a[i]));
			doc.push_back(tmp);
		}
	}
}                 

int Document::indexOfCharacter(char ch) {
	for (int i = 0; i < NO_CHAR; i++) {
		if (arrChar[i].getLetter() == toupper(ch)) {
			return i;
		}
	}
	return -1;
}

CharacterCount* Document::get(char ch) {
	if (!(indexOfCharacter(ch) < sizeof(arrChar)) || !(indexOfCharacter(ch) >= 0)) {
		return nullptr;
	}
	else {
		return arrChar+indexOfCharacter(ch);
	}
	
}

CharacterCount* Document::maxFreq() {
	int max = 0;
	int index = 0;
	for (int i = 0; i < NO_CHAR; i++) {
		if (arrChar[i].getFreq() > max) {
			max = arrChar[i].getFreq();
			index = i;
		}
	}
	return &arrChar[index];
}

void Document::printAll() {
	cout << "Frequency of found characters:" << endl;
	int shouldNextLine = 0;
	for (int i = 0; i < NO_CHAR; i++) {
		if (!(arrChar[i].getFreq() == 0)) {
			cout << "\t" << arrChar[i].toString();
			shouldNextLine++;	
		}
		if (shouldNextLine > 0 && shouldNextLine % 2 == 0) {
			cout << endl;
			shouldNextLine = 0;
		}
	}
	cout << endl;
}
