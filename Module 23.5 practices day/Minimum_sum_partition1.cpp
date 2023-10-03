
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
//   const int N = 1e3 + 1;
//   int dp[N][N];
	int minDifference(int arr[], int n)  { 
	   
	   int s = 0; 
	   for(int i = 0; i < n; i++){
	       s+= arr[i];
	   }
        
       bool dp[n + 1][s + 1];
       
       for(int i = 0; i <=n; i++){
           for(int j = 0; j<= s; j++){
               if(i, j == 0){
                   dp[i][j] = true;
                   continue;
               }
               if(i == 0){
                   dp[i][j] = false;
                   continue;
               }
               
               if(j >= arr[i - 1]){
                   dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
               }
               else{
                   dp[i][j] = dp[i - 1][j];
               }
           }
       }
       
       vector<int> v;
       for(int i = 0; i <=n; i++){
           for(int j = 0; j<= s; j++){
               if(dp[i][j] == 1){
                   v.push_back(j);
               }
           }
       }
        
        int ans = INT_MAX;
        for(auto val : v){
            ans = min(ans, abs(val - (s - val)));
        }
        return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends