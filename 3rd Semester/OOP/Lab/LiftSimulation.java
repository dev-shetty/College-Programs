import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.Semaphore;

public class LiftSimulation {
    static int currentFloor1 = 1;
    static int currentFloor2 = 10;
    static Semaphore semaphore = new Semaphore(1);
    static Queue<Integer> requestQueue = new LinkedList<>();

    public static void main(String[] args) {
        Thread lift1 = new Thread(new Lift("Lift1", currentFloor1));
        Thread lift2 = new Thread(new Lift("Lift2", currentFloor2));
        lift1.start();
        lift2.start();

        for (int i = 1; i <= 10; i++) {
            Thread person = new Thread(new Person(i));
            person.start();
        }
    }

    static class Lift implements Runnable {
        String name;
        int currentFloor;

        Lift(String name, int currentFloor) {
            this.name = name;
            this.currentFloor = currentFloor;
        }

        @Override
        public void run() {
            while (true) {
                try {
                    semaphore.acquire();
                    if (!requestQueue.isEmpty()) {
                        int targetFloor = requestQueue.poll();
                        System.out.println(name + " is on the way to Floor " + targetFloor);
                        int distance = Math.abs(targetFloor - currentFloor);
                        Thread.sleep(distance * 1000);
                        currentFloor = targetFloor;
                        System.out.println("Lift has been arrived at " + targetFloor);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                } finally {
                    semaphore.release();
                }
            }

        }

    }

    static class Person implements Runnable {
        int floor;

        Person(int floor) {
            this.floor = floor;
        }

        @Override
        public void run() {
            try {
                int sleepTime = (int) Math.random() * 10000;
                Thread.sleep(sleepTime);
                semaphore.acquire();
                requestQueue.offer(floor);
                System.out.println("Person on floor " + floor + " called the lift");
            } catch (Exception e) {
                e.printStackTrace();
            } finally {
                semaphore.release();
            }
        }
    }

}
