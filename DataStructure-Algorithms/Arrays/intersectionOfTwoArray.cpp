// broute Force APPROACH

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> numSet;
    std::vector<int> result;
    
    for (int num : nums1) {
        numSet.insert(num);
    }
    
    for (int num : nums2) {
        if (numSet.count(num) > 0) {
            result.push_back(num);
            numSet.erase(num);
        }
    }
    
    return result;
}

//OPTIMAL SOUTIONS 


// unordered set provides constant time average case complexity for insertion, deletion, and searching,
//   resulting in better performance compared to searching through the entire set in each iteration.
  
std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> numSet(nums1.begin(), nums1.end()); // sorted array its easy way to reduce time complexity 
    std::vector<int> result;
    
    for (int num : nums2) {
        if (numSet.count(num) > 0) {
            result.push_back(num);
            numSet.erase(num);
        }
    }
    
    return result;
}
