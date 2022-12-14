import java.util.ArrayList;

public class BoardDice {

    static ArrayList<String> dicePos(int source, int target){
        // Termination Case
        if(source == target){    // if matched then stored in array and return it
            ArrayList<String> list = new ArrayList<>();
            list.add("");
            return list;
        }
      
        if(source> target){   // when outpt of range 
            ArrayList<String> list = new ArrayList<>();
            return list;
        }
      
        // Dice Roll
        ArrayList<String> finalResult = new ArrayList<>();
        for(int dice = 1; dice<=6; dice++){
            int currentValue = source + dice;
            ArrayList<String> list = dicePos(currentValue, target);
            for(String temp : list){
                finalResult.add(temp + dice);
            }
        }
        return finalResult;
    }
    public static void main(String[] args) {
        System.out.println(dicePos(0, 10));
        
    }
}
