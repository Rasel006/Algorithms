#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Take input 
    int n;
    cin >> n;
    
    int arr[n];
    int sum_arr = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum_arr += arr[i];
    }

    if (sum_arr % 2 == 0)
    {
        int s = sum_arr / 2;

        bool dp[n + 1][s + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (i, j == 0)
                {
                    dp[i][j] = true;
                    continue;
                }

                if (i == 0)
                {
                    dp[i][j] = false;
                    continue;
                }

                // bottom up 
                if(j >= arr[i - 1]){
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if(dp[n][s]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}