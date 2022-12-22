/*
* 2A) There are n people standing in a circle ready to be executed. The counting out starts at some 
* point in the circle and proceeds around the circle in a fixed direction. In every step a certain
* number of people are skipped and the next individual is executed. The removal proceeds around the
* circle until last person remains, who is given freedom. Given the total number of person N and the 
* number k which indicates the k-1 persons are skipped and the kth person is removed in a circle. The
* task is to choose the place in the initial circle so that you are the last one remaining and so
* survive.

? Sample Output:
    Enter the number of people: 12
    Enter the k value: 3
    The safe position is: 10
*/

import java.util.Scanner;

public class JosephusExecution {
    int findSafePosition(int n, int k) {
        if (n == 1)
            return n;
        else
            return (findSafePosition(n - 1, k) + k - 1) % n + 1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        JosephusExecution exe = new JosephusExecution();
        int n, k;
        System.out.print("Enter the number of people: ");
        n = in.nextInt();
        System.out.print("Enter the k value: ");
        k = in.nextInt();

        int safePosition = exe.findSafePosition(n, k);
        System.out.println("The safe position is: " + safePosition);

        in.close();
    }
}
