public class fibonacci {

    // 6. FIBBONACCI SERIES
    public static int fibo(int num) {
        // base case
        if (num == 1 || num == 2) {
            return 1;
        }

        int smallProblem = fibo(num - 1) + fibo(num - 2);
        int output = smallProblem;
        return output;

    }

    public static void main(String[] args) {
        System.out.println(fibo(5));
    }
}
