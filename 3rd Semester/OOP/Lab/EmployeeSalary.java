/*
* In the IT company there are 20 employees and the monthly salary of the employess must be arranged
* in descending order. Write a Java Program to read 20 employess salaries as a floating point numbers
* and apply forEach to perform the sorting and display the result. Also the industry places the 
* highest paid employee in the first level, the next highest paid 2 employees placed in the second 
* level and next 3 highest paid employees in the third level and so on.

? Sample Output:
    Enter employee salary: 
    Employee1: 12000
    Employee2: 15000.5
    Employee3: 36000
    Employee4: 87000
    Employee5: 96000
    Employee6: 125000
    Employee7: 36500
    Employee8: 14500.75
    Employee9: 78000
    Employee10: 92000
    Employee11: 35000.5
    Employee12: 78000
    Employee13: 165000
    Employee14: 220000
    Employee15: 21400
    Employee16: 65410
    Employee17: 12300
    Employee18: 78000
    Employee19: 46000
    Employee20: 32000
    The output as per the given format is: 
    220000.0
    165000.0  125000.0
    96000.0  92000.0  87000.0
    78000.0  78000.0  78000.0  65410.0
    46000.0  36500.0  36000.0  35000.5  32000.0
    21400.0  15000.5  14500.75 12300.0  12000.0
*/

import java.util.Scanner;

public class EmployeeSalary {
    void sort(float[] arr) {
        int n = arr.length;
        float temp;
        for (int i = 0; i < n - 1; i++) {
            float max = arr[i];
            for (int j = i + 1; j < n; j++) {
                if (max < arr[j]) {
                    temp = arr[j];
                    arr[j] = max;
                    max = temp;
                }
            }
            arr[i] = max;
        }
    }

    public static void main(String[] args) {
        EmployeeSalary emp = new EmployeeSalary();
        int n = 20;
        Scanner in = new Scanner(System.in);
        float emp_salary[] = new float[n];
        System.out.println("Enter employee salary: ");
        for (int i = 0; i < n; i++) {
            System.out.print("Employee" + (i + 1) + ": ");
            emp_salary[i] = in.nextFloat();
        }
        emp.sort(emp_salary);
        System.out.println("The output as per the given format is: ");
        int x = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j <= i; j++) {
                if (x == n)
                    break;
                System.out.print(emp_salary[x] + "  ");
                x++;
            }
            System.out.println();
        }
        in.close();
    }
}
