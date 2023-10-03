#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e5+9;
ll arr[N];

int main(){
    // Take input 
    ll n; cin >> n;
    
    arr[0] = 1;
    arr[1] = 1;

    // loop Fibonacci 
    for (ll i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    
    cout << arr[n];

    return 0;
}