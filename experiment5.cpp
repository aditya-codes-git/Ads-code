#include <iostream>
using namespace std;

#define MAX 10
#define INF 999

int graph[MAX][MAX];
int parent[MAX];
int cities;

/* Add Route between Cities */
void addRoute(int src, int dest, int weight)
{
    graph[src][dest] = weight;
    graph[dest][src] = weight;
}

/* Display Graph */
void displayGraph()
{
    cout << "\nTransportation Network (Adjacency Matrix)\n";

    for(int i=0;i<cities;i++)
    {
        for(int j=0;j<cities;j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

/* ---------- Prim's Algorithm ---------- */
void prims()
{
    int visited[MAX]={0};
    int edges=0;
    int min,x=0,y=0;
    int cost=0;

    visited[0]=1;

    cout<<"\nMinimum Spanning Tree using Prim's Algorithm\n";

    while(edges < cities-1)
    {
        min=INF;

        for(int i=0;i<cities;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<cities;j++)
                {
                    if(!visited[j] && graph[i][j])
                    {
                        if(graph[i][j] < min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout<<"Route: "<<x<<" - "<<y<<"  Cost: "<<graph[x][y]<<endl;

        cost += graph[x][y];
        visited[y]=1;
        edges++;
    }

    cout<<"Total Cost = "<<cost<<endl;
}

/* ---------- Kruskal's Algorithm ---------- */

int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}

void union_set(int i,int j)
{
    parent[j] = i;
}

void kruskal()
{
    int min,a,b,u,v;
    int edges=0;
    int cost=0;

    int temp[MAX][MAX];

    for(int i=0;i<cities;i++)
        for(int j=0;j<cities;j++)
            temp[i][j] = (graph[i][j]==0)?INF:graph[i][j];

    cout<<"\nMinimum Spanning Tree using Kruskal's Algorithm\n";

    while(edges < cities-1)
    {
        min = INF;

        for(int i=0;i<cities;i++)
        {
            for(int j=0;j<cities;j++)
            {
                if(temp[i][j] < min)
                {
                    min = temp[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(u != v)
        {
            cout<<"Route: "<<a<<" - "<<b<<"  Cost: "<<min<<endl;
            union_set(u,v);
            cost += min;
            edges++;
        }

        temp[a][b] = temp[b][a] = INF;
    }

    cout<<"Total Cost = "<<cost<<endl;
}

/* ---------- Main ---------- */

int main()
{
    cities = 5;

    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            graph[i][j]=0;

    /* Transportation Routes */

    addRoute(0,1,2);
    addRoute(0,3,6);
    addRoute(1,2,3);
    addRoute(1,3,8);
    addRoute(1,4,5);
    addRoute(2,4,7);
    addRoute(3,4,9);

    displayGraph();

    prims();
    kruskal();

    return 0;
}