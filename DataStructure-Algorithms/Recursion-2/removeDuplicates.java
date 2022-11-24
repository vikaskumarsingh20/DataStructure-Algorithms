
// REMOVE THE CHARACTERS FROM THE STRING
public class removeDuplicates {

    public static String removeChar(String s , char a){

        // base case
          if(s.length() == 0)
           return s;
     
           String smallOutput = removeChar(s.substring(1) ,a);
            if(s.charAt(0) == a)
             return smallOutput;

          else
         return s.charAt(0) + smallOutput;
    }

      // Remove Duplicates Recursively
    public static String removeConsecutiveDuplicates(String s) {
       
        if (s.length() <= 1) {
            return s;
        }
        String smalloutput = removeConsecutiveDuplicates(s.substring(1));
        if (s.charAt(0) == s.charAt(1)) {

            return smalloutput;
        } else {

            return s.charAt(0) + smalloutput;
        }
    }
    public static void main(String[] args) {
        System.out.println(removeChar("axaxxxxbbxxaaa" , 'x'));
        System.out.println(removeConsecutiveDuplicates("vikkas"));
    }
}
