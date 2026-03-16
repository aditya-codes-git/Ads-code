#include <iostream>
using namespace std;

int parent[10];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unite(int a, int b)
{
    int x = find(a);
    int y = find(b);
    parent[x] = y;
}

int main()
{
    int n = 4;

    int graph[4][4] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };

    for(int i = 0; i < n; i++)
        parent[i] = i;

    int edges = 0;
    int cost = 0;

    cout << "Edge : Weight\n";

    while(edges < n-1)
    {
        int min = 999, a = -1, b = -1;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(graph[i][j] != 0 && graph[i][j] < min)
                {
                    min = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int x = find(a);
        int y = find(b);

        if(x != y)
        {
            cout << a << " - " << b << " : " << min << endl;
            cost += min;
            unite(x, y);
            edges++;
        }

        graph[a][b] = graph[b][a] = 999;
    }

    cout << "Total cost = " << cost;

    return 0;
}