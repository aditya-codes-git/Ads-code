#include <iostream>
using namespace std;

#define V 5
#define INF 999

int graph[V][V] = {
    {0,2,0,6,0},
    {2,0,3,8,5},
    {0,3,0,0,7},
    {6,8,0,0,9},
    {0,5,7,9,0}
};

int parent[V];

int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}

void uni(int i,int j)
{
    if(i!=j)
        parent[j]=i;
}

void prims()
{
    int visited[V]={0};
    int edges=0;
    int min,x=0,y=0;

    visited[0]=1;

    cout<<"\nPrim's Minimum Spanning Tree:\n";

    while(edges < V-1)
    {
        min=INF;

        for(int i=0;i<V;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<V;j++)
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

        cout<<x<<" - "<<y<<" : "<<graph[x][y]<<endl;
        visited[y]=1;
        edges++;
    }
}

void kruskal()
{
    int edges=0,a,b,u,v,min;

    cout<<"\nKruskal's Minimum Spanning Tree:\n";

    int temp[V][V];

    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            temp[i][j]=graph[i][j]==0?INF:graph[i][j];

    while(edges < V-1)
    {
        min=INF;

        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(temp[i][j] < min)
                {
                    min=temp[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }

        u=find(u);
        v=find(v);

        if(u!=v)
        {
            cout<<a<<" - "<<b<<" : "<<min<<endl;
            uni(u,v);
            edges++;
        }

        temp[a][b]=temp[b][a]=INF;
    }
}

int main()
{
    prims();
    kruskal();
}