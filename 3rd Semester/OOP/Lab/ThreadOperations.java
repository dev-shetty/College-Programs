import java.util.Random;

class Square extends Thread {
    int side;

    Square(int side) {
        this.side = side;
    }

    public void run() {
        int squared = side * side;
        System.out.println("Square is = " + squared);
    }
}

class Cube extends Thread {
    int side;

    Cube(int side) {
        this.side = side;
    }

    public void run() {
        int cube = side * side * side;
        System.out.println("Cube is = " + cube);
    }
}

class Reverse extends Thread {
    int number;

    Reverse(int number) {
        this.number = number;
    }

    public void run() {
        int temp = number, reverse = 0, rem;
        while (temp != 0) {
            rem = temp % 10;
            reverse = reverse * 10 + rem;
            temp /= 10;
        }
        System.out.println("Reverse of " + number + " is: " + reverse);
    }
}

// Just for a change implementing Runnable
class RandomNumbers implements Runnable {
    Random r = new Random();
    int size = 10;

    public void run() {
        for (int i = 0; i < size; i++) {
            System.out.println("Random number is = " + r.nextInt(100));
        }
    }
}

public class ThreadOperations {
    public static void main(String[] args) {
        Thread t1 = new Square(5);
        t1.start();
        Thread t2 = new Cube(5);
        t2.start();
        Thread t3 = new Thread(new RandomNumbers());
        t3.start();
        Thread t4 = new Reverse(123456);
        t4.start();

    }
}
