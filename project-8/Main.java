// Random
// This program generates a random number between 1 and 10.

import java.util.Random;

public class Main {
    public static void main(String[] args) {

        // For generating random numbers
        Random random = new Random();

        // To keep random numbers between -10 and 42
        int[][][] myArray = new int[3][3][3];
        int[] myArray1d = new int[27];

        // Student ID is odd
        String studentId = "63170017";
        int x = 0;
        int y = 1;
        int z = 2;

        int A = 7;
        
        // Fill the array with random numbers between -10 to 42
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    myArray[i][j][k] = random.nextInt(53) - 10;
                }
            }
        }
        
        // Print the array
        System.out.println("3D array which is randomly generated:\n");

        for (int i = 0; i < myArray.length; i++) {
            for (int j = 0; j < myArray[i].length; j++) {
                for (int k = 0; k < myArray[i][j].length; k++) {
                    System.out.print(myArray[i][j][k] + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
        System.out.println();

        
        // Fill the 1D array with the values from the 3D array
        int counter = 0;
        for (int i = 0; i < myArray.length; i++) {
            for (int j = 0; j < myArray[i].length; j++) {
                for (int k = 0; k < myArray[i][j].length; k++) {
                    myArray1d[counter] = myArray[i][j][k];
                    counter++;
                }
            }
        }
        int value = myArray[x][y][z];
        System.out.println("Element in myArray[0][1][2] for student ID " + studentId + ": " + value);
        System.out.println("The number of A: " + A);
        
        int key = value - A;
        System.out.println("The result of subtraction: " + key);

        // Print the 1D array
        System.out.println("\nElements of 1D array:");
        for (int i = 0; i < myArray1d.length; i++) {
            System.out.print(myArray1d[i] + " ");
        }
        System.out.println();

        // Sort the 1D array
        selectionSort(myArray1d);

        // Print the sorted 1D array
        System.out.println("\nSorted array:");
        for (int i = 0; i < myArray1d.length; i++) {
            System.out.print(myArray1d[i] + " ");
        }

        int result = binarySearch(myArray1d, key);
        if (result == -1) {
            System.out.println("\n\nKey to be searched=" + key);
            System.out.println("Element is not found in the array!");
        } else {
            System.out.println("\n\nKey to be searched=" + key);
            System.out.println("Element is found at index: " + result);
        }
    }

    // Sort the array with selection sort algorithm
    public static void selectionSort(int[] myArray) {
        for (int i = 0; i < myArray.length - 1; i++) {
            int min = i;
            for (int j = i + 1; j < myArray.length; j++) {
                if (myArray[j] < myArray[min]) {
                    min = j;
                }
            }
            int temp = myArray[i];
            myArray[i] = myArray[min];
            myArray[min] = temp;
        }
    }

    // Binary search, returns the index of the element if found, otherwise returns -1
    public static int binarySearch(int[] myArray, int key) {
        int low = 0;
        int high = myArray.length - 1;
        while (high >= low) {
            int mid = (low + high) / 2;
            if (key < myArray[mid]) {
                high = mid - 1;
            } else if (key == myArray[mid]) {
                return mid;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
}
