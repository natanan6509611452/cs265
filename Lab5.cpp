#include <iostream>
using namespace std;
struct Node {
	double data; // data
	Node* next; // pointer to next
	Node(double value) { // Node constructor
		data = value;
		next = NULL;
	}
};

int main(int argc, char** argv) {
	Node *a, *tmp;
	a = new Node(10);
	a->next = new Node(20);
	a->next->next = new Node(30);

	for (tmp = a; tmp->next->next != NULL; tmp = tmp->next);
	
	delete tmp->next;
	tmp->next = NULL;

	tmp = a;
	while(tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
	return 0;
}







