import java.util.*;

class NotEnoughFruits extends Exception {
    public NotEnoughFruits(String s) {
        super(s);
    }
}

class BoxFullException extends Exception {
    public BoxFullException(String s) {
        super(s);
    }
}

class LowStock extends Exception {
    public LowStock(String s) {
        super(s);
    }
}

public class FruitsException {
    private String fruitName;
    private int qty;

    FruitsException() {
        fruitName = "";
        qty = 0;
    }

    FruitsException(String name, int count) {
        fruitName = name;
        qty = count;
    }

    public void addFruits(int count) {
        try {
            if (qty + count > 100) {
                throw new BoxFullException("Box is almost full. You can add only " + 100 + " fruits");
            } else {
                qty += count;
            }
        } catch (BoxFullException e) {
            System.out.println(e.getMessage());
        }
    }

    public void useFruits(int count) throws LowStock {
        try {
            if (qty == 0) {
                throw new LowStock("Low Stock");
            }
            if (qty < count) {
                throw new NotEnoughFruits("You have only " + qty + " number of fruits");
            } else {
                qty -= count;
            }
            if (qty > count) {
                throw new BoxFullException("Box is almost full");
            }
        } catch (NotEnoughFruits e) {
            System.out.println(e.getMessage());
        } catch (BoxFullException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the name of the fruit: ");
        String name = sc.next();
        System.out.print("Enter the quantity of the fruit: ");
        int qty = sc.nextInt();
        try {
            FruitsException obj = new FruitsException(name, qty);
            System.out.print("Enter the no. of fruits to be added: ");
            int n = sc.nextInt();
            obj.addFruits(n);
            obj.useFruits(101);
        } catch (LowStock e) {
            System.out.println(e.getMessage());
        }
    }

}