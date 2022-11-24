public class PrintFristNumber {

    // 5. PRINT FIRST N NUMBER

    public static int printNum(int num) {

        if (num == 0)
            return 1;
        int output = printNum(num - 1);
        // for Accesding order
        System.out.println(num);
        return output;
    }
    public static void main(String[] args) {
        System.out.println(printNum(5));
    }
}
