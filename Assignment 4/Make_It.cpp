#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int dp[N];

bool CHOI(int n,long long u){
    
    if(n==u)
    {
        return true;
    }
    else if(u>n)
    {
        return false;
    }

    if(dp[u]!=-1)
    {
        return dp[u];
    }

    bool op1=CHOI(n,u+3);
    bool op2=CHOI(n,u*2);

    return dp[u]=op1 || op2;
}

int main(){
    int k;
    cin>>k;

    while(k--)
    {
        int n;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            dp[i]=-1;
        }
        bool rslt=CHOI(n,1);

        if(rslt)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}