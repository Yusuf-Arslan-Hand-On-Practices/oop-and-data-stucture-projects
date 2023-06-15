// student class with ID and CGPA
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int id;
    double cgpa;
public:
    // constructor
    Student(int id, double cgpa) {
        this->id = id;
        this->cgpa = cgpa;
    }
    // getter
    int getId() const {
        return id;
    }
    double getCgpa() const {
        return cgpa;
    }

    // This functions will be used for sorted insertion
    // compares id's and returns true if first one is larger (will be used for sorting). 
    static bool compareId(const Student& s1, const Student& s2) {
        return s1.getId() < s2.getId();
    }

    // compares cgpa's and returns true if first one is smaller. (will be used for sorting)
    static bool compareCgpa(const Student& s1, const Student& s2) {
        return s1.getCgpa() < s2.getCgpa();
    }

    // operator overloading
    bool operator==(const Student& s) const {
        return id == s.id;
    }

    bool operator!=(const Student& s) const {
        return id != s.id;
    }

    // stream
    void tostring() {
        std::cout << "id: " << id << " CGPA: " << cgpa << std::endl;
    }
};

#endif // STUDNET_H
