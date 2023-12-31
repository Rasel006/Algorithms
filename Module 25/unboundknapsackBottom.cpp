#include<bits/stdc++.h>
using namespace std;

int main(){
    // Take input
     int n, w; cin >> n >> w;
     int v[n],wt[n];

     for (int i = 0; i < n; i++)
     {
        cin >> v[i];
     }
     for (int i = 0; i < n; i++)
     {
        cin >> wt[i];
     }
     
    // Apply the bottow 
    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }

            // btm 
            if(j >= wt[i - 1]){
                dp[i][j] = max(dp[i][j - wt[i - 1]] + v[i - 1], dp[i - 1][j]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
        
    }
    
    cout << dp[n][w];
     

    return 0;
}