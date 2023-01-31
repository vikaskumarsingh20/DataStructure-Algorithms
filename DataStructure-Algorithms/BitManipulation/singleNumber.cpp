
//Most 
136. Single Number
Easy
12.8K
492
Companies
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
  
	// Most Important
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0; 
	   for(auto x:nums) // 2 2 1
	   ans^=x;    // 2^2 =0 0 0 * 0 0 1 =  0 0 1
	   return ans;
    }
};

  //CODE
  class Solution {
    //T.C O(n) linear 
    //S.C o(1) const space
public:
    int singleNumber(vector<int>& nums) {
        // storing the ans
         int ans =0;
         // const interate 32 bits
        for(int i=0;i<32;i++){
            int sum = 0;
            // counts the one ,interate over the array
            for(int j=0;j<nums.size();j++){
                if((nums[j]>>i & 1)== 1)
                   sum++;
            }
            // grouping 
            sum%=3;
            // not equal
            if(sum != 0)
            // update ans
             ans |= sum<<i;
        }
        return ans;
    }
};
// Method 1
  
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       unordered_map<int,int> a;
	   for(auto x: nums)
		   a[x]++;
	   for(auto z:a)
		   if(z.second==1)
			   return z.first;
	   return -1;
    }
};

//Method 2
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};
// Method 3
To use this approach you first need to understand about Bitwise XOR operator.
Most of us who have a background in physics ( highschool level ) , are aware of the LOGIC GATES.
One of such gates is the XOR Gate :
According to this gate , the output is true , only if both the inputs are of opposite kind .
That is ,
A B Y
0 0 0
0 1 1
1 0 1
1 1 0

We apply the extended version of this gate in our bitwise XOR operator.
If we do "a^b" , it means that we are applying the XOR gate on the 2 numbers in a bitwise fashion ( on each of the corresponding bits of the numbers).
Similarly , if we observe ,

A^A=0
A^B^A=B
(A^A^B) = (B^A^A) = (A^B^A) = B This shows that position doesn't matter.
Similarly , if we see , a^a^a......... (even times)=0 and a^a^a........(odd times)=a
Google It for more details.

We apply the above observations :

Traverse the array and take the Bitwise XOR of each element.
Return the value.
Why does this work ??
Because , the elements with frequency=2 will result in 0. And then the only element with frequency=1 will generate the answer.


//Method 4

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};

