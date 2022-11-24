public class ArraySum {

    // 7. SUM OFTHE ARRRAY

    public static int sum(int input[], int i) {

        if (i == input.length) {
            return 0;
        }
        return input[i] + sum(input, i + 1);
    }

    public static int sum(int input[]) {
        return sum(input, 0);
    }

 
    /**
     * @param args
     */
    public static void main(String[] args) {
        
    }
}
