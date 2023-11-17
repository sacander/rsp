#include <iostream>
#include <fstream>
#include <queue>
#include "Graph.hpp"

using namespace std;

int main() {
    Graph graph(10, false);

    ifstream graphFile("SampleGraph.txt");
    string line;
    getline(graphFile, line);
    sscanf(line.c_str(), "%d", &graph.nvertices);
    while (getline(graphFile, line)) {
        int x, y;
        sscanf(line.c_str(), "%d %d", &x, &y);
        graph.insertEdge(x, y, 0, false);
    }
    graphFile.close();

    for (int i = 1; i <= graph.nvertices; i++) {
        cout << i << ": ";
        EdgeNode* edge = graph.edges[i];
        while (edge != nullptr) {
            cout << edge->y << " ";
            edge = edge->next;
        }
        cout << endl;
    }

    cout << endl;

    bool* discovered = new bool[graph.nvertices+1];
    bool* processed = new bool[graph.nvertices+1];
    int* entryTime = new int[graph.nvertices+1];
    int* exitTime = new int[graph.nvertices+1];
    int* parent = new int[graph.nvertices+1];

    for (int i = 0; i <= graph.nvertices; i ++) {
        discovered[i] = false;
        processed[i] = false;
        entryTime[i] = -1;
        exitTime[i] = -1;
        parent[i] = -1;
    }

    // graph.depthFirstSearch(1, discovered, processed, entryTime, exitTime, parent);
    graph.breadthFirstSearch(1, discovered, processed, parent);

    cout << endl;
    
    return 0;
}