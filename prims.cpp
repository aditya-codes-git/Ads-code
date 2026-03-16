#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int visited[5] = {0};
    int edges = 0;
    int totalCost = 0;

    visited[0] = 1;

    cout << "Edge : Weight\n";

    while (edges < n - 1)
    {
        int min = 999;
        int x = 0, y = 0;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (visited[j] == 0 && graph[i][j] != 0)
                    {
                        if (graph[i][j] < min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << graph[x][y] << endl;

        totalCost += graph[x][y];
        visited[y] = 1;
        edges++;
    }

    cout << "Total cost = " << totalCost;

    return 0;
}