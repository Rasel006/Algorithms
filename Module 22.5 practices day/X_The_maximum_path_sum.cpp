#include<bits/stdc++.h>
using namespace std;
int arr[11][11];
int n, m;
int maxPath(int i, int j){
  // base case normal 
    if(i == n - 1 && j == m - 1) return arr[i][j];
    // base case beyon bound 
    if(i == n + 1 || j  == m + 1) return -1000000;
    
    // Call paths 
    int callRight = maxPath(i, j + 1);
    int callDown = maxPath(i + 1, j);
    // cout << i << j << endl;
    return arr[i][j] + max(callRight, callDown);
}
int main(){
  // Take input
     cin >> n >> m;
     for (int i = 0; i < n; i++)
     {
        for (int j = 0; j < m; j++)
        {
          cin>>arr[i][j];
        }
        
     }

    //  Call the function
    cout << maxPath(0, 0);
    

     

    return 0;
}