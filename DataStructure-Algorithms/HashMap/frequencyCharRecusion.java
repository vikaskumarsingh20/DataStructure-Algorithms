import java.util.HashMap;

public class frequencyCharRecusion {
    static HashMap<Character, Integer> getFrequency(String str, int len , int index){
        if(index == len){   // base case  bottom up approach
            HashMap<Character, Integer> map = new HashMap<>();  // crate hashMap when stack full and retuen then perfom operation
            return map;
        }
        HashMap<Character, Integer> map = getFrequency(str, len, index + 1);   // update index value by recusion 
        char singleChar = str.charAt(index);
        if(map.get(singleChar) == null){  
            map.put(singleChar, 1);
        }
        else{
            int count  = map.get(singleChar);
            map.put(singleChar , count + 1);
        }
        return map;   
    }
    public static void main(String[] args) {
        String str = "vikas singh";
        HashMap<Character, Integer> map = getFrequency(str, str.length(), 0);  // calls mathod or function 
        System.out.println(map);
    }
}
