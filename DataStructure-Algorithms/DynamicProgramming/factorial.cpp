#include<iostream>
#include<vector>
using namespace std;


int factorial(vector<int> dp , int n){
    // base case 
    dp[0] = 1;

    for(int  i = 1; i <= n;i++){
        dp[i] =dp[i -1]* i;   
    }
    return dp[n];

}
int main()
{
    vector<int > v = {1,2,3,4,5};
    cout<<factorial(v, 3) <<endl;
    return 0;
}