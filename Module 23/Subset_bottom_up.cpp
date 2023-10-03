#include<bits/stdc++.h>
using namespace std;

int main(){

     int n,s; cin >> n >> s;
     int arr[n];

     for (int i = 0; i < n; i++)
     {
        cin >>arr[i];
     }
     
    //  int s ; cin >> s;

    //  Create the dp 
    bool Dp[n + 1][s + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            // Base case like 
            if(i == 0 && j == 0){
                Dp[i][j] = true;
                continue;
            }
            if(i == 0){
                Dp[i][j] = false;
                continue;
            }
            
            // main Tabulation 
            if(j >= arr[i - 1]){
                bool opt1_nibo = Dp[i - 1][j - arr[i - 1]];
                bool opt2_nibo_na = Dp[i - 1][j];

                Dp[i][j] = opt1_nibo || opt2_nibo_na; 
            }
            else{
                Dp[i][j] = Dp[i - 1][j];
            }
        }
        
    }
//    for (int i = 0; i <= n; i++)
//    {
//     for (int j = 0; j <= s; j++)
//     {
//          if(Dp[i][j]) cout << "YES" << " ";
//         else cout << "NO" << " ";
//     }
//     cout << endl;
//    }
   cout  << Dp[n][s];
    return 0;
}