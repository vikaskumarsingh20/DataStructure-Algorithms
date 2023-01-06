Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10



class Solution {
   int  Memorization(vector<vector<int>>&dp,vector<vector<int>>& tri,int i,int j,int n)
    {   if(i==n-1 )
          return tri[i][j];                  //return at end of triangle
        
        if(dp[i][j]!=-1)
          return dp[i][j];                          // return if we already have a better answer  calculated there
        int down = tri[i][j]+Memorization(dp,tri,i+1,j,n);                //going down at a time
        int down_right = tri[i][j]+Memorization(dp,tri,i+1,j+1,n);        //going bottom right
        
        return dp[i][j] = min(down,down_right);                     // return minimum element of that position.
        
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp (triangle.size(),vector<int>(n,-1));
        return Memorization(dp,triangle,0,0,n);                            //finally return the answer.
    
    }
};
