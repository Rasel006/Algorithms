#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int parentLevel[1000];

void Dsu_Set(int n){
    // while (n--)
    // {
    //     parent[n] = -1;
    //     parentLevel[n] = 1;
    // }
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentLevel[i] = 0;
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

        if(parentLevel[leader_A] > parentLevel[leader_B]){
            parent[leader_B] = leader_A;
        }
        else if(parentLevel[leader_A] == parentLevel[leader_B]){
            parent[leader_B] = leader_A;
            parentLevel[leader_A]++;
        }
        else{
            parent[leader_A] = leader_B;
        }
    }
}
int main(){

    int n, e; cin >> n >> e;

    Dsu_Set(n + 1);

    while (e--)
    {
        int a, b; cin >> a >> b;
        int leaderA = Dsu_find(a);
        int leaderB = Dsu_find(b);

        if(leaderA == leaderB){
            cout << "Cycle Detectd in  :" << a << " " << b << endl;
        }
        else{
            Dsu_union(a,b);
        }
    }
    
     
    return 0;
}