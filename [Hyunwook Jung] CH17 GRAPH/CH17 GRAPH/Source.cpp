#include <iostream>

using namespace std;
#define MAXIMUM 5
// Hyunwook Jung
// Lab Ch17 Graphs
// 18 NOV 2019
// Diablo Valley College COMSC 210

/*For this lab, you will create an implementation of this algorithm.

Your driver program should provide a graph 
and a source vertex in the graph.  

Your implementation should use Dijkstra's Algorithm 
to determine the shortest path using adjacency matrix representation.

Specifically, given a graph and a source vertex in the graph, 
find the shortest paths from source to all vertices 
in the given graph, using Dijkstra's Algorithm.*/
class vertex {
public:
	int distance = 0;
	vertex* predV = 0;
};

int minDistance(int distance[], bool Dset[]) {
	int min = 99999;
	int index;
	for (int v = 0; v < MAXIMUM; v++) {
		if (Dset[v] == false && distance[v] <= min) {
			min = distance[v];
			index = v;
		}
	}
	return index;
}
void DijkstraShortestPath(int graph[MAXIMUM][MAXIMUM], int startV) {
	int distance[MAXIMUM];
	bool Dset[MAXIMUM];
	for (int i = 0; i < MAXIMUM; i++) {
		distance[i] = 99999;
		Dset[i] = false;
	}
	distance[startV] = 0;

	for (int c = 0; c < MAXIMUM; c++) {
		int u = minDistance(distance, Dset);
		Dset[u] = true;
		for (int v = 0; v < MAXIMUM; v++) {
			if ((!Dset[v]) && (graph[u][v]) && (distance[u] != 99999) && (distance[u] + graph[u][v] < distance[v])) {
				distance[v] = distance[u] + graph[u][v];
			}
		}
	}

	cout << "Vertex\t\tDistance from the starting Vertex" << endl;
	for (int i = 0; i < MAXIMUM; i++) {
		char c = 65 + i;
		cout << c << "\t\t" << distance[i] << endl;
	}
}
int main()
{
	cout << "Enter the graph's element between 0~9" << endl;
	int Graph[MAXIMUM][MAXIMUM];
	for (int i = 0; i < MAXIMUM; i++)
	{
		for (int j = 0; j < MAXIMUM; j++) {
			if (i == j) {
				Graph[i][j] = 0;
			}
			else {
				cout << i << " Column, " << j << " Row: ";
				cin >> Graph[i][j];
			}
		}
	}

	cout << "\n\nGraph made" << endl << endl;
	for (int i = 0; i < MAXIMUM; i++)
	{
		for (int j = 0; j < MAXIMUM; j++) {
			cout << Graph[i][j];
		}
		cout << endl;
	}

	cout << "\nWhich vertex do you want to start at? (0 ~ 4)" << endl;
	int startingPoint;
	cin >> startingPoint;
	cout << endl << endl;

	DijkstraShortestPath(Graph, startingPoint);
	return 0;
}