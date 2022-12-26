class BoxDimensions {
    double width;
    double height;
    double depth;

    // Constructor Overloading

    BoxDimensions() {
        width = 10;
        height = 10;
        depth = 10;
    }

    BoxDimensions(double w, double h, double d) {
        width = w;
        height = h;
        depth = d;
    }

    double volume() {
        double volume = width * height * depth;
        return volume;
    }

}

public class Box {
    public static void main(String[] args) {
        // Default Constructor
        BoxDimensions box1 = new BoxDimensions();
        System.out.println("Default values initialized using constructor");
        System.out.println("Width: " + box1.width + "\tHeight: " + box1.height + "\tDepth: " + box1.depth);
        System.out.println("Volume of box 1 is: " + box1.volume());
        System.out.println();

        // Parameterized Constructor
        BoxDimensions box2 = new BoxDimensions(100, 200, 300);
        System.out.println("Values initialized using parameterized constructor");
        System.out.println("Width: " + box2.width + "\tHeight: " + box2.height + "\tDepth: " + box2.depth);
        System.out.println("Volume of box 2 is: " + box2.volume());
    }
}
