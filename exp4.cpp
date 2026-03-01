#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10];
bool visited[10];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int i : adj[node]) {
        if (!visited[i])
            dfs(i);
    }
}

int main() {
    int v, e, a, b;

    cout << "Enter vertices and edges: ";
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << "BFS: ";
    for(int i=0;i<10;i++) visited[i]=false;
    bfs(0);

    cout << "\nDFS: ";
    for(int i=0;i<10;i++) visited[i]=false;
    dfs(0);

    return 0;
}