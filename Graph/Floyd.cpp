#include <bits/stdc++.h>
using namespace std;

int n, m,
int Distance[555][555];
void addEdge(int u, int v, int w)
{
    // Directed and Weighted
    Distance[u][v] = w;
    // if The Graph is Undirected add Distance[v][u] = w
    return;
}
void Initiate()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            Distance[i][j] = 1e9;
    for(int i = 1; i <= n; i++)
        Distance[i][i] = 0;
}
void Floyd()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                Distance[i][j] = min(Distance[i][j], Distance[i][k] + Distance[k][j]);
}

int main()
{
    n = 5;

    Initiate();

    addEdge(1, 3, 2);
    addEdge(1, 2, 2);
    addEdge(2, 4, 3);
    addEdge(4, 5, 8);
    addEdge(1, 4, 6);

    Floyd();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (Distance[i][j] == 1e8)
                cout << "There is no path form " << i << " to " << j << endl;
            else
                cout << "Shortest Path from " << i << " to " << j << " is " << Distance[i][j] << endl;
        }
        cout << "\n--------------\n";
    }
    return 0;
}
