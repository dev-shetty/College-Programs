class MultiThreadDemo extends Thread {
    public void run() {
        try {
            System.out.println("Thread " + Thread.currentThread().threadId() + " is running.");
        } catch (Exception e) {
            System.out.println("Execption caught");
        }
    }
}

public class MultiThreadingClass {
    public static void main(String[] args) {
        int n = 8;
        for (int i = 0; i < n; i++) {
            MultiThreadDemo mtd = new MultiThreadDemo();
            mtd.start();
        }
    }
}
