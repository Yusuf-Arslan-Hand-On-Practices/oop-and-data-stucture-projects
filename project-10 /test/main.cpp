#include <iostream>
#include <string>

using namespace std;

// Hours class that represents the time of the day
class Hours
{
public:
    int hour;
    int minute;
    // constructors
    Hours() : hour(0), minute(0) {}
    Hours(int h, int m) : hour(h), minute(m) {}
    // Overload the << operator
    friend ostream& operator<<(ostream& os, const Hours& h);
    // Overload the >> operator
    friend istream& operator>>(istream& is, Hours& h);
};

// implementation of the << operator
ostream& operator<<(ostream& os, const Hours& h)
{
    os << h.hour << ":" << h.minute;
    return os;
}

// implementation of the >> operator
istream& operator>>(istream& is, Hours& h)
{
    is >> h.hour >> h.minute;
    return is;
}


// Animal class that represents an animal
class Animal
{
    protected:
        string id;
        string animalName;
        string ownerName;
        string ownerSurname;
        Hours totalHours;
        int totalMins;
    public:
        // constructors
        Animal() : id(""), animalName(""), ownerName(""), ownerSurname(""), totalHours(0, 0), totalMins(0) {}
        Animal(string id, string animalName, string ownerName, string ownerSurname);
        // calculate the total minutes
        int calculateMinutes(const Hours& checkin, const Hours& checkout);
};


// constructor
Animal::Animal(string id, string animalName, string ownerName, string ownerSurname)
{
    this->id = id;
    this->animalName = animalName;
    this->ownerName = ownerName;
    this->ownerSurname = ownerSurname;
}

// calculate the total minutes
int Animal::calculateMinutes(const Hours& checkin, const Hours& checkout)
{
    // If hours are same and checkout is after checkin
    if (checkout.hour == checkin.hour && checkout.minute > checkin.minute)
    {
        this->totalMins = checkout.minute - checkin.minute;
    }
    // If checkout hour is after checkin hour
    else if (checkout.hour > checkin.hour)
    {
        this->totalMins = (checkout.hour - checkin.hour) * 60 + checkout.minute - checkin.minute;
    }
    else
    {
        // Return -1 to time control
        return -1;
    }
    return this->totalMins;
}

// Cat class inherits from Animal class
class Cat : public Animal
{
    protected:
        string type;
    public:
        Cat() : Animal(), type("") {}
        Cat(string id, string animalName, string ownerName, string ownerSurname, string type);
        void printInfo();
};

// constructor
Cat::Cat(string id, string animalName, string ownerName, string ownerSurname, string type) : 
     Animal(id, animalName, ownerName, ownerSurname), type(type) {}

// print the information of the cat
void Cat::printInfo()
{
    cout << "Id of the animal is " << this->id << endl;
    cout << "Name of the animal is " << this->animalName << endl;
    cout << "Name of the animal's owner is " << this->ownerName << endl;
    cout << "Surname of the animal's owner is " << this->ownerSurname << endl;
    cout << "Type of the animal is cat" << endl;
}





int main()
{
    Hours checkin, checkout;
    int totalMins;

    Cat cat1("123456", "Mimi", "John", "Smith", "Persian");
    cat1.printInfo();
    cout << "Enter the check in time of the animal:\n";
    cin >> checkin;

    cout << "Enter the check out time of the animal:\n";
    cin >> checkout;

    cout << "Check in and check out times are: " << checkin << "/" << checkout << endl;

    totalMins = cat1.calculateMinutes(checkin, checkout);
    if (totalMins == -1)
    {
        cout << "Please enter appropriate time" << endl;
    }
    else
    {
        cout << "Total time  animal stays in the clinic is " << totalMins << endl << "minutes. !" << endl << endl;
    }
    return 0;
}