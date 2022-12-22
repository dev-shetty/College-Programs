/*
* 2B) In a financial application computing the CD value where CD is the Certificate of Deposit 
* allows you to save money at a fixed interest rate for a fixed amount of time suppose you put 
* INR 10,000 into a CD with an annual percentage yield of 5.75%. After one month the CD is worth 
* INR 10,047.91. Calculated as 
? CD_Amount + CD_Amount * (interest/(total no. of month * 100)).
* Write a program using appropriate class and objects that prompts the user to enter an amount,
* the amount percentage yield and the number of months and display a table as shown below.

? Sample Output:
    Enter the deposit amount: 10000
    Enter annual percentage yield: 5.75
    Enter maturity period (no. of months): 18
        Month   CD Value
        1       10047.917
        2       10096.063
        3       10144.44
        4       10193.049
        5       10241.891
        6       10290.967
        7       10340.277
        8       10389.824
        9       10439.608
        10      10489.632
        11      10539.895
        12      10590.398
        13      10641.145
        14      10692.134
        15      10743.367
        16      10794.846
        17      10846.571
        18      10898.545
*/

import java.util.Scanner;

class Calculate {
    float initialAmount;
    float rate;
    int timePeriod;

    void readData() {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the deposit amount: ");
        initialAmount = in.nextFloat();
        System.out.print("Enter annual percentage yield: ");
        rate = in.nextFloat();
        System.out.print("Enter maturity period (no. of months): ");
        timePeriod = in.nextInt();
    }

    void displayData() {
        float CDValue = initialAmount;
        System.out.println("\tMonth \tCD Value");
        for (int i = 0; i < timePeriod; i++) {
            CDValue = CDValue + CDValue * (rate / (12 * 100));
            System.out.println("\t" + (i + 1) + "\t" + CDValue);
        }
    }
}

public class CDValue {
    public static void main(String[] args) {
        Calculate cal = new Calculate();
        cal.readData();
        cal.displayData();
    }
}
