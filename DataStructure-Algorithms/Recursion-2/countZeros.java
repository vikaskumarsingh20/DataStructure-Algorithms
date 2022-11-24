
/*
Given an integer N, count and return the number of zeros that are present in the given integer using recursion.
 * 
 */
public class countZeros {
    
    public static int countZerosRec(int input){
		// Write your code here        
        if(input==0){
            return 1;
        }
     if(input<10){
        return 0;
     }
     else if(input%10==0){
         return 1+ countZerosRec(input/10);
     }
     return countZerosRec(input/10);
    }

    public static void main(String[] args){
        System.out.println(countZerosRec(708000));
    }

}
