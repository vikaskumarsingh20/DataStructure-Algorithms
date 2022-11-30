Given a number N. Find the minimum number of squares of any number that sums to N. For Example: If N = 100 
  , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as minimum number of square is 1 , i.e (10*10).
  
 Expcted Time Complexity: O(N * sqrt(N) )
Expected Space Complexity: O(N)
  
  SOLUTIONS FOR IT .
  
  //User function Template for C++

class Solution{
	public:
	
	int solve(int n){
	    if(n == 0 )
	    return 0;
	    
	    int ans = n;
	    for(int i =0 ;i*i <= n;i++){
	        int temp = i*i;
	        ans = min(ans , 1+ solve(n- temp));
	    }
	    return ans;
	}
	
	int solveMem(int n  , vector<int>&dp){
	    if(n == 0) return 0;
	    if(dp[n] != -1)
	    return dp[n];
	    
	    int ans = n;
	    for(int  i = 1 ;i*i<= n;i++){
	            int temp = i*i;
	            ans = min(ans , 1+ solveMem(n-temp , dp));
	        }
	        dp[n] = ans;
	        return dp[n];
	        
	    }
	    
	   int solveTab(int n){
	       vector<int>dp(n+1 , INT_MAX);
	       
	       dp[0] = 0;
	       
	     
	       for(int  i = 1;i<=n;i++){
	           for(int j= 1;j*j <=n;j++){
	               int temp = j*j;
	               if(i-temp >=0)
	               dp[i] = min(dp[i],1 + dp[i -temp]);
	           }
	       }
	       return dp[n];
	   }
	   
	int MinSquares(int n)
	{
	    
	   // return solve(n);
	  
	   //vector<int>dp(n+1, -1);
	   //return solveMem(n, dp);
	   
	   return solveTab(n);
	   
	}
};
