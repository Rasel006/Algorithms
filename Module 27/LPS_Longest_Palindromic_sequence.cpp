#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string a; cin >> a;

    string b = a;
    reverse(b.begin(), b.end());


    int n = a.size();
        
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }

            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
    }
    
    int i = n;
    int j = n;
    string ans;
    while (i != 0 && j !=  0)
    {
        if(a[i - 1] == b[j - 1]){
            ans += a[i - 1];
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

    reverse(ans.begin(), ans.end());

    cout << ans << endl;
    

    return 0;
}