#include<bits/stdc++.h>

using namespace std;

int dp[1000] [1000];

bool unboundSS(int N,int ar[],int S)
{
     
    if(N==0)
    {
        if(S==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if(dp[N][S]!=-1)
    {
        return dp[N][S];
    }
    if(S>=ar[N-1])
    {
        bool op1_will_take=unboundSS(N,ar,S-ar[N-1]);

        bool op2_will_not_take=unboundSS(N-1,ar,S);

        return dp[N][S]=op1_will_take || op2_will_not_take;
    }
    else
    {
        return dp[N][S]=unboundSS(N-1,ar,S);
    }

}

int main()
{
    int test;
    cin>>test;

    while(test--)
    {
        int N,k;
         cin>>N>>k;

        int ar[N];
        for(int i=0;i<N;i++)
        {
            cin>>ar[i];
        }
        
        int def=abs(k-1000);

        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=def;j++)
            {
                dp[i][j]=-1;
            }
            
        }
        
        bool rslt=unboundSS(N,ar,def);
        
        if(rslt)
        {
             cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    

    return 0;
}