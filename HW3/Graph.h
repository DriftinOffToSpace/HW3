#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

#include <string>

using namespace std;

struct EdgeNode {
	string name; // name of the NODE (vertex) 
	int y;  // vertex NUMBER 
	int weight; // wt of EDGE between node i and node j, and this is stored inside NODE i 
	struct EdgeNode* next; // next NODE adjacent to y.
};

class Graph {

private:
	static const int MAXV = 20;
	EdgeNode* edges[MAXV + 1] = {}; // edges is an array of linked lists of edges (edgenodes)

public:

	Graph()
	{
		/*for (int i = 0; i <= MAXV; i++)
		{
			edges[i].name = "";
			edges[i].y = i;
			edges[i].weight = -1;
			edges[i].next = NULL;
		}*/
	}

	/**
	 * Destructor for the graph
	 */
	~Graph() {}

	/**
	 * Associates the name with node i
	 */
	void name(int i, string name) {
		/*edges[i].name = name;
			edges[i].y = i;*/
	}

	/**
	 * Add an edge from i to j with weight d
	 */
	void link(int i, int j, int d) {

		/**
		* 1. Ensure i and j exist
		* 2. Add j in "next" of i
		* 3. Add i in "prev" of j
		* 4. Add ij weight d in the adjacency list.
		*/
			/*if (edges[i].next == nullptr) {
				edges[i].next = &edges[j];
			}
			else {
				if (edges[j].prev == nullptr)
					edges[j].prev = &edges[i];
			}
			edges[i].weight = d;*/

		if (edges[i] == nullptr)
		{
			EdgeNode* newEdge = new EdgeNode;
			newEdge->y = j;
			newEdge->weight = d;
			newEdge->next = nullptr;
			edges[i] = newEdge;
		}
		else {
			EdgeNode* temp = edges[i];
			while (temp->next != nullptr)
			{
				if (temp->y == j)
				{
					return;
				}
			}
			EdgeNode* newEdge = new EdgeNode;
			newEdge->y = j;
			newEdge->weight = d;
			newEdge->next = nullptr;
			temp->next = newEdge;
		}
	}

	/**
	 * Delete edge i, j if one exists
	 */
	void deleteEdge(int i, int j) {
		/**
		* 1. Remove node j from the "next" of i.
		* 2. Remove node i from the "prev" of j.
		* 2. Remove ij from the adjacency list.
		*/
		/*if (edges[i]->next == &edges[j]) {}*/
	}


		/**
		 * Prints a listing of all edges in the graph
		 * Each edge is listed as: name of  source node, name of destination node, distance between the two
		 */
		void dump() {
			// Initialize string vector
			// For nodes in the position y, incrementing by 1 each loop (in try catch block)	
				// Find "next" of y = i.
				// Add any edges found to the string vector.
			// When an exception occurs, print the adjacency list line by line.

			EdgeNode* temp = new EdgeNode;
			for (int i = 1; i < MAXV; i++) {
				temp = edges[i];
				while (temp != nullptr)
				{
					cout << "Edge i to " << temp->y << " with weight " << temp->weight << ".\n";
					temp = temp->next;
				}
			}
		}

		/**
		 * Print the shortest path from s to g
		 */
		void path(int s, int g) {
			// Variation on Dijsktra's Algorithm
		}

		/**
		 * Prints all the "dead end" nodes in the network. A node is a “dead end” if it has  an out-degree of zero.
		 */
		void dend() {
			// Initialize int vector
			// For nodes in the position y, incrementing by 1 each loop (in try catch block)
				// If y has no "next" nodes, add y to the int vector
			// When an exception occurs, print the vector separated by commas.
		}

		/**
		 * Prints all the "inaccessible" nodes in the network. A node is “inaccessible” if it has an in-degree of zero.
		 */
		void inacess() {
			// Initialize int vector
			// For nodes in the position y, incrementing by 1 each loop (in try catch block)
				// If t has no "prev" nodes, add y to the int vector
			// When an exception occurs, print the vector separated by commas.
		}

		// Note: you may need more instance variables (ivars) here depending on your implementation

	};

#endif