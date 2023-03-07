#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

// Date class
class Date
{
// Represent a date as a day, month, and year
public:
    int day;
    string month;
    int year;
    Date(int d, string m, int y) : day(d), month(m), year(y) {}
};

// Player class
class Player
{
// Represent a player as a first name, last name, and date of birth
private:
    string first;
    string last;
    Date birth;
    
public:
    // Constructor
    Player(string f, string l, Date b) : first(f), last(l), birth(b) {}

    // set and get functions, printInfo function
    void setMonth(string m) 
    { 
        birth.month = m; 
    }
    void printInfo (ostream &out) const
    {
        out << first << " " << last << " -- " << birth.month << " " << birth.day << ", " << birth.year << endl;
    }
    int getDay() const 
    { 
        return birth.day; 
    }
    int getYear() const 
    { 
        return birth.year; 
    }
};


int main()
{
    ifstream fin(INPUT_FILE);
    string months[] = {"January", "February", "March", "April", "May", "June", 
                       "July", "August", "September", "October", "November", "December"};

    if (!fin)
    {
        cout << "Cannot open input file." << endl;
        return 1;
    }

    ofstream fout(OUTPUT_FILE);
    if (!fout)
    {
        cout << "Cannot open output file." << endl;
        return 1;
    }

    string first, last, month;
    int day, year;
    while (fin >> first >> last >> day >> month >> year)
    {
        try
        {
            for (int i = 0; i < 12; i++)
            {
                // Check first 3 letters of month
                if (month.substr(0, 3) == months[i].substr(0, 3))
                {
                    if (month != months[i])
                    {
                        // If month is incorrect, change it to the correct month and throw an exception
                        // with the incorrect month and the correct month
                        string incorrectMonth = month;
                        month = months[i];
                        throw "Incorrectly inputted month: " + incorrectMonth + 
                                               " is corrected to " + month;
                    }
                    break;
                }
            }
        }
        catch (string e)
        {
            cout << e << endl;
        }
        
        // Create a Date object
        Date birth(day, month, year);

        // Create a Player object
        Player player(first, last, birth);
        
        // Print the player's information to the output file
        player.printInfo(fout);
    }

    return 0;
}