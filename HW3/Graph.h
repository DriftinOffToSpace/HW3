#ifndef GRAPH_H
#define GRAPH_H

#include <string>

using namespace std;

struct EdgeNode {
	int y;
	int weight;
	struct EdgeNode* next;
	struct EdgeNode* prev;
}edgenode;

class Graph {

private:
	static const int MAXV = 20;
	EdgeNode* edges[MAXV + 1] = {};

public:

	Graph() 
	{
	}

	/**
     * Destructor for the graph
     */
	~Graph() {}

	/**
	 * Associates the name with node i
	 */
	void name(int i, string name) {
		EdgeNode this.name;
		edgenode.y = i;
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