package Recursion;

public class Pyramid {

    static void printSpace(int nSpace) {   // for space print 
        if(nSpace == 0) {
            return;
        }
        System.out.print(" ");
        printSpace(nSpace - 1);
    }

    static void printStar(int nStar) {  // for star print
        if(nStar == 0) {
            return;
        }
        System.out.print("*");
        printStar(nStar - 1);
    }

    static void printPattern(int rows, int currentRow) {   // pattern logic 
        if(rows == 0) {
            return;
        }
        printSpace(rows - 1);
        printStar(currentRow);
        // printStar(2*currentRow - 1);
        System.out.println();
        printPattern(rows - 1, currentRow + 1);
    }

    public static void main(String[] args) {
        printPattern(5, 1);
    }
}
