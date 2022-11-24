public class Factorial{
  
 
   // 1. FACTORAIL FINDING
   public static int fact(int n) {

     if (n == 0)
       return 1;
     int smallProblem = fact(n - 1);
     int output = n * smallProblem;

     return output;
   }

    /**
     * @param args
     */
    public static void main(String[] args) {
      System.out.println(fact(5));
  }
}