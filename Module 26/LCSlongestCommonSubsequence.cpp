#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int CountheSubSequnce(string a, int a_size, string b, int b_size)
{
    // base case
    if (a_size == 0 || b_size == 0)
        return 0;

    if (dp[a_size][b_size] != -1)
        return dp[a_size][b_size];

    if (a[a_size - 1] == b[b_size - 1])
    {
        return dp[a_size][b_size] = 1 + CountheSubSequnce(a, a_size - 1, b, b_size - 1);
    }

    else
    {
        return dp[a_size][b_size] = max(CountheSubSequnce(a, a_size - 1, b, b_size), CountheSubSequnce(a, a_size, b, b_size - 1));
    }
}
int main()
{

    string a, b;
    cin >> a >> b;

    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j <= b.size(); j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << CountheSubSequnce(a, a.size(), b, b.size());

    return 0;
}