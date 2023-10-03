#include<bits/stdc++.h>
using namespace std;
int Dp[1005][1005];

bool Subset(int n,int arr[],int s){
     
    //  Base case 
    if(n == 0){
        if(s == 0) return true;
        else return false;
    }
    if(Dp[n][s] != -1) return Dp[n][s];
    if(s >= arr[n - 1]){
        bool oparation1_nibo = Subset(n - 1, arr, s - arr[n - 1]);
        bool oparation2_nobona = Subset(n - 1 , arr, s);

        return Dp[n][s] = oparation1_nibo || oparation2_nobona;
    }
    else{
        return Dp[n][s] = Subset(n - 1, arr, s);
    }

}
int main(){

     int n; cin >> n;

     int arr[n];
     for (int i = 0; i < n; i++)
     {
        cin >> arr[i];
     }
    int s; cin >> s;

     for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            Dp[i][j] = -1;
        }
        
    }
    
    bool subset_found = Subset(n, arr, s);
     
     if(subset_found) cout << "YES" << endl;
     else cout << "NO" << endl;

    return 0;
}