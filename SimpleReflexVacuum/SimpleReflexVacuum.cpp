#include <iostream>
using namespace std;

struct Room {
	char roomName;
	bool isClean;
	Room(char roomName, bool isClean) {
		this->roomName = roomName;
		this->isClean = isClean;
	}
};

static void ruleMatch(Room* room) {
	cout << "Room " << room->roomName << ": ";
	if (!room->isClean) {
		cout << "Suck";
	}
	else {
		switch (room->roomName)
		{
		case 'A':
		case 'B':
		{
			cout << "Right";
			break;
		}
		case 'C': {
			cout << "Up";
			break;
		}
		case 'D':
		case 'F':
		{
			cout << "Left";
			break;
		}
		case 'E':
		{
			cout << "Down";
			break;
		}
		}
	}
	cout << endl;
}

int main() {
	Room* percepts[] = { new Room('A', true), new Room('B', false), new Room('B', true), new Room('E', true), new Room('F', false), new Room('F', true),new Room('D', true), new Room('C', true) };
	Room* roomState;
	for (Room* room : percepts) {
		roomState = room;
		ruleMatch(roomState);
	}
}