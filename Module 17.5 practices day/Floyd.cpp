#include<bits/stdc++.h>
using namespace std;

int main(){
    
    // Taken Input 
     int n; cin >> n;
     
     int Dis[n+1][n+1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x; cin >> x;
            if(x == -1) x = 10000;
            Dis[i][j] = x;
        }
        
    }

    // Aplly the Folyd WarShall 
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                Dis[i][j] = min(Dis[i][j], Dis[i][k] + Dis[k][j]);
            }
            
        }
        
    }
    
    // Print the resutl  
    int maximum = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(Dis[i][j] < 10000){
                maximum = max(maximum, Dis[i][j]);
            }
        }
    }

    cout << maximum << endl;
    

    return 0;
}