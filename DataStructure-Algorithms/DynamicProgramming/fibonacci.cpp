#include<bits/stdc++.h>
using namespace std;

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