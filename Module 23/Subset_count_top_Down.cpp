#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
int dp[N][N];
int SubsetCount(int n, int arr[],int s){
    // Base case 
    if(n == 0){
        if(s == 0) return 1;
        else return 0;
    }
    // if i work with same val dp will have 
    if(dp[n][s] != -1) return dp[n][s];

    if(s >= arr[n - 1]){
        int opt1 = SubsetCount(n - 1, arr, s - arr[n - 1]);
        int opt2 = SubsetCount(n - 1, arr, s);
        return dp[n][s] = opt1 + opt2;
    }
    else{
        return dp[n][s] = SubsetCount(n - 1, arr, s);
    }

}

int main(){
    
    // Take input 
     int n; cin >> n;
     int s; cin >> s;

     int arr[n];
     for (int i = 0; i < n; i++) cin >> arr[i];

    //  make the dp -1 
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
        
    }
    

    //  Call Func 
     cout << SubsetCount(n, arr, s);

    return 0;
}