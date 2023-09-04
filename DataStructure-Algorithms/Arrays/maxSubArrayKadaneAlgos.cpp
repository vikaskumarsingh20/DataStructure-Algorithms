#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

        //BRUTE FORCE APPROACH
        //T.C -> O(N^2)
    long long maxSubarraySumBruteForce(int arr[],int n){
         // Your code here
        
        long maxSum = INT_MIN;
        
        for(long i=0;i<n;++i){
            
            long currentSum =0;
            
            for(long j=i;j<n;++j){
                
                currentSum += arr[j];
                
                maxSum = max(maxSum ,currentSum);
            }
        }
        return maxSum;
    }

        //OPTIMAL SOLUTIONS
         //T.C -> O(N)
    long long kadaneAlgo(int arr[],int n){
       long long maxSum = arr[0];  
       
       long long currentSum = arr[0];   

    for (int i = 1; i < n; ++i) {
        
        currentSum = std::max(static_cast<long long>(arr[i]), currentSum + arr[i]);

       
        maxSum = std::max(maxSum, currentSum);
    }

    return maxSum;
        
    }
    
    long long maxSubarraySum(int arr[], int n){
        
        // maxSubarraySumBruteForce(arr,n);
        kadaneAlgo(arr,n);
        
    }
};
