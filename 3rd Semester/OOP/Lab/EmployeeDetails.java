import java.io.*;

/*
* 2C) Create a java class called Employee with following details as variables within it -
* (i) EmpId (ii) empName (iii) salary (iv) phoneNo
* Write a java program to create n employee objects and print the empId, empName, salary and phoneNo of
* these objects with suitable headings.

? Sample Output:
    Enter total no. of employees: 2
    Enter employee 1's ID: 1001
    Enter employee 1's Name: Dev 
    Enter employee 1's Salary: 45000
    Enter employee 1's Phone No.: 8798465
    Enter employee 2's ID: 1002
    Enter employee 2's Name: Rohan
    Enter employee 2's Salary: 50000
    Enter employee 2's Phone No.: 524564 
    
    Employee Details are as follows: 
                    ID      Name    Salary  Phone No.
    Employee 1      1001    Dev     45000   8798465
    Employee 2      1002    Rohan   50000   524564
*/

class Employee {
    int empId, salary;
    String empName, phoneNo;

    Employee(int id, int salary, String name, String phno) {
        empId = id;
        // Used a this because why not.
        this.salary = salary;
        empName = name;
        phoneNo = phno;
    }

    void displayData(int i) {
        System.out.println("Employee " + (i + 1) + " \t" + empId + " \t" + empName + " \t" + salary + " \t" + phoneNo);
    }
}

public class EmployeeDetails {
    public static void main(String[] args) throws IOException {
        int n;
        InputStreamReader i = new InputStreamReader(System.in);
        BufferedReader b = new BufferedReader(i);
        System.out.print("Enter total no. of employees: ");
        n = Integer.parseInt(b.readLine());
        Employee e[] = new Employee[n];
        for (int j = 0; j < n; j++) {
            System.out.print("Enter employee " + (j + 1) + "'s ID: ");
            int id = Integer.parseInt(b.readLine());
            System.out.print("Enter employee " + (j + 1) + "'s Name: ");
            String name = b.readLine();
            System.out.print("Enter employee " + (j + 1) + "'s Salary: ");
            int salary = Integer.parseInt(b.readLine());
            System.out.print("Enter employee " + (j + 1) + "'s Phone No.: ");
            String phno = b.readLine();

            e[j] = new Employee(id, salary, name, phno);
        }

        System.out.println("Employee Details are as follows: ");
        System.out.println();
        System.out.println("\t\tID \tName \tSalary \tPhone No.");
        for (int j = 0; j < n; j++) {
            e[j].displayData(j);
        }
    }
}
