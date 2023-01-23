198. House Robber
Medium
16.6K
325
Companies
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12
 
 //CODE

/* To check all the possibility for robber and the find out the maximum money from the house
*/
class Solution {
public:
    int dp[105];
    int robHouse(int i, vector<int>&a) {
        //when robber earched all house
        if (i >= a.size()) {
            return 0;
        }
        if (dp[i] != -1) 
          return dp[i];
           //i+2 why-> start stealing from next->next
        int stealCurrent = a[i] + robHouse(i + 2, a);
        //skip next house
        int skipCurrent = robHouse(i + 1, a);
        return dp[i] = max(stealCurrent, skipCurrent);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return robHouse(0, nums);
    }
};
