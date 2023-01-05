import java.util.ArrayList;

public class bracketCombination {

 
  static ArrayList<String> bracketCombo(String number){
    // base case
    if(number.length() == 0){
        ArrayList<String> empList  = new ArrayList<>();
        empList.add("");
        return empList;
    }
 
   }
    public static void main(String[] args) {
        ArrayList<String> list = bracketCombo(3);
        System.out.println(list);
    }
}