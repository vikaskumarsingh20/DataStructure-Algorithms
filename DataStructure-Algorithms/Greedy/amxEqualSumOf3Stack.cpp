Given three stacks S1, S2, and S3 of the positive numbers, the task is to find the possible equal maximum sum of the stacks with the removal of top elements allowed. Stacks are represented as an array, and the first index of the array represents the top element of the stack.

 

Example 1:

Input:
N1 = 3, N2 = 4, N3 = 2
S1 = {4,2,3}
S2 = {1,1,2,3}
S3= {1,4}
Output:
5
Explanation:
We can pop 1 element from the 1st stack, and 2
elements from the 2nd stack. Now remaining elements
yield the equal sum of the three stacks, that is 5.
 

Example 2:

Input: 
N1 =2, N2 = 1, N3 = 3
S1 = {4,7}
S2 = {10}
S3 = {1,2,3}
Output:
0
Explanation:
We will never get an equal sum after popping
some elements, so the answer will be 0.

// solution given below 
  
  //{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
            int sum1=0,sum2=0,sum3=0;
            
            for(int x:S1) sum1=sum1+x; 
            for(int x:S2) sum2=sum2+x;
            for(int x:S3) sum3=sum3+x;
            
            int i=0,j=0,k=0;
            int n1=S1.size(),n2=S2.size(),n3=S3.size();
                
            while(i<n1 && j<n2 && k<n3){
            if(sum1==sum2 && sum2==sum3){
              return sum1;
            }
            if(sum1>=sum2 && sum1>=sum3) sum1=sum1-S1[i++];
            else  if(sum2>=sum1 && sum2>=sum3) sum2=sum2-S2[j++];
            else  if(sum3>=sum1 && sum3>=sum2) sum3=sum3-S3[k++];
            }
              return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
