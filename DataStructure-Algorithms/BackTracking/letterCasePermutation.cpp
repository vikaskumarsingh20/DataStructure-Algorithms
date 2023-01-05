link-> https://leetcode.com/problems/letter-case-permutation/submissions/?envType=study-plan&id=algorithm-i

Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.

 

Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]


class Solution {
public:
    vector<string> ans;
    void helper(string s, int index)
    {
        // Base Case
        if(index >= s.length())
        {
            ans.push_back(s);
            return;
        }
        // If s[index] is uppercase, convert to lower and call for helper again
        if(s[index] >= 65 and s[index] <= 90)
        {
            s[index] = (int)tolower(s[index]);
            helper(s, index + 1);
            s[index] = (int)toupper(s[index]);
        }
        // if(s[index]) is lowercase, convert to uppercase and call for helper
        else if(s[index] >= 97 and s[index] <= 122)
        {
            s[index] = (int)toupper(s[index]);
            helper(s, index + 1);
            s[index] = (int)tolower(s[index]);
        }
        // if s[index] is not a letter, ie a digit or something else
        helper(s, index + 1);
    }
    
    vector<string> letterCasePermutation(string s) {
        helper(s, 0);
        return ans;
    }
};
         
         
         
