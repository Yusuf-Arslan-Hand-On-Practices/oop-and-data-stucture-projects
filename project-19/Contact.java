import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.TreeSet;

/*
 * Java Generic Collections API
 * 
 * The Java Collections API is a set of classes and interfaces that implement
 * commonly used data structures. The Java Collections API is a part of the Java
 * Platform. 
 * 
 * The Comparator interface is used to compare two objects. The Comparator, gives
 * opportunity to sort the elements of the collection in different ways and different data fields.
 * 
 * The HashSet is a collection that contains no duplicate elements. It stores the elements by using a
 * mechanism called hashing. In this mechanism, the elements are stored in buckets. Each bucket is
 * associated with a value called a hash value. The hash value is calculated by using the hashCode()
 * method. The elements are placed in the bucket based on the hash value. The HashSet class implements
 * the Set interface.
 * 
 * The TreeSet is a collection that contains no duplicate elements. It stores the elements in a sorted
 * and ascending order. It is a red-black tree based implementation of the Set interface. The elements
 * in the TreeSet are sorted by using their natural ordering, or by a Comparator provided at set
 * creation time, depending on which constructor is used. 
 * 
 * The HashMap is a collection that stores key/value pairs. It is a part of the Java Collections API.
 * The HashMap class implements the Map interface. The HashMap class uses a technique called hashing.
 * In this technique, the elements are stored in buckets. Each bucket is associated with a value called
 * a hash value. The hash value is calculated by using the hashCode() method. The elements are placed
 * in the bucket based on the hash value.
 * 
 */

// Contact class, implements Comparable interface
public class Contact implements Comparable<Contact> {

    public static final String INPUT_FILE = "contacts.txt";
    public static final String ARRAY_OUTPUT = "contactArrayList.txt";
    public static final String SORTED_ARRAY_OUTPUT = "contactsArrayListOrderByLastName.txt";
    public static final String HASHSET_OUTPUT = "contactHashSet.txt";
    public static final String TREESET_OUTPUT = "contactTreeSet.txt";
    public static final String SORTED_TREESET_OUTPUT = "contactTreeSetOrderByLastName.txt";
    public static final String HASHMAP_OUTPUT = "contactsHashMap.txt";

    private String phoneNumber;
    private String firstName;
    private String lastName;
    private String socialSecurityNumber;

    // Parameterized constructor
    public Contact(String phoneNumber, String firstName, String lastName, String socialSecurityNumber) {
        this.phoneNumber = phoneNumber;
        this.firstName = firstName;
        this.lastName = lastName;
        this.socialSecurityNumber = socialSecurityNumber;
    }

    // Getters and setters
    public String getSocialSecurityNumber() {
        return socialSecurityNumber;
    }

    public void setSocialSecurityNumber(String socialSecurityNumber) {
        this.socialSecurityNumber = socialSecurityNumber;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    @Override
    public String toString() {
        return phoneNumber + ' ' + firstName + ' ' + lastName + ' ' + socialSecurityNumber;
    }

    @Override
    public int compareTo(Contact o) {
        return this.phoneNumber.compareTo(o.phoneNumber);
    }

    @Override
    public int hashCode() {
        return phoneNumber.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Contact other = (Contact) obj;
        if ((this.phoneNumber == null) ? (other.phoneNumber != null) : !this.phoneNumber.equals(other.phoneNumber)) {
            return false;
        }
        return true;
    }

    // Comparator class
    public static class LastNameComparator implements Comparator<Contact> {
        @Override
        public int compare(Contact o1, Contact o2) {
            return o1.getLastName().compareTo(o2.getLastName());
        }
    }

    // Main method
    public static void main(String[] args) {

        // Read the contacts from the file
        File inputFile = new File(INPUT_FILE);

        // output files
        File arrayOutput = new File(ARRAY_OUTPUT);
        File sortedArrayOutput = new File(SORTED_ARRAY_OUTPUT);
        File hashSetOutput = new File(HASHSET_OUTPUT);
        File treeSetOutput = new File(TREESET_OUTPUT);
        File sortedTreeSetOutput = new File(SORTED_TREESET_OUTPUT);
        File hashMapOutput = new File(HASHMAP_OUTPUT);

        // ----------------- Array List -----------------
        // Contact array list
        ArrayList<Contact> contacts = new ArrayList<>();
        
        // Read file and add contacts to the list
        try (Scanner scanner = new Scanner(inputFile)) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");
                Contact contact = new Contact(parts[0], parts[1], parts[2], parts[3]);
                contacts.add(contact);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        // Write the contacts to the file
        try (FileWriter writer = new FileWriter(arrayOutput)) {
            for (Contact contact : contacts) {
                writer.write(contact.toString() + "\n");
        
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Sort the contacts by last name and write them to the file
        Collections.sort(contacts, new LastNameComparator());
        try (FileWriter writer = new FileWriter(sortedArrayOutput)) {
            for (Contact contact : contacts) {
                writer.write(contact.toString() + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }


        // ----------------- Hash Set -----------------
        // Contact hash set
        HashSet<Contact> contactHashSet = new HashSet<>();

        // Read file and add contacts to the hash set
        try (Scanner scanner = new Scanner(inputFile)) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");
                Contact contact = new Contact(parts[0], parts[1], parts[2], parts[3]);
                contactHashSet.add(contact);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        // Write the contacts to the file
        try (FileWriter writer = new FileWriter(hashSetOutput)) {
            for (Contact contact : contactHashSet) {
                writer.write(contact.toString() + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // ----------------- Tree Set -----------------
        // Contact tree set
        TreeSet<Contact> contactTreeSet = new TreeSet<>();

        // Read file and add contacts to the tree set
        try (Scanner scanner = new Scanner(inputFile)) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");
                Contact contact = new Contact(parts[0], parts[1], parts[2], parts[3]);
                contactTreeSet.add(contact);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        // Write the contacts to the file
        try (FileWriter writer = new FileWriter(treeSetOutput)) {
            for (Contact contact : contactTreeSet) {
                writer.write(contact.toString() + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Sort the contacts by last name
        Collections.sort(contacts, new LastNameComparator());

        // Write the contacts to the file
        try (FileWriter writer = new FileWriter(sortedTreeSetOutput)) {
            for (Contact contact : contacts) {
                writer.write(contact.toString() + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // ----------------- Hash Map -----------------
        // Phone numbers are keys and contacts are values
        HashMap<String, Contact> contactHashMap = new HashMap<>();
        
        // Read file and add contacts to the hash map
        try (Scanner scanner = new Scanner(inputFile)) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");
                Contact contact = new Contact(parts[0], parts[1], parts[2], parts[3]);
                contactHashMap.put(contact.getPhoneNumber(), contact);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        // Write the contacts to the file
        try (FileWriter writer = new FileWriter(hashMapOutput)) {
            for (Contact contact : contactHashMap.values()) {
                writer.write(contact.toString() + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

