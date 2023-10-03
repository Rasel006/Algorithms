#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int parent[N];
int parentSize[N];

void Union_Set(int n){
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        parentSize[i] = 1;
    }
    
}

int Union_Find(int node){
    if (node == parent[node]) return node;

     return parent[node] = Union_Find(parent[node]);
    
}

void Union(int a, int b){
    int leaderA = Union_Find(a);
    int leaderB = Union_Find(b);

    if(leaderA != leaderB){
            parent[leaderB] = leaderA;
    }
}

int main(){

     int n, e; cin >> n;
     e = n - 1;
     Union_Set(n);
    vector<pair<int, int>> listOfCycles;
     while (e--)
     {
        int a, b;
        cin >> a >> b;

        int leaderA = Union_Find(a);
        int leaderB = Union_Find(b);

        if(leaderA == leaderB){
            listOfCycles.push_back({a, b});
        }

        Union(a, b);
     }
    vector<pair<int, int>> NewConnection;

    for (int i = 2; i <= n; i++)
    {
        int leaderofi = Union_Find(i);
        int leaderofj = Union_Find(i-1);
        if(leaderofj == leaderofi) continue;
        else{
            NewConnection.push_back({1, i});
            Union(i-1,i);
        }
    }
    cout << listOfCycles.size() << endl;
    for (int i = 0; i < NewConnection.size(); i++)
    {
        cout << listOfCycles[i].first << " " << listOfCycles[i].second << " ";
        cout << NewConnection[i].first << " " << NewConnection[i].second << endl;
         
    }
    
     
    

    return 0;
}