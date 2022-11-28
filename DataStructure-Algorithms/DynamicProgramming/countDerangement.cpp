// link -> https://www.codingninjas.com/codestudio/problems/count-derangements_873861?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#define MOD 1000000007
#include <vector>
long long int solveRec(int ){
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    return  (((n - 1) % MOD) * ((solveMom(n - 1, dp) % MOD) + (solveMom(n - 2, dp) % MOD)) % MOD);
}


long long int solveMom(int n, vector<long long int> &dp)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    dp[n] = (((n - 1) % MOD) * ((solveMom(n - 1, dp) % MOD) + (solveMom(n - 2, dp) % MOD)) % MOD);
    return dp[n];
}

long long int solveTab(long long int n)
{
    vector<long long int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (((i - 1) % MOD) * ((dp[i - 1] % MOD) + (dp[i - 2] % MOD)) % MOD);
    }
    return dp[n];
}

long long int solveSpaceOptimization(int n)
{
    long long int prev2 = 0;
    long long int prev1 = 1;
    for (int i = 3; i <= n; i++)
    {
        long long int curr = (((i - 1) % MOD) * ((prev1 % MOD) + (prev2 % MOD)) % MOD);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

long long int countDerangements(int n)
{
    //    if( n == 1)
    //        return 0;
    //     if( n == 2)
    //         return 1;
    //    int ans = (((n-1)%MOD) *((countDerangements(n-1)%MOD) + (countDerangements(n-2)%MOD))%MOD);
    //     return ans;
    //      vector<long long int>dp(n +1 , -1);
    //     return solveMom(n , dp);
    //    return solveTab(n);

    return solveOptimization(n);
}
