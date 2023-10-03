#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int dp[N][N];

int knapsack(int n,int s,int a[],int w[]){

    if(s==0 || n==0)
        return 0;

    if(dp[n][s]!=-1)
        return dp[n][s];

    if(w[n-1]<=s)
    {
        int op1=knapsack(n-1, s-w[n-1],a,w)+a[n-1];
        int op2=knapsack(n-1,s,a,w);

        return dp[n][s]=max(op1,op2);
    }

    else
    {
       return dp[n][s]=knapsack(n-1, s,a,w);
    }
}

int main(){
    int k;
    cin>>k;

    while(k--)
    {
        int n;
        cin>>n;

        int s;
        cin>>s;

        int a[n],w[n];

        for(int i=0;i<n;i++)
        {
            cin>>w[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                dp[i][j]=-1;
            }
        }
        int result=knapsack(n,s,a,w);
        cout<<result<<endl;
    }

    return 0;
}