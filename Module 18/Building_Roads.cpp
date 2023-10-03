#include<bits/stdc++.h>
using namespace std;
const int N =1e5 + 5; 
int parent[N];
int parentSize[N];

void Dsu_Set(int n){
    // while (n--)
    // {
    //     parent[n] = -1;
    //     parentSize[n] = 1;
    // }
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int Dsu_find(int node){

    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

void Dsu_union(int a, int b){
    int leader_A = Dsu_find(a);
    int leader_B = Dsu_find(b);
    
    if(leader_A != leader_B){
        if (parentSize[leader_A] >= parentSize[leader_B] )
        {
            parent[leader_B] = leader_A;
            parentSize[leader_A] += parentSize[leader_B];
        }
        else{
            parent[leader_A] = leader_B;
            parentSize[leader_B] += parentSize[leader_A];
        }
        
    }
}

int main(){
    
    int n, e; cin >> n >> e;

    Dsu_Set(n+1);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        Dsu_union(a, b);
    }

    map<int, bool> mp;
     for (int i = 1; i <= n; i++)
    {
         int leaders = Dsu_find(i);
         mp[leaders] = true;
    }

    vector<int> v;
    for (auto &&i : mp)
    {
        v.push_back(i.first);
    }

    cout << v.size() - 1 << endl;
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << " " << v[i + 1] << endl;
    }
    
    
    

     

    return 0;
}