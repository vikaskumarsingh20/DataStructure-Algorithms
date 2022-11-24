public class Power {
    // 3 . POWER

    public static int pow(int num, int n) {

        if (n == 0) {
            return 1;
        }

        int smallProblem = pow(num, n - 1);
        int output = num * smallProblem;
        return output;
    }

    public static void main(String[] args) {
        System.out.println(pow(2, 5));
    }
}
