
package simulation;

public class Intern {
    private String name;
    private String id;

    // Default constructor
    public Intern() {
        this.name = "Dummy Name";
        this.id = "000000";
    }

    // Constructor with name
    public Intern(String name) {
        this.name = name;
        this.id = "000000";
    }

    // Constructor with name and id
    public Intern(String name, String id) {
        this.name = name;
        this.id = id;
    }

    // Getter and setter methods
    public String getName() {
        return this.name;
    }

    public String getId() {
        return this.id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setId(String id) {
        this.id = id;
    }
}
