#include <iostream>
using namespace std;

int main() {
    int graph[4][4] = {
        {0, 1, 4, 0},
        {1, 0, 2, 6},
        {4, 2, 0, 3},
        {0, 6, 3, 0}
    };

    int dist[4] = {0, 999, 999, 999};
    bool visited[4] = {false, false, false, false};

    for(int i = 0; i < 4; i++) {
        int min = 999, u;

        for(int j = 0; j < 4; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = true;

        for(int v = 0; v < 4; v++) {
            if(graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distances:\n";
    for(int i = 0; i < 4; i++) {
        cout << "0 -> " << i << " = " << dist[i] << endl;
    }

    return 0;
}