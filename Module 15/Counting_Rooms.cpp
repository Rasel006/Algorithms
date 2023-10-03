#include<bits/stdc++.h>
using namespace std;
// Create the a vector that can store the value of the input 
const int N = 1e3; 
int n , m;
vector<string> graph_Matrix;
bool visited[N][N];
bool isValid(int i, int j){
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void DFS(int i, int j){
    if(!isValid(i, j)) return;
    if(graph_Matrix[i][j] == '#') return;
    if(visited[i][j] == true) return;
 
    visited[i][j] = true;
 
    DFS(i , j + 1);
    DFS(i  , j - 1);
    DFS(i + 1 , j);
    DFS(i - 1 , j);
}
 
int main(){
    
    // Take input 
    cin >> n >> m;
    
    for (int i = 0; i < n ; i++)
    {
        string s; cin >> s;
        graph_Matrix.push_back(s);
    }
    
    // Find the number of rooms
    int cnt = 0;  
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(visited[i][j] == true) continue;
            if(graph_Matrix[i][j] == '#') continue;
            DFS(i, j);
            cnt++;
        }
        
    }
 
    cout << cnt << endl;
    
 
 
 
    return 0;
}