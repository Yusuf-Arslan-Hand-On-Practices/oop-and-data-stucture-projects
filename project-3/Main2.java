/**
 * @author Name Lastname
 * @id 123456789
 * 
 */

import java.util.Scanner;

public class Main2 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input;
        while (true) {
            System.out.println("Proje 1 Kullanici Menusu");
            System.out.println("1. Karakter dizini cizdir");
            System.out.println("2. Buyuk harfe cevir");
            System.out.println("3. Sifrele ve sifre coz");
            System.out.println("4. Harf ciz\n");
            System.out.print("Lutfen bir secim yapiniz: ");

            input = scanner.nextLine();
            if (input.equals("Dur") || input.equals("DUr") || input.equals("DuR") || 
                input.equals("dUR") || input.equals("dUr") || input.equals("duR") || 
                input.equals("dur") || input.equals("DUR")) {
                System.out.println("Programdan cikiliyor...");
                break;
            }
            
            // Menu items
            // 1 - Draw a character set based on the user's input
            if ("1".equals(input)) {
                System.out.print("Bir dizi karakter giriniz: ");
                input = scanner.nextLine();
                karakterDizisiCizdir(input);
            }
            // Convert every words' first letter to the uppercase
            else if ("2".equals(input)) {
                System.out.print("Cumle giriniz: ");
                input = scanner.nextLine();
                System.out.print("Cikti: ");
                System.out.println(buyukHarfeCevir(input));
            }
            // Encrypt or decrypt a user input based on the given instructions
            else if ("3".equals(input)) {
                int kaydirmaDegeri;

                System.out.print("Bir cumle giriniz: ");
                input = scanner.nextLine();
                System.out.print("Kaydirma degeri giriniz: ");
                kaydirmaDegeri = scanner.nextInt();
                scanner.nextLine();
                System.out.println("Sifrelenmis metin: ");
                System.out.println(sifreleCoz(input, kaydirmaDegeri));
                System.out.println();
            }
            // Print either X or Z by user input with given an odd size by user
            else if ("4".equals(input)) {
                int boyut = 0;
                input = "";
                while (!(input.equals("X") || input.equals("Z"))) {
                    System.out.print("Bir karakter giriniz: ");
                    input = scanner.nextLine();
                    if (!(input.equals("X") || input.equals("Z"))) {
                        System.out.println("Girilen karakter gecersiz");    
                    }
                }
                while (boyut % 2 != 1) {
                    System.out.print("Bir sayi giriniz: ");
                    boyut = scanner.nextInt();
                    scanner.nextLine();
                    if (boyut % 2 == 0) {
                        System.out.println("Gecerli degil");
                    }
                }
                harfCizdir(input, boyut);
            }
            // invalid entry
            else {
                System.out.println("Hatali secim yaptiniz!");
            }
        }
    }

    /**
     * The function takes a string as input and prints out the a sequence of characters
     * according to defined rules. 
     * 
     * @param input The string to be drawn.
     */
    public static void karakterDizisiCizdir(String input) {
        // digits represents the number of chars 
        // b represents the space
        // s represents the asterisk
        // n represents the new line
        // t represents the three spaces
        char c;

        for (int i = 0; i < input.length(); i++) {

            c = input.charAt(i);
            if (c >= '1' && c <= '9') {
                int digit = c - '0';
                
                c = input.charAt(++i);
                if (c == 'b') {
                    for (int j = 0; j < digit; j++) {
                        System.out.print(" ");
                    }
                } 
                else if (c == 's') {
                    for (int j = 0; j < digit; j++) {
                        System.out.print("*");
                    }
                } 
                else if (c == 'n') {
                    for (int j = 0; j < digit; j++) {
                        System.out.println();
                    }
                } 
                else if (c == 't') {
                    for (int j = 0; j < digit; j++) {
                        System.out.print("   ");
                    }
                }
            }
            else {
                if (c == 'b') {
                    System.out.print(" ");
                } 
                else if (c == 's') {
                    System.out.print("*");
                } 
                else if (c == 'n') {
                    System.out.println();
                }
                else if (c == 't') {
                    System.out.print("   ");
                }
            }
        }
        System.out.println();
    }

    /**
     * It takes a string as input and returns the the result of converting the first letter of each
     * word to uppercase
     * 
     * @param input The string to be converted.
     * @return The result of converting the first letter of each word to uppercase.
     */
    public static String buyukHarfeCevir(String input) {
        // It takes a string as input and returns the the result of converting the first
        // letter of each word to uppercase.
        StringBuilder sb = new StringBuilder();
        char c;
        for (int i = 0; i < input.length(); i++) {
            c = input.charAt(i);
            if (i == 0 || input.charAt(i - 1) == ' ') {
                if (c >= 'a' && c <= 'z') {
                    c -= 32;
                }
                sb.append(c);
            }
            else {
                sb.append(c);
            }
        }
        return sb.toString();
        
    }

    /**
     * It takes a string and an integer as input and returns the result of shifting the characters of
     * the string by the given integer
     * 
     * @param input The string to be encrypted or decrypted.
     * @param kaydirma_degeri the number of characters to shift
     * @return The result of shifting the characters of the string by the given integer.
     */
    public static String sifreleCoz(String input, int kaydirma_degeri) {
        // It takes a string and an integer as input and returns the result of shifting
        // the characters of the string by the given integer.
        StringBuilder sb = new StringBuilder();
        char c;
        // if c is space, do not shift
        
        if (kaydirma_degeri > 0)
        {
            for (int i = 0; i < input.length(); i++) {
                c = input.charAt(i);
                if (c == ' ') {
                    sb.append(c);
                }
                else {
                    // if c is a lowercase letter, then it should be converted to uppercase
                    if (c >= 'a' && c <= 'z') {
                        c = (char) (c - 32);
                    }

                    c = (char) (c + kaydirma_degeri);

                    // If c goes beyond 'Z', then it should be converted to 'A'
                    if (c > 'Z') {
                        c = (char) (c - 26);
                    }
                    sb.append(c);
                }
            }
        }
        else // decrypt
        {
            for (int i = 0; i < input.length(); i++) {
                c = input.charAt(i);
                if (c == ' ') {
                    sb.append(c);
                }
                else {
                    // convert to lowercase
                    c = (char)(c + 32);

                    c = (char)(c + kaydirma_degeri);
                    
                    // if char goes beyond 'a', then it should be converted to 'z'
                    if (c < 'a') {
                        c = (char)(c + 26);
                    }

                    sb.append(c);
                }
            }
            // Convert first letter to uppercase
            c = sb.charAt(0);
            c = (char)(c - 32);
            sb.setCharAt(0, c);
        }
        return sb.toString();
    }
    
    /**
     * It prints the letter X or Z with the given size with asterisks
     * 
     * @param karakter The letter to be drawn.
     * @param boyut size of the letter
     */
    public static void harfCizdir(String karakter, int boyut) {
        // draw the letter X with the given size with asterisks
        // If karakter is Z, then draw the letter Z with the given size with asterisks
        if ("Z".equals(karakter)) {
            // draw the upper part of the letter X
            for (int i = 0; i < boyut; i++) {
                System.out.print("*");
            }
            System.out.println();
            for (int i = 0; i < boyut - 2; i++) {
                for (int j = 0; j < boyut - 1 - i; j++) {
                    System.out.print(" ");
                }
                System.out.println("*");
            }
            // draw the lower part of the letter Z
            for (int i = 0; i < boyut; i++) {
                System.out.print("*");
            }
        }
        if ("X".equals(karakter)) {
            // draw the upper part of the letter X
            char[] temp = new char[boyut];

            for (int i = 0; i < boyut; i++) {
                temp[i] = '*';
                temp[boyut - 1 - i] = '*';
                for (int j = 0; j < boyut; j++) {
                    if (!(j == i || j == (boyut - 1 - i))) {
                        temp[j] = ' ';
                    }
                }
                for (int j = 0; j < boyut; j++) {
                    System.out.print(temp[j]);
                }
                System.out.println();
            }
        }
        System.out.println();
    }
}
