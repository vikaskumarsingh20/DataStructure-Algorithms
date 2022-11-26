746. Min Cost Climbing Stairs
 
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

SOLUTION FOR IT GIVEN BELOW 

class Solution {
public:
    
    int solve(vector<int > &cost , int n, vector<int> &dp){
        // base case
        if( n == 0 ) return cost[0];
        if(n == 1)  return cost[1];
        
         if(dp[n] != -1)
            return dp[n];  // if alredy presented then return array
        
   dp[n] = cost[n] + min (solve(cost , n -1 ,dp) , solve(cost , n -2 , dp)); /// find mini then add with previous array
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int>dp(n +1 , -1);
        int ans =  min(solve( cost, n-1  ,dp) , solve(cost , n -2 , dp));
          return ans;
    }
};
