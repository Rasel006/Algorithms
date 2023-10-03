#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Take input
    int n;
    cin >> n;
    int arr[n];
    int sum_of_arr = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum_of_arr += arr[i];
    }

    // Create the dp
    bool dp[n + 1][sum_of_arr + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum_of_arr; j++)
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

            // Bottom up
            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    vector<int> set1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum_of_arr; j++)
        {
            if (dp[i][j] == 1)
                set1.push_back(j);
        }
    }

    int result = INT_MAX;
    for (auto val : set1)
    {
        // nomal way 
        // int s1 = val;
        // int s2 = sum_of_arr - val;
        // result = min(result, abs(s1 - s2));
        // fancy way 

        result = min(result, abs(val - (sum_of_arr - val)));
    }

    cout << result << endl;

    return 0;
}