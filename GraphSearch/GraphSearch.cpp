#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;

struct Node {
	string name;
	int height;
	vector<pair<Node, int>> child;
	bool seen;
	Node(string name, int height, bool seen = false): name(name), height(height), seen(seen){

	}
};

struct Graph {
	Node A = Node("A", 8);
	Node B = Node("B", 9);
	Node C = Node("C", 7);
	Node D = Node("D", 4);
	Node E = Node("E", 3);
	Node F = Node("F", 0);
	Node G = Node("G", 6);
	Node H = Node("H", 6);
	Node S = Node("S", 10);
	Graph() {
		A.child.push_back(make_pair(C, 3));
		A.child.push_back(make_pair(G, 2));

		B.child.push_back(make_pair(A, 4));
		B.child.push_back(make_pair(D, 6));

		C.child.push_back(make_pair(B, 4));
		C.child.push_back(make_pair(H, 3));

		D.child.push_back(make_pair(E, 2));
		D.child.push_back(make_pair(F, 3));

		E.child.push_back(make_pair(F, 5));
		
		G.child.push_back(make_pair(D, 4));
		G.child.push_back(make_pair(E, 5));
		
		H.child.push_back(make_pair(A, 4));
		H.child.push_back(make_pair(D, 4));

		S.child.push_back(make_pair(A, 3));
		S.child.push_back(make_pair(B, 2));
		S.child.push_back(make_pair(C, 5));
	}
};

vector<Node> depthFirstSearch(Node, Node, int, vector<Node>, unordered_map<string, bool>);

int main(int* argc, char** argv) {
	Graph g;
	vector<Node> path = depthFirstSearch(g.S, g.F, 0, vector<Node>(), unordered_map<string, bool>());
	for (Node node : path) {
		cout << node.name << "->";
	}
}

vector<Node> depthFirstSearch(Node initial, Node goal, int expandCount, vector<Node> path, unordered_map<string, bool> seenMap) {
	vector<Node> a = vector<Node>();
	a.push_back(initial);
	while (!a.empty()) {
		Node node = a.back();
		a.pop_back();
		if (!seenMap[node.name]) {
			seenMap[node.name] = true;
			path.push_back(node);
			if (node.name == goal.name) {
				cout << "FOUND!!";
				return path;
			}
			for (auto node : node.child) {
				if (!seenMap[node.first.name]) {
					a.push_back(node.first);
				}
			}
		}
	}
	return path;
}