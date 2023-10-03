#include<bits/stdc++.h>

using namespace std;

int dp[1000][1000];

bool SS(int n,int ar[],int s)
{
     
    if(n==0)
    {
        if(s==0)
        { 
            return true;
        }
        else
        { 
            return false;
        }
    }

    if(dp[n][s]!=-1)
    {
        return dp[n][s];
    }

    if(s>=ar[n-1])
    {
        bool op1_will_take=SS(n-1, ar,s-ar[n-1]);
        bool op2_will_not_take=SS(n-1,ar,s);

        return dp[n][s]=op1_will_take || op2_will_not_take;
    }
    else
    {
        return dp[n][s]=SS(n-1,ar,s);
    }

}
int main()
{
    int test;
    cin>>test;

    while(test--)
    {
        int n,k;
        cin>>n>>k;

        int ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        
        int Def=abs(k-1000);

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=Def;j++)
            {
                dp[i][j]=-1;
            }
            
        }
        
        bool rslt=SS(n,ar,Def);
        
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