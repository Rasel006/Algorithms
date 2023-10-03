#include <bits/stdc++.h>

using namespace std;

int main(){

    int test;

    cin>>test;

    while(test--)
    {
        string k1;
        
        cin>>k1;

        int N=k1.size();

        string k2=k1;

        reverse(k2.begin(),k2.end());

        int dp[N+1][N+ 1];

        for(int i=0;i <=N;i++){
            for(int j=0;j<=N;j++)
            {
                if (i==0 || j == 0)
                {
                    dp[i][j]=0;

                    continue;
                }

                if(k1[i-1]==k2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }

                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        cout<<abs(N-dp[N][N])<<endl;
    }

    return 0;
}