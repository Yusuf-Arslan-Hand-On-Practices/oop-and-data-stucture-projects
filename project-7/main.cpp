#include <iostream>
#include <fstream>

#include "order.cpp"
#include "queue.cpp"
#include "statistics.cpp"

using namespace std;

typedef struct Cashier
{
    Order *current;
    double freeAt;
} Cashier;

typedef struct Barista
{
    Order *current;
    double freeAt;
} Barista;

int cashierQueueCounter = 0;
int maxCashierQueue = 0;

int baristaQueueCounter = 0;
int maxBaristaQueue = 0;


#include "simulation1.cpp"
#include "simulation2.cpp"


// Main with arguments
int main(int argc, char *argv[])
{
    // Check for correct number of arguments
    if (argc != 3)
    {
        cout << "Usage: ./main <input file> <output file>" << endl;
        return 1;
    }

    // Open input file
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        cout << "Error: Unable to open file " << argv[1] << endl;
        return 1;
    }

    // Open output file
    ofstream outputFile(argv[2]);
    if (!outputFile.is_open())
    {
        cout << "Error: Unable to open file " << argv[2] << endl;
        return 1;
    }

    simulation1(inputFile, outputFile);
    // Open input file again, because simulation1() closes it
    inputFile.open(argv[1]);
    outputFile << endl;
    simulation2(inputFile, outputFile);

    // Close files
    inputFile.close();
    outputFile.close();

}