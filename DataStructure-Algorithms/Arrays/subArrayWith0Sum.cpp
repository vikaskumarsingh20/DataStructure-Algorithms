// } Driver Code Ends
class Solution{
    public:   
    //time complexity o(n2)
    bool bruteForce(int arr[],int n){
                //Your code here
        
        for(int i=0;i<n;i++){
            
            int currentSum = 0;
            for(int j=1;j<n-1;j++){
                
                currentSum += arr[j];
                
                if(currentSum == 0)
                  return true;
            }
        }
        return false;
    }
        
        // time complexity O(N)
        //space O(N)
    
    bool optimalSol(int arr[],int n){
    
     //unique elements
     unordered_set<int> prefixSumSet;
        int prefixSum = 0;
    
        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];
    
            // If the current prefix sum is 0 or it has been seen before, there is a subarray with a sum of 0.
            if (prefixSum == 0 || prefixSumSet.find(prefixSum) != prefixSumSet.end()) {
                return true;
            }
    
            // Add the current prefix sum to the set
            prefixSumSet.insert(prefixSum);
        }
    
        // If no subarray with sum 0 is found
        return false;
    
    }

    bool subArrayExists(int arr[], int n){
        
        // bruteForce(arr,n);
        optimalSol(arr,n);
        
    }

};
 
