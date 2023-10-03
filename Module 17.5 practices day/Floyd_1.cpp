#include<bits/stdc++.h>
using namespace std;

int main(){
    
    // Taken input 

     int n; cin >> n;
     
     int Distance[n+1][n+1];

     for (int i = 1; i <= n; i++)
     {
        for (int j = 1; j <= n; j++)
        {
            int x; cin >> x; 
            Distance[i][j] = x;
        }
     }

    // Apply the Floyd Warshall
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (Distance[i][j] > Distance[i][k] + Distance[k][j])
                {
                    Distance[i][j] = Distance[i][k] + Distance[k][j];
                }
                
            }
            
        }
        
    }
    
    // Print the output
     for (int i = 1; i <= n; i++)
     {
        for (int j = 1; j <= n; j++)
        {
            
            cout << Distance[i][j] << " ";
        }
        cout << endl;
     }
     
    return 0;
}