#include <iostream>
#include <map>

using namespace std;

int main()
{
    int q;

    cin >> q;

    map<long, long> mp;

    while (q--)
    {
        int type;

        cin >> type;

        if (type == 0)
        {
            long k, v;
            cin >> k >> v;

            mp[k] = v;
        }
        if (type == 1)
        {
            long k;
            cin >> k;

            cout << mp[k] << "\n";
        }
    }
    
    return 0;
}