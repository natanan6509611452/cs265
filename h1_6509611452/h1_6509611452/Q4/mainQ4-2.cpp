#include "Document.cpp"
#include <fstream>
int main() {
	Document *doc = new Document();
	string line = "";
	cout << "Enter filename: ";
	getline(cin, line);
	ifstream file(line);
	if (!file) {
		cerr << "File Not Found";
		abort();
	}

	while (getline(file, line)) {
		cout << line << endl;
		doc->addSentence(line);
	}		
	
	doc->printAll();
	delete doc;
	return 0;
}