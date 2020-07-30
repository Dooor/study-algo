#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct StaticRangeSum
{
    vector<long> org;
    vector<long> pre;

    void resize(int n)
    {
        org.resize(n);
        pre.resize(n);
    }

    void preCompute()
    {
        pre[0] = org[0];
        for (int i = 1; i < org.size(); i++)
        {
            pre[i] = org[i] + pre[i-1];
        }
    }

    long rangeSum(int i, int j)
    {
        if (i == 0)
        {
            return pre[j - 1];
        }

        return pre[j- 1] - pre[i - 1];
    }
};

int main()
{
    int n, q;

    cin >> n >> q;

    StaticRangeSum static_range_sum;
    static_range_sum.resize(n);
    for (int i = 0; i < n; i++) cin >> static_range_sum.org[i];

    static_range_sum.preCompute();

    while(q--)
    {
        long l, r;

        cin >> l >> r;
        cout << static_range_sum.rangeSum(l, r) << endl;
    }
}