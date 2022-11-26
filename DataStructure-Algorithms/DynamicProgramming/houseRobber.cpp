#include <bits/stdc++.h> 

long long int solveTab(vector<int> &valueInHouse){
 long long int n =valueInHouse.size();
    vector<int>dp(n , 0);
    
    dp[0] = valueInHouse[0];
    for(int i = 1 ; i<n ; i++){
       long long  int include = dp[i-2] + valueInHouse[i];
       long long int exclude = dp[i-1] + 0 ;
        
        dp[i] = max(include, exclude);
    }
    return dp[n-1];
}
 
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n == 1)  // only one house
        return valueInHouse[0];
  
    vector<int> first , second;
    
    for(int i =0 ;i<n;i++){
        if(i != n-1) // for insert from last
            first.push_back(valueInHouse[i]);
        if( i != 0) // insert in fist
            second.push_back(valueInHouse[i]);
    } // find out the max form both of array 
    return max(solveTab(first) , solveTab(second));
}
