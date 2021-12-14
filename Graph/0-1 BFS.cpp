#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> MyGraph[200200];

void addEdge(int u, int v, int w)
{
    // w is 0 or 1
    MyGraph[u].push_back({v, w});
    MyGraph[v].push_back({u, w});
    return;
}

vector<int> Bfs01(int start)
{
    deque<int> q;
    vector<int> distance(n + 1, 1e8);
    q.push_front(start);
    distance[start] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop_front();
        for (auto pairSon : MyGraph[parent])
        {
            int son = pairSon.first;
            int weight = pairSon.second;
            if (distance[son] > distance[parent] + weight)
            {
                distance[son] = distance[parent] + weight;
                if (weight == 0)
                    q.push_front(son);
                else
                    q.push_back(son);
            }
        }
    }
    return distance;
}
int main()
{
    n = 8;
    addEdge(1, 5, 0);
    addEdge(1, 2, 1);
    addEdge(2, 3, 0);
    addEdge(3, 4, 1);
    addEdge(5, 6, 1);
    addEdge(6, 7, 1);
    addEdge(5, 4, 0);
    int sorce = 1;
    vector<int> Dist = Bfs01(sorce);
    for (int i = 1; i <= n; i++)
    {
        if (Dist[i] == 1e8)
            cout << "There is no path from " << sorce << " to " << i << endl;
        else
            cout << "The length from " << sorce << " to " << i << " is " << Dist[i] << endl;
    }
    return 0;
}
