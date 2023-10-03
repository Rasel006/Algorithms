#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];

int unboundKnapsack(int n, int tw, int wts[], int vls[])
{
    // Base case
    if (n == 0 || tw == 0)
        return 0;

    // Dp work
    if (dp[n][tw] != -1)
        return dp[n][tw];
    // unboundKnapsack
    if (tw >= wts[n - 1])
    {
        int choice1 = vls[n - 1] + unboundKnapsack(n, tw - wts[n - 1], wts, vls); // change in here for the Knapsack
        int choice2 = unboundKnapsack(n - 1, tw, wts, vls);
        return dp[n][tw] = max(choice1, choice2);
    }
    else
    {
        return dp[n][tw] = unboundKnapsack(n - 1, tw, wts, vls);
    }
}
int main()
{
    // Take input
    int n, totalW;
    cin >> n >> totalW;

    int values[n], weights[n];
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }


    //  Add -1 all i j in dp
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= totalW; j++)
        {
            dp[i][j] = -1;
        }
    }


    //  Call the unbound function
    cout << unboundKnapsack(n, totalW, weights, values);

    return 0;
}