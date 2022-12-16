/*
* 1A) Consider a collection of series with a combination of 2 sequence - all the odd terms 
* in this series from a geometric series and all the even terms form yet another geometric series.
* Develop a java program to find the nth term in the series.

? Sample Series:
    1, 1, 2, 3, 4, 9, 8, 27, 16, 81, 32, 243, 64, 729, 128, 2187, ...

? Sample Output:
    Enter the nth term: 12
    12th term of the series is: 243.0
*/

import java.lang.Math;
import java.util.Scanner;

class GeometricSeries {
    void findNTerm(int n) {
        int num = n;
        if(n%2==0) {
            n = n/2;
            System.out.println(num + "th term of the series is: " + Math.pow(3, n-1));
        } else {
            n = n/2 + 1;
            System.out.println(num + "th term of the series is: " + Math.pow(2, n-1));
        }
    }
}

public class Series {
    public static void main(String[] args) {
        GeometricSeries geo = new GeometricSeries();
        Scanner in = new Scanner(System.in);
        int n;
        System.out.print("Enter the nth term: ");
        n = in.nextInt();
        geo.findNTerm(n);

        in.close();
    }
}