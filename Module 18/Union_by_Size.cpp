#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int parentSize[1000];

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
        // else if (parentSize[leader_A] == parentSize[leader_B])
        // {
        //      parent[leader_B] = leader_A;
        //     parentSize[leader_A] += parentSize[leader_B];
        // }
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


     for (int i = 1; i <= n; i++)
    {
        cout << "Leader Of " << i << " is : " << Dsu_find(i) << endl;
    
    }

     

    return 0;
}