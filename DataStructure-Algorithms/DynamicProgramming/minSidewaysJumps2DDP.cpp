class Solution {
public:
    
    int solveRec(vector<int>& obstacles , int currlane ,int currpos){
         
        int n = obstacles.size()-1;
        // abse case
         if(currpos == n)   // stay target == initial
             return 0;
        
        if(obstacles[currpos +1] != currlane){  // next position havn't obstacles , one case
            return solveRec(obstacles , currlane , currpos +1); // all done by recursion
        }
        else{
             int ans = INT_MAX;
            for(int  i =1;i<=3;i++){  // have 3 moves only up, down, stright
                if(currlane != i && obstacles[currpos] != i){
                   ans = min(ans , 1 + solveRec(obstacles ,i , currpos));
                }
            }
              return ans;
        }
    
    }
    
    int solveMem(vector<int> & obstacles , int currlane ,int currpos ,vector<vector<int>>&dp){
        
        int  n = obstacles.size()-1;
            if(currpos == n)
                return 0;
        
         if(dp[currlane][currpos] != -1)
             return dp[currlane][currpos];
        
        if(obstacles[currpos+1] != currlane){
            return solveMem(obstacles , currlane , currpos +1 , dp);
        }
        else{
            int ans = INT_MAX;
            
            for(int i =1;i<=3;i++){
                if(currlane != i && obstacles[currpos] != i){
                    ans = min(ans , 1+ solveMem(obstacles ,i, currpos ,dp));
                }
            }
              dp[currlane][currpos] = ans;
            return dp[currlane][currpos];
        }
    }
    
    int solveTab(vector<int>&obstacles){
        vector<vector<int>>  dp = vector<vector<int>> (obstacles.size() , vector<int> (3, 10e6) );
        
        int n = obstacles.size();
        dp[n-1][0] = dp[n-1][1] = dp[n-1][2] =  0;
 
        
       
        for(int i = n-2 ; i >= 0 ; i--)
        {
            for(int j = 0 ; j<3 ; j++)
            {   
                if (obstacles[i+1] != j+1)
                    dp[i][j] = dp[i+1][j];
                else
                {
                    int ans = 10e6;
                    for(int k = 0 ; k< 3 ; k++)
                    {
                        if(k != j && obstacles[i] != k+1)
                        ans = min(ans,1 + dp[i+1][k]);
                    }
                    dp[i][j] = ans;
                }
            }
        }
        
        return min(dp[0][1], 1 + min(dp[0][0], dp[0][2]));
    }
    
        int SolveBySpaceOptimisation(vector<int> obstacles)
    {
       vector<int> curr(3, 10e6) , prev(3, 0);
         
        int n = obstacles.size();
       
        for(int i = n-2 ; i >= 0 ; i--)
        {
            for(int j = 0 ; j<3 ; j++)
            {   
                if (obstacles[i+1] != j+1)
                    curr[j] = prev[j];
                else
                {
                    int ans = 10e6;
                    for(int k = 0 ; k< 3 ; k++)
                    {
                        if(k != j && obstacles[i] != k+1)
                        ans = min(ans,1 + prev[k]);
                    }
                    curr[j] = ans;
                }
            }
            
            prev = curr;
        }
        
        return min(curr[1] , 1 + min(curr[0], curr[2]));
    }
    
    int minSideJumps(vector<int>& obstacles) {
        
        // return solveRec(obstacles ,2, 0);
        
        
      // vector<vector<int>> dp(4,  vector<int >(obstacles.size() , -1));
      //     return solveMem(obstacles , 2,0 , dp);
        
        // return solveTab(obstacles);
        return SolveBySpaceOptimisation(obstacles);
    }
};
