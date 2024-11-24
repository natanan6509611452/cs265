#ifndef CHARACTERCOUNT_H_
#define CHARACTERCOUNT_H_
#include <iostream>
using namespace std;
class CharacterCount {
	private:
		char letter;
		int freq;
	public:
		CharacterCount (): letter('A'), freq(0) {}
		CharacterCount (char letter);
		~CharacterCount() { }
		void setLetter(char ch);
		char getLetter();
		int getFreq();
		void incFreq();
		void addFreq(int count);
		string toString();
};
#endif /* CHARACTERCOUNT_H_ */