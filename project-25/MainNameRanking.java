import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class MainNameRanking {
    protected static final String[] fileNames = {
        "namefiles/babynameranking2001.txt",
        "namefiles/babynameranking2002.txt",
        "namefiles/babynameranking2003.txt",
        "namefiles/babynameranking2004.txt",
        "namefiles/babynameranking2005.txt",
        "namefiles/babynameranking2006.txt",
        "namefiles/babynameranking2007.txt",
        "namefiles/babynameranking2008.txt",
        "namefiles/babynameranking2009.txt",
        "namefiles/babynameranking2010.txt",
        "namefiles/babynameranking2011.txt",
        "namefiles/babynameranking2012.txt",
        "namefiles/babynameranking2013.txt",
        "namefiles/babynameranking2014.txt",
        "namefiles/babynameranking2015.txt",
        "namefiles/babynameranking2016.txt",
        "namefiles/babynameranking2017.txt",
        "namefiles/babynameranking2018.txt",
        "namefiles/babynameranking2019.txt",
        "namefiles/babynameranking2020.txt",
        "namefiles/babynameranking2021.txt"
    };

    protected static class Info {
        public String name;
        public int rank;

        public Info(String name, int rank) {
            this.name = name;
            this.rank = rank;
        }

        public String toString() {
            return name + " " + rank;
        }
    }

    public static void main(String[] args) throws Exception {
        ArrayList<ArrayList<Info>> maleNames = new ArrayList<ArrayList<Info>>();
        ArrayList<ArrayList<Info>> femaleNames = new ArrayList<ArrayList<Info>>();
        // File stream
        Scanner input;
        File file;
        System.out.println("Loading...");
        for (int i = 0; i < 21; i++) {
            file = new File(fileNames[i]);
            ArrayList<Info> mList = new ArrayList<Info>();
            ArrayList<Info> fList = new ArrayList<Info>();

            try {
                input = new Scanner(file);
                for (int j = 0; j < 1000; j++) {
                    String line = input.nextLine();
                    // Split the line with any whitespace
                    String[] parts = line.split(" ");
                    mList.add(new Info(parts[1], Integer.parseInt(parts[0])));
                    fList.add(new Info(parts[3], Integer.parseInt(parts[0])));
                }
                maleNames.add(mList);
                femaleNames.add(fList);
            } catch (Exception e) {
                System.out.println("File not found");
            }
        }

        Scanner in = new Scanner(System.in);
        while(true) {
            System.out.println("Enter the year (-1 to exit)");
            int year = in.nextInt();
            if (year == -1) {
                break;
            }
            System.out.println("Enter the gender (M/F)");
            String gender = in.next();
            
            System.out.println("Enter the name");
            String name = in.next();

            // Find the name in the list
            ArrayList<Info> list;
            if (gender.equals("M")) {
                list = maleNames.get(year - 2001);
            }
            else {
                list = femaleNames.get(year - 2001);
            }

            boolean found = false;
            for (Info info : list) {
                if (info.name.equals(name)) {
                    System.out.println(info.name + " is ranked #" + info.rank + " in year " + year + "\n");
                    found = true;
                }
            }
            if (!found) {
                System.out.println("The name " + name + " is not ranked in year " + year + "\n");
            }
        }

    }

}
