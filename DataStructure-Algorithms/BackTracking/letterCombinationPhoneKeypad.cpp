class Solution {
private:
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[] ) {
        
        //base case
        if(index >= digit.length()) { 
            ans.push_back(output);
            return;
        }
        
        int number = digit[index] - '0';  //convert string into int
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(digit, output, index+1, ans, mapping);
            //backTracking step
            output.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};


// JAVA SULUTION 
/*
 import java.util.*;
public class letterCombination {
    static String keypadKeys[] = {"","v" , "abc" , "def","ghi" , "jkl","mno" ,"pqrs","tuv","wxyz"};
 
    static ArrayList<String> keypad (String number){

        // base case
         if(number.length() == 0){
            ArrayList<String> empList = new ArrayList<>();
            empList.add("");
            return empList;
         }
     char currentChar = number.charAt(0); // for 2 index
     String remString = number.substring(1); // for 3 index
 
     int index = currentChar - '0'; // convert into integer
     String key = keypadKeys[index];
     ArrayList<String> result = new ArrayList<>();

     for(int i=0;i<key.length();i++){
        ArrayList<String> temp = keypad(remString);
        for(String s : temp){
            result.add(key.charAt(i) + s);
        }
     }
     return result;
    }

    public static void main(String[] args){
     
        ArrayList<String> list = keypad("23");
        System.out.println(list);
    }
}

*/
