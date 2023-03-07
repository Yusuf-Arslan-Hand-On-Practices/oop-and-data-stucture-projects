import java.util.ArrayList;
import java.util.Scanner;

public class Split {
    // This method splits a string into an array of strings using the delimiters.
    public static ArrayList<String> split(String s, String delimiters) {
        ArrayList<String> result = new ArrayList<String>();
        StringBuilder sb = new StringBuilder();
        // Iterate through the string.
        for (int i = 0; i < s.length(); i++) {
            // If the character is not a delimiter, add it to the StringBuilder.
            if (delimiters.indexOf(s.charAt(i)) == -1) {
                sb.append(s.charAt(i));
            }
            // If the character is a delimiter, add the StringBuilder to the result. 
            else {
                if (sb.length() > 0) {
                    result.add(sb.toString());
                    sb = new StringBuilder();
                }
            }
        }
        // Add the last StringBuilder to the result.
        if (sb.length() > 0) {
            result.add(sb.toString());
        }

        return result;
    }

    // Driver method.
    public static void main(String[] args) {
        String s;
        String delimiters;

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        s = scanner.nextLine();
        System.out.print("Enter delimiters: ");
        delimiters = scanner.nextLine();

        ArrayList<String> result = split(s, delimiters);
        System.out.println("result is: " + result);
    }

}
