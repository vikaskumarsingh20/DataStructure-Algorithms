//SUM OF THE DIGIT USING RECURSION 

public class sumDigit {

    public static int sumOfDigit(int num){
        if(num/10 == 0){
            return num;
        }

        int temp = sumOfDigit(num%10);
        int others =sumOfDigit(num/10);
        return temp + others;
    }
    public static void main(String[] args) {
        System.out.println(sumOfDigit(12345));
    }
}
