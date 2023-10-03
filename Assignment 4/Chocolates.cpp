#include <bits/stdc++.h>

using namespace std;

int main(){

    int test;
    cin>>test;

    while(test--)
    {
        int N;
        cin>>N;

        int ar[N];
        int Sum=0;

        for(int i=0;i<N;i++){

            cin>>ar[i];
            Sum+=ar[i];
        }

        if(Sum%2==0){
            int S=Sum/2;

            bool dp[N+1][S+1];

            for(int i=0;i<=N;i++){
                for(int j=0;j<=S;j++)
                {
                    if(i==0 && j==0)
                    {
                        dp[i][j]=true;

                        continue;
                    }

                    if(i==0)
                    {
                        dp[i][j]=false;

                        continue;
                    }

                    if(j>=ar[i-1])
                    {
                        dp[i][j]=dp[i-1][j-ar[i-1]] || dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }

            if(dp[N][S])
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<< endl;
            }
        }

        else
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}