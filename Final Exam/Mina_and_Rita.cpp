#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;

    while(test--)
    {
        string x, y;

        cin>>x>>y;

        int u,v;

        u=x.size();
        v=y.size();

        int dp[u+1][v+1];

        for(int i=0;i<=u;i++)
        {
            for(int j=0;j<=v;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;

                    continue;
                }

                if(x[i-1]==y[j-1])

                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }

                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int i=u;
        int j=v;

        string Answer;
        
        while(i!=0 && j!=0)
        {
            if(x[i-1]==y[j-1])
            {
                Answer+=x[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                Answer+=x[i-1];
                i--;
            }
            else
            {
                Answer+=y[j-1];
                j--;
            }
        }

        while(i!=0)
        {
            Answer+=x[i-1];
            i--;
        }

        while(j!=0)
        {
            Answer+=y[j-1];
            j--;
        }

        reverse(Answer.begin(),Answer.end());
        cout<<Answer.size()<< endl;
    }

    return 0;
}