#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> *filter(const int* arr, int size, int value, int compare) {
	vector<int>* vec = new vector<int>(arr, arr + size);

	if (compare < 0) {
		for (auto i = vec->begin(); i < vec->end(); i++) {
			if (!(*i < value)) {
				vec->erase(i);
				i--;
			}
		}
		return vec;
	} else if (compare > 0) {
		for (auto i = vec->begin(); i < vec->end(); i++) {
			if (!(*i > value))  {
				vec->erase(i);
				i--;
			}
		}
		return vec;
	} else {
		for (auto i = vec->begin(); i < vec->end(); i++) {
			if (!(*i == value))  {
				vec->erase(i);
				i--;
			}
		}
		return vec;
	}
}

int main(int argc, char** argv) {

	string str;
	cout << "Original Array: ";
	getline(cin, str);
	stringstream* s = new stringstream(str);
	int size;
	string tmpString;
	while(*s >> tmpString) {
		size++;
	}

	s = new stringstream(str);
	int* arr = new int[size];

	for (int i = 0; i < size; i++) {
		*s >> tmpString;
		arr[i] = stoi(tmpString);
	}

	auto vec = *filter(arr, size, 4, 0);
	cout << "Result of == 4: ";
	if(!vec.empty()) {
		for (int a : vec) {
		cout << a << " ";
		}
	}
	else {
		cout << "NULL";
	}
	cout << endl;

	vec = *filter(arr, size, 4, -1);
	cout << "Result of < 4: ";
	if(!vec.empty()) {
		for (int a : vec) {
			cout << a << " ";
		}
	}
	else {
		cout << "NULL";
	}
	cout << endl;

	vec = *filter(arr, size, 4, 1);
	cout << "Result of > 4: ";
	if(!vec.empty()) {
		for (int a : vec) {
		cout << a << " ";
		}
	}
	else {
		cout << "NULL";
	}
	cout << endl;
	
	delete(arr);
	return 0;
}

