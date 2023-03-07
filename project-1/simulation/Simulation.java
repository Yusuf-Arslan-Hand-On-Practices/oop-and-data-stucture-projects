
package simulation;

import java.util.ArrayList;
import java.util.Random;

public class Simulation {
    // Data fields
    private int[][] performance;
    private ArrayList<Training> trainings;
    public static final int THRESHOLD = 65;
    
    // a --> number of interns, b --> number of trainings
    public Simulation(int a, int b) {
        this.performance = new int[a][b];
        this.trainings = new ArrayList<Training>();

    }

    // This function adds a training to the list of trainings
    public void appendTraining(Training trn) {
        this.trainings.add(trn);
    }

    // Simulate the performance of interns in trainings with random numbers between 10 and 100
    public void simulateTable() {
        Random generator = new Random(1500);

        for (int i = 0; i < this.performance.length; i++) {
            for (int j = 0; j < this.performance[i].length; j++) {
                this.performance[i][j] = generator.nextInt(90) + 10;
            }
        }
        displaySimulatedTable();
    }

   
    // Printing the table of the intern training.
    private void displaySimulatedTable() {
        System.out.println("------------------------- Intern Training Table -------------------------\n");
        // Print name of the trainings
        System.out.format("%-15s", "Names");
        for (Training trn : this.trainings) {
            System.out.format("%-7s", trn.getTitle());
        }
        System.out.println();
        for (int i = 0; i < this.performance.length; i++) {
            System.out.format("%-14s", trainings.get(0).getInternList().get(i));
            System.out.print("|  ");
            for (int j = 0; j < this.performance[i].length; j++) {
                System.out.format("%-4d", this.performance[i][j]);
                System.out.print("|  ");
            }
            System.out.println();
        }
    }

    // Print the average performance of interns in trainings
    public void showInternPerformance() {
        System.out.println("------------------------- Interns Performance -------------------------\n");

        for (int i = 0; i < this.performance.length; i++) {
            int sum = 0;
            for (int j = 0; j < this.performance[i].length; j++) {
                sum += this.performance[i][j];
            }
            System.out.println(trainings.get(0).getInternList().get(i) + " has the Average score of " 
                               + sum / (double) this.performance[i].length);
        }
    }

    // Print the level of each training
    public void showTrainingLevel() {
        System.out.println("------------------------- Training Level -------------------------\n");

        for (int i = 0; i < this.performance[0].length; i++) {
            int sum = 0;
            for (int j = 0; j < this.performance.length; j++) {
                sum += this.performance[j][i];
            }
            double avg = sum / (double) this.performance.length;
            System.out.print("The average of " + trainings.get(i).getTitle() + " is ");
            System.out.format("%.1f", avg);
            System.out.println(", then, its level is " + (avg > THRESHOLD ? "above" : "below") + " the threshold.");
        }
    }

    // Find max training performance and print it
    public void findMax() {
        System.out.println("------------------------- Max Training Performance -------------------------\n");

        int max = 0;
        int maxIntern = 0;
        int maxTraining = 0;
        for (int i = 0; i < this.performance.length; i++) {
            for (int j = 0; j < this.performance[i].length; j++) {
                if (this.performance[i][j] > max) {
                    max = this.performance[i][j];
                    maxIntern = i;
                    maxTraining = j;
                }
            }
        }
        System.out.println("Max Performance: " + max);
        System.out.println("Intern: " + trainings.get(0).getInternList().get(maxIntern) + 
                           ", ID: " + trainings.get(0).getInterns().get(maxIntern).getId());
        
    }
    
    public void updateTrainingPerformance(String trainingName, String internName, int newPerformance) {
        int internIndex = 0;
        int trainingIndex = 0;
        for (int i = 0; i < this.performance.length; i++) {
            if (trainings.get(0).getInternList().get(i).equals(internName)) {
                internIndex = i;
                break;
            }
        }
        for (int i = 0; i < this.performance[0].length; i++) {
            if (trainings.get(i).getTitle().equals(trainingName)) {
                trainingIndex = i;
                break;
            }
        }
        this.performance[internIndex][trainingIndex] = newPerformance;
    }
}
