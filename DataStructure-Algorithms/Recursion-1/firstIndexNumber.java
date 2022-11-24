/**
 * firstIndexNumber
 */
/*
 * First Index Of a Number in an Array - Question
 * 
 * Given an array of length N and an integer x, you need to find and return the
 * first index of integer x present in the array. Return -1 if it is not present
 * in the array.
 * First index means, the index of first occurrence of x in the input array.
 * Do this recursively. Indexing in the array starts from 0.
 * 
 */
public class firstIndexNumber {

    /**
     * @param arr
     * @param val
     * @param index
     * @return
     */
    public static int findElementArray(int arr[] , int val , int index){
        // base case
          if(index == arr.length){
            return -1;
          }
          if(arr[index] == val){
            return index;
          }

          int ans = findElementArray(arr, val, index+1);
            return ans;
    }

    public static void main(String[] args) {
        
        int arr[] = {1,2,3,4};
        int val = 4;
        System.out.println(findElementArray(arr, val, 0));
    }
}