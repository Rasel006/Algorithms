#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int DP_V[N];
int Solve(int arr[],int n){
    if (n == 1)
    {
        return 0;
    }

    if(DP_V[n] != -1) return DP_V[n];
    
    else if(n == 2){
        return DP_V[n] = abs(arr[2] - arr[1]);
    }

    else{

        int choice = Solve(arr, n - 1) + abs(arr[n] - arr[n - 1]);
        int choice2 = Solve(arr, n - 2) + abs(arr[n] - arr[n - 2]);
        return DP_V[n] = min(choice, choice2);
    }
    
}
int main(){

     int n; cin >> n;

     int arr[n+1];

     for (int i = 1; i <= n; i++)
     {
        DP_V[i] = -1;
        cin >> arr[i];
     }

     cout << Solve(arr, n);
     

    return 0;
}