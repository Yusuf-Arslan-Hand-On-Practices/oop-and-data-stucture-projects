#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "HashMap.cpp"

#define COMPIN "compin"
#define COMPOUT "compout"

using namespace std;

#define MAX 4096

int main()
{
    // ------------------ COMPRESSION ------------------ 
	// Declare and initialize variables
    string infile = COMPIN;
    string outfile = COMPOUT;

    ifstream inFile;
    ofstream outFile;

    // Open the input file
    inFile.open(infile);
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    // Check if the input file is open
    // Initialize variables for reading and processing the input file
    char ch;
    HashMap compressionHashMap(MAX);
    string allChars = "";

    // Read all characters from the input file and store them in the "allChars" string
    while (!inFile.eof()) {
        inFile.get(ch);
        allChars += ch;
    }

    // Remove the extra character added by the loop
    allChars = allChars.substr(0, allChars.length() - 1);

    // Insert all ASCII codes into the hash table
    string str;
    for (int asciiCode = 0; asciiCode <= 255; asciiCode++) {
        str = string(1,char(asciiCode));
        compressionHashMap.put(str, asciiCode);
    }

    // Open the output file
    outFile.open(outfile);

    // Check if the output file is open
    if (!outFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    // Initialize variables for processing the "allChars" string
    int currentIndex = 256;         // The current index in the hash table
    int substrLength = 2;           // The length of the substring to be processed
    int udpatedStrLength = 1;       // The length of the processed substring

    // Iterate through the "allChars" string
    for (int i = 0; i < allChars.length(); i++) {
        // Get a substring of the current iteration
        string substr = allChars.substr(0, substrLength);

        // Check if the substring is not in the hash table
        if (compressionHashMap.find(substr) == -1) {
            // If the current index is less than MAX, add the substring to the hash table
            if (currentIndex < MAX) {
                compressionHashMap.put(substr, currentIndex);
            }
            // Write the current substring to the output file
            outFile << compressionHashMap.find(allChars.substr(0, udpatedStrLength)) << " ";

            // Remove the processed portion of the "allChars" string and reset the processing variables
            allChars = allChars.substr(udpatedStrLength, allChars.length() - 1);

            substrLength = 2;       // Change the substring length to 2
            udpatedStrLength = 1;   // Change the processed substring length to 1
            currentIndex++;         // Increment the current index in the hash table
            i = 0;                  // Reset the current iteration
        }
        // If the substring is in the hash table, update the processing variables
        else {
            substrLength++;
            udpatedStrLength++;
        }
    }

    // Write the remaining portion of the "allChars" string to the output file
    outFile << compressionHashMap.find(allChars) << "";

    // Close the input and output files
    inFile.close();
    outFile.close();
}