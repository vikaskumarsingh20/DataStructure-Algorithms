import java.util.ArrayList;

public class PermutationString {

    /**
     * @param str
     * @return
     */
    static ArrayList<String> PermutationString(String str){
        // base case 
        if(str.length() == 0){
            ArrayList<String> output = new ArrayList<>();
               output.add("");
          return output;
        }

        char currentChar = str.charAt(0);
        String remString = str.substring(1);

        ArrayList<String > temp = PermutationString(remString);
        ArrayList<String> result = new ArrayList<>();

        for(String s: temp){
            for(int i =0 ;i<=s.length();i++){
                StringBuffer sb = new StringBuffer(s);
                sb.insert(i ,currentChar );
                result.add(sb.toString());

            }

        }
        return result;
    }
    public static void main(String[] args) {
        String str ="abc";
        ArrayList<String> s = PermutationString(str);
        System.out.println(s);
    }
}
