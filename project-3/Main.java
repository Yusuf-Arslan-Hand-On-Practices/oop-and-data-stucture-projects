/**
 * @author Name Lastname
 * @id 123456789
 * 
 */

import java.util.Scanner;

class Main {
    // The scanner object is used to read input from the console
    public static final Scanner scanner = new Scanner(System.in);

    // Array of strings to store the strings that each of them terminates the program
    protected static final String[] stop = {"Dur", "DUr", "DUR", "dUR", "duR", "dUr", "DuR", "dur"};
    
    // The menu
    public static final String MENU =   "Proje 1 Kullanıcı Menüsü\n" +
                                        "1. Karakter dizisini çizdir\n" +
                                        "2. Büyük harfe çevir\n" +
                                        "3. Sifrele ve sifre çöz\n" +
                                        "4. Harf çizdir\n";
    /**
     * The main method
     * It contains a menu that allows the user to choose between 4 options
     * 
     * @param args The command line arguments (not used)
     */
    public static void main(String[] args) {
        // ask for user a string
        String input;
        int kaydirma_degeri;
        int boyut;

        while (true) {
            System.out.print(MENU);
            System.out.print("Lütfen bir seçim yapınız: ");
            input = scanner.nextLine();
            // Check if the string is equal to "Dur" or "DUr" or "DUR" or "dUR" or "duR" or "dUr" or "DuR" or "dur"
            if (isStop(input)) {
                break;
            }
            // User Menu
            switch (input) {
                // 1. Karakter dizisini çizdir
                case "1":
                    System.out.print("Bir dizi karakter giriniz: ");
                    input = scanner.nextLine();
                    karakterDizisiCizdir(input);
                    break;
                // 2. Büyük harfe çevir
                case "2":
                    System.out.print("Cümle Giriniz: ");
                    input = scanner.nextLine();
                    System.out.print("Çıktı: ");
                    System.out.println(buyukHarfeCevir(input));
                    System.out.println();
                    break;
                // 3. Sifrele ve çöz
                case "3":
                    System.out.print("Bir cümle giriniz: ");
                    input = scanner.nextLine();

                    System.out.print("Kaydırma değeri giriniz: ");
                    kaydirma_degeri = scanner.nextInt();
                    scanner.nextLine();

                    if ((kaydirma_degeri >= 1 && kaydirma_degeri <= 25) || 
                        (kaydirma_degeri >= -25 && kaydirma_degeri <= -1)) {
                        System.out.println("Şifrelenmiş metin: " + sifreleCoz(input, kaydirma_degeri));
                    } 
                    else {
                        System.out.println("Kaydırma değeri 1 ile 25 arasında olmalıdır.\n");
                    }
                    System.out.println();
                    break;
                // 4. Harf çizdir
                case "4":
                    while (true) {
                        System.out.println("Bir karakter giriniz: ");
                        input = scanner.nextLine();
                        if (input.equals("X") || input.equals("x") ||
                            input.equals("Z") || input.equals("z")) {
                            break;
                        }
                        else {
                            System.out.println("Girilen karakter gecersiz\n");
                        }
                    }                    
                    // Ask user for a odd number until the user enters a valid number
                    while (true) {
                        System.out.print("Boyut değeri giriniz: ");
                        boyut = scanner.nextInt();
                        scanner.nextLine();
                        if (boyut % 2 == 1) {
                            break;
                        }
                        else {
                            System.out.println("Geçerli değil\n");
                        }
                    }
                    if (input.equals("X") || input.equals("x")) {
                        harfCizdir("X", boyut);
                    }
                    else {
                        harfCizdir("Z", boyut);
                    };
                    break;
                default:
                    System.out.println("\nHatalı seçim yaptınız! Tekrar Deneyiniz.\n");
            }
        }
    }
    
    /**
     * The function takes a string as input and prints out the corresponding characters.
     * 
     * @param input a string that represents the characters to be printed
     */
    public static void karakterDizisiCizdir(String input) {
        /* 
         * char b for an empty space
         * char s for a star
         * char n for a new line
         * char t for '   '
         */
        char next;
        char c;
        String print;

        for (int i = 0; i < input.length(); i++) {
            next = input.charAt(i);
            // If the next character is a number, then look at the
            // next character. Then print the corresponding number 
            // of characters

            if (next >= '1' && next <= '9') {
                c = input.charAt(i + 1);
                if (c == 'b') {
                    print = " ";
                } 
                else if (c == 's') {
                    print = "*";
                }
                else if (c == 't'){
                    print = "   ";
                } 
                else {
                    print = "\n";
                } 

                for (int j = 0; j < next - '0'; j++) {
                    System.out.print(print);
                }

                i++;
            }
            else {
                if (next == 'b') {
                    print = " ";
                } 
                else if (next == 's') {
                    print = "*";
                }
                else if (next == 't'){
                    print = "   ";
                } 
                else {
                    print = "\n";
                }
                System.out.print(print);
            }
        }
        System.out.println("\n");
    }

