Problem Statement
Sample Input 1 :
2
3 7
1 2 3
1 0
1
Sample Output 1 :
 3
 0
Explanation For Sample Output 1:
For the first test case,
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.

For the second test case,
Way 1 - You can take 3 elements  [1, 1, 1] as 1 + 1 + 1  = 3.
Way 2 - You can take 2 elements  [2, 1] as 2 + 1 = 3.
Here, you can see in Way 2 we have used 2 coins to reach the target sum of 7.
Hence the output is 2.
Sample Input 2 :
2
3 4
12 1 3
2 11
2 1
Sample Output 2 :
2
6 
  
  SOLUTION FOR THAT QUESTIOSN
  
  #include <bits/stdc++.h> 

 // RECURSION METHOD EXPNTIAL TIME 
int solveRec(vector<int> & num , int x){
    // base case
    if(x == 0)  
       return 0;
     if( x < 0)  
        return INT_MAX;
    
    int mini = INT_MAX;
    
    for(int  i = 0;i<num.size();i++){
        int ans = solveRec(num , x - num[i]);
        if(ans != INT_MAX)
            mini = min(mini , 1+ans);
    }
    return mini;
}
// MEMORIZATION + RECURSION

int solveMom(vector<int > & num , int x, vector<int> &dp){
       // base case
    if(x == 0)  
       return 0;
     if( x < 0)  
        return INT_MAX;
    
    if(dp[x] != -1)
        return dp[x];
    
    int mini = INT_MAX;
    
    for(int  i = 0;i<num.size();i++){
        int ans = solveMom(num , x - num[i] , dp);
        if(ans != INT_MAX)
            mini = min(mini , 1+ans);
    }
    dp[x] = mini;
    return mini;
        
}

// TABULATIONS METHOD 
int solveTab(vector<int> num , int x){
    vector<int>dp(x+1, INT_MAX);
        dp[0]=0;
    for(int i = 1 ; i<=x ; i++ ){  // for iteerate 1 to X
        for( int j = 0 ; j< num.size() ; j++ ){  
            if( i-num[j] >= 0 && dp[i- num[j]] != INT_MAX  ){
                dp[i] = min(dp[i] , 1+ dp[i- num[j]] );
            }
        }
    }
    if(dp[x]== INT_MAX )return -1;
    
    return dp[x];

}

int minimumElements(vector<int> &num, int x)
{
//     int ans = solveRec(num , x);
//     if(ans == INT_MAX)
//         return -1;
//     vector<int > dp(x + 1 ,-1);
//    int ans =  solveMom(num , x , dp);
//     if(ans == INT_MAX)
//         return -1;
//     else
//         ans;
    vector<int> dp(x+1 , INT_MAX);
    return solveTab(num , x);
    
}
