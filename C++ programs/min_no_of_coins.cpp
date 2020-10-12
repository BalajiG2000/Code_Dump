#include <bits/stdc++.h>
using namespace std;

// question - https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

//dp solution
// Time Complexity = O(mV)
int minCoins_dp(int coins[], int m, int V)
{
  vector<int> dp(V + 1);
  dp[0] = 0;
  for (int i = 1; i <= V; i++)
    dp[i] = INT_MAX;

  for (int i = 1; i <= V; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (coins[j] <= i)
      {
        int sub_res = dp[i - coins[j]];
        if (sub_res != INT_MAX && sub_res + 1 < dp[i])
          dp[i] = sub_res + 1;
      }
    }
  }
  return dp[V];
}

//recursive solution
// exponential complexity
int minCoins_recurrsive(int coins[], int m, int V)
{
  if (V == 0)
    return 0;

  int res = INT_MAX;

  for (int i = 0; i < m; i++)
  {
    if (coins[i] <= V)
    {
      int sub_res = minCoins_recurrsive(coins, m, V - coins[i]);

      if (sub_res != INT_MAX && sub_res + 1 < res)
        res = sub_res + 1;
    }
  }
}
