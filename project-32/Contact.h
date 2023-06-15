#ifndef CONTACT
#define CONTACT

#include <iostream>
#include <string>

// contact class
class Contact {
    private:
        string fullName;
        string phoneNumber;
        string location;
    public:
        Contact(string fullName, string phoneNumber, string location);
        Contact(string search);
        ~Contact();
        string getFullName();
        string getPhoneNumber();
        string getLocation();
        // operator overloads
        bool operator<(const Contact& other);
        bool operator>(const Contact& other);
        bool operator==(const Contact& other);
        bool operator!=(const Contact& other);
        friend ostream& operator<<(ostream& os, const Contact& contact);
};

// implementations
Contact::Contact(string fullName, string phoneNumber, string location) {
    this->fullName = fullName;
    for (int i = 0; i < fullName.length(); i++) {
        this->fullName[i] = toupper(fullName[i]);
    }
    this->phoneNumber = phoneNumber;
    this->location = location;
}

Contact::Contact(string search) {
    this->fullName = search;
    for (int i = 0; i < fullName.length(); i++) {
        fullName[i] = toupper(fullName[i]);
    }
}

Contact::~Contact() {}

string Contact::getFullName() {
    return fullName;
}

string Contact::getPhoneNumber() {
    return phoneNumber;
}

string Contact::getLocation() {
    return location;
}

bool Contact::operator<(const Contact& other) {
    return fullName < other.fullName;
}

bool Contact::operator>(const Contact& other) {
    return fullName > other.fullName;
}

bool Contact::operator==(const Contact& other) {
    // this operator will be used for search a contact. so partial match from the beginning will be true
    if (other.fullName.length() > fullName.length()) {
        return false;
    }
    for (int i = 0; i < other.fullName.length(); i++) {
        if (other.fullName[i] != fullName[i]) {
            return false;
        }
    }

    return true;
}

bool Contact::operator!=(const Contact& other) {
    return fullName != other.fullName;
}

ostream& operator<<(ostream& os, const Contact& contact) {
    os << contact.fullName << " " << contact.phoneNumber << " " << contact.location;
    return os;
}


#endif