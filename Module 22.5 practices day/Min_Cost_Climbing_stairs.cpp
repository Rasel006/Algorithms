// /minimum cost climbing stairs
 
// Algo:
// Create a class Solution with a private integer array dp of size 1001 to store memoization values.
 
// Define a private recursive function solve that takes two arguments: the cost vector and an integer i representing the current step.
 
// In the solve function:
 
// Check if i is either 0 or 1 (the base cases). If so, return 0 because there is no cost to climb these steps.
 
// Check if dp[i] has been memoized. If so, return its value.
 
// Calculate two values c1 and c2 representing the cost of climbing i-th step:
 
// c1 is the cost of the i-1-th step plus the minimum cost to reach the i-1-th step (recursively call solve with i-1).
// c2 is the cost of the i-2-th step plus the minimum cost to reach the i-2-th step (recursively call solve with i-2).
// Return dp[i] as the minimum of c1 and c2 and store it in dp[i] for memoization.
 
// In the minCostClimbingStairs function:
 
// Initialize the dp array with -1 values using memset.
 
// Call the solve function with the cost vector and the size of the cost vector as arguments.
 
// Return the result, which is the minimum cost to climb the stairs.
 
 
 
class Solution {
    int dp[1001];
    int solve(vector<int>& cost, int i){
        if(i==0 || i==1){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int c1=cost[i-1]+solve(cost, i-1);
        int c2=cost[i-2]+solve(cost, i-2);
        return dp[i]=min(c1, c2);
 
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        return solve(cost, cost.size());
    }
};