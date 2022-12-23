Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

 

Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 
Example 2:

Input:
N = 2, W = 50
values[] = {60,100}
weight[] = {10,20}
Output:
160.00
Explanation:
Total maximum value of item
we can have is 160.00 from the given
capacity of sack.
 

Your Task :
Complete the function fractionalKnapsack() that receives maximum capacity , array of structure/class and size n and returns a double value representing the maximum value in knapsack.
Note: The details of structure/class is defined in the comments above the given function.


Expected Time Complexity : O(NlogN)
Expected Auxilliary Space: O(1)
  
  //SOLUTION GIVEN BELOW 
  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    static bool cmp(pair<double , Item> a, pair<double , Item> b){
        return a.first > b.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
         vector<pair<double , Item>> v;
         
         for(int i =0 ;i<n;i++){
             double perUnitValue = (1.0*arr[i].value)/arr[i].weight;
             pair<double , Item> p = make_pair(perUnitValue,arr[i]);
             v.push_back(p);
         }
         
         sort(v.begin(),v.end(),cmp);
         
         double totalValue = 0;
         for(int i=0;i<n;i++){
             if(v[i].second.weight > W){
                 totalValue += W*v[i].first;
                  W = 0 ;
             }
             else{
                 totalValue += v[i].second.value;
                 W = W - v[i].second.weight;
             }
         }
         return totalValue;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
