// Import Calendar class

import java.util.Calendar;
import java.util.Scanner;
import java.text.SimpleDateFormat;

// SpaceCrafts class implementation
public class SpaceCrafts {
    // Private variables
    private int userSelection;
    private double studentID_lastDigit;         // Student ID
    private String[] planetName;                // Array of planet names
    private String[] spaceCraftName;            // Array of spacecraft names
    private String[] pilotName;                 // Array of pilot names 
    private String[] timeToReady;               // Array of time to ready

    // Default constructor
    public SpaceCrafts() {
        userSelection = 0;
        studentID_lastDigit = 7;            // Student ID is 63170017
        planetName = new String[5];         // 5 planets
        spaceCraftName = new String[8];     // 8 spacecrafts
        pilotName = new String[8];          // 8 pilots
        timeToReady = new String[8];        // 8 time to ready for each spacecraft

        // Planet names -- To make program more concise, I used duplicated planet names
        planetName[0] = "Jupiter";
        planetName[1] = "Saturn";
        planetName[2] = "Uranus";
        planetName[3] = "Neptune";
        planetName[4] = "Mars";

        // Spacecraft names
        spaceCraftName[0] = "Galileo";
        spaceCraftName[1] = "Voyager 1";
        spaceCraftName[2] = "Huygens";
        spaceCraftName[3] = "Cassini";
        spaceCraftName[4] = "Voyager 2";
        spaceCraftName[5] = "Voyager 3";
        spaceCraftName[6] = "Perserverance";
        spaceCraftName[7] = "Spirit";

        // Pilot names
        pilotName[0] = "Pilot 1";
        pilotName[1] = "Pilot 2";
        pilotName[2] = "Pilot 3";
        pilotName[3] = "Pilot 4";
        pilotName[4] = "Pilot 5";
        pilotName[5] = "Pilot 6";
        pilotName[6] = "Pilot 7";
        pilotName[7] = "Pilot 8";

        // Time to ready in days
        timeToReady[0] = "0";       
        timeToReady[1] = "98";      
        timeToReady[2] = "13";
        timeToReady[3] = "856";
        timeToReady[4] = "1";
        timeToReady[5] = "0";
        timeToReady[6] = "0";
        timeToReady[7] = "123";

        // Print the table
        System.out.println("\n\nPlanet\t\tSpacecraft\t\tPilot\t\tTime to Ready\t\tCoeficients");
        System.out.println("------------------------------------------------------------------------------------------");
        for (int i = 0; i < 8; i++) 
        {
            // Jupiter
            if (i == 0 || i == 1)
            {
                System.out.format("%-16s", planetName[0]);
            }
            // Saturn
            else if (i == 2 || i == 3)
            {
                System.out.format("%-16s", planetName[1]);
            }
            // Uranus
            else if (i == 4)
            {
                System.out.format("%-16s", planetName[2]);
            }
            // Neptune
            else if (i == 5)
            {
                System.out.format("%-16s", planetName[3]);
            }
            // Mars
            else
            {
                System.out.format("%-16s", planetName[4]);
            }

            System.out.format("%-24s", spaceCraftName[i]);
            System.out.format("%-16s", pilotName[i]);
            System.out.format("%-24s", "0".equals(timeToReady[i]) ? "Ready" : timeToReady[i] + " days");

            if (i == 0 || i == 1)
            {
                System.out.println("X*3");
            }
            else if (i == 2 || i == 3)
            {
                System.out.println("(X*9)/5");
            }
            else if (i == 4)
            {
                System.out.println("X*10/71");
            }
            else if (i == 5)
            {
                System.out.println("X+2");
            }
            else
            {
                System.out.println("X/64");
            }
        }
    }

    // Parameterized constructor
    public SpaceCrafts(String[] planetName, String[] spaceCraftName, String[] pilotName, String[] timeToReady,
                       double studentID_lastDigit, int userSelection) {
        this.planetName = planetName;
        this.spaceCraftName = spaceCraftName;
        this.pilotName = pilotName;
        this.timeToReady = timeToReady;
        this.studentID_lastDigit = studentID_lastDigit;
        this.userSelection = userSelection;
    }
    
