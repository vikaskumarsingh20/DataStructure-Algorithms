There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.

Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.

class Solution {
private:
    int find(vector<int>& slices, int index, int slicePending, int endIndex, vector<vector<int>>& dp){
        if(index >= endIndex || slicePending == 0)
            return 0;
        
        if(dp[index][slicePending] != -1)
            return dp[index][slicePending];
        
        int take = slices[index] + find(slices, index + 2, slicePending - 1, endIndex, dp);
        int notTake = find(slices, index + 1, slicePending, endIndex, dp);
        
        return dp[index][slicePending] = max(take, notTake);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        
        int k = n / 3;
        vector<vector<int>> dp1(n + 1, vector<int>(k + 1, -1));
        int pizzaSize1 = find(slices, 0, k, n - 1, dp1);
        vector<vector<int>> dp2(n + 1, vector<int>(k + 1, -1));
        int pizzaSize2 = find(slices, 1, k, n, dp2);
        
        return max(pizzaSize1, pizzaSize2);
    }
};
