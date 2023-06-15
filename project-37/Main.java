import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Shape> shapes = new ArrayList<>();

        shapes.add(new Circle(5));
        shapes.add(new Rectangle(3, 4));
        shapes.add(new Triangle(6, 2));

        double totalArea = calculateTotalArea(shapes);
        System.out.println("The total area is: " + totalArea);
    }

    public static double calculateTotalArea(List<Shape> shapes) {
        double totalArea = 0;

        for (Shape shape : shapes) {
            totalArea += shape.calculateArea();
        }

        return totalArea;
    }
}