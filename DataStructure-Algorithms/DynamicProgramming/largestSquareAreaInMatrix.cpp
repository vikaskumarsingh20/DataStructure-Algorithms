// User function Template for C++
#include<bits/stdc++.h>
class Solution{
public:
     int solveRec(vector<vector<int>>mat, int i , int j , int &maxi){
         // abse case
          if(i >= mat.size() || j >= mat[0].size())   // when out of range means matrix
             return 0;
             
        int right = solveRec(mat, i, j+1, maxi);  // for right check
        int diagonal = solveRec(mat, i+1 , j+1 ,maxi);  // diagonal check
        int down = solveRec(mat , i+1 , j , maxi);  // down check 
        
        if(mat[i][j] == 1){  // if matched to 1 then it will make squares
            int ans = 1+ min(right , min(diagonal ,down));  // find minimum ans add 1
            maxi = max(maxi , ans);
            return ans;
        }
      else
        return 0;
     }
        // Top Down Approach i.e Memorization
       int solveMem(vector<vector<int>>&mat, int i , int j , int &maxi ,vector<vector<int>>&dp){
         // abse case
          if(i >= mat.size() || j >= mat[0].size())  // when out of matrix then retun 0
             return 0;
             
             if(dp[i][j] != -1)  // already exist ans then return it 
             return dp[i][j];
             
        int right = solveMem(mat, i, j+1, maxi,dp);
        int diagonal = solveMem(mat, i+1 , j+1 ,maxi, dp);
        int down = solveMem(mat , i+1 , j , maxi, dp);
        
        if(mat[i][j] == 1){
             dp[i][j] = 1+ min(right , min(diagonal ,down));
            maxi = max(maxi , dp[i][j]);
            return dp[i][j];
        }
      else
        return dp[i][j] = 0;
     }
     
    int solveSpaceOptimazation(vector<vector<int>> &mat,int &maxi){   // time complexity O(M*N) sapce O(N)

    int row=mat.size();

    int col=mat[0].size();

    vector<int>curr(col+1,0);

    vector<int>next(col+1,0);

    for(int i=row-1;i>=0;i--){

        for(int j=col-1;j>=0;j--){

            int right=curr[j+1];

            int diag=next[j+1];

            int left=next[j];

            if(mat[i][j]==1){

                curr[j]=1+min(diag,min(left,right));

                maxi=max(curr[j],maxi);

            }

            else{

                curr[j]=0;

            }
        }
          next=curr;
    }
    return next[0];
}
     
    int maxSquare(int n, int m, vector<vector<int>> mat){
        //  int maxi = 0;
        //  solveRec(mat ,0 , 0 , maxi);
        //   return maxi;
        // int maxi =0 ;
        // vector<vector<int>>dp(n, vector<int>(m,-1));
        // solveMem(mat , 0 , 0 ,maxi , dp);
        // return maxi;
        
      int maxi =0 ;
      solveSpaceOptimazation(mat , maxi);
      return maxi;
    }
};
