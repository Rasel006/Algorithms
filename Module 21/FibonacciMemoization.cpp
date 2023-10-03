#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e5+5;
ll save[N]; 
// Fibonacci Memoization 
ll Fibonacci(ll n){

    if(n == 0 || n == 1) return 1;
    
    if(save[n] != -1) return save[n];

    ll ans1 = Fibonacci(n - 1);
    ll ans2 = Fibonacci(n - 2);
    save[n] = ans1 + ans2;
    return save[n];
}
int main(){
    // TAkeinput
     ll n; cin >> n;
    for (int i = 0; i <= n; i++)
    {
        save[i] = -1;
    }
    
    ll result = Fibonacci(n);

    cout << result << endl;
    

    return 0;
}