    /**
     * It takes a string as input and prints the string with the first letter of each word capitalized
     * 
     * @param input The string to be capitalized.
     */
    public static String buyukHarfeCevir(String input) {
        String result = "";
        // Transform the each words first character to uppercase
        boolean isWord = true;
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (isWord) {
                if (c >= 'a' && c <= 'z') {
                    c -= 32;
                }
                result += c;
                isWord = false;
            }
            else {
                result += c;
                if (c == ' ' || c == '\n') {
                    isWord = true;
                }
            }
        }
        return result;
    }

    /**
     * It takes a string and a number as input, and it prints the encrypted or decrypted version of the
     * string
     * 
     * @param input The string that will be encrypted or decrypted.
     * @param kaydirma_degeri The number of characters to shift the alphabet by.
     */
    public static String sifreleCoz(String input, int kaydirma_degeri) {
        String result = "";
        char next;
        if (kaydirma_degeri > 0) {   
            for (int i = 0; i < input.length(); i++) {
                next = input.charAt(i);
                // if the character is a lowercase letter, capitalize it
                if (next >= 'a' && next <= 'z') {
                    next -= 32;
                }
                // If char is a ' ', then print ' '
                if (next == ' ') {
                    result += " ";
                }
                // else, shift the character by the kaydirma_degeri
                else {
                    next += kaydirma_degeri;
                    // If the character is greater than 'Z', then subtract 26
                    if (next > 'Z') {
                        next -= 26;
                    }
                    result += next;
                }
            }
        }
        else {
            // If the kaydirma_degeri is negative, then print the resolved 
            // characters with lower case but the first letter
            for (int i = 0; i < input.length(); i++) {
                next = input.charAt(i);
                if (next == ' ') {
                    result += " ";
                }
                else {
                    next += kaydirma_degeri;
                    if (next < 'A') {
                        next += 26;
                    }

                    if (i == 0) {
                        result += next;
                    }
                    else {
                        result += (char) (next + 32);
                    }
                }
            }
        }
        return result;
    }

    /**
     * It prints an X or a Z depending on the input, with asterisks
     * 
     * @param input The letter to be drawn.
     * @param boyut The size of the letter.
     */
    public static void harfCizdir(String karakter, int boyut) {

        // If karakter is X, then print X pattern with asterisks
        /**
         *       *     *
         *        *   *
         *         * *
         *          *
         *         * *
         *        *   *
         *       *     *
         */     
        // Gap between the asterisks in first and last line
        int k = boyut - 2;    
        if (karakter.equals("X")) {
            // Draw above half of the X
            for (int i = 0; i < boyut / 2; i++) {
                
                for (int j = 0; j < boyut - k - i + 1; j++) {
                    System.out.print(" ");
                }
                System.out.print("*");
                for (int j = 0; j < k; j++) {
                    System.out.print(" ");
                }
                System.out.println("*");
                k -= 2;
            }
            
            // Middle asterisk of X
            for (int j = 0; j < boyut/2 - k + 2; j++) {
                System.out.print(" ");
            }
            System.out.println("*");

            // Draw below half of the X
            k = 1;
            for (int i = boyut/2 - 1; i >= 0; i--) {
                for (int j = 0; j < boyut - k - i + 1; j++) {
                    System.out.print(" ");
                }
                System.out.print("*");
                for (int j = 0; j < k; j++) {
                    System.out.print(" ");
                }
                System.out.println("*");
                k += 2;

            }
        }
        else {
            // Draw the letter 'Z' with asterisks
            /**
             * *********
             *        *
             *       *
             *      *
             *     *
             *    *
             *   *
             *  *
             * *********
             */
            System.out.print(" ");
            for (int i = 0; i < boyut - 1; i++) {
                System.out.print("*");
            }
            System.out.println();
            for (int i = 0; i < boyut - 2; i++) {
                for (int j = boyut - i - 1; j > 1; j--) {
                    System.out.print(" ");
                }
                System.out.println("*");
            }
            for (int i = 0; i < boyut - 1; i++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }

    /**
     * The function takes a string as input and returns true if the string is a stop word, and false
     * otherwise
     * 
     * @param input the word to be checked
     * @return The method isStop() is returning a boolean value.
     */
    public static boolean isStop(String input) {
        for (String s : stop) {
            if (input.equals(s)) {
                return true;
            }
        }
        return false;
    }
}