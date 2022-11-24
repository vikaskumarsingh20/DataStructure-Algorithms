public class SrairClimb {

    static int stairClimb(int n){
        // base base
        if(n == 1 || n == 2){
            return n;
        }
       
        int output = stairClimb( n - 1) + stairClimb(n -2);
           return output ;
    }
    /**
     * @param args
     */
    public static void main(String[] args) {
        int n = 2;
        System.out.println(stairClimb(n));
    }
}
