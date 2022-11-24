public class SumOfNaturalN {
    // 2. SUM OF NATURAL NUMBER
    public static int sumn(int n) {
        // base case:
        if (n == 0)
            return 0;

        int smallProblem = sumn(n - 1);
        int Output = n + smallProblem;
        return Output;
    }

    public static void main(String[] args) {
        System.out.println(sumn(5));
    }
}
