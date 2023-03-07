import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/*
    The bin packing problem is to pack the objects of various weights into containers. Assume that each 
    container can hold a maximum of 10 pounds. The program uses an algorithm that places an object 
    with the largest weight into the first bin in which it would fit. Your program should prompt the user 
    to enter the total number of objects and the weight of each object. The program displays the total 
    number of containers needed to pack the objects and the contents of each container.
*/
public class BinPacking {
    
    public static class Time {
        private int hour;
        private int minute;
        private int day;
        private int month;
        private int year;

        public Time() {
            // create random Time
            hour = (int) (Math.random() * 24);
            minute = (int) (Math.random() * 60);
        }

        @Override
        public String toString() {
            return String.format("%02d:%02d", hour, minute);
        }

        public boolean before(Time other) {
            if (hour < other.hour) {
                return true;
            } else if (hour == other.hour) {
                if (minute < other.minute) {
                    return true;
                }
            }
            return false;
        }

        public int compareTo(Time other) {
            if (before(other)) {
                return -1;
            } else {
                return 0;
            }
        }
    }

    public static class Flight {
        private Time departureTime;
        private double weight;

        public Flight(double weight) {
            // Randomly generated time as departure time
            this.departureTime = new Time();
            this.weight = weight;
        }

        @Override
        public String toString() {
            return String.format("Time: %s %nWeight: %.2f", departureTime, weight);
        }

        // Comparator for sorting the list by Time
        public static Comparator<Flight> TimeComparator = new Comparator<Flight>() {
            public int compare(Flight f1, Flight f2) {
                return f1.departureTime.compareTo(f2.departureTime);
            }
        };

        double getWeight() {
            return weight;
        }
    }

    public static void main(String[] args) {
        // Scanner for user input
        Scanner scanner = new Scanner(System.in);
        List<Flight> flights = new ArrayList<Flight>();

        // Maximum weight of a container
        double containerSize = 10;

        System.out.println("Enter the number of objects: ");
        int numObjects = scanner.nextInt();
        
        // Read weights of objects
        System.out.println("Enter the weights of the objects: ");
        for (int i = 0; i < numObjects; i++) {
            flights.add(new Flight(scanner.nextDouble()));
        }

        // Sort the flights by departure time
        flights.sort(Flight.TimeComparator);

        // Print the flights
        System.out.println("\nThe flights before packing are (sorted by departure time):\n");
        for (Flight flight : flights) {
            System.out.println(flight);
            System.out.println();
        }
        System.out.println("A constructor that create: " + numObjects);
        
        ArrayList<ArrayList<Double>> containers = new ArrayList<ArrayList<Double>>();
        while (!flights.isEmpty())
        {
            ArrayList<Double> container = new ArrayList<Double>();
            double max = getMaximumWeight(flights, containerSize);
            container.add(max);
            // If there is a flight that can fit in the container, add it to the container
            while (true) {
                double currenWeight = 0;
                for (int i = 0; i < container.size(); i++) {
                    currenWeight += container.get(i);
                }
                max = getMaximumWeight(flights, containerSize - currenWeight);
                if (max == -1)
                    break;
                container.add(max);
            }
            containers.add(container);
        }

        // Print the containers
        System.out.println("\nThe containers are: ");
        for (int i = 0; i < containers.size(); i++) {
            System.out.println("Container " + i + 1 + " contains objects with weight " + containers.get(i));
        }
    }

    private static double getMaximumWeight(List<Flight> flights, double maxWeight) {
        // If there are no flights, return -1
        if (flights.isEmpty() || maxWeight <= 0)
            return -1;
    
        // Return the maximum weight of the flights that can fit in a container
        int index = -1;
        double max = -1;

        for (int i = 0; i < flights.size(); i++) {
            if (flights.get(i).getWeight() <= maxWeight) {
                if (flights.get(i).getWeight() > max) {
                    max = flights.get(i).getWeight();
                    index = i;
                }
            }
        }
        if (index == -1)
            return -1;
        // Remove the flight from the list
        flights.remove(index);
        return max;
    }

}
