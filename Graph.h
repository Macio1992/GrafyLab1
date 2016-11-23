#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <fstream>

using namespace std;

class Graph{
	
	private:
		int **graph;
		int size;
	
	public:
		Graph(int);
		~Graph();
		
		void wypisz();
		void zeroGraph(int**);
		void fillTheMatrix();
		void removeEdge();
		bool checkIfEdgeExists(int, int);
		void addEdge();
		void addVertex();
		void removeVertex();
		int returnDegreeOfVertex(int);
		void maxAndMinDegree();
		void evenAndOddDegrees();
		int checkIfHasCycle();
		void degreeVertexSequence();
		bool checkIfSequenceGraphical(int *, int);
};

#endif
