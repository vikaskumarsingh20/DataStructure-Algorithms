Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
  //CODE

class Solution {
public:
//in dp array a coordinate shift is done as it cannot store -1 in dp 
//do we would have to declare n+1 size array and then do a +1 for all //the instances
  
  
    int solveRec(int prev,int curr, vector<int>&nums){
         if(curr==nums.size())
          return 0;
         int opt1 =0;
         
         if(prev == -1 || nums[prev]<nums[curr]){
             opt1 = 1 + solveRec(curr ,curr+1,nums);
         }
        int opt2 = solveRec(prev,curr+1, nums);
        return max(opt1,opt2);
     }
    int lengthOfLIS(vector<int>& nums) {
        return LISHelper(-1,0,nums);
    }
  
    int memoization(int idx,int n,int prev,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(idx==n)
           return 0;
        if(dp[idx][prev+1]!=-1) 
           return dp[idx][prev+1];

        int notPick=memoization(idx+1,n,prev,nums,dp);
        int pick=0;

        if(prev==-1 || nums[idx]>nums[prev])
            pick=1+memoization(idx+1,n,idx,nums,dp);

        return dp[idx][prev+1]=max(pick,notPick);
    }

    int tabulation(int n,vector<int> &nums,vector<vector<int>> &dp)
    {
        for(int idx=n-1;idx>=0;idx--)
        {
            //prev always begins from index-1 as it is the prev inedex
            for(int prev=idx-1;prev>=-1;prev--)
            {
                int notPick=dp[idx+1][prev+1];
                int pick=0;
                if(prev==-1 || nums[idx]>nums[prev]) 
                   pick=1+dp[idx+1][idx+1];

                dp[idx][prev+1]=max(pick,notPick);
            }
        }
        return dp[0][0];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0)); //for memo include 0,tab == -1
        //two changing parameters in dp 
        //index from 0 --> n-1 total N elements
        //prev_ind from -1 --> n-1 total N+1 elements

        // return memoization(0,n,-1,nums,dp);
        return tabulation(n,nums,dp);
    }
};
