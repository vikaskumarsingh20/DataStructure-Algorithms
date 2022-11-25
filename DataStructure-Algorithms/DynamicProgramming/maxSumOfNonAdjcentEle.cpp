Maximum sum of non-adjacent elements

Link for SPOURCE CODE ->https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


SOLUTION FOR THIS QUESTIONS 
#include <bits/stdc++.h> 

// By Recursion method
int solveRecursion(vector<int> &nums , int n){
    //Base Case
    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0];
    
    int include = solveRecursion(nums , n-2) + nums[n];
    int exclude = solveRecursion(nums , n-1) + 0 ;
    
    return max(include , exclude);
    
    
}

// My recursion Memoization

int solveMemoization(vector<int> &nums , int n , vector<int>&dp){
    //Base Case
    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0];
    
    if(dp[n] != -1)
        return dp[n];
    
    int include = solveMemoization(nums , n-2 , dp) + nums[n];
    int exclude = solveMemoization(nums , n-1 , dp) + 0 ;
    
    dp[n] = max(include , exclude);
    return dp[n]; 
}

// My Tabulations
int solveTabulation(vector<int> &nums){
    int n = nums.size();
    vector<int>dp(n , 0);
    
    dp[0] = nums[0];
    for(int i = 1 ; i<n ; i++){
        int include = dp[i-2] + nums[i];
        int exclude = dp[i-1] + 0 ;
        
        dp[i] = max(include, exclude);
    }
    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     int ans = solveRecursion(nums , n-1);
//     return ans;
    
//     int n = nums.size();
//     vector<int>dp(n , -1);
//     int ans = solveMemoization(nums , n-1 , dp);
//     return ans;
    
    
    return solveTabulation(nums);
    
}
