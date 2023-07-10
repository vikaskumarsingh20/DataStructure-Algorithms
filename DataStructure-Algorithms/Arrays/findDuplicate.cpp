// broute force approach
int findDuplicate(std::vector<int>& nums) {
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        int curr = abs(nums[i]);
        if (nums[curr] < 0) {
            return curr;
        }
        nums[curr] = -nums[curr];
    }
    
    // If no duplicate is found
    return -1;
}


//optimal solutions 
int findDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> numSet;
    
    for (int num : nums) {
        if (numSet.count(num) > 0) {
            return num;
        }
        numSet.insert(num);
    }
    
    // If no duplicate is found
    return -1;
}

int main() {
    std::vector<int> nums = {1, 3, 4, 2, 2};
    int duplicate = findDuplicate(nums);
    
    if (duplicate != -1) {
        std::cout << "Duplicate number: " << duplicate << std::endl;
    } else {
        std::cout << "No duplicate number found." << std::endl;
    }
    
    return 0;
}
 
