#include<bits/stdc++.h>
using namespace std;

int main(){
    // Take input 
    int n; cin >> n;
    int arr[n];
    int ar_s = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ar_s+= arr[i];
    }
    int defference; cin >> defference;

    int set_one_sum = (defference + ar_s) / 2;

    // use Bottom up 
    int dp[n + 1][set_one_sum + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= set_one_sum; j++)
        {
            if(i, j == 0){
                dp[i][j] = 1;
                continue;
            }
            if(i == 0){
                dp[i][j] = 0;
                continue;
            }

            // Btm 
            if(j >= arr[i - 1]){
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
        
    }

    // for (int i = 0; i <=n; i++)
    // {
    //     for (int j = 0; j <= set_one_sum; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    cout << dp[n][set_one_sum];
    
    
    return 0;
}