// link-> https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h>
#define MOD 1000000007

              int
              add(int a, int b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}
int mul(int a, int b)
{
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

int solveRec(int n, int k)
{
    // base case
    if (n == 1)
        return k;
    if (n == 2)
        return add(k, mul(k, k - 1));

    int ans = add(mul(solveRec(n - 2, k), k - 1), mul(solveRec(n - 1, k), k - 1));
    return ans;
}

int solveMom(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;
    if (n == 2)
        return add(k, mul(k, k - 1));
    if (dp[n] != -1)
        return dp[n];

    dp[n] = add(mul(solveMom(n - 2, k, dp), k - 1), mul(solveMom(n - 1, k, dp), k - 1));
    return dp[n];
}

int solveTab(int n, int k)
{
    vector<int> dp(n + 1, 0);

    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));
    }
    return dp[n];
}

int solveSpaceOptimization(int n, int k)
{
    int prev2 = k;
    int prev1 = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        int curr = add(mul(prev2, k - 1), mul(prev1, k - 1));
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int numberOfWays(int n, int k)
{
    //  return  solveRec(n, k);
    //     vector<int>dp(n+1 , -1);
    //     return solveMom(n, k, dp);
    //     return solveTab(n, k);
    return solveSpaceOptimization(n, k);
}
