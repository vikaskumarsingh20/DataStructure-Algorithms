package HashMap;

import java.util.ArrayList;
import java.util.HashMap;

public class removeDuplicates {

    public static ArrayList<Integer> removeDuplicate(int arr[]){
        // for storing the values in array
         ArrayList<Integer> result =  new ArrayList<>();

         // create a hashmap to put unique values
         HashMap<Integer , Boolean> map = new HashMap<>();
          
         // interate whole array
         for(int  i = 0 ; i <arr.length ;i++){
            // if matched duplicates then skip it 
            if(map.containsKey(arr[i])){
                continue;
            }
            // if present the add into array What is the return type of containsKey()
            // function in Hashmap
            result.add(arr[i]);

            // insert into hashmap and print it
            map.put(arr[i] , true);
         }

         return result;

    }
    public static void main(String[] args) {
        int arr[] = { 1,2,2,3,4,3,2,2,2,2,23,2,4,5,6};  // output [1, 2, 3, 4, 23, 5, 6]
        ArrayList<Integer> output = removeDuplicate(arr);
        System.out.println(output);
    }
}
