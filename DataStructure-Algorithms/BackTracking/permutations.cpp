link -> https://leetcode.com/problems/permutations/submissions/872019333/
class Solution {
public:
    
void solve(vector<int>&nums,vector<vector<int>> &ans,int index)
{   
    
    // base case or condtion
    
	if(index >=nums.size())
	{
      ans.push_back(nums);
		return ;
	}
	for(int i=index;i<nums.size();i++)
	{
		swap(nums[index],nums[i]); // catch
		solve(nums,ans ,index+1); //recusion call  
        // backtracking concepts
		swap(nums[index],nums[i]);
	}
}

 vector<vector<int>> permute(vector<int>& nums) {
	
	vector<vector<int>> ans;        
	int index =0;
	solve(nums,ans,index);
	  return ans;

}

};
