#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

struct EdgeNode {
	string name = ""; // name of the NODE (vertex) 
	int y;  // vertex NUMBER 
	int weight; // wt of EDGE between node i and node j, and this is stored inside NODE i 
	struct EdgeNode* next; // next NODE adjacent to y.
};

class Graph {

private:
	static const int MAXV = 20;
	EdgeNode* edges[MAXV + 1] = {}; // edges is an array of linked lists of edges (edgenodes)
	int numNodes;
	vector<EdgeNode*> eVec;
	string names[MAXV];

public:

	Graph()
	{
		for (int i = 0; i < MAXV; i++)
		{
			names[i] = to_string(i);
		}
	}

	/**
	 * Destructor for the graph
	 */
	~Graph() {}

	void update()
	{
		set<int> counter;
		EdgeNode* temp = nullptr;
		for (int i = 0; i < eVec.size(); i++)
		{
			temp = eVec.at(i);
			while (temp != nullptr)
			{
				counter.insert(i);
				counter.insert(temp->y);
				temp = temp->next;
			}
		}

		numNodes = counter.size();
	}

	/**
	 * Associates the name with node i
	 */
	void name(int i, string nameIn) {
		names[i] = nameIn;
	}

	/**
	 * Add an edge from i to j with weight d
	 */
	void link(int i, int j, int d) {
	// Method hangs at nested if. Diagnose.
		// Should work fine now.

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
		* 2. Remove ij from the adjacency list.
		*/
		/*if (edges[i]->next == &edges[j]) {}*/

		if (eVec.at(i)->y == j)
		{
			EdgeNode* temp = eVec.at(i)->next;
			delete eVec.at(i);
			eVec.at(i) = temp;
		}
		else
		{
			EdgeNode* temp = eVec.at(i);
			while (temp->next->y != j && temp->next->next != nullptr)
			{
				temp = temp->next;
			}
			if (temp->next->y == j)
			{
				EdgeNode* newNext = temp->next->next;
				delete temp->next;
				temp->next = newNext;
			}
		}
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
						cout << "Edge " << names[i] << " to " << temp->y << " with weight " << temp->weight << ".\n";
						temp = temp->next;
				}
			}
		}

		/**
		 * Print the shortest path from s to g
		 */
		void path(int s, int g) {
			// Variation on Dijsktra's Algorithm
			update();
			EdgeNode* p;
			bool intree[MAXV + 1];
			int distance[MAXV + 1];
			int parent[MAXV + 1];
			int i;
			int v;
			int w;
			int dist;
			int weight = 0;

			for (i = 1; i <= numNodes; i++)
			{
				intree[i] = false;
				distance[i] = INT_MAX;
				parent[i] = -1;
			}

			distance[s] = 0;
			intree[s] = false;
			v = s;

			while (!intree[v])
			{
				intree[v] = true;
				if (v != s)
				{
					std::cout << "Checking edge (" << s << ", " << v << ")." << std::endl;
					weight = weight + dist;
				}
				p = eVec.at(v);

				while (p != nullptr)
				{
					w = p->y;
					if (distance[w] > (distance[v] + p->weight))
					{
						distance[w] = distance[v] + p->weight;
						parent[w] = v;
					}
					p = p->next;
				}
				dist = INT_MAX;

				for (int i = 1; i <= numNodes; i++)
				{
					if ((!intree[i]) && (dist > distance[i]))
					{
						dist = distance[i];
						v = i;
					}
				}
			}
			
			std::cout << "The shortest path from " << names[s] << " to " << names[g] << " has a weight of " << distance[g] << endl;
		}

		/**
		 * Prints all the "dead end" nodes in the network. A node is a “dead end” if it has  an out-degree of zero.
		 */
		void dend() {
			// Note: Method hangs on the print cycle. Troubleshoot soon.
			// Addressing above, should be fixed now.

			cout << endl << "Dead-end Nodes: " << endl;
			for (int i = 0; i < eVec.size(); i++)
			{
				if (eVec.at(i) == nullptr)
				{
					cout << names[i] << " ";
				}
			}
			cout << endl;
		}

		/**
		 * Prints all the "inaccessible" nodes in the network. A node is “inaccessible” if it has an in-degree of zero.
		 */
		void inacess() {
			cout << endl << "The following nodes are inaccessible: " << endl;
			bool found;
			EdgeNode* temp;
			for (int i = 0; i < eVec.size(); i++)
			{
				found = false;
				temp = nullptr;
				for (int j = 0; j < eVec.size(); j++)
				{
					temp = eVec.at(j);
					while (temp != nullptr)
					{
						if (temp->y == i)
						{
							found = true;
						}
						temp = temp->next;
					}
				}

				if (!found)
				{
					cout << names[i] << " ";
				}
			}
		}
		// Note: you may need more instance variables (ivars) here depending on your implementation


	};

#endif