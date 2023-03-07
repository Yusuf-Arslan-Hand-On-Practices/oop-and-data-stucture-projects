// Driver program for Circle2D class
public class Driver {
    public static void main(String[] args) {
        driverCircle2D();
        driverMyInteger();
    }

    private static void driverCircle2D() {
        System.out.println("\n\n------- Circle2D class driver -------\n");
        Circle2D c1 = new Circle2D(2, 2, 5.5);
        System.out.println("Circle 1: " + "center (" + c1.getX() + ", " + c1.getY() + "), radius " + c1.getRadius());
        System.out.println("Area is " + c1.getArea());
        System.out.println("Perimeter is " + c1.getPerimeter());
        System.out.println("c1 contains (3, 3)? " + c1.contains(3, 3));
        System.out.println("c1 contains circle2 (4, 5, 10.5)? " + c1.contains(new Circle2D(4, 5, 10.5)));
        System.out.println("c1 overlaps circle2? (3, 5, 2.3)" + c1.overlaps(new Circle2D(3, 5, 2.3)));
    }   
    
    private static void driverMyInteger() {
        System.out.println("\n------- MyInteger class driver -------\n");
        MyInteger n1 = new MyInteger(5);
        MyInteger n2 = new MyInteger(24);
        
        System.out.println("n1 is " + n1.getValue());
        System.out.println("n2 is " + n2.getValue());
        
        // Test the isEven(), isOdd(), and isPrime() methods
        System.out.println("n1 is even? " + n1.isEven());
        System.out.println("n1 is odd? " + n1.isOdd());
        System.out.println("n1 is prime? " + n1.isPrime());
        System.out.println("n2 is even? " + MyInteger.isEven(n2));
        System.out.println("n2 is odd? " + MyInteger.isOdd(n2));
        System.out.println("n2 is prime? " + MyInteger.isPrime(n2));
        
        // Test the static methods: isEven(int), isOdd(int), and isPrime(int) methods
        System.out.println("15 is even? " + MyInteger.isEven(15));
        System.out.println("15 is odd? " + MyInteger.isOdd(15));
        System.out.println("15 is prime? " + MyInteger.isPrime(15));

        
        // Test the static methods: isEven(MyInteger), isOdd(MyInteger), and isPrime(MyInteger) methods
        System.out.println("37 is even? " + MyInteger.isEven(new MyInteger(37)));
        System.out.println("37 is odd? " + MyInteger.isOdd(new MyInteger(37)));
        System.out.println("37 is prime? " + MyInteger.isPrime(new MyInteger(37)));


        // Test the equals(int) and equals(MyInteger) methods
        System.out.println("n1 is equal to 5? " + n1.equals(5));
        System.out.println("n1 is equal to n2? " + n1.equals(n2));
        System.out.println("n1 is equal to 24? " + n1.equals(new MyInteger(24)));

        char[] chars = {'3', '5', '3', '9'};
        System.out.println(MyInteger.parseInt(chars));
        System.out.println(MyInteger.parseInt("3539"));
    }
}
