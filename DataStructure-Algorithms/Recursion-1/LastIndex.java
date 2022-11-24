/*Last Index Of a Number in an Array - Question
 * 
 * Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
You should start traversing your array from 0, not from (N - 1).
Do this recursively. Indexing in the array starts from 0.
 */

public class LastIndex {

    public static int lastIndexSearch(int arr[]  , int val , int index){
          // base case
           if(index == arr.length){
              return -1;
           }

           int  k = lastIndexSearch(arr, val, index +1);
            if( k != -1){
                return k;
            }

            else{
                if( arr[index] == val){
                    return index;
                }
                else{
                    return -1;
                }
            }
    }
    public static void main(String[] args) {
        int arr[] = {1,2,3,4,4,5,5,5};
         System.out.println(lastIndexSearch(arr, 5, 0));
        
    }
}
