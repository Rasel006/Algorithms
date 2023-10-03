#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int unboundKnapsack(int n, int s, int v[], int w[])
{
    // base case
    if (n == 0 || s == 0)
        return 0;

    if (dp[n][s] != -1)
        return dp[n][s];

    if (s >= w[n - 1])
    {

        return dp[n][s] = max(unboundKnapsack(n, s - w[n - 1], v, w) + v[n - 1], unboundKnapsack(n - 1, s, v, w));
    }
    else
    {
        return dp[n][s] = unboundKnapsack(n - 1, s, v, w);
    }
}
int main()
{
    // Take input
    int n;
    cin >> n;

    int v[n], w[n];
    // There n i the cpacity and the 1 - 8 is the weight
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        w[i] = i + 1;
    }

    // make the dp and initalize the -1 /
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << unboundKnapsack(n, n, v, w);

    return 0;
}