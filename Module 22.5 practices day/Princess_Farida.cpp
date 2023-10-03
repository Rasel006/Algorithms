#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        int n;
        cin >> n;
        long long int dp[n + 1];
        memset(dp, 0, sizeof(dp));
 
        for (int i = 0; i < n; i++)
        {
            cin >> dp[i];
        }
 
        dp[1] = max(dp[0], dp[1]);
 
        if (n == 0)
        {
            printf("Case %d:  %d\n",j,0);
        }
        else if (n == 1)
        {
            printf("Case %d:  %lld\n", j, dp[0]);
        }
        else if (n == 2)
        {
 
            printf("Case %d:  %lld\n", j, dp[1]);
        }
        else
        {
            for (int i = 2; i < n; i++)
            {
                dp[i] = max(dp[i - 1], dp[i] + dp[i - 2]);
            }
            printf("Case %d:  %lld\n", j, dp[n - 1]);
        }
    }
 
    return 0;
} 