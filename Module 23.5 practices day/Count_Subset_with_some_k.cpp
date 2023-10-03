
const int N = 1e3+3;
int dp[N][N];
#define Mod 1000000007
int subset_sum(int n,int k, vector<int> arr){
	// base case 
	if(n == 0){
		if(k == 0) return 1;
		else return 0;
	}

	if(dp[n][k] != -1) return dp[n][k];

	if(k >= arr[n - 1]){
		dp[n][k] = subset_sum(n - 1,k - arr[n - 1], arr) + subset_sum(n - 1, k, arr);
		return dp[n][k] = dp[n][k] % Mod;
	}
	else{
		dp[n][k] = subset_sum(n - 1, k, arr);
		return dp[n][k] = dp[n][k] % Mod; 
	}
}


int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	for(int i = 0; i<= n; i++){
		for(int j = 0; j <= k; j++){
			dp[i][j] = -1;
		}
	}
	return subset_sum(n, k, arr);
}