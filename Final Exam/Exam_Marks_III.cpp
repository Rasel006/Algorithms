#include<bits/stdc++.h>

using namespace std;

int main()
{

    int test;

    cin>>test;

    while(test--)
    {
        int N;

        cin>>N;

        int k;
        
        cin>>k;

        int w[N];

        for(int i=0;i<N;i++)
        {
            cin>>w[i];
        }

        int S=abs(k-1000);

        int dp[N+1][S+1];

        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=S;j++)

            {
                if (i==0 && j==0)
                {
                    dp[i][j]=0;

                    continue;
                }

                if(i==0)
                {
                    dp[i][j]=INT_MAX-1;

                    continue;
                }

                if (j>=w[i-1])
                {
                    dp[i][j]=min(1+dp[i][j-w[i-1]],dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        if(dp[N][S]==INT_MAX-1)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<dp[N][S]<<endl;
        }
    }

    return 0;
}