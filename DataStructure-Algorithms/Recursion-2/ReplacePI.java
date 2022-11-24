/*Replace Characters Recursively
 * 

 Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
Do this recursively.
 */


public class ReplacePI {
    public static String replacePi(String s) {
        if (s.length() <= 1) {
            return s;
        }
        if (s.charAt(0) == 'p' && s.charAt(1) == 'i') {
            // Call recursion on string of length n-2;
            String smallOutput = replacePi(s.substring(2));
            return "3.14" + smallOutput;
        } else {
            // call recursion on string of length n-1;
            String smallOutput = replacePi(s.substring(1));
            return s.charAt(0) + smallOutput;
        }
         
    }
    
    public static void main(String[] args) {
        System.out.println(replacePi("abaipipipipipi"));
    }
}
