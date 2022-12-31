interface in1 {
    final int a = 10;

    void printName(String name);
}

class Hindi implements in1 {
    @Override
    public void printName(String name) {
        System.out.println("Namaste " + name);
    }
}

class English implements in1 {
    @Override
    public void printName(String name) {
        System.out.println("Hello " + name);
    }
}

public class InterfaceDemo {
    public static void main(String[] args) {
        English eng = new English();
        Hindi hin = new Hindi();
        eng.printName("Deveesh");
        hin.printName("Deveesh");
        System.out.println("Value of a in English: " + eng.a + " in Hindi: " + hin.a);
    }
}
