class MultiThreadingDemo implements Runnable {
    public void run() {
        try {
            System.out.println("Thread " + Thread.currentThread() + "is running.");
            Thread.sleep(500);
        } catch (Exception e) {
            System.out.println("Exeception is caught");
        }
    }
}

public class MultiThreadingInterface {
    public static void main(String[] args) {
        int n = 8;
        Thread t = new Thread();
        System.out.println("Main Thread " + Thread.currentThread().threadId() + " is running.");
        for (int i = 0; i < n; i++) {
            MultiThreadDemo mtd = new MultiThreadDemo();
            mtd.start();
        }
    }
}
