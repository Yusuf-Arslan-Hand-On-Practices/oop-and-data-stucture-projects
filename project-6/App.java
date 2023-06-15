import java.util.Scanner;

public class App {

    public static void main(String[] args) {

        // Ask user to enter the number of students
        Scanner input = new Scanner(System.in);
        int counter = 0;
        
        System.out.print("\nEnter the number of students: ");
        int numberOfStudents = input.nextInt();
        
        // Create an array of students
        Student[] students = new Student[numberOfStudents];

        // Ask user to enter the students' information
        for (int i = 0; i < students.length; i++) {

            System.out.println("Student " + (i + 1));
            System.out.println("----------------------------\n");

            // Asking the user to enter the student's id. If the user enters -1, the loop is
            // terminated.
            System.out.print("Enter the student's id: ");
            int id = input.nextInt();
            if (id == -1) {
                System.out.println("Loop is terminated!\n");
                break;
            }            
            
            // Asking the user to enter the student's name. If the user enters a name that contains
            // nonletter characters, the user is asked to enter the name again.
            System.out.print("Enter the student's name: ");
            String name = input.next();
            while (!isCorrectName(name)) {
                System.out.print("Invalid name, please enter again: ");
                name = input.next();
            }

            // Asking the user to enter the student's last name. If the user enters a last name that contains
            // nonletter characters, the user is asked to enter the last name again.
            System.out.print("Enter the student's last name: ");
            String lastName = input.next();
            while (!isCorrectName(lastName)) {
                System.out.print("Invalid last name, please enter again: ");
                lastName = input.next();
            }
            
            // Asking the user to enter the student's score. If the user enters -1, the loop is
            // terminated.
            System.out.print("Enter the student's score: ");
            int score = input.nextInt();
            if (score == -1) {
                System.out.println("Loop is terminated!\n");
                break;
            }

            // Creating a new student object and assigning it to the students array.
            students[i] = new Student(id, name, lastName, score);
            counter++; // User can terminate loop by entering -1, so we need to keep track of the number of students.
            System.out.println("\n");
        }

        // Sort the students array by score, if scores are equal, sort by name, if names are equal, sort by last name.
        sortStudents(students, counter);
        
        // Print the students array - sorted.
        System.out.println("Students (sorted)");
        for (int i = 0; i < counter; i++) {
            System.out.println(students[i]);
        }
        
        Student[] duplicatedStudents = findDuplicatedStudents(students, counter);

        double mean = calculateMean(students, counter);
        double median = calculateMedian(students, counter);
        double standartDeviation = calculateStandartDeviation(students, counter, mean);

        System.out.println("\nStatistics");
        System.out.println("----------------------------\n");
        System.out.println("Mean: " + mean);
        System.out.println("Median: " + median);
        System.out.println("Standart deviation: " + standartDeviation);

        System.out.println("\nDuplicated students (Does not included to the calculation)");
        System.out.println("---------------------------------------------------------");
        for (int i = 0; i < duplicatedStudents.length; i++) {
            if (duplicatedStudents[i] == null) {
                break;
            }
            System.out.println(duplicatedStudents[i]);
        }

    }

    /**
     * It returns true if the string contains only letters, and false otherwise
     * 
     * @param name The name of the person
     */
    public static boolean isCorrectName(String name) {
        for (int i = 0; i < name.length(); i++) {
            if (!Character.isLetter(name.charAt(i))) {
                return false;
            }
        }
        return true;
    }

    /**
     * It sorts the students array by score, if scores are equal, sort by name, if names are equal, sort by last name.
     * 
     * @param students The array of students
     * @param counter The number of students
     */
    public static void sortStudents(Student[] students, int studentNum) {
        // Sorting the students array by score, if scores are equal, sort by name, if names are equal,
        // sort by last name by selection sort algorithm in descending order.
        for (int i = 0; i < studentNum - 1; i++) {
            int maxIndex = i;
            for (int j = i + 1; j < studentNum; j++) {
                if (students[j].compareTo(students[maxIndex]) > 0) {
                    maxIndex = j;
                }
            }
            if (maxIndex != i) {
                Student temp = students[i];
                students[i] = students[maxIndex];
                students[maxIndex] = temp;
            }
        }
        
    }

    /**
     * It takes an array of students and returns an array of duplicated students.
     * Sets the duplicated students to null.
     * 
     * @param students an array of Student objects
     * @param studentNum the number of students in the array
     * @return An array of students that are duplicated.
     */
    public static Student[] findDuplicatedStudents(Student[] students, int studentNum) {
        Student[] duplicatedStudents = new Student[studentNum];
        int counter = 0;
        for (int i = 0; i < studentNum; i++) {
            for (int j = i + 1; j < studentNum; j++) {
                if (students[i] != null && students[j] != null && students[i].equals(students[j])) {
                    duplicatedStudents[counter] = students[j];
                    counter++;
                    students[j] = null;
                }
            }
        }
        return duplicatedStudents;
    }

    /**
     * It calculates the mean of the scores of the students
     * 
     * @param students an array of Student objects
     * @param studentNum the number of students in the array
     * @return The mean of the scores of the students
     */
    public static double calculateMean(Student[] students, int studentNum) {
        double sum = 0;
        int counter = 0;
        for (int i = 0; i < studentNum; i++) {
            if (students[i] != null) {
                sum += students[i].getScore();
                counter++;
            }
        }

        if (counter == 0) {
            return 0;
        }
        return sum / counter;
    }

    /**
     * It calculates the median of the scores of the students
     * 
     * @param students an array of Student objects
     * @param studentNum the number of students in the array
     * @return The median of the scores of the students
     */
    public static double calculateMedian(Student[] students, int studentNum) {
        int counter = 0;

        for (int i = 0; i < studentNum; i++) {
            if (students[i] != null) {
                counter++;
            }
        }
        int[] scores = new int[counter];
        for (int i = 0; i < counter; i++) {
            if (students[i] != null) {
                scores[i] = students[i].getScore();
            }
        }
        if (counter == 0) {
            return 0;
        }
        if (counter % 2 == 0) {
            return (scores[counter / 2] + scores[counter / 2 - 1]) / 2.0;
        } else {
            return scores[counter / 2];
        }
    }

    /**
     * It calculates the standart deviation of the scores of the students
     * 
     * @param students an array of Student objects
     * @param studentNum the number of students in the array
     * @param mean the mean of the scores of the students
     * @return The standart deviation of the scores of the students
     */
    public static double calculateStandartDeviation(Student[] students, int studentNum, double mean) {
        double sum = 0;
        int counter = 0;
        for (int i = 0; i < studentNum; i++) {
            if (students[i] != null) {
                sum += Math.pow(students[i].getScore() - mean, 2);
                counter++;
            }
        }
        if (counter == 0) {
            return 0;
        }
        return Math.sqrt(sum / counter);
    }
}

