#include<bits/stdc++.h>
using namespace std;
// Noraml Fibonacci
int Fibonacci(int n){
    if(n == 0 || n == 1) return 1;
     
     return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main(){

        int n; cin >> n;

        int The_Result = Fibonacci(n);

        cout << The_Result;

    return 0;
}