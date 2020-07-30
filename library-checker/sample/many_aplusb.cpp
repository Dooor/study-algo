#include <iostream>

using namespace std;

int main(void)
{
    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        long a;
        long b;

        cin >> a >> b;

        cout << a + b << "\n";
    }

    return 0;
}