#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;

public:
    Graph(int v) {
        vertices = v;
        adjMatrix.resize(v, vector<int>(v, 0));
        adjList.resize(v);
    }
    /// ========================
    /// Adding Edge to the Graph
    /// ========================
    void addEdge(int u, int v) {
        /// update matrix adjacency
        adjMatrix[u][v] = 1;
        /// Undirected
        adjMatrix[v][u] = 1;
        /// update list adjacency
        adjList[u].push_back(v);
        /// Undirected
        adjList[v].push_back(u);
    }
    /// ======================
    /// print Adjacency Matrix
    /// ======================
    void printAdjacencyMatrix() {
        cout << "Adjacency Matrix:\n";
        cout << "   ";
        for (int i = 0; i < vertices; i++) {
            cout << i << " ";
        }
        cout << endl;

        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    /// BFS
    void BFS(int startVertex) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        cout << "BFS Traversal: ";

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    /// 3- DFS
    void DFS(int startVertex) {
        vector<bool> visited(vertices, false);
        stack<int> s;

        cout << "DFS Traversal: ";

        s.push(startVertex);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";

                /// We place the neighbors in the stack in reverse order to get the same order as the image
                for (int i = adjList[current].size() - 1; i >= 0; i--) {
                    int neighbor = adjList[current][i];
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }
        cout << "\n";
    }
};

int main() {
    Graph g(11);

    g.addEdge(1, 2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,9);
    g.addEdge(3,10);
    g.addEdge(2,5);
    g.addEdge(2,7);
    g.addEdge(2,8);
    g.addEdge(5,7);
    g.addEdge(5,8);
    g.addEdge(5,6);
    g.addEdge(7,8);

    g.printAdjacencyMatrix();
    cout << endl;
    g.BFS(1);
    cout << endl;
    g.DFS(1);

    return 0;
}
