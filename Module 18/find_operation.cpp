#include<bits/stdc++.h>
using namespace std;
// Create the arrray 
int parent[8] = {-1,-1,1,1,6,4,-1,-1};
// Create the finding function 
void find(int n){
    
    while (parent[n] != -1)
    {
        n = parent[n];
    }
    cout << n << endl;
}

int main(){

    for (int i = 0; i < 8; i++)
    {
        cout << "Leader Of " << i << " is : ";
        find(i);
    }
    
    return 0;
}