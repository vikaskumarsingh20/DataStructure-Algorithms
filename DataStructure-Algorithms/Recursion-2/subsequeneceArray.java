import java.util.ArrayList;

public class subsequeneceArray {

    static ArrayList<String> subSeq(String str){

        // BASE CASE
        if(str.length() == 0){
            // if stack full then return with ArrayList 
            ArrayList <String > output = new ArrayList<>();
            output.add("");
            return output;
        }
        // string at first index
        char currentChar = str.charAt(0);
        // all remaning string by recursion
       String remString = str.substring(1);

       
       // temp array store all string 
       ArrayList<String> temp = subSeq(remString);
       ArrayList<String> ans = new ArrayList<>();
       for(String s: temp){
         ans.add(s);
         ans.add( currentChar +s);
       }
    return ans;


    }
    public static void main(String[] args) {
        String str = "ravi";
        ArrayList<String > s = subSeq(str);
        System.out.println(s);
    }
}
