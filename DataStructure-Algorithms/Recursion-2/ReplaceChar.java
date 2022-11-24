// REPLACE CHARACTERS WITH WITH EACH OTHERS PROGRAM

public class ReplaceChar {
    
      public static String replingChar(String s , char a , char b){
        // base case 
        if(s.length() == 0)
          return s;

     String smallOutput = replingChar(s.substring(1), a, b);
    
     if(s.charAt(0) == a)
          return (b + smallOutput);
     
     else
        return s.charAt(0) + smallOutput;
    
        
      }

    public static void main(String[] Args){
 
      System.out.println(replingChar("abababa", 'a' , 'b'));
    }
}
