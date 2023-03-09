import java.util.*;

public class Arithemetic {
    double x, y;
    double z = 0;

    public void getInput1() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the double value for x: ");
        x = (double) sc.nextDouble();
        System.out.print("Enter the double value for y: ");
        y = (double) sc.nextDouble();

        try {
            if (y == 0) {
                throw new ArithmeticException("Divide by 0 error");
            }
            double result = x / y;
            System.out.println(x + " / " + y + " = " + result);
        } catch (ArithmeticException e) {
            System.out.println("Raised Exception is " + e);
        }
    }

    public void getInput2() {
        Scanner sc = new Scanner(System.in);
        try {
            double[] arr = new double[5];
            System.out.print("Enter the array elements: ");
            for (int i = 0; i < arr.length; i++) {
                arr[i] = sc.nextDouble();
            }
            System.out.println("Array elements are: ");
            for (int i = 0; i <= arr.length; i++) {
                System.out.println(arr[i]);
            }
        } catch (IndexOutOfBoundsException e) {
            System.out.println("Raised execption is: " + e);
        }
    }

    public static void main(String[] args) {
        Arithemetic obj = new Arithemetic();
        obj.getInput1();
        obj.getInput2();
    }
}
