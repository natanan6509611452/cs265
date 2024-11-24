#include "Document.cpp"

int main() {
	Document *doc = new Document();
	string line = "";
	cout << "Enter 1st line: ";
	getline(cin, line);
	if (!line.empty())
		doc->addSentence(line);
	cout << "Enter 2nd line: ";
	getline(cin, line);
	doc->addSentence(line);
	doc->printAll();
	cout << "Max character " << doc->maxFreq()->toString() << endl;
	cout << "Index of X " << doc->indexOfCharacter('X') << endl;
	cout << "Index of 9 " << doc->indexOfCharacter('9') << endl;
	cout << "Index of U " << doc->indexOfCharacter('U') << endl;
	cout << "Character X: " << (doc->get('X')? doc->get('X')->toString(): "NULL") << endl;
	cout << "Character 9: " << (doc->get('9')? doc->get('9')->toString(): "NULL") << endl;
	cout << "Character U: " << (doc->get('U')? doc->get('U')->toString(): "NULL") << endl;
	cout << "Bye\n";
	delete doc;
	return 0;
}