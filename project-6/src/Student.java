public class Student implements Comparable<Student> {

    private int id;
    private String name;
    private String lastName;
    private int score;

    public Student(int id, String name, String lastName, int score) {
        this.id = id;
        this.name = name;
        this.lastName = lastName;
        this.score = score;
    }

    // Getter and Setter methods
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }
    // Getter and Setter methods ---- END



    @Override
    public String toString() {
        return "Student [" + "id: " + id + "\tname: " + name + "\tlastName: " + lastName + "\tscore: " + score + ']';
    }

    @Override
    public int compareTo(Student o) {
        // Compare scores, if scores are equal, compare names, if names are equal, compare last names.
        if (this.score == o.score) {
            if (this.name.equals(o.name)) {
                return this.lastName.compareTo(o.lastName);
            } else {
                return this.name.compareTo(o.name);
            }
        } else {
            return this.score - o.score;
        }
    }

    @Override
    public boolean equals(Object obj) {
        // If id's are equal, return true, otherwise return false.
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Student other = (Student) obj;
        if (this.id != other.id) {
            return false;
        }
        return true;
    }
}