    /**
     * The function takes the user's selection and displays the information of the planet and the
     * spacecrafts that are available for launching
     */
    public void userOptionProcess()
    {
        Scanner input = new Scanner(System.in);
        double coeficient = 0;

        while (true)
        {
            // Add a new line
            System.out.println();

            // Display the menu
            options();

            userSelection = input.nextInt();
            if (userSelection == 6)
            {
                System.out.println("Thank you for using the program!");
                break;
            }

            if (userSelection == 1)
            {
                // Jupiter
                // Galielo
                System.out.println("#################### JUPITER ####################");
                System.out.println(planetName[0] + "  |  " + spaceCraftName[0] + "  |  " + 
                                   pilotName[0]  + "  |  " + "Ready" + "  |  " + studentID_lastDigit * 3);
                // Voyager 1
                System.out.println(planetName[0] + "  |  " + spaceCraftName[1] + "  |  " + 
                                   pilotName[1]  + "  |  " + timeToReady[1]    + " days" + "  |  " + 
                                   studentID_lastDigit * 3);
                System.out.println();
                
                // Galileo is ready for launching to Jupiter, pass the index of jupiter and galileo
                writePossibleShuttles(0, 0, timeToReady);
            }
            else if (userSelection == 2)
            {
                // Saturn
                // Huygens
                System.out.println("#################### SATURN ####################");
                System.out.println(planetName[1] + "  |  " + spaceCraftName[2] + "  |  " + 
                                   pilotName[2]  + "  |  " + timeToReady[2]    + " days" + "  |  " + 
                                   (studentID_lastDigit * 9) / 5);

                // Cassini
                System.out.println(planetName[1] + "  |  " + spaceCraftName[3] + "  |  " + 
                                   pilotName[3]  + "  |  " + timeToReady[3]    + " days" + "  |  " + 
                                   (studentID_lastDigit * 9) / 5);
                System.out.println();
                
                // Huygens is more close to launch to Saturn, pass the index of saturn and huygens
                writePossibleShuttles(1, 2, timeToReady);
            }
            else if (userSelection == 3)
            {
                // Uranus
                // Voyager 2
                System.out.println("#################### URANUS ####################");
                System.out.println(planetName[2] + "  |  " + spaceCraftName[4] + "  |  " + 
                                   pilotName[4] +  "  |  " + timeToReady[4]    + " days" + "  |  " + 
                                   (studentID_lastDigit * 10) / 71);
                System.out.println();

                // Pass the index of uranus and voyager 2
                writePossibleShuttles(2, 4, timeToReady);
            }
            else if (userSelection == 4)
            {
                // Neptune
                // Voyager 3
                System.out.println("#################### NEPTUNE ####################");
                System.out.println(planetName[3] + "  |  "  + spaceCraftName[5] + "  |  " + 
                                   pilotName[5]  +  "  |  " + " Ready"          + "  |  " + 
                                   studentID_lastDigit + 2);
                System.out.println();
            
                // Pass the index of neptune and voyager 3
                writePossibleShuttles(3, 5, timeToReady);
            }
            else if (userSelection == 5)
            {
                // Mars
                // Perseverance
                System.out.println("#################### MARS ####################");
                System.out.println(planetName[4] + "  |  " + spaceCraftName[6] + "  |  " + 
                                   pilotName[6]  + "  |  " + " Ready"          + "  |  " + 
                                   studentID_lastDigit / 64);
                // Spirit
                System.out.println(planetName[4] + "  |  " + spaceCraftName[7] + "  |  " + 
                                   pilotName[7]  + "  |  " + timeToReady[7]    + " days" + "  |  " + 
                                   studentID_lastDigit / 64);
                System.out.println();

                // Perseverance is ready for launching to Mars, pass the index of mars and perseverance
                writePossibleShuttles(4, 6, timeToReady);
            }
            else
            {
                System.out.println("Invalid option!");
            }
        }
    }

    /**
     * This function is used to display the list of available spacecrafts for the user to choose from
     */
    public void writePossibleShuttles(int planet, int spaceCraft, String[] timeToReady)
    {
        System.out.println("############## List of Available Spacecrafts ##############");
        if ("0".equals(timeToReady[spaceCraft]))
        {
            System.out.println(spaceCraftName[spaceCraft] + " is ready for launching to " + planetName[planet]);
        }
        else
        {
            System.out.println("Nearest Expected completion time: ");
            expectedLaunchDateCalculation(Integer.parseInt(timeToReady[spaceCraft]));
            System.out.println();
        }
    }

    /**
     * This function takes in a number of days and adds it to the current date to calculate the
     * expected launch date
     */
    public void expectedLaunchDateCalculation(int day)
    {
        // Get current date
        Calendar calendar = Calendar.getInstance();
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
        
        // Add days to current date
        calendar.add(Calendar.DAY_OF_YEAR, day);
        String expectedLaunchDate = dateFormat.format(calendar.getTime());

        // Finds the expected launch date and prints it
        System.out.print(expectedLaunchDate);
    }
    
    /**
     * This function is used to display the list of available planets for the user to choose from
     */
    public void options()
    {
        System.out.println("1- Jupiter");
        System.out.println("2- Saturn");
        System.out.println("3- Uranus");
        System.out.println("4- Neptune");
        System.out.println("5- Mars\n");
        System.out.println("6- Exit\n");

        System.out.print("Please select an option for desired planet: ");        
    }

    public static void main(String[] args) {
        SpaceCrafts spaceCrafts = new SpaceCrafts();
        spaceCrafts.userOptionProcess();
    }

}

