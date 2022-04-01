#include "Graph.h"
#include <iostream>
using namespace std;

int main() {

	Graph graph = Graph();

	int selection = 0;
	cout << "Welcome to the Directed Graph Builder!" << endl << "WARNINGS: Work will not be saved upon exiting the program. Directed graphs may not exceed 20 nodes." << endl;
	while (selection != 8) {
		cout << endl << "Please select an option from the list, inputting the number:" << endl;
		cout << "1. Add a node to the network." << endl;
		cout << "2. Add an edge" << endl;
		cout << "3. Delete an edge." << endl;
		cout << "4. Print all edges in a network." << endl;
		cout << "5. Find the shortest path between nodes." << endl;
		cout << "6. List all dead-end nodes." << endl;
		cout << "7. List all inaccessible nodes." << endl;
		cout << "8. Exit the program." << endl;
		cout << "Selection:  ";
		cin >> selection;

		switch (selection) {
		case 1:
			int yInt;
			string nameString;
			cout << "Please enter the name of the node:  ";
			cin >> nameString;
			cout << "Please enter the placement of the node:  ";
			cin >> yInt;
			Graph name(yInt, nameString);

		case 2:
			int y1, y2, weight;
			cout << "Please enter the y-value of the first node:  ";
			cin >> y1;
			cout << "Please enter the y-value of the second node:  ";
			cin >> y2;
			cout << "Please enter the weight of the edge:  ";
			cin >> weight;
			Graph link(y1, y2, weight);

		case 3:
			int y1, y2;
			cout << "Please enter the y-value of the first node:  ";
			cin >> y1;
			cout << "Please enter the y-value of the second node:  ";
			cin >> y2;
			Graph deleteEdge(y1, y2);

		case 4:
			Graph dump();

		case 5:
			int y1, y2;
			cout << "Please enter the y-value of the beginning node:  ";
			cin >> y1;
			cout << "Please enter the y-value of the destination node:  ";
			cin >> y2;
			Graph path(y1, y2);

		case 6:
			Graph dend();

		case 7:
			Graph inacess();

		case 8:
			exit(2);
		}
	}
}