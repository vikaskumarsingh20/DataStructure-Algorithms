class Solution {
public:
   
  
  // Based on Knapsack Problem 
  
  //T.C N(EXP) + S.C N(EXP)
    int solveRec(vector<int>&satisfaction , int index, int time){
        // base case
         if(index == satisfaction.size()) // out of array 
           return 0;
         
         //chef have option to include or not ,why -> to findout maximum dishes 
      int include = satisfaction[index]*(time+1) + solveRec(satisfaction , index +1 , time +1);
      // 0 here why -> just ignore 
      int exclude = 0 + solveRec(satisfaction , index +1 , time);

      return max(include , exclude);
    }

  
 //T.C N(N2) + S.CN(N2)
    
    int solveMem(vector<int>&satisfaction , int index , int time , vector<vector<int>>&dp){
        // base case
        if(index == satisfaction.size())
            return 0;

       if(dp[index][time] != -1)
         return dp[index][time];

    int include = satisfaction[index]*(time+1) +solveMem(satisfaction , index+1 ,time +1,dp);
    int exclude = 0 + solveMem(satisfaction , index +1 ,time, dp);

    return dp[index][time] = max(include, exclude);
    }
 
  //T.C O(N2) + S.C O(N2)
int sloveTab(vector<int>&satisfaction){

         int n  = satisfaction.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+1 ,0));

        for(int index = n-1 ;index >=0;index-- ){
            for(int time = index ;time >=0;time--){
                    int include = satisfaction[index]*(time+1) + dp[index+1][time+1];
                    int exclude = 0 +  dp[index+1][time];

                 dp[index][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
   
     //T.C O(N2)  + S.C O(N)
       int solveSpaceOptimzation(vector<int>&satisfaction){

         int n  = satisfaction.size();
        
        vector<int>curr(n+1 , 0); // row 
        vector<int>next(n+1 , 0); // col

        for(int index = n-1 ;index >=0;index-- ){
            for(int time = index ;time >=0;time--){
                    int include = satisfaction[index]*(time+1) + next[time+1];
                    int exclude = 0 +  next[time];

                 curr[time] = max(include, exclude);
            }
            next = curr; // next deponds on current 
        }
        return next[0];
    }


    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(),satisfaction.end());
             
        //        int n = satisfaction.size();
        //  vector<vector<int>> dp(n , vector<int>(n+1 , -1));
        // return solveMem(satisfaction , 0 ,0,dp);

        // return sloveTab(satisfaction);
        return solveSpaceOptimzation(satisfaction);
    }
};
