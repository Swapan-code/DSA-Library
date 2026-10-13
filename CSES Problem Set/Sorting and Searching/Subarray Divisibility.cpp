#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  unordered_map<int, int> mpp; // {rem, count}
  long long sum = 0;
  mpp[0] = 1;
  long long ans = 0;

  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
    int rem = ((sum % n) + n) % n;

    if (mpp.find(rem) != mpp.end())
    {
      ans += mpp[rem];
      mpp[rem]++;
    }
    else
    {
      mpp[rem] = 1;
    }
  }

  cout << ans;
  return 0;
}

// Time - O(N)
// Space - O(N)
