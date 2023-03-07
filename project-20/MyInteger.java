// MyInteger class
public class MyInteger {

    // Data field
    private int value;
    
    // Constructor
    public MyInteger(int value) {
        this.value = value;
    }

    // Getter
    public int getValue() {
        return value;
    }

    // Methods
    // return true if the value in this object is even
    public boolean isEven() {
        return value % 2 == 0;
    }

    // return true if the value in this object is odd
    public boolean isOdd() {
        return value % 2 != 0;
    }

    // return true if the value in this object is prime
    public boolean isPrime() {
        // Checking if the value is prime.
        for (int i = 2; i < value / 2 + 1; i++) {
            if (value % i == 0) {
                return false;
            }
        }
        return true;
    }

    // return true if the specified value is even
    public static boolean isEven(int value) {
        return value % 2 == 0;
    }

    // return true if the specified value is odd
    public static boolean isOdd(int value) {
        return value % 2 != 0;
    }

    // return true if the specified value is prime
    public static boolean isPrime(int value) {
        for (int i = 2; i < value; i++) {
            if (value % i == 0) {
                return false;
            }
        }
        return true;
    }

    // return true if the specified object is even
    public static boolean isEven(MyInteger myInteger) {
        return myInteger.isEven();
    }

    // return true if the specified object is odd
    public static boolean isOdd(MyInteger myInteger) {
        return myInteger.isOdd();
    }

    // return true if the specified object is prime
    public static boolean isPrime(MyInteger myInteger) {
        return myInteger.isPrime();
    }

    // return true if the value in this object is equal to the specified value
    public boolean equals(int value) {
        return this.value == value;
    }

    // return true if the value in this object is equal to the specified object
    public boolean equals(MyInteger myInteger) {
        return myInteger.value == value;
    }

    // Convert an array of numeric characters to an int value
    public static int parseInt(char[] chars) {
        int result = 0;
        for (int i = 0; i < chars.length; i++) {
            result = result * 10 + (chars[i] - '0');
        }
        return result;
    }

    // Convert a string into an int value
    public static int parseInt(String string) {
        int result = 0;
        for (int i = 0; i < string.length(); i++) {
            result = result * 10 + (string.charAt(i) - '0');
        }
        return result;
    }
}
