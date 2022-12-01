int solveRec(int n, vector<int>&days, vector<int>&cost , int index){   // expontial solution
    // base case
     if(index >= n){
         return 0;
     }
    // 1 days pass
    int option1 = cost[0] + solveRec(n, days , cost , index +1);
    
    
    // 7 days pass
     int i ;
     for(i = index  ;i< n && days[i]< days[index]+7;i++);
         int option2 = cost[1]+ solveRec(n , days ,cost , i);
     
    // 30 days apss
     for(i = index ;i< n && days[i]< days[index]+30;i++);
         int option3= cost[2]+ solveRec(n , days ,cost , i);
    
    return min(option1, min(option2, option3));
}


int solveMem(int n, vector<int> days, vector<int> cost ,int index , vector<int>&dp){   // constant time complxity
    // base case 
     if(index >= n){
         return 0;
     }
    if(dp[index] != -1)
        return dp[index];
    // 1 days pass
    int option1 = cost[0] + solveMem(n, days , cost , index +1, dp);
    
    
    // 7 days pass
     int i ;
     for(i = index  ;i< n && days[i]< days[index]+7;i++);
         int option2 = cost[1]+ solveMem(n , days ,cost , i, dp);
     
    // 30 days apss
     for(i = index ;i< n && days[i]< days[index]+30;i++);
         int option3= cost[2]+ solveMem(n , days ,cost , i, dp);
    
   dp[index] =  min(option1, min(option2, option3));
    return dp[index];
}


int solveTab(int n, vector<int> days, vector<int> cost ){    // o(N) time complexity
    // base case
    vector<int>dp(n+1 ,INT_MAX);
   
   dp[n] = 0;
    // 1 days pass
    
    for(int k = n-1;k>= 0;k--){
    int option1 = cost[0] +  dp[k+1];
    
    
    // 7 days pass
     int i ;
     for(i = k  ;i< n && days[i]< days[k]+7;i++);
         int option2 = cost[1]+  dp[i];
     
    // 30 days apss
     for(i = k ;i< n && days[i]< days[k]+30;i++);
         int option3= cost[2] + dp[i];
        
   dp[k] =  min(option1, min(option2, option3));
    }
      return dp[0];
    }


int minimumCoins(int n, vector<int> days, vector<int> cost)
{
//     vector<int> dp(n+1 , -1);
//     return solveMem(n, days , cost , 0, dp);
    
    return solveTab(n , days, cost);
}
