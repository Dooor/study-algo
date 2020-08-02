#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
  int n, q;

  cin >> n >> q;

  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];

  int lookup[n][(int)log2(n) + 1];
  for (int i = 0; i < n; i++) lookup[i][0] = i;

  for (int j = 1; (1<<j) <= n; j++)
  {
    for (int i = 0; (i + (1<<j) - 1) < n; i++)
    {
      if (arr[lookup[i][j-1]] < arr[lookup[i + (1 << (j-1))][j-1]])
      {
        lookup[i][j] = lookup[i][j-1];
      }
      else
      {
        lookup[i][j] = lookup[i + (1 << (j-1))][j-1];
      }

    }
  }

  while(q--)
  {
    int l, r;

    cin >> l >> r;

    r = r - 1;

    int j = (int)log2(r - l + 1);

    if (arr[lookup[l][j]] <= arr[lookup[r - (1<<j) + 1][j]])
    {
      cout << arr[lookup[l][j]] << "\n";
    }
    else
    {
      cout << arr[lookup[r - (1<<j) + 1][j]] << "\n";
    }
  }
}
