#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "HashMap.cpp"

#define COMPOUT "compout"
#define DECOMPOUT "decompout"

using namespace std;

#define MAX 4096

//this is the function defined in the homework instructions
string decompression(HashMap& hashMap, int prev, int& currentIndexRef, 
                     int current, string prevKey, string *keyArray) {
    // Declare constant reference variables to store the empty string and 
    // the current string in the array
    string notfound; 
    string currstr = keyArray[current];

    // Declare a string variable to store the previous string in the array and initialize it with the value at the previous index
    string printprev = keyArray[prev];
    prevKey = keyArray[prev];

    // Check if the current string is the empty string
    if (currstr == notfound) { 
        // If the current index in the array is empty, append the first character of the previous string to it
        prevKey += prevKey[0]; 
    } else {
        // If the current index is not empty, create a new code for the dictionary 
        // by appending the first character of the current string to the previous string
        prevKey += currstr[0]; 
    }

    // Add the Dictionary object to the hash table using the new code
    hashMap.put(prevKey, currentIndexRef); 

    // Store the new code in the array at the current hash index
    keyArray[currentIndexRef] = prevKey; 

    // Increment the current hash index
    currentIndexRef++;

    // Return the initial keys inside the dictionary
    return hashMap.findKey(printprev);
}

int main()
{
    // ------------------ DECOMPRESSION ------------------ 
	// Declare input and output file streams
    ifstream inFile;
    ofstream outFile;

    // Open the input file
    inFile.open(COMPOUT);

    // Check if the input file is open
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    // Open the output file
    outFile.open(DECOMPOUT);

    // Check if the output file is open
    if (!outFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    // Create a hash map with a size of MAX
    HashMap decompressionHashMap(MAX);

    // Create a vector to store the integers read from the input file
    vector<int> values;     // Possible values 

    // Read integers from the input file and store them in the vector
    int nums;
    while (inFile >> nums) {
        // If the integer is greater than MAX, exit the program
        if (nums > MAX)
            exit(1);

        // Add the integer to the vector
        values.push_back(nums);
    }

    // Create an array to store the keys
    string keys[MAX];

    // Insert all ASCII codes into the hash map and the array
    for (int asciiCode = 0; asciiCode < 256; asciiCode++) {
        // Convert the ASCII code to a string
        string str(1, char(asciiCode));
        // Store the string in the array
        keys[asciiCode] = char(asciiCode);
        // Insert the string and its corresponding ASCII code into the hash map
        decompressionHashMap.put(str, asciiCode);
    }

    // Set the current index to 256
    int currentIndex = 256;

    // Initialize the previous and current integers to the first element in the vector
    int prevnum = values[0];
    // Convert the previous integer to a string
    string pstr = string(1, char(prevnum));
    int currentnum = 0;

    // Loop through the rest of the elements in the vector
    for (int k = 1; k <= values.size(); k++) {
        // If the current element is not the last element, update the current integer
        if (k != values.size()) currentnum = values[k];
        // Write the keys to the output file using the decompression function
        outFile << decompression(decompressionHashMap, prevnum, currentIndex, currentnum, pstr, keys);
        // Update the previous integer and string
        prevnum = currentnum;
        pstr = keys[prevnum];
    }

    // Close the output file
    outFile.close();
    // Close the input file
    inFile.close();
}