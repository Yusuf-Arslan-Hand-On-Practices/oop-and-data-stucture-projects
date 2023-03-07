import java.util.Scanner;

// This class is implemented to find the intersection of two lines.
// The intersection is a point, which is represented by a class Point2D.
// Also with main method, you can test the class.

class Intersection {

    /**
     * A Point2D is a class that has two double fields, x and y, and a constructor that takes two
     * doubles and assigns them to x and y.
     */
    public static class Point2D {
        public double x;
        public double y;

        public Point2D(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public String toString() {
            // Return a string representation of this point.
            // Float values are rounded to 5 decimal places.

            // Round x and y to 5 decimal places.
            x = Math.round(x * 100000) / 100000.0;
            y = Math.round(y * 100000) / 100000.0;
            return "(" + x + ", " + y + ")";
        }
    }

    public static Point2D getIntersectingPoint(Point2D p1, Point2D p2, Point2D p3, Point2D p4) {
        // If the two lines are parallel, return null.
        // Formula: (y2 - y1) / (x2 - x1) = (y4 - y3) / (x4 - x3)
        if ((p2.y - p1.y) / (p2.x - p1.x) == (p4.y - p3.y) / (p4.x - p3.x)) {
            return null;
        }
        
        // Formula: x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4))
        // Formula: y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4))

        // Calculate the intersection point.
        double x = ((p1.x * p2.y - p1.y * p2.x) * (p3.x - p4.x) - (p1.x - p2.x) * (p3.x * p4.y - p3.y * p4.x))
                / ((p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x));


        double y = ((p1.x * p2.y - p1.y * p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x * p4.y - p3.y * p4.x))
                / ((p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x));

        return new Point2D(x, y);
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);        
        // Get the input from the user.
        System.out.print("Enter x1, y1, x2, y2, x3, y3, x4, y4: ");

        // Read the input in string format. (to be able to handle negative and decimal values)
        String x1 = scanner.next();
        String y1 = scanner.next();
        String x2 = scanner.next();
        String y2 = scanner.next();
        String x3 = scanner.next();
        String y3 = scanner.next();
        String x4 = scanner.next();
        String y4 = scanner.next();

        // Create two points for each line. 
        Point2D p1 = new Point2D(Double.parseDouble(x1), Double.parseDouble(y1));
        Point2D p2 = new Point2D(Double.parseDouble(x2), Double.parseDouble(y2));
        Point2D p3 = new Point2D(Double.parseDouble(x3), Double.parseDouble(y3));
        Point2D p4 = new Point2D(Double.parseDouble(x4), Double.parseDouble(y4));

        Point2D intersectingPoint = getIntersectingPoint(p1, p2, p3, p4);
        if (intersectingPoint == null) {
            System.out.println("The two lines are parallel");
        } else {
            System.out.println("The intersecting point is at " + intersectingPoint);
        }
        scanner.close();
    }
}