#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct UnionFind
{
    vector<int> parent;

    void resize(int size)
    {
        parent.resize(size);
    }

    void make(int index)
    {
        parent[index] = index;
    }

    int root(int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    void merge(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y) return;

        parent[x] = y;
    }

    bool same(int x, int y)
    {
        return root(x) == root(y);
    }
};

int main()
{
    int n, q;

    cin >> n >> q;

    UnionFind unionfind;
    unionfind.resize(n);

    for (int i = 0; i < n; i++) unionfind.make(i);

    while(q--)
    {
        int type, u, v;

        cin >> type >> u >> v;

        if (type == 0)
        {
            unionfind.merge(u, v);
        }
        if (type == 1)
        {
            if (unionfind.same(u, v)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }

    return 0;   
}