import java.util.HashMap;

public class frequencyChar {
    public static void main(String[] args) {
        String str = "vikas singh";  // given string 
        HashMap<Character, Integer> map = new HashMap<>();
        for(int i  = 0; i<str.length(); i++){  // interate all string 
            char singleChar = str.charAt(i); // indexing 
            if(singleChar == ' '){  // if meet empty string  then skip it 
                continue;
            }
            if(map.get(singleChar)== null){    //  meet null string then put into map
                map.put(singleChar, 1);  
            }
            else{
                int count = map.get(singleChar);  
                map.put(singleChar, count+1);   // upates count 
            }
        }
        System.out.println(map);  // print it 

    }
}

// output  ->{a=1, s=2, v=1, g=1, h=1, i=2, k=1, n=1}
