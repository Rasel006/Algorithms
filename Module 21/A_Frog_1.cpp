#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int dp[N];
int main(){

     int n; cin >> n;
    int cost[n + 1];
     for (int i = 1; i <= n; i++)
     {
        cin >> cost[i];
     }

    //  Solve with loop in dp 
    dp[1] = 0;
    dp[2] = abs(cost[1] - cost[2]);
    for (int i = 3; i <= n; i++)
    {
        int choice1 = dp[i-2] + abs(cost[i] - cost[i - 2]);
        int choice2 = dp[i - 1] + abs(cost[i] - cost[i - 1]);

        dp[i] = min(choice1, choice2); 
    }
    
     cout << dp[n];

    return 0;
}