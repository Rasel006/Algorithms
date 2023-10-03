#include<bits/stdc++.h>
using namespace std;

int main(){
    // Take input 
     string s1, s2; 
     cin >> s1 >> s2;
    
    // Find the size 
    int n = s1.size();
    int m = s2.size();

    // make the dp 

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }

            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
    }

    int i = n;
    int j = m;

    string ans; 

    while (i != 0 && j != 0)
    {
        if(s1[i - 1] == s2[j - 1]){
            ans+= s1[i - 1];
            i--;
            j--;
        }
        else{
            if(dp[i - 1][j] < dp[i][j - 1]){
                j--;
            }
            else{
                i--;
            }
        }
    }

    reverse(ans.begin(),ans.end());

    cout << ans << endl;
    
    



    
         

    return 0;
}