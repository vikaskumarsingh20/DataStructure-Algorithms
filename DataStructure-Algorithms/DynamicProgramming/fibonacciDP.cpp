#include<bits/stdc++.h>
using namespace std;


// solved by TABULATOR METHOD with o(N) time & space complexity 
int fibo(vector<int > dp , int n){
    

    // this is base case and stores the values 
    dp[0] = 0;
    dp[1] = 1;

    for(int  i = 2;i <= n; i++){   // iterrate from 2
        dp[i] = dp[i -1] + dp[i -2];
    }
    return dp[n]; // return the dp[n]

    // By recursion using dynamic programming 

}

// Solved by Recursive Memorizarion   with o(N) time & o(N) + (N) space cpletxity
int solveRec( int  n , vector<int>&dp){
    if(n == 0 || n == 1)
        return n;
    
    if(dp[n] != -1)
        return dp[n];
  
    dp[n] = solveRec(n-1 , dp) + solveRec(n-2 , dp);
    return dp[n];
}

// SPACE OPTIMAZATION WITH 0(1)
int solveSpaceOptm(){
        int n; cin>>n;
    
    int prev1 = 1;
    int prev2 = 0;
    
    for(int  i=2 ;i<=n;i++){
        int curr = prev1 + prev2;
        // shifting logic 
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int solve(int n , vector<int >dp){

    if( n == 0 )
       return 1;
  // for checks the answer is already stored then return array or data structure 
    if(dp[n] != -1)
    return dp[n];

  return (dp[n] * solve(n-1 , dp));
}

int main()
{
  vector<int > v= {1,2,3,4,5};
    cout<<solve(3, v)<<endl;
}
