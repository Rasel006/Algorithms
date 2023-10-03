#include<bits/stdc++.h>
using namespace std;

int main(){
    // Take input 
     int n; cin>> n;

     int v[n+1], w[n + 1];
    
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> w[j];
    }

    int weight; cin >> weight;
    // 0 1 knapsack 
    int Dp[n + 1][weight + 1];

    // Bottom Up Aproaceh 
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= weight; j++)
    //     {
    //         if(i == 0 || j == 0) Dp[i][j] = 0; // for 0 items and 0 knapsack 
    //     }
        
    // }
    
    // for (int i = 1; i <= n; i++) long prosese ^
    for (int i = 0; i <= n; i++)
    {
        // for (int j = 1; j <= weight; j++)
        for (int j = 0; j <= weight; j++)
        {
             if(i == 0 || j == 0){// for 0 items and 0 knapsack 
                    Dp[i][j] = 0; 
                    continue;
            }
            if(j >= w[i - 1]){
                // int opt1_nibo = Dp[i - 1][j - w[i - 1]] + v[i - 1];
                // int opt2_niboNa = Dp[i - 1][j];

                // Dp[i][j] = max(opt1_nibo, opt2_niboNa);
           
                Dp[i][j] = max(v[i-1] + Dp[i - 1][j - w[i - 1]], Dp[i - 1][j]);
            }

            else{
                Dp[i][j] = Dp[i - 1][j];
            }
        }
    }




      for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= weight; j++)
        {
            cout << Dp[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}