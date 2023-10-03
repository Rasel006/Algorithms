#include<bits/stdc++.h>
using namespace std;

int main(){
    
    // Take input 
    int n; cin >> n;

    int arr[n]; 
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int s; cin >> s;

    // Createe the dp 
    int dp[n + 1][s + 1];

    // Bottom up in subset max 
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if(i == 0 && j == 0){
                dp[i][j] = 1;
                continue;
            } 

            if(i == 0){
                dp[i][j] = 0;
                continue;
            }

            // Bottom up with unbound 
            if(j >= arr[i - 1]){
                dp[i][j] = dp[i][j - arr[i - 1]] + dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }


        }
        
    }
    
    
for (int i = 0; i <= n; i++)
{
    for (int j = 0; j <= s; j++)
    {
        cout << dp[i][j] << " ";
    }
    cout << endl;
    
}
     

    return 0;
}