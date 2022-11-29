// link ->     https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// This is 2D DP Problem with solution worst case to Optimal solution .

#include <bits/stdc++.h>

        
  int  solveRec(vector<int> &weight, vector<int> &value, int index, int capacity)
{
    // base case
    if (index == 0)
    {
        if (weight[0] <= capacity)  // in range
            return value[0];
        else
            return 0;
    }
    int include = 0;
    if (weight[index] <= capacity)  // under the knapsack weight 
    {
        include = value[index] + solveRec(weight, value, index - 1, capacity - weight[index]);
    }
    int exclude = 0 + solveRec(weight, value, index - 1, capacity);

    int ans = max(exclude, include);
    return ans;
}

int solveMom(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= capacity) // To check uh under the  // rejecting
        {
            return value[0];
        }
        else
            return 0;
    }
    if (dp[index][capacity] != -1)   // 2D DP return
        return dp[index][capacity];

    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveMom(weight, value, index - 1, capacity - weight[index], dp);
    }
    int exclude = 0 + solveMom(weight, value, index - 1, capacity, dp);
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    //     return solveRec(weight , value , n-1 , maxWeight);  // by recursion
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solveMom(weight, value, n - 1, maxWeight, dp); // by memorization
}
