#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int knapsack(int n, int s, int* v, int* w)
{
    if(n == 0 || s == 0) return 0; 
    if(dp[n][s] != -1) return dp[n][s];
    if(w[n - 1] <= s)
    {
        int op1 = knapsack(n - 1, s - w[n - 1], v, w) + v[n - 1];
        int op2 = knapsack(n - 1, s, v, w);
        //dp[n][s] = max(op1, op2);
        return dp[n][s] = max(op1, op2);
    }
    else
    {
        return dp[n][s] = knapsack(n - 1, s, v, w);
    }
}
int main()
{
    int n,s;
    cin >> n >> s;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }
    int weight[n], value[n];
    for(int i = 0; i < n; i++)
    {
        cin >> weight[i];
        cin >> value[i];
    }
    cout << knapsack(n, s, value, weight);
    cout << endl;
    // for(int i = 0; i <= n; i++)
    // {
    //     for(int j = 0; j <= s; j++)
    //     {
    //         cout << dp[n][s] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}