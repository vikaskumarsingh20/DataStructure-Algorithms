public class checkPalindrome {

    public static boolean helper(String s , int si , int ei){

        // base case
        if( si >= ei){
            return true;
        }

        while(s.charAt(si) != s.charAt(ei)){
            return false;
        }
        return helper(s , si+ 1 , ei -1);
    }

    public static boolean isPalindromeString(String s){
        int si = 0;
        int ei = s.length() - 1;
        
        return helper(s, si ,ei);
    }
    public static void main(String[] args) {
        System.out.println(isPalindromeString(""));
    }
}
