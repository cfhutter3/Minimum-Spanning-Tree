#include <iostream>
#include <string>
#include "MSTMaker.h"

using namespace std;

int main() {

	MSTMaker graph;
	graph.read("input.txt");
	graph.outputGraph();

	cout << "\nBegin MST 1 starting at Vertex 0\n";
	graph.calculateMST(0);
	graph.writeMST("vertex0.txt");
	cout << '\n';

	cout << "\nBegin MST 2 starting at Vertex 4\n";
	graph.calculateMST(4);
	graph.writeMST("vertex4.txt");
	cout << '\n';

	cout << "\nBegin MST 3 starting at Vertex 2\n";
	graph.calculateMST(2);
	graph.writeMST("vertex2.txt");
	cout << '\n';

	cout << endl;
	system("pause");
	return 0;
}