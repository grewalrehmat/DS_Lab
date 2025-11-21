#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

/*-------------------------------------------------------
   1. GRAPH REPRESENTATION (Matrix + List)
-------------------------------------------------------*/
class Graph {
public:
    int V;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;

    Graph(int V) {
        this->V = V;
        adjMatrix.assign(V, vector<int>(V, 0));
        adjList.assign(V, vector<int>());
    }

    void addEdge(int u, int v, int w = 1) {
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;  // Undirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printAdjMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    void printAdjList() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int x : adjList[i]) cout << x << " ";
            cout << endl;
        }
    }

    int degree(int v) {
        return adjList[v].size();
    }

    void adjacentVertices(int v) {
        cout << "\nAdjacent vertices of " << v << ": ";
        for (int x : adjList[v]) cout << x << " ";
        cout << endl;
    }

    int countEdges() {
        int cnt = 0;
        for (int i = 0; i < V; i++)
            cnt += adjList[i].size();
        return cnt / 2; // Undirected graph
    }
};

/*-------------------------------------------------------
   2. BREADTH FIRST SEARCH (BFS)
-------------------------------------------------------*/
void BFS(Graph &g, int start) {
    vector<bool> visited(g.V, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "\nBFS: ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int u : g.adjList[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
    cout << endl;
}

/*-------------------------------------------------------
   3. DEPTH FIRST SEARCH (DFS)
-------------------------------------------------------*/
void DFSUtil(Graph &g, int v, vector<bool> &visited) {
    visited[v] = true;
    cout << v << " ";

    for (int u : g.adjList[v])
        if (!visited[u])
            DFSUtil(g, u, visited);
}

void DFS(Graph &g, int start) {
    vector<bool> visited(g.V, false);
    cout << "\nDFS: ";
    DFSUtil(g, start, visited);
    cout << endl;
}

/*-------------------------------------------------------
   4. KRUSKAL'S ALGORITHM (MST)
-------------------------------------------------------*/
struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (rank[x] < rank[y]) parent[x] = y;
        else if (rank[y] < rank[x]) parent[y] = x;
        else {
            parent[y] = x;
            rank[x]++;
        }
    }
};

void KruskalMST(Graph &g) {
    vector<Edge> edges;

    for (int i = 0; i < g.V; i++)
        for (int j = i + 1; j < g.V; j++)
            if (g.adMatrix[i][j] != 0)
                edges.push_back({i, j, g.adMatrix[i][j]});

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    DSU dsu(g.V);
    cout << "\nKruskal's MST:\n";

    int cost = 0;
    for (auto e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            cout << e.u << " -- " << e.v << " (weight " << e.w << ")\n";
            cost += e.w;
            dsu.unite(e.u, e.v);
        }
    }

    cout << "Total Cost = " << cost << endl;
}

/*-------------------------------------------------------
   5. PRIM'S ALGORITHM (MST)
-------------------------------------------------------*/
void PrimMST(Graph &g, int start = 0) {
    vector<int> key(g.V, INT_MAX);
    vector<bool> inMST(g.V, false);
    vector<int> parent(g.V, -1);

    key[start] = 0;

    for (int count = 0; count < g.V - 1; count++) {
        int u = -1;

        for (int i = 0; i < g.V; i++)
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;

        inMST[u] = true;

        for (int v = 0; v < g.V; v++) {
            if (g.adjMatrix[u][v] && !inMST[v] && g.adjMatrix[u][v] < key[v]) {
                key[v] = g.adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nPrim's MST:\n";
    int cost = 0;
    for (int i = 1; i < g.V; i++) {
        cout << parent[i] << " -- " << i << " (weight " << g.adjMatrix[i][parent[i]] << ")\n";
        cost += g.adjMatrix[i][parent[i]];
    }
    cout << "Total Cost = " << cost << endl;
}

/*-------------------------------------------------------
   6. DIJKSTRA'S SHORTEST PATH
-------------------------------------------------------*/
void Dijkstra(Graph &g, int src) {
    vector<int> dist(g.V, INT_MAX);
    vector<bool> visited(g.V, false);
    dist[src] = 0;

    for (int count = 0; count < g.V - 1; count++) {
        int u = -1;

        for (int i = 0; i < g.V; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = true;

        for (int v = 0; v < g.V; v++) {
            if (g.adjMatrix[u][v] && dist[u] != INT_MAX &&
                dist[u] + g.adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + g.adjMatrix[u][v];
            }
        }
    }

    cout << "\nDijkstra (from " << src << "):\n";
    for (int i = 0; i < g.V; i++)
        cout << "Distance to " << i << ": " << dist[i] << endl;
}

/*-------------------------------------------------------
   MAIN
-------------------------------------------------------*/
int main() {
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.printAdjMatrix();
    g.printAdjList();

    cout << "\nDegree of vertex 1 = " << g.degree(1) << endl;
    g.adjacentVertices(1);
    cout << "Number of edges = " << g.countEdges() << endl;

    BFS(g, 0);
    DFS(g, 0);

    KruskalMST(g);
    PrimMST(g);
    Dijkstra(g, 0);

    return 0;
}
