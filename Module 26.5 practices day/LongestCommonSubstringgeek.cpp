
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int dp[n + 1][m + 1];
        
        for(int i = 0; i<= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        int ci , cj; 
        int max = 0;
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(dp[i][j] > max){
                    max = dp[i][j];
                }
            }
        }
        
        string ans;
        while (ci != 0 && cj != 0){
            if(s1[ci - 1] == s2[cj - 1]){
                ans+= s1[ci - 1];
                ci--;
                cj--;
            }
            else{
                break;
            }
        }
        
        reverse(ans.begin(), ans.end());
        return max;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends