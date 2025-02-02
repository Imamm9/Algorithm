#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define INF 9999999

// Function to add an edge to the graph
void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(vector<pair<int, int>> adj[], int V) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int src = 0; // Assuming the start node as 0, can be changed if needed
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;

            if (inMST[v] == false && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<pair<int, int>> adj[V];

    cout << "Enter edges (src, dest, weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        addEdge(adj, u, v, wt);
    }

    primMST(adj, V);

    return 0;
}
