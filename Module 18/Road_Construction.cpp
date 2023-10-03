#include<bits/stdc++.h>
using namespace std;
// Create the variables and array 
const int N = 1e5+5;
int UnionSize[N];
int parent[N];
int mx = 0;

// Create the Union set 
void Union_Set(int n){
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        UnionSize[i] = 1;
    }
}

// Create the Union find funtion  
int Union_Find(int u){
    if(u == parent[u]) return u;

    return parent[u] = Union_Find(parent[u]);
}

// Create the Union funtion  
void Union(int a, int b){
    int leaderA = Union_Find(a);
    int leaderB = Union_Find(b);

    if(leaderA != leaderB){
        if(UnionSize[leaderA] >= UnionSize[leaderB]){
            parent[leaderB] = leaderA;
            UnionSize[leaderA] += UnionSize[leaderB];
            mx = max(mx, UnionSize[leaderA]);
        }
        else
        {
            parent[leaderA] = leaderB;
            UnionSize[leaderB] += UnionSize[leaderA]; 
            mx = max(mx, UnionSize[leaderB]);
        }
        
    }
}

int main(){
    
    // Take input 
    int n , e; cin >> n >> e;
    int components = n;

    Union_Set(n);
    
    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = Union_Find(a);
        int leaderB = Union_Find(b);
        if(leaderA != leaderB){
            components--;
            Union(a, b);
        }
        cout << components << " " << mx << endl;
    }
    


     

    return 0;
}