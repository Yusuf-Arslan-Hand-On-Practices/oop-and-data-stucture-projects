#include <iostream>
#include <string>
#include "Hours.h"
#include "Cat.h"

using namespace std;

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
        cout << "Total time  animal stays in the clinic is" << totalMins << endl << "minutes. !" << endl << endl;
    }
    return 0;
}