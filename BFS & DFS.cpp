#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void addEdge(vector<int> adj[], int u, int v) {
   adj[u].push_back(v);
   adj[v].push_back(u);
}
void DFSUtil(int u, vector<int> adj[], vector<bool>& visited) {
   visited[u] = true;
   cout << u << " ";
   for (int v : adj[u]) {
       if (!visited[v]) {
           DFSUtil(v, adj, visited);
       }
   }
}
void DFS(vector<int> adj[], int V, int start) {
   vector<bool> visited(V, false);
   DFSUtil(start, adj, visited);
}
void BFS(vector<int> adj[], int V, int start) {
   vector<bool> visited(V, false);
   queue<int> q;
   visited[start] = true;
   q.push(start);
   while (!q.empty()) {
       int u = q.front();
       cout << u << " ";
       q.pop();
       for (int v : adj[u]) {
           if (!visited[v]) {
               visited[v] = true;
               q.push(v);
           }
       }
   }
}
int main() {
   int V = 5;
   vector<int> adj[V];
   addEdge(adj, 0, 1);
   addEdge(adj, 0, 2);
   addEdge(adj, 1, 3);
   addEdge(adj, 2, 3);
   cout << "DFS traversal starting from node 0: ";
   DFS(adj, V, 0);
   cout << "\n";
   cout << "BFS traversal starting from node 0: ";
   BFS(adj, V, 0);
   cout << "\n";
   return 0;
}
