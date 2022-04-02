

https://www.tutorialspoint.com/cplusplus/index.htm

https://www.programiz.com/dsa/graph-adjacency-matrix

https://kalkicode.com/adjacency-matrix-representation-of-directed-graph-in-cpp

#ifndef GRAPH_H
#define GRAPH_H

#include <string>

using namespace std;

struct EdgeNode {
	string name; // name of the NODE (vertex) 
	int y;  // vertex NUMBER 
	int weight; // wt of EDGE between node i and node j, and this is stored inside NODE i 
	struct EdgeNode* next; // next NODE adjacent to y.
	struct EdgeNode* prev; // prev NODE adjacent to y.
} edgenode;

class Graph {

private:
	static const int MAXV = 20;
	EdgeNode* edges[MAXV + 1] = {}; // edges is an array of linked lists of edges (edgenodes)

public:

	Graph()
	{
		for (i = 0; i <= MAXV; i++)
		{
			edges[i].name = "";
			edges[i].y = i;
			edges[i].weight = -1;
			edges[i].next = NULL;
			edges[i].prev = NULL;
		}
	}

	/**
	 * Destructor for the graph
	 */
	~Graph() {}


	bool exists(int i)
	{
		return (edges[i].weight != -1)
	}

	/**
	 * Associates the name with node i
	 */
	void name(int i, string name) {
		if (exists(i) {
			edges[i].name = name;
				edges[i].y = i;
		}
		else {
			cout << "Error node " << i << " does not exist. " << endl;
		}
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
		if (exists(i) && exists(j))
		{
			if (edges[i].next == nullptr) {
				edges[i].next = &edges[j];
			}
			else {
				if (edges[j].prev == nullptr)
					edges[j].prev = &edges[i];
			}
			edges[i].weight = d;
		}
		else {
			cout << "Error link could not be initialized. " << endl;
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
		if (exists(i) && exists(j))
		{
			if (edges[i].next == &edges[j]
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