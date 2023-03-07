#include <iostream>

#include "library.h"

using namespace std;

/*
    The menu has 6 options:
    1 - Prints the all frames (Original matrices)
    2 - Prints the compressed frames (Initially filled with zeros, after 
        3rd option performed, it will be filled with compressed matrices)
    3 - Compresses all the frames in original matrices, 
        puts them in compressed matrices and prints them
    4 - Compresses two frames in original matrices,
        puts them in compressed matrices and prints them
    5 - Resets the original matrices by generating new matrices and
        fills the compressed matrices with zeros
    6 - Pxits the program
*/

int main()
{
    // Set-up the program
    matrixGenerator();

    // Create an array to store the matrices
    double matrixArray[MATRIX_NUMBER][MATRIX_SIZE][MATRIX_SIZE];
    double compressedMatrixArray[MATRIX_NUMBER / 2][MATRIX_SIZE][MATRIX_SIZE];

    // Fill compressed matrices with zeros
    fillMatricesWithZeros(compressedMatrixArray, MATRIX_NUMBER / 2);

    // Read the matrices from the file
    readMatrices(matrixArray);

    // Menu
    int choice = 0;
    int frameNumber = 0;

    while (choice != 6)
    {
        cout << "--------- MENU - Video Compressor ---------" << endl;
        cout << "1. Print original frames" << endl;
        cout << "2. Print compressed frames" << endl;
        cout << "3. Compress and print frames" << endl;
        cout << "4. Compress and print two frames" << endl;
        cout << "5. Reset frames" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            printMatrices(matrixArray, MATRIX_NUMBER);
            break;
        case 2:
            printMatrices(compressedMatrixArray, MATRIX_NUMBER / 2);
            break;
        case 3:
            compressMatrices(matrixArray, compressedMatrixArray);
            printMatrices(compressedMatrixArray, MATRIX_NUMBER / 2);
            break;
        case 4:
            frameNumber = 0;
            cout << "\nEnter the frame number" << " (" << 1 << "-" << MATRIX_NUMBER / 2 << ")" << endl;
            for (int i = 0; i < MATRIX_NUMBER; i = i + 2)
            {
                cout << i/2 + 1 << "-  " << "Frame: " <<  i + 1 << "/" << i + 2 << endl;
            }
            cin >> frameNumber;
            while (frameNumber < 1 || frameNumber > MATRIX_NUMBER / 2)
            {
                cout << "Invalid frame number" << endl;
                cin >> frameNumber;
            }
            compressSingleMatrix(matrixArray, compressedMatrixArray, (frameNumber - 1) * 2);
            cout << "\nCompressed frame: " << (frameNumber - 1) * 2 + 1 << "/" << (frameNumber - 1) * 2 + 2 << endl;
            printSingleMatrix(compressedMatrixArray, frameNumber - 1);
            break;
        case 5:
            cout << "\nResetting..." << endl << endl;
            // Reset the file
            matrixGenerator();
            readMatrices(matrixArray);
            fillMatricesWithZeros(compressedMatrixArray, MATRIX_NUMBER / 2);
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}



