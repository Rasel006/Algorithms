#include<bits/stdc++.h>
using namespace std;
int const N = 1e3+4;
int dp[N][N];
int knapsack(int n,int wet,int v[],int w[]){
    // Base case 
    if(n == 0 || wet == 0) return 0;

    if(dp[n][wet] != -1) return dp[n][wet];

    if(wet >= w[n - 1]){
        int opt1 = v[n - 1] + knapsack(n - 1, wet - w[n - 1], v, w);
        int opt2 = knapsack(n - 1, wet, v,w);
        
        return dp[n][wet] = max(opt1, opt2);
    }
    else{
        return dp[n][wet] = knapsack(n - 1, wet, v, w);
    }

}
int main(){

     int n, wet; cin >> n >> wet;
     int v[n], w[n];
     for (int i = 0; i < n; i++)
     {
        cin >> w[i] >> v[i];
     }

     for(int i = 0; i<= n; i++){
        for (int j = 0; j <= wet; j++)
        {
            dp[i][j] = -1;
        }
        
     }

    int result = knapsack(n, wet, v, w);

    cout << result;
     
      


    return 0;
}