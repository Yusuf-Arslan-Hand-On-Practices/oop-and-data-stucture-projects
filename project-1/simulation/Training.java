
package simulation;

import java.util.ArrayList;

public class Training {
    // Data fields
    private String title;
    private String code;
    private ArrayList<Intern> interns;

    // Constructor with title and code
    public Training(String title, String code) {
        this.title = title;
        this.code = code;
        this.interns = new ArrayList<Intern>();
    }

    // Getter and setter methods
    public String getTitle() {
        return this.title;
    }

    public String getCode() {
        return this.code;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public void appendIntern(Intern intern) {
        this.interns.add(intern);
    }

    // This method returns the list of interns
    public ArrayList<String> getInternList() {
        ArrayList<String> internList = new ArrayList<String>();
        for (Intern intern : this.interns) {
            internList.add(intern.getName());
        }
        return internList;
    }

    public ArrayList<Intern> getInterns() {
        return this.interns;
    }
    
}
