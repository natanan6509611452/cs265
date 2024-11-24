#include "CharacterCount.cpp"
using namespace std;

int main() {
	CharacterCount ch0;
	cout << ch0.toString() << endl;
	
	CharacterCount ch1('b');
	cout << ch1.toString() << endl;
	ch1.incFreq();
	cout << ch1.toString() << endl;
	
	CharacterCount * ch2 = new CharacterCount('X');
	ch2->incFreq();
	ch2->addFreq(4);
	cout << ch2->toString() << endl;
	delete ch2;
	return 0;
}
