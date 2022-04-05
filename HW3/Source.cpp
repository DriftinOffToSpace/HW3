#include "Graph.h"
#include <iostream>
using namespace std;

int main() {

	Graph graph = Graph();

	int selection = 0;
	cout << "Welcome to the Directed Graph Builder!" << endl << "WARNINGS: Work will not be saved upon exiting the program. Directed graphs may not exceed 20 nodes." << endl;
	do {
		cout << endl << "Please select an option from the list, inputting the number:" << endl;
		cout << "1. Add a name to a node." << endl;
		cout << "2. Add an edge." << endl;
		cout << "3. Delete an edge." << endl;
		cout << "4. Print all edges in a network." << endl;
		cout << "5. Find the shortest path between nodes." << endl;
		cout << "6. List all dead-end nodes." << endl;
		cout << "7. List all inaccessible nodes." << endl;
		cout << "8. Exit the program." << endl;
		cout << "Selection:  ";
		cin >> selection;
		cout << endl;

		switch (selection) {
		case 1: {
			int yInt;
			string nameString;
			cout << "Please enter the name of the node:  ";
			cin >> nameString;
			cout << "Please enter the placement of the node:  ";
			cin >> yInt;
			graph.name(yInt, nameString);
			break;
		}

		case 2: {
			int y1, y2, weight;
			cout << "Please enter the y-value of the first node:  ";
			cin >> y1;
			cout << "Please enter the y-value of the second node:  ";
			cin >> y2;
			cout << "Please enter the weight of the edge:  ";
			cin >> weight;
			graph.link(y1, y2, weight);
			break;
		}

		case 3: {
			int y1, y2;
			cout << "Please enter the y-value of the first node:  ";
			cin >> y1;
			cout << "Please enter the y-value of the second node:  ";
			cin >> y2;
			graph.deleteEdge(y1, y2);
			break;
		}

		case 4: {
			graph.dump();
			break;
		}

		case 5: {
			int y1, y2;
			cout << "Please enter the y-value of the beginning node:  ";
			cin >> y1;
			cout << "Please enter the y-value of the destination node:  ";
			cin >> y2;
			graph.path(y1, y2);
			break;
		}

		case 6: {
			graph.dend();
			break;
		}

		case 7: {
			graph.inacess();
			break;
		}
	}
	} while (selection != 8);
}