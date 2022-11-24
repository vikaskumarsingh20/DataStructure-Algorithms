public class CountDIGIT {
    // 4. COUNT DIGIT

    public static int countDigit(int num) {

        // base case
        if (num / 10 == 0) {
            return 1;
        }
        int output = 1 + countDigit(num / 10);
        return output;
    }

    public static void main(String[] args) {
        System.out.println(countDigit(6));
    }
}
