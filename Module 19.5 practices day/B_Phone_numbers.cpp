#include<bits/stdc++.h>
using namespace std;

int main(){

     int n; cin >> n;

     if(n % 2 == 0) // means n is even 
    {
        string s; cin >> s;
        for (int i = 0; i < s.size(); i+=2)
        {
            cout << s[i] << s[i+1];
            if(i != s.size()-2) cout << "-" ;
        }
    }
    else{
         string s; cin >> s;
         cout << s[0] << s[1] << s[2];
        if(s.size() != 3) cout << "-" ;
        for (int i = 3; i < s.size(); i+=2)
        {
            cout << s[i] << s[i+1];
            if(i != s.size()-2) cout << "-" ;
        }
    }

    return 0;
}