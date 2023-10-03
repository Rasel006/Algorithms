#include<bits/stdc++.h>
using namespace std;
bool checkresult(long long int n, long long int x){
    // base case 
    if(n == x) return true;
    else if (n < x) return false;
    return checkresult(n, x * 10) || checkresult(n, x * 20);
}
int main(){

     int testcase; cin >> testcase;

     while (testcase--)
     {
        long long int n; cin >> n;
        bool result  = checkresult(n, 1);
        
        if(result) cout << "YES" << endl;
        else cout << "NO" << endl;
     }
     

    return 0;
}