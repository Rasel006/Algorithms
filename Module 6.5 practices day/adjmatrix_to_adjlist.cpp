#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>> n;
    int adjmat[n+1][n+1];
    vector<int> adjlist[n+1];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> adjmat[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
           if(adjmat[i][j] == 1)
           {
                adjlist[i].push_back(j);
                // adjlist[j].push_back(i);
           }
        }
        
    }
    for(int i = 1; i <= n; i++)
    {
        cout << "List " << i << " : ";
        for(int val : adjlist[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}