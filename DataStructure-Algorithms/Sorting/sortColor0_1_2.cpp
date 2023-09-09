class Solution {
public:

  //brute Force Approach
  void bubbleSort(vector<int>&nums ,int n){
   
    bool swapped;
   for(int turn = 0; turn<n-1;turn++){
       swapped = false;
       for(int j = 0;j<n-1-turn;j++){

          if(nums[j] > nums[j+1]){
             int temp = nums[j];
             nums[j] = nums[j+1];
             nums[j+1] = temp;
          }
       }
      //best case O(N^2)
       if(!swapped){
           break;
       }
   }
  }

   //Optimal Solutions
   // it is used for small range of the array,less time complexity comparetivily O(N+range)
    void countingSort(vector<int>& nums) {
        int largest = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            largest = max(largest, nums[i]);
        }

        vector<int> count(largest + 1);

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++; // Increment the count for each number in the input array
        }

        // Sorting
        int j = 0;
        for (int i = 0; i <= largest; i++) {
            while (count[i] > 0) {
                nums[j] = i;
                j++;
                count[i]--;
            }
        }
    }
  
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        // bubbleSort(nums,n);
        countingSort(nums);
    }
};
