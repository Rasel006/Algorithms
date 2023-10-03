#include<bits/stdc++.h>
using namespace std;

int main(){

     string s1;
     cin >> s1;

     int n = s1.size();

     string s2 = s1;
     reverse(s2.begin(), s2.end());
     
     int dp[n + 1][n + 1];

     for (int i = 0; i <= n; i++)
     {
        for (int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }

            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
        
     }
     }
     
    cout << "The number of minimun deletion we need to find the palindomic string :" << abs(n - dp[n][n]);
    return 0;
}