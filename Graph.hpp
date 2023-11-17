struct EdgeNode {
    int y = -1;
    int weight = -1;
    EdgeNode* next = nullptr;
    EdgeNode() {}
    EdgeNode(int y, int weight): EdgeNode(y, weight, nullptr) {}
    EdgeNode(int y, int weight, EdgeNode* next): y(y), weight(weight), next(next) {}
    ~EdgeNode() {
        delete next;
    }
};

struct Graph {
    EdgeNode** edges;
    int* degree;
    int nvertices = 0;
    int nedges = 0;
    bool directed;
    Graph(int maxv, bool directed): directed(directed) {
        edges = new EdgeNode*[maxv+1];
        degree = new int[maxv+1];
        for (int i = 1; i < maxv; i++) {
            edges[i] = nullptr;
            degree[i] = 0;
        }
    }
    ~Graph() {
        delete[] edges;
        delete[] degree;
    }
    void insertEdge(int x, int y, int weight, bool directed) {
        EdgeNode* edge = new EdgeNode(y, weight, edges[x]);
        edges[x] = edge;
        degree[x]++;
        if (directed == false) {
            insertEdge(y, x, weight, true);
        } else {
            nedges++;
        }
    }
    void depthFirstSearch(int v, bool* discovered, bool* processed, int* entryTime, int* exitTime, int* parent);
    void breadthFirstSearch(int start, bool* discovered, bool* processed, int* parent);
    void processVertexEarly(int v) {
        std::cout << v << " ";
    }
    void processVertexLate(int v) {}
    void processEdge(int v, int y) {}
};

void Graph::depthFirstSearch(int v, bool* discovered, bool* processed, int* entryTime, int* exitTime, int* parent) {
    EdgeNode* current;
    int y;
    int time = 0;

    discovered[v] = true;
    time += 1;
    entryTime[v] = time;

    processVertexEarly(v);

    current = edges[v];
    while (current != nullptr) {
        y = current->y;
        if (!discovered[y]) {
            parent[y] = v;
            processEdge(v, y);
            depthFirstSearch(y, discovered, processed, entryTime, exitTime, parent);
        } else if ( (!processed[y] && parent[v] != y) || directed ) {
            processEdge(v, y);
        }
        
        current = current->next;
    }

    processVertexLate(v);
    time += 1;
    exitTime[v] = time;
    processed[v] = true;
}

void Graph::breadthFirstSearch(int start, bool* discovered, bool* processed, int* parent) {
    std::queue<int> q;
    int v, y;
    EdgeNode* current;

    q.push(start);
    discovered[start] = true;

    while (!q.empty()) {
        v = q.front();
        q.pop();
        processVertexEarly(v);
        processed[v] = true;
        current = edges[v];
        while (current != nullptr) {
            y = current->y;
            if (!processed[y] || directed) {
                processEdge(v, y);
            }
            if (!discovered[y]) {
                q.push(y);
                discovered[y] = true;
                parent[y] = v;
            }
            current = current->next;
        }
        processVertexLate(v);
    }
}