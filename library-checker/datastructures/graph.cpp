#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

using Graph = vector<vector<int>>;

bool search(Graph graph, int u, int goal, vector<bool> seen)
{
    seen[u] = true;

    for (int next_v: graph[u])
    {
        if (seen[next_v]) continue;

        if (next_v == goal)
        {
            return true;
        }

        return search(graph, next_v, goal, seen);
    }

    return false;
}

int main()
{
    int n, q;

    cin >> n >> q;

    Graph graph(n);
    vector<bool> seen =  vector<bool>(n);

    while(q--)
    {
        int type, u, v;

        cin >> type >> u >> v;

        if (type == 0)
        {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if (type == 1)
        {
            seen.assign(n, false);
            if (search(graph, u, v, seen))
            {
                printf("%i\n", 1);
            }
            else
            {
                printf("%i\n", 0);
            }
        }
    }

    return 0;   
}