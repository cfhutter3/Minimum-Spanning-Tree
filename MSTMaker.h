#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <iomanip>
#include <vector>

const int VERTICES = 6;

class MSTMaker { 
public:
	MSTMaker() {}

	void read(std::string filename) {
		std::ifstream input;
		input.open(filename.c_str());
		for (int i{ 0 }; i < VERTICES; i++) {
			for (int j{ 0 }; j < VERTICES; j++) {
				input >> graph.at(i).at(j);
				if (graph.at(i).at(j) != 0) {
					edges++;
				}
			}
		}
		edges /= 2;
		input.close();
		std::cout << "Matrix read. Vertices: " << VERTICES << ". Edges: " << edges << ".\n";
	}

	void outputGraph() {
		std::cout << "Matrix:\n";
		for (int i{ 0 }; i < VERTICES; i++) {
			for (int j{ 0 }; j < VERTICES; j++) {
				std::cout << std::setw(5) << graph.at(i).at(j);
			}
			std::cout << '\n';
		}
	}

	void writeMST(std::string filename) {
		std::ofstream output;
		output.open(filename.c_str());
		std::cout << "MST number of vertices: " << vertMST << ". MST number of edges: " << edgesMST << ".\n";
		std::cout << "MST:\n";
		for (int i{ 0 }; i < VERTICES; i++) {
			for (int j{ 0 }; j < VERTICES; j++) {
				output << std::setw(5) << MSTgraph.at(i).at(j);
				std::cout << std::setw(5) << MSTgraph.at(i).at(j);
			}
			output << '\n';
			std::cout << '\n';
		}
	}



	void calculateMST(int startingVertex) {
		int shortestWt, toWhichVert, fromWhichVert;
		prepMSTcalc();
		visited.at(startingVertex) = 1;
		for (int k{ 0 }; k < VERTICES - 1; k++) {
			shortestWt = 9999;
			toWhichVert = -1;
			fromWhichVert = -1;
			for (int i{ 0 }; i < VERTICES; i++) {
				if (visited.at(i)) {
					for (int j{ 0 }; j < VERTICES; j++) {
						if (graph.at(i).at(j) < shortestWt && !visited.at(j) && graph.at(i).at(j) != 0) {
							toWhichVert = j;
							fromWhichVert = i;
							shortestWt = graph.at(i).at(j);
						}
					}
				}
			}
			visited.at(toWhichVert) = 1;
			addEdgeMST(fromWhichVert, toWhichVert, shortestWt);
		}
	}

private:
	std::array<std::array<int, VERTICES>, VERTICES> graph;
	std::array<std::array<int, VERTICES>, VERTICES> MSTgraph;
	std::array<int, VERTICES> visited;
	int edges{ 0 };
	int vertMST{ 1 };
	int edgesMST{ 0 };
	
	void addEdgeMST(int v1, int v2, int wt) {
		std::cout << "Add edge " << v1 << " to " << v2 << ".\n";
		MSTgraph.at(v1).at(v2) = wt;
		MSTgraph.at(v2).at(v1) = wt;
		edgesMST++;
		vertMST++;
	}

	void prepMSTcalc() {
		vertMST = 1;
		edgesMST = 0;
		for (int i{ 0 }; i < VERTICES; i++) {
			for (int j{ 0 }; j < VERTICES; j++) {
				MSTgraph.at(i).at(j) = 0;
			}
		}
		for (int i{ 0 }; i < VERTICES; i++) {
			visited.at(i) = 0;
		}
	}

